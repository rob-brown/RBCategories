//
// NSArray+RBExtras.h
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

/** 
 * Convenient typedef for declaring blocks for enumerating arrays.
 *
 * Template Example: 
 * NSArrayEnumerationBlock enumBlock = ^(id obj, NSUInteger idx, BOOL * stop) { ... }
 */
typedef void(^NSArrayEnumerationBlock)(id obj, NSUInteger idx, BOOL * stop);

@interface NSArray (RBExtras)

/**
 * Returns the first object in the array. If the array is empty, returns nil.
 */
- (id)firstObject;

/**
 * Returns the second object in the array. If the array doesn't have a second 
 * element, returns nil.
 */
- (id)secondObject;

/**
 * Returns the third object in the array. If the array doesn't have a second 
 * element, returns nil.
 */
- (id)thirdObject;

/**
 * Returns the fourth object in the array. If the array doesn't have a second 
 * element, returns nil.
 */
- (id)fourthObject;

/**
 * Returns the fifth object in the array. If the array doesn't have a second 
 * element, returns nil.
 */
- (id)fifthObject;

/**
 * Returns an array of values which come from the key path being applied to 
 * every element of the receiving array.
 *
 * @param keyPath The key path to apply to each element of the array.
 *
 * @return An array of values extracted from the receiving array..
 */
- (NSArray *)extractValuesForKeyPath:(NSString *)keyPath;

@end
