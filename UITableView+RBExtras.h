//
// Copyright 2011 Robert Brown
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>


@interface UITableView (RBExtras)

/**
 * Scrolls to the first row of a table view with or without animation.
 *
 * @param animated Whether or not to animate the scroll.
 */
- (void)scrollToFirstRowAnimated:(BOOL)animated;

/**
 * Scrolls to the last row of a table view with or without animation.
 *
 * @param animated Whether or not to animate the scroll.
 */
- (void)scrollToLastRowAnimated:(BOOL)animated;

/**
 * Scrolls to the first responder, if any, to the middle with or without 
 * animation.
 *
 * @param animated Whether or not to animate the scroll.
 */
- (void)scrollFirstResponderIntoViewAnimated:(BOOL)animated;

/**
 * Removes the selection highlight from the currently highlighted row.
 */
- (void)deselectSelectedRowAnimated:(BOOL)animated;

@end
