//
//  NSMutableSet+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/3/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import "NSMutableSet+RBExtras.h"


@implementation NSMutableSet (RBExtras)

- (void) symmetricDifferenceSet:(NSMutableSet *)otherSet {
    
    NSMutableSet * copySet = [self copy];
    
    [copySet minusSet:otherSet];
    [otherSet minusSet:self];
    [self unionSet:copySet];
}

- (NSMutableSet *) createSymmetricDifferenceSet:(NSMutableSet *)otherSet {
    
    NSMutableSet * copySet = [self copy];
    
    [copySet minusSet:otherSet];
    [otherSet minusSet:self];
    [copySet unionSet:otherSet];
    
    return [copySet autorelease];
}

- (NSMutableSet *) createMinusSet:(NSMutableSet *)otherSet {
    
    NSMutableSet * copySet = [self copy];
    
    [copySet minusSet:otherSet];
    
    return  [copySet autorelease];
}

- (NSMutableSet *) createIntersectionSet:(NSMutableSet *)otherSet {
    
    NSMutableSet * copySet = [self copy];
    
    [copySet intersectSet:otherSet];
    
    return  [copySet autorelease];
}

- (NSMutableSet *) createUnionSet:(NSMutableSet *)otherSet {
    
    NSMutableSet * copySet = [self copy];
    
    [copySet unionSet:otherSet];
    
    return  [copySet autorelease];
}

@end
