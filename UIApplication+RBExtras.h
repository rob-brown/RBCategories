//
//  UIApplication+RBExtras.h
//  StatCollector
//
//  Created by Robert Brown on 5/16/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UIApplication (RBExtras)

/**
 * Convenience method that returns the app delegate. This is much shorter than
 * using [[UIApplication sharedApplication] delegate].
 */
+ (id<UIApplicationDelegate>)appDelegate;

@end
