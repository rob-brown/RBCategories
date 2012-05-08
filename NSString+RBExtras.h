//
// NSString+RBExtras.h
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

#import <Foundation/Foundation.h>

@class CLLocation;

@interface NSString (RBExtras)

/**
 * Returns true if the string is nil or empty.
 *
 * @param string The string to check if it's empty.
 */
+ (BOOL)isEmpty:(NSString *)string;

/**
 * If string is nil, then returns an empty string. Otherwise, returns the string 
 * unaltered.
 *
 * @param string The string to convert from nil, if necessary.
 *
 * @return Empty string for nil, otherwise returns the input string.
 */
+ (NSString *)convertNilString:(NSString *)string;

/**
 * Same as +convertNilString: except nil strings are returned as the input 
 * string. This is included mostly for completeness, but it some situations you 
 * may find it cleaner than using the ternary conditional.
 * 
 * @param string The string to convert from nil, if necessary.
 * @param defaultStr The string to return if string is nil.
 *
 * @return defaultStr for nil, otherwise returns the input string.
 */
+ (NSString *)convertNilString:(NSString *)string toDefault:(NSString *)defaultStr;

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

+ (NSString *)MIMETypeForExtension:(NSString *)extension;

@end
