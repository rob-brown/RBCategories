//
// NSManagedObject+RBExtras.h
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
#import <CoreData/CoreData.h>

@interface NSManagedObject (RBExtras)

/**
 * Creates an autoreleased instance of a managed object in the given MOC. This 
 * method is written to work properly with subclassing. 
 *
 * @param context The context to create the managed object in.
 */
+ (id)createManagedObjectInContext:(NSManagedObjectContext *)context;

/**
 * This isn't normally called directly. You probably want to use 
 * createManagedObjectInContext: instead. One instance where you will want to
 * use this method is if you implement copyWithZone:.
 *
 * @param context The context to create the managed object in.
 * @param zone The zone to allocate the managed object in.
 */
+ (id)createManagedObjectInContext:(NSManagedObjectContext *)context withZone:(NSZone *)zone;

/**
 * This isn't normally called directly. You probably want to use 
 * createManagedObjectInContext: instead. One instance where you may want to use
 * this method is when you want to create a managed object without subclassing.
 *
 * @param name The class name of the managed object to create.
 * @param context The context to create the managed object in.
 * @param zone The zone to allocate the managed object in.
 */
+ (id)createManagedObjectWithName:(NSString *)name inContext:(NSManagedObjectContext *)context withZone:(NSZone *)zone;

/**
 * The managed object loads itself into the given context and returns the new 
 * managed object that exists in the given MOC. This can be overriden by 
 * subclasses to also load required relationships in the MOC too. NOTE: Make 
 * sure that the managed object in the original context has been saved. 
 * Otherwise, you won't see any unsaved changes with the returned object.
 *
 * @todo It would be nice if this would automatically discover the required 
 * relationships and load them in the MOC.
 */
- (id)loadIntoMOC:(NSManagedObjectContext *)moc;

/**
 * Given a set of NSManagedObjects, returns an array of their managed object IDs.
 *
 * @param set The set of NSManagedObjects to extract IDs from.
 *
 * @return An array of NSManagedObjectIDs.
 */
+ (NSArray *)managedObjectIDsFromSet:(NSSet *)set;

/**
 * Given a array of NSManagedObjects, returns an array of their managed object IDs.
 *
 * @param array The array of NSManagedObjects to extract IDs from.
 *
 * @return An array of NSManagedObjectIDs.
 */
+ (NSArray *)managedObjectIDsFromArray:(NSArray *)array;

/**
 * Convenience method for creating an NSEntityDescription for a given MOC. 
 *
 * @param context The MOC to use when creating the entity description.
 * 
 * @return An NSEntityDescription for the given MOC. 
 */
+ (NSEntityDescription *)entityForContext:(NSManagedObjectContext *)context;

/**
 * Convenience method for creating a basic fetch request with a given MOC. The 
 * fetch request may be further customized after calling this method.
 * 
 * @param context The MOC to use when creating the fetch request.
 *
 * @return A basic fetch request with the given MOC
 */
+ (NSFetchRequest *)fetchRequestForContext:(NSManagedObjectContext *)context;

@end
