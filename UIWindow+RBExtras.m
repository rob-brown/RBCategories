//
//  UIWindow+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/6/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import "UIWindow+RBExtras.h"
#import "UIViewController+RBExtras.h"

@implementation UIWindow (RBExtras)

- (UINavigationController *)topNavController {
    
    return [[self rootViewController] topNavController];
}

@end
