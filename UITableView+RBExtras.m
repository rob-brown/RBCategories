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

#import "UITableView+RBExtras.h"
#import "UIWindow+RBExtras.h"
#import "UIView+RBExtras.h"


@implementation UITableView (TTCategory)

// Modified from Three20
- (void)scrollToFirstRowAnimated:(BOOL)animated {
    
    NSInteger sectionCount = [self numberOfSections];
    
    if (sectionCount > 0) {
        
        for (NSInteger section = 0; section < sectionCount; section++) {
            
            NSInteger rowCount = [self numberOfRowsInSection:section];
            
            if (rowCount > 0) {
                NSIndexPath * indexPath = [NSIndexPath indexPathForRow:0 
                                                             inSection:section];
                [self scrollToRowAtIndexPath:indexPath
                            atScrollPosition:UITableViewScrollPositionTop 
                                    animated:animated];
                return;
            }
        }
    }
}

// Modified from Three20
- (void)scrollToLastRowAnimated:(BOOL)animated {
    
    NSInteger sectionCount = [self numberOfSections];
    
    if (sectionCount > 0) {
        
        for (NSInteger section = [self numberOfSections] - 1; section > 0; section--) {
            
            NSInteger rowCount = [self numberOfRowsInSection:section];
            
            if (rowCount > 0) {
                NSIndexPath * indexPath = [NSIndexPath indexPathForRow:rowCount - 1 
                                                             inSection:section];
                [self scrollToRowAtIndexPath:indexPath
                            atScrollPosition:UITableViewScrollPositionBottom 
                                    animated:animated];
                return;
            }
        }
    }
}

// From Three20
- (void)scrollFirstResponderIntoViewAnimated:(BOOL)animated {
    
    UIView * responder = [[self window] findFirstResponder];
    
    UITableViewCell * cell = (UITableViewCell *)[responder ancestorOrSelfWithClass:[UITableViewCell class]];
    
    if (cell) {
        
        NSIndexPath * indexPath = [self indexPathForCell:cell];
        
        if (indexPath) {
            [self scrollToRowAtIndexPath:indexPath atScrollPosition:UITableViewScrollPositionMiddle
                                animated:animated];
        }
    }
}

@end


@implementation UITableView (RBExtras)

- (void)deselectSelectedRowAnimated:(BOOL)animated {
    
    [self deselectRowAtIndexPath:[self indexPathForSelectedRow]
                        animated:animated];
}

@end
