//
//  NSMutableSet+RBExtras.h
//  StatCollector
//
//  Created by Robert Brown on 5/3/11.
//  Copyright 2011 Robert Brown. All rights reserved.
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
