//
//  NSManagedObject+Extras.h
//  StatCollector
//
//  Created by Robert Brown on 4/30/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSManagedObject (Extras)

/**
 * Creates an autoreleased instance of a managed object in the given MOC. This 
 * method is written to work properly with subclassing. 
 *
 * @param context The context to create the managed object in.
 */
+ (NSManagedObject *) createManagedObjectInContext:(NSManagedObjectContext *)context;

/**
 * This isn't normally called directly. You probably want to use 
 * createManagedObjectInContext: instead. One instance where you will want to
 * use this method is if you implement copyWithZone:.
 *
 * @param context The context to create the managed object in.
 * @param zone The zone to allocate the managed object in.
 */
+ (NSManagedObject *) createManagedObjectInContext:(NSManagedObjectContext *)context withZone:(NSZone *)zone;

/**
 * This isn't normally called directly. You probably want to use 
 * createManagedObjectInContext: instead. One instance where you may want to use
 * this method is when you want to create a managed object without subclassing.
 *
 * @param name The class name of the managed object to create.
 * @param context The context to create the managed object in.
 * @param zone The zone to allocate the managed object in.
 */
+ (NSManagedObject *) createManagedObjectWithName:(NSString *)name inContext:(NSManagedObjectContext *)context withZone:(NSZone *)zone;

/**
 * The managed object loads itself into the given context and returns the new 
 * managed object that exists in the given MOC. This can be overriden by 
 * subclasses to also load required relationships in the MOC too. 
 *
 * @todo It would be nice if this would automatically discover the required 
 * relationships and load them in the MOC.
 */
- (NSManagedObject *)loadIntoMOC:(NSManagedObjectContext *)moc;

@end
