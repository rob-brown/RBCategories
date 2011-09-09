//
// GCD+RBExtras.c
//
// Copyright (c) 2011 Robert Brown
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <stdio.h>
#include <assert.h>
#include <Block.h>

#include "GCD+RBExtras.h"

void dispatch_sync_safe_main(dispatch_block_t block) {
    dispatch_sync_safe(dispatch_get_main_queue(), block);
}

void dispatch_sync_safe(dispatch_queue_t queue, dispatch_block_t block) {
    
    // If we're already on the given queue, just run the block.
    if (dispatch_get_current_queue() == queue)
        block();
    // Otherwise, dispatch to the given queue.
    else
        dispatch_sync(queue, block);
}

void dispatch_async_main(dispatch_block_t block) {
    dispatch_async(dispatch_get_main_queue(), block);
}

void dispatch_async_low(dispatch_block_t block) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), block);
}

void dispatch_async_default(dispatch_block_t block) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block);
}

void dispatch_async_high(dispatch_block_t block) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), block);
}

void dispatch_stride(size_t stride, size_t iterations, dispatch_queue_t queue, StrideBlock block) {
    
    assert(block);
    
    size_t strideCount = iterations / stride;
    
    // queue must be a concurrent queue!
    dispatch_apply(strideCount, queue, ^(size_t idx) {
        size_t i = idx * stride;
        size_t stop = i + stride;
        do {
            block(idx);
        } while (i < stop);
    });
    
    // Pick up any left over iterations.
    for (size_t i = iterations - (iterations % stride); i < iterations; i++)
        block(i);
}
