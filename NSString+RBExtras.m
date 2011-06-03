//
//  NSString+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/24/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

#import "NSString+RBExtras.h"


@implementation NSString (RBExtras)

+ (NSString *)stringWithException:(NSException *)exception {
    
    return [NSString stringWithFormat:
            @"EXCEPTION:\n Name: %@\n Reason: %@\n User Info: %@\n Stack Return Addresses: %@\n Stack Symbols: %@\n", 
            [exception name],
            [exception reason],
            [exception userInfo],
            [exception callStackReturnAddresses],
            [exception callStackSymbols]];
}

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

+ (NSString *)stringWithLocation:(CLLocation *)location {
    
    CLLocationCoordinate2D coord = [location coordinate];
    
    return [self stringWithLatitude:coord.latitude
                          longitude:coord.longitude];
}

+ (NSString *)stringWithLatitude:(double)latitude longitude:(double)longitude {
    
    return [NSString stringWithFormat:@"%0.2f˚ %0.2f˚", latitude, longitude];
}

- (NSString *)stringByRemovingCharactersInString:(NSString *)characters {
    
    NSString * result = [[self copy] autorelease];
    
    // Removes the designated characters one-by-one.
    for (NSUInteger i = 0; i < [characters length]; i++) {
        
        // Grabs the character at the index.
        NSString * character = [characters substringWithRange:NSMakeRange(i, 1)];
        
        // Removes the character from the string.
        result = [result stringByReplacingOccurrencesOfString:character
                                                   withString:@""];
    }
    
    return result;
}

+ (NSString *)pathWithComponentsRelativeToDocumentsDirectory:(NSArray *)components {
    
    // Finds the documents directory.
    NSArray * docDirs = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString * docDir = [docDirs lastObject];
    
    // Inserts the documents directory to the begining of the components.
    NSMutableArray * alteredComponents = [[components mutableCopy] autorelease];
    [alteredComponents insertObject:docDir atIndex:0];
    
    return [NSString pathWithComponents:alteredComponents];
}

@end
