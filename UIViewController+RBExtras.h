//
//  UIViewController+RBExtras.h
//  StatCollector
//
//  Created by Robert Brown on 5/17/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UIViewController (RBExtras)

/**
 * Returns the top UINavigationController in the view hierarchy of this view 
 * controller. This should only be called on a view controller in the key 
 * window. This has no meaning and has not been tested on non-key windows.
 */
- (UINavigationController *)topNavController;

@end
