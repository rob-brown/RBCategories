//
//  NSString+RBExtras.h
//  StatCollector
//
//  Created by Robert Brown on 5/24/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CLLocation;

@interface NSString (RBExtras)

+ (NSString *)stringWithError:(NSError *)error;

+ (NSString *)stringWithLocation:(CLLocation *)location;

+ (NSString *)stringWithLatitude:(double)latitude longitude:(double)longitude;

- (NSString *)stringByRemovingCharactersInString:(NSString *)characters;

@end
