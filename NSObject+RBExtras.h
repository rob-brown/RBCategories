//
// NSObject+RBExtras.h
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

@interface NSObject (RBExtras)

/**
 * Converts this object into a dictionary. The default implementation should do 
 * the right thing. It uses the dynamic runtime to get all of the properties and 
 * their names. This method may be overriden if something different is needed. 
 */
- (NSDictionary *)asDictionary;

/**
 * Given the name of a property, returns the key that will be used to store it 
 * in the dictionary created by -asDictionary. By default just returns propName. 
 * Override this to provide custom keys. This is useful when your data model 
 names don't match with the names for a REST request, for example.
 *
 * @param propName The name of the property to get the key for.
 *
 * @return The key associated with the property name.
 */
- (NSString *)keyForPropertyWithName:(NSString *)propName;

/**
 * The inverse of -keyForPropertyWithName:. If you modify 
 * -keyForPropertyWithName:, then you must make the same changed (inversed) in 
 * this method.
 *
 * @param key The key to get a property name for.
 *
 * @return The property name associated with the given key.
 */
- (NSString *)propertyNameForKey:(NSString *)key;

/**
 * Returns the root class.
 *
 * @return The root class.
 */
+ (Class)rootClass;

@end
