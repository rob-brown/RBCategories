//
// NSObject+RBExtras.m
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

#import <objc/runtime.h>

#import "NSObject+RBExtras.h"


@implementation NSObject (RBExtras)

- (NSDictionary *)asDictionary {
    
    // ???: Can I move this method to an NSObject category?
    
    NSAutoreleasePool * pool = [NSAutoreleasePool new];
    NSMutableDictionary * dictionary = [[NSMutableDictionary dictionary] retain];
    
    // Uses the dynamic runtime to discover the internal properties and generate a dictionary. 
    unsigned int propertyCount;
    objc_property_t * properties = class_copyPropertyList([self class], &propertyCount);
    
    for (int i = 0; i < propertyCount; i++) {
        
        const char * cName = property_getName(properties[i]);
        NSString * propertyName = [NSString stringWithFormat:@"%s", cName];
        NSString * propertyKey = [self keyForPropertyWithName:propertyName];
        
        id value = [self valueForKey:propertyName];
        
        // A dictionary can't hold nil values. 
        if (!value) {
            value = [NSNull null];
            
            // !!!: I could also skip nil values by using a 'continue' here. 
        }
        // Sub-AOObjects also need to be converted to dictionaries. 
        else if ([value isKindOfClass:[NSObject class]]) {
            value = [value asDictionary];
        }
        // If the value is an array, it needs to be traversed in case there are any AOObjects in it.
        else if ([value isKindOfClass:[NSArray class]]) {
            
            NSMutableArray * array = [NSMutableArray array];
            
            for (id obj in value) {
                
                if ([obj isKindOfClass:[NSObject class]])
                    obj = [obj asDictionary];
                
                [array addObject:obj];
            }
        }
        // If the value is a set, it needs to be traversed in case there are any AOObjects in it.
        else if ([value isKindOfClass:[NSArray class]]) {
            
            NSMutableSet * set = [NSMutableSet set];
            
            for (id obj in value) {
                
                if ([obj isKindOfClass:[NSObject class]])
                    obj = [obj asDictionary];
                
                [set addObject:obj];
            }
        }
        
        // ???: Do I need to traverse dictionaries too?
        
        [dictionary setValue:value
                      forKey:propertyKey];
    }
    
    free(properties);
    [pool release];
    
    return [dictionary autorelease];
}

- (id)createFromDictionary:(NSDictionary *)dict {
    
    // TODO: Finish.
    
    return nil;
}

- (NSString *)keyForPropertyWithName:(NSString *)propName {
    
    // TODO: It would be nice if this detected that no such property exists with the given name. 
    
    return propName;
}

- (NSString *)propertyNameForKey:(NSString *)key {
    return key;
}


#pragma mark - Dynamic Runtime methods

+ (Class)rootClass {
    
    Class rootClass = nil;
    Class currentClass = [self class];
    
    while ((currentClass = class_getSuperclass(currentClass)))
        rootClass = currentClass;
    
    return rootClass;
}

@end
