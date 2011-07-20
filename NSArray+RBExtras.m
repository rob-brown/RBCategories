//
// NSArray+RBExtras.m
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

#import "NSArray+RBExtras.h"


@implementation NSArray (RBExtras)

- (id)firstObject {
    return [self count] > 0 ? [self objectAtIndex:0] : nil;
}

- (id)secondObject {
    return [self count] > 1 ? [self objectAtIndex:1] : nil;
}

- (id)thirdObject {
    return [self count] > 2 ? [self objectAtIndex:2] : nil;
}

- (id)fourthObject {
    return [self count] > 3 ? [self objectAtIndex:3] : nil;
}

- (id)fifthObject {
    return [self count] > 4 ? [self objectAtIndex:4] : nil;
}

- (NSArray *)extractValuesForKeyPath:(NSString *)keyPath {
    
    NSMutableArray * results = [NSMutableArray array];
    
    for (id obj in self) {
        
        id value = [obj valueForKeyPath:keyPath];
        
        if (!value) {
            [results addObject:[NSNull null]];
        }
        else {
            [results addObject:value];
        }
    }
    
    return results;
}

@end
