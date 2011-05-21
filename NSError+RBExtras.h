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
