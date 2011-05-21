//
//  UITableView+RBExtras.m
//  StatCollector
//
//  Created by Robert Brown on 5/6/11.
//  Copyright 2011 Robert Brown. All rights reserved.
//

#import "UITableView+RBExtras.h"
#import "UIWindow+RBExtras.h"
#import "UIView+RBExtras.h"


@implementation UITableView (RBExtras)

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

- (void)deselectSelectedRowAnimated:(BOOL)animated {
    
    [self deselectRowAtIndexPath:[self indexPathForSelectedRow]
                        animated:animated];
}

@end
