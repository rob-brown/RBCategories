//
//  NSURL+RBExtras.h
//  StatCollector
//
//  Created by Robert Brown on 5/19/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSURL (RBExtras)

/**
 * Equality comparator for NSURLs. Works as expected. isEqual: on the other hand
 * doesn't seem to make proper comparisons.
 */
- (BOOL) isEqualToURL:(NSURL *)otherURL;

@end
