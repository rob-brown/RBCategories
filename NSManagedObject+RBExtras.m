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

#import "NSManagedObject+Extras.h"


@implementation NSManagedObject (Extras)

+ (NSManagedObject *) createManagedObjectInContext:(NSManagedObjectContext *)context {
    
    return [self createManagedObjectWithName:NSStringFromClass([self class]) 
                                   inContext:context
                                    withZone:nil];
}

+ (NSManagedObject *) createManagedObjectInContext:(NSManagedObjectContext *)context withZone:(NSZone *)zone {
    
    return [self createManagedObjectWithName:NSStringFromClass([self class]) 
                                   inContext:context
                                    withZone:zone];
}

+ (NSManagedObject *) createManagedObjectWithName:(NSString *)name inContext:(NSManagedObjectContext *)context withZone:(NSZone *)zone {
    
    NSEntityDescription * entDesc = [NSEntityDescription entityForName:name
                                                inManagedObjectContext:context];
    
    NSManagedObject * obj = [[self allocWithZone:zone] initWithEntity:entDesc 
                                       insertIntoManagedObjectContext:context];
    
    return [obj autorelease];
}

- (NSManagedObject *)loadIntoMOC:(NSManagedObjectContext *)moc {
    
    return [moc objectWithID:[self objectID]];
}

@end
