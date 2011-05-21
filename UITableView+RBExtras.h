//
//  UITableView+RBExtras.h
//  StatCollector
//
//  Created by Robert Brown on 5/6/11.
//  Copyright 2011 Robert Brown. All rights reserved.
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
