//
// Copyright 2011 Robert Brown
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
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
