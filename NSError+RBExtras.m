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

#import "NSError+RBExtras.h"

// Error Domains
NSString * const RBErrorDomain = @"RBErrorDomain";

// Error Codes
const NSInteger RBValidationError = 2000;

@implementation NSError (RBExtras)

// Modified from http://developer.apple.com/library/ios/#documentation/Cocoa/Conceptual/CoreData/Articles/cdValidation.html
+ (NSError *)validationErrorFromOriginalError:(NSError *)originalError error:(NSError *)secondError {
    
    NSMutableDictionary * userInfo = [NSMutableDictionary dictionary];
    NSMutableArray * errors = [NSMutableArray arrayWithObject:secondError];
    
    if ([originalError code] == NSValidationMultipleErrorsError) {
        
        [userInfo addEntriesFromDictionary:[originalError userInfo]];
        [errors addObjectsFromArray:[userInfo objectForKey:NSDetailedErrorsKey]];
    }
    else {
        [errors addObject:originalError];
    }
    
    [userInfo setObject:errors forKey:NSDetailedErrorsKey];
    
    return [NSError errorWithDomain:NSCocoaErrorDomain
                               code:NSValidationMultipleErrorsError
                           userInfo:userInfo];
}

@end
