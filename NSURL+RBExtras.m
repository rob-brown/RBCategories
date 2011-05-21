//
//  NSURL+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/19/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import "NSURL+RBExtras.h"


@implementation NSURL (RBExtras)

- (BOOL) isEqualToURL:(NSURL *)otherURL {
	return [[self absoluteURL] isEqual:[otherURL absoluteURL]] ||
            [self isFileURL] && [otherURL isFileURL] &&
             ([[self path] isEqual:[otherURL path]]);
}

@end
