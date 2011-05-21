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

#import "UIView+RBExtras.h"


@implementation UIView (RBExtras)

// Modified from Three20
- (UIView *)findFirstResponder {
    
    if ([self isFirstResponder])
        return self;
    
    for (UIView * subView in [self subviews]) {
        
        UIView * firstResponderCheck = [subView findFirstResponder];
        
        if (nil != firstResponderCheck)
            return firstResponderCheck;
    }
    
    // A first responder was not found.
    return nil;
}

// From Three20
- (UIView *)ancestorOrSelfWithClass:(Class)cls {
    
    if ([self isKindOfClass:cls])
        return self;
    else if ([self superview])
        return [[self superview] ancestorOrSelfWithClass:cls];
    
    return nil;
}

@end

// Entire category from http://blog.carbonfive.com/2009/07/10/resizing-uilabel-to-fit-text/
@implementation UIView (Resize)

- (CGFloat) resizeLabel:(UILabel *)theLabel {
    return [self resizeLabel:theLabel shrinkViewIfLabelShrinks:YES];
}

- (CGFloat) resizeLabel:(UILabel *)theLabel shrinkViewIfLabelShrinks:(BOOL)canShrink {
    
    CGRect frame = [theLabel frame];
    CGSize size = [theLabel.text sizeWithFont:theLabel.font
                            constrainedToSize:CGSizeMake(frame.size.width, CGFLOAT_MAX)
                                lineBreakMode:UILineBreakModeWordWrap];
    
    CGFloat delta = size.height - frame.size.height;
    frame.size.height = size.height;
    [theLabel setFrame:frame];
    
    CGRect contentFrame = self.frame;
    contentFrame.size.height = contentFrame.size.height + delta;
    
    if(canShrink || delta > 0)
        [self setFrame:contentFrame];
    
    return delta;
}

@end
