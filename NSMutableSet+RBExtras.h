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
