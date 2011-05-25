//
//  NSString+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/24/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import "NSString+RBExtras.h"


@implementation NSString (RBExtras)

+ (NSString *)stringWithError:(NSError *)error {
    
    return [NSString stringWithFormat:
            @"ERROR:\n Description: %@\n Recovery Options:%@\n Recovery Suggestion:%@\n Failure Reason:%@\n Recovery Attempter:%@\n Error Info:%@\n",
            [error localizedDescription], 
            [error localizedRecoveryOptions], 
            [error localizedRecoverySuggestion], 
            [error localizedFailureReason], 
            [error recoveryAttempter], 
            [error userInfo]];
}

@end
