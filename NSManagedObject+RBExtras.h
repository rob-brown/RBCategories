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


@interface NSManagedObject (RBExtras)

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
