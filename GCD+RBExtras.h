//
// GCD+RBExtras.h
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

#ifndef AboutOne_GCD_RBExtras_h
#define AboutOne_GCD_RBExtras_h

#import <dispatch/dispatch.h>

/**
 * Guarantees that the given block will be safely and synchronously run on the 
 * main thread. 
 *
 * @param block The block to run on the main thread.
 */
void dispatch_sync_safe_main(dispatch_block_t block);

/**
 * Guarantees that the given block will be safely and synchronously run on the 
 * given queue. This is good for when you want to run code sychronously, but 
 * have the possiblity of already being dispatched from the given queue. 
 *
 * @param block The block to run on the main thread.
 */
void dispatch_sync_safe(dispatch_queue_t queue, dispatch_block_t block);

/**
 * Convenience method for asynchronously dispatching to the main queue.
 *
 * @param block The block to asynchrously dispatch.
 */
void dispatch_async_main(dispatch_block_t block);

/**
 * Convenience method for asynchronously dispatching to the low priority queue.
 *
 * @param block The block to asynchrously dispatch.
 */
void dispatch_async_low(dispatch_block_t block);

/**
 * Convenience method for asynchronously dispatching to the default priority 
 * queue.
 *
 * @param block The block to asynchrously dispatch.
 */
void dispatch_async_default(dispatch_block_t block);

/**
 * Convenience method for asynchronously dispatching to the high priority queue.
 *
 * @param block The block to asynchrously dispatch.
 */
void dispatch_async_high(dispatch_block_t block);

#endif
