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

@interface UIView (RBExtras)

- (void)setWidth:(CGFloat)width;

- (void)setHeight:(CGFloat)height;

@end

/**
 * Category borrowed from Three20
 */
@interface UIView (TTCategory)

/**
 * Returns the view in the view hierarchy that is the first responder, if any. 
 * Otherwise, nil is returned. 
 *
 * @returns The first responder in the view hierarchy, if any.
 */
- (UIView *)findFirstResponder;

/**
 * Returns the first view in the superview hierarchy that is of the given class.
 *
 * @return The first view in the superview hierarchy that is of the given class.
 */
- (UIView *)ancestorOrSelfWithClass:(Class)cls;

@end

@interface UIView (Resize)

/**
 * Convenience method. Simply calls 
 * [self resizeLabel:theLabel shrinkViewIfLabelShrinks:YES].
 */
- (CGFloat) resizeLabel:(UILabel *)theLabel;

/**
 * Resizes the height of the given label so that its text can fit within its
 * bounds. It also resizes the parent view accordingly. Some calculations may
 * assume too much for all cases.
 */
- (CGFloat) resizeLabel:(UILabel *)theLabel shrinkViewIfLabelShrinks:(BOOL)canShrink;

@end
