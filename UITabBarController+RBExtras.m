//
//  UITabBarController+RBExtras.m
//  HomeFinder
//
//  Created by Robert Brown on 5/5/12.
//  Copyright (c) 2012 Robert Brown. All rights reserved.
//

#import "UITabBarController+RBExtras.h"

@implementation UITabBarController (RBExtras)

+ (UITabBarController *)tabBarControllerWithStoryboardTabs:(NSArray *)tabs {
    
    UITabBarController * tabBarController = [UITabBarController new];
    NSMutableArray * instantiatedTabs = [NSMutableArray arrayWithCapacity:[tabs count]];
    
    // Instantiates each of the storyboards.
    [tabs enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL * stop) {
        
        NSAssert([obj isKindOfClass:[UIStoryboard class]], 
                 @"Expected UIStoryboard, got %@", 
                 NSStringFromClass([obj class]));
        
        [instantiatedTabs addObject:[obj instantiateInitialViewController]];
    }];
    
    [tabBarController setViewControllers:instantiatedTabs];
    
    return tabBarController;
}

@end
