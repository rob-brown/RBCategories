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

#ifndef GCD_RBExtras_h
#define GCD_RBExtras_h

#include <dispatch/dispatch.h>


/// Deadlock warnings may be turned on/off by defining or not defining 
/// DEADLOCK_WARNINGS. It's best to turn these warnings on in debug mode.
#if defined(DEADLOCK_WARNINGS)

/// Issues a warning when a synchronous method is called from the main queue.
/// Put this macro in your sychronous methods that are not safe for the main 
/// queue. Intended for Objective-C.
#define DEADLOCK_SYNC_WARNING() \
if (dispatch_get_current_queue() == dispatch_get_main_queue()) \
NSLog(\
@"WARNING: Deadlock possible. "\
"Calling sychronous method from main queue in method: "\
"%@ file: %s line: %d.", \
NSStringFromSelector(_cmd), \
__FILE__, \
__LINE__);

/// Issues a warning when a synchronous method is called from the main queue.
/// Put this macro in your sychronous methods that are not safe for the main 
/// queue. Intended for C or Objective-C.
#define DEADLOCK_SYNC_WARNING_C() \
if (dispatch_get_current_queue() == dispatch_get_main_queue()) \
NSLog(\
@"WARNING: Deadlock possible. "\
"Calling sychronous function from main queue in "\
"%@ file: %s line: %d.", \
__FILE__, \
__LINE__);

#else
#define DEADLOCK_SYNC_WARNING()
#define DEADLOCK_SYNC_WARNING_C() 
#endif


/// Race condition warnings may be turned on/off by defining or not defining 
/// RACE_CONDITION_WARNINGS. It's best to turn these warnings on in debug mode.
#if defined(RACE_CONDITION_WARNINGS)

/// Issues a warning when the current queue is not the given queue. Useful for
/// when you want to make sure a certain method is only run with the given 
/// queue. Intended to be used with Objective-C. 
/// q must be of type dispatch_queue_t.
#define RACE_CONDITION_WARNING(q) \
if (dispatch_get_current_queue() != q) \
NSLog(\
@"WARNING: Race condition possible. " \
"Running method from wrong queue in method: "\
"%@ file: %s line: %d. Expected queue: %s but running in: %s",\
NSStringFromSelector(_cmd), \
__FILE__, \
__LINE__, \
dispatch_queue_get_label(q), \
dispatch_queue_get_label(dispatch_get_current_queue()));

/// Issues a warning when the current queue is not the given queue. Useful for
/// when you want to make sure a certain method is only run with the given 
/// queue. Intended to be used with Objective-C.
/// q must be of type dispatch_queue_t.
#define RACE_CONDITION_WARNING_C(q) \
if (dispatch_get_current_queue() != q) \
NSLog(\
@"WARNING: Race condition possible. " \
"Running method from wrong queue in method: "\
"%@ file: %s line: %d. Expected queue: %s but running in: %s",\
NSStringFromSelector(_cmd), \
__FILE__, \
__LINE__, \
dispatch_queue_get_label(q), \
dispatch_queue_get_label(dispatch_get_current_queue()));

/// Issues a warning when the current queue is not the main queue. Useful for
/// when you want to make sure a certain method is only run with the main queue.
/// Intended to be used with Objective-C.
#define RACE_CONDITION_WARNING_MAIN() RACE_CONDITION_WARNING(dispatch_get_main_queue())

/// Issues a warning when the current queue is not the main queue. Useful for
/// when you want to make sure a certain method is only run with the main queue.
/// Intended to be used with C or Objective-C.
#define RACE_CONDITION_WARNING_MAIN_C() RACE_CONDITION_WARNING_C(dispatch_get_main_queue())

#else
#define RACE_CONDITION_WARNING(q) 
#define RACE_CONDITION_WARNING_C(q) 
#define RACE_CONDITION_WARNING_MAIN()
#define RACE_CONDITION_WARNING_MAIN_C() 
#endif

/// A convenient block type to use with dispatch_stride.
typedef void(^StrideBlock)(size_t idx);

