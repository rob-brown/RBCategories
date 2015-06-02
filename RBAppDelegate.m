//
// RBAppDelegate.m
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

#import "RBAppDelegate.h"
#import "UITabBarController+RBExtras.h"


@implementation RBAppDelegate

@synthesize window = _window;

- (void)setUpTabBasedAppWithTabs:(NSArray *)tabs block:(RBTabBarCustomizationBlock)block {
    
    NSAssert(tabs, @"No tabs given.");
    NSAssert([tabs count] >= 2, @"Insufficient number of tabs.");
    
    // Sets up the tab bar controller.
    UITabBarController * tabBarController = [UITabBarController tabBarControllerWithStoryboardTabs:tabs];
    
    // The block is called to allow customization of the tab bar controller.
    if (block) block(tabBarController);
    
    // Sets up the window.
    UIWindow * window = [UIWindow new];
    [window setScreen:[UIScreen mainScreen]];
    [window setRootViewController:tabBarController];
    [window setFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
    [window makeKeyAndVisible];
    [self setWindow:window];
}

@end
