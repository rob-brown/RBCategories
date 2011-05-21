//
//  UIViewController+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/17/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import "UIViewController+RBExtras.h"


@implementation UIViewController (RBExtras)

- (UINavigationController *)topNavController {
    
    if ([self isKindOfClass:[UITabBarController class]]) {
        
        UITabBarController * tabBarController = (UITabBarController *)self;
        UIViewController * rootViewController = [tabBarController selectedViewController];
        
        return [rootViewController topNavController];
    }
    else if ([self isKindOfClass:[UINavigationController class]]) {
        
        UINavigationController * navController = (UINavigationController *)self;
        
        // Attempts to find a deeper nav controller, especially if there is a modal view on top.
        UINavigationController * subNavController = [[navController visibleViewController] topNavController];
        
        if (subNavController)
            return subNavController;
        else
            return navController;
    }
    else if ([self isKindOfClass:[UIViewController class]]) {
        
        if ([self modalViewController]) {
            return [[self modalViewController] topNavController];
        }
        else {
            return [self navigationController]; 
        }
    }
    
    // Hopefully this isn't ever reached.
    return nil;
}

@end
