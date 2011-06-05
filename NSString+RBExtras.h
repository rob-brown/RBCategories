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

//------------------------------------------------------------------------------
// String creation methods.
//------------------------------------------------------------------------------

+ (NSString *)stringWithException:(NSException *)exception;

+ (NSString *)stringWithError:(NSError *)error;

+ (NSString *)stringWithLocation:(CLLocation *)location;

+ (NSString *)stringWithLatitude:(double)latitude longitude:(double)longitude;

/**
 * Returns a string with all instances of the given characters removed from the 
 * receiver. The receiver itself is unaffected.
 *
 * @return A string stripped of the given characters.
 */
- (NSString *)stringByRemovingCharactersInString:(NSString *)characters;


//------------------------------------------------------------------------------
// Path methods.
//------------------------------------------------------------------------------

/**
 * Given an array of path components relative to the documents directory, 
 * constructs and returns a path.
 *
 * @param components An array of NSStrings which make up the components in a 
 * path relative to the documents directory.
 *
 * @return A string represting a file path. 
 */
+ (NSString *)pathWithComponentsRelativeToDocumentsDirectory:(NSArray *)components;

/**
 * Returns the MIME type of the string assuming it's a valid path. The return 
 * type is undefined if the string is not in a valid path format.
 *
 * @return The MIME type of the string.
 */
- (NSString *)MIMEType;

@end
