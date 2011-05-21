//
//  NSManagedObject+Extras.m
//  StatCollector
//
//  Created by Robert Brown on 4/30/11.
//  Copyright 2011 Robert Brown. All rights reserved.
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
