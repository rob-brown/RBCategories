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
