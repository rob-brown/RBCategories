//
//  UIWindow+RBExtras.h
//  StatCollector
//
//  Created by Robert Brown on 5/6/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * Category borrowed from Three20
 */
@interface UIWindow (RBExtras)

/**
 * Returns the top UINavigationController in the view hierarchy of this window.
 * This should only be called on the key window. This has no meaning and has not
 * been tested on non-key windows.
 */
- (UINavigationController *)topNavController;

@end
