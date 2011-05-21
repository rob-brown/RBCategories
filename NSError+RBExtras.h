//
//  NSError+RBExtras.h
//  StatCollector
//
//  Created by Robert Brown on 5/10/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const RBErrorDomain;

// Error Codes
extern const NSInteger RBValidationError;

@interface NSError (RBExtras)

/**
 * Merges two validation errors into one error. The two input errors are not
 * modified.
 * 
 * @todo This method should be generalized better so that it works for all types
 * of errors.
 */
+ (NSError *)validationErrorFromOriginalError:(NSError *)originalError error:(NSError *)secondError;

@end
