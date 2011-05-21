//
//  UIApplication+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/16/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import "UIApplication+RBExtras.h"


@implementation UIApplication (RBExtras)

+ (id<UIApplicationDelegate>)appDelegate {
    
    return [[self sharedApplication] delegate];
}

@end