/**
 * Guarantees that the given block will be safely and synchronously run on the 
 * main thread. 
 *
 * @deprecated This function does not guarantee that it won't block. Consider 
 * the situation where you dispatch_sync_safe_main to queue A. Then 
 * dispatch_sync_safe_main to queue B. Finally, dispatch_sync_safe_main back to 
 * queue A. This will cause deadlock. Use dispatch_async_continue instead.
 *
 * @param block The block to run on the main thread.
 */
void dispatch_sync_safe_main(dispatch_block_t block) __attribute__ ((deprecated));

/**
 * Guarantees that the given block will be safely and synchronously run on the 
 * given queue. This is good for when you want to run code sychronously, but 
 * have the possiblity of already being dispatched from the given queue. 
 *
 * @deprecated This function does not guarantee that it won't block. Consider 
 * the situation where you dispatch_sync_safe to queue A. Then dispatch_sync_safe
 * to queue B. Finally, dispatch_sync_safe back to queue A. This will cause 
 * deadlock. Use dispatch_async_continue instead.
 * 
 * @param queue The queue to run the given block on.
 * @param block The block to run on the given queue.
 */
void dispatch_sync_safe(dispatch_queue_t queue, dispatch_block_t block) __attribute__ ((deprecated));

/**
 * Runs the given block on the main queue. Like dispatch_sync, this function may
 * block. The difference, however, is that this function will first check if 
 * execution is already on the main queue. This offers some extra deadlock 
 * protection.
 *
 * @deprecated This function does not guarantee that it won't block. Consider 
 * the situation where you dispatch_sync_safe_main to queue A. Then 
 * dispatch_sync_safe_main to queue B. Finally, dispatch_sync_safe_main back to 
 * queue A. This will cause deadlock. Use dispatch_async_continue instead.
 *
 * @param block The block to run on the main thread.
 */
void dispatch_sync_checked_main(dispatch_block_t block);

/**
 * Runs the given block on the given queue. Like dispatch_sync, this function 
 * may block. The difference, however, is that this function will first check if 
 * execution is already on the given queue. This offers some extra deadlock 
 * protection.
 *
 * @param queue The queue to run the given block on.
 * @param block The block to run on the given queue.
 */
void dispatch_sync_checked(dispatch_queue_t queue, dispatch_block_t block);

/**
 * Convenience method for asynchronously dispatching to the main queue.
 *
 * @param block The block to asynchrously dispatch. Must not be NULL.
 */
void dispatch_async_main(dispatch_block_t block);

/**
 * Convenience method for asynchronously dispatching to the low priority queue.
 *
 * @param block The block to asynchrously dispatch. Must not be NULL.
 */
void dispatch_async_low(dispatch_block_t block);

/**
 * Convenience method for asynchronously dispatching to the default priority 
 * queue.
 *
 * @param block The block to asynchrously dispatch. Must not be NULL.
 */
void dispatch_async_default(dispatch_block_t block);

/**
 * Convenience method for asynchronously dispatching to the high priority queue.
 *
 * @param block The block to asynchrously dispatch. Must not be NULL.
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
 * independent of other iterations. Must not be NULL.
 */
void dispatch_stride(size_t stride, size_t iterations, dispatch_queue_t queue, StrideBlock block);

/**
 * Runs asyncBlock on the given queue. After that block has run to completion,
 * then runs continueBlock on the caller's queue. This is a great replacement 
 * for dispatch_sync_safe. The basic idea is that it causes you to temporarily
 * jump to a queue and subsequently jump back to your original queue. This 
 * gives the same behavior as dispatch_sync but will never block. Furthermore,
 * your code keeps its synchrounous appearance.
 *
 * @param queue The queue to temporarily jump to. Must not be NULL.
 * @param asyncBlock The block to run on queue. Must not be NULL.
 * @param continueBlock The block to run on the caller's queue after completing
 * asyncBlock. May be NULL. If NULL, then this acts the same as dispatch_async.
 */
void dispatch_async_continue(dispatch_queue_t queue, dispatch_block_t asyncBlock, dispatch_block_t continueBlock);

#endif    // GCD_RBExtras_h
