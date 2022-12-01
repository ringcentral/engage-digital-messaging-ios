//  Copyright (c) 2014 Dimelo. All rights reserved.

#import <UIKit/UIKit.h>
#import "DMXTextViewPlaceholder.h"

// This is a private declaration only to assist linking with DimeloChatInputAccessoryView.xib outlets.
__attribute__((visibility("default"))) @interface DimeloChatInputAccessoryView : UIView<UITextViewDelegate>
@property (nonatomic) IBOutlet UIButton *sendVideoCallRequestButton;
@property (nonatomic) IBOutlet UIButton *attachmentButton;
@property (nonatomic) IBOutlet DMXTextViewPlaceholder *textView;
@property (nonatomic) IBOutlet UIButton *sendButton;
@property (nonatomic) IBOutlet UIImageView *attachmentImageView;
@property (nonatomic) IBOutlet UIToolbar *toolbar;
@property (nonatomic) UITabBar *tabBar;
@property (weak, nonatomic) IBOutlet UIView *mainView;
- (IBAction)send:(id)sender;
- (IBAction)addAttachment:(id)sender;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *rightConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *bottomConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *leftConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *textViewHeightConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *attachmentButtonWidthConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *attachmentButtonRightConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *sendVideoCallRequestButtonWidthConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *attachmentButtonTextViewMarginConstraint;
@property (nonatomic) CGFloat keyboardHeight;
- (void)updateChatInputAccessoryViewFrame;
- (BOOL)updateFittingSize;
- (BOOL)validMessage;
@end
