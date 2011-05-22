//
// NSMutableSet+RBExtras.h
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


@interface NSMutableSet (RBExtras)

/**
 * Modifies the receiver such that it equals ((A - B) U (B - A)), where A is the
 * receiver and B is otherSet. otherSet is not modified.
 *
 * @param otherSet The set that should have the symmetric difference calculated 
 * from.
 */
- (void) symmetricDifferenceSet:(NSMutableSet *)otherSet;

/**
 * Returns an autoreleased set such that ((A - B) U (B - A)), where A is the
 * receiver and B is otherSet. The receiver and parameters are not modified.
 * 
 * @param otherSet The set that should have the symmetric difference calculated 
 * from.
 */
 - (NSMutableSet *) createSymmetricDifferenceSet:(NSMutableSet *)otherSet;

/**
 * Returns an autoreleased set such that (A - B), where A is the receiver and B 
 * is otherSet. The receiver and parameters are not modified.
 * 
 * @param otherSet The set that should have the difference calculated from.
 */
- (NSMutableSet *) createMinusSet:(NSMutableSet *)otherSet;

/**
 * Returns an autoreleased set such that (A intersect B), where A is the 
 * receiver and B is otherSet. The receiver and parameters are not modified.
 * 
 * @param otherSet The set that should have the intersection calculated from.
 */
- (NSMutableSet *) createIntersectionSet:(NSMutableSet *)otherSet;

/**
 * Returns an autoreleased set such that (A U B), where A is the receiver and B 
 * is otherSet. The receiver and parameters are not modified.
 * 
 * @param otherSet The set that should have the union calculated from.
 */
- (NSMutableSet *) createUnionSet:(NSMutableSet *)otherSet;

@end
