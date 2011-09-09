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

#include <dispatch/dispatch.h>

// Deadlock warnings may be turned on/off by defining or not defining 
// DEADLOCK_WARNINGS. It's best to turn these warnings on in debug mode.
#if defined(DEADLOCK_WARNINGS)

// Issues a warning when a synchronous method is called from the main queue.
// Put this macro in your sychronous methods that are not safe for the main queue.
#define DEADLOCK_SYNC_WARNING() if (dispatch_get_current_queue() == dispatch_get_main_queue()) NSLog(@"WARNING: Deadlock possible. Calling sychronous method from main queue in method: %@ file: %s line: %d.", NSStringFromSelector(_cmd), __FILE__, __LINE__);

#else
#define DEADLOCK_SYNC_WARNING() 
#endif

typedef void(^StrideBlock)(size_t idx);

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

/**
 * Convenience method for using the striding pattern. Runs the given block on 
 * the given queue in parallel. The block will be run 'iterations' number of 
 * times and 'stride' number of iterations will run per thread.
 *
 * @param stride The number of times to run 'block' per thread.
 * @param iterations The total number of times to run 'block'.
 * @param queue The queue to run the block on. This must be a concurrent queue 
 * to take advantage of parallelization.
 * @param block The block of code to run in parallel. Must be thread safe and 
 * independent of other iterations. 
 */
void dispatch_stride(size_t stride, size_t iterations, dispatch_queue_t queue, StrideBlock block);

#endif
