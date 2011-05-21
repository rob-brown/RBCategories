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
