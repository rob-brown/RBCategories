//
//  NSError+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/10/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import "NSError+RBExtras.h"

// Error Domains
NSString * const RBErrorDomain = @"RBErrorDomain";

// Error Codes
const NSInteger RBValidationError = 2000;

@implementation NSError (RBExtras)

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
