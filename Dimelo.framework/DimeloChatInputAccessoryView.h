//  Copyright (c) 2014 Dimelo. All rights reserved.

#import <UIKit/UIKit.h>

// This is a private declaration only to assist linking with DimeloChatInputAccessoryView.xib outlets.
__attribute__((visibility("default"))) @interface DimeloChatInputAccessoryView : UIView<UITextViewDelegate>
@property(nonatomic) IBOutlet UIButton *attachmentButton;
@property(nonatomic) IBOutlet UITextView *textView;
@property(nonatomic) IBOutlet UIButton *sendButton;
@property(nonatomic) IBOutlet UIImageView *attachmentImageView;
@property(nonatomic) IBOutlet UIToolbar* toolbar;
- (IBAction) send:(id)sender;
- (IBAction) addAttachment:(id)sender;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *rightConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *bottomConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *leftConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *textViewHeightConstraint;
- (BOOL) updateFittingSize;
@end
