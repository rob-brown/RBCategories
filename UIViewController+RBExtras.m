//
// UIViewController+RBExtras.m
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
