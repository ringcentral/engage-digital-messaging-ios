Dimelo Plist configuration
==========================

All keys are optional.

[Download example plist](
://raw.githubusercontent.com/dimelo/Dimelo-iOS/master/Dimelo/DimeloConfig.plist?token=AAAerlawQARBQ6TV9UhaL6FzBKNpsC02ks5VAJLlwA%3D%3D).

## Screenshots default interface

Some screenshots will be used in that documentation to show the impact of the different configuration attributes.

The default interface without any customization is the following on iOS.

You can refer to this interface to understand how an option affect the interface.

<p align="center">
   <img src="http://s12.postimg.cc/5ysjzuiz1/default.png"/>
</p>

## Required Configuration

### domainName
This is a mandatory key (e.g. DIMELO_DOMAIN_NAME.engagement.dimelo.com)

### apiKey
Public API key that identifies all requests to Dimelo (used only for the
secure server-side authentication, see section "Setup with a server-side secret")

API Key is always represented in hex format, e.g. `ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70`.

### apiSecret
Secret API key, only embed in the app for client-side authentication, see section "Setup with a built-in secret").
This is not recommended to embed in .plist but rather to set it directly via a setter in the code of the application for better obfuscation.

API Key is always represented in hex format, e.g. `ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70`.


## Optionnal configuration

### language
Language pList field allows you to override the system current language and define what locale should be sent to the Dimelo Server (and thus, what language will be used for messages returned by the server).

language can be any value supported by the Accept-Language HTTP Header.

## Notification

### disableNotification
Used to disable notification permission prompt (default is enabled). Disabling this attribute will result in not receiving any notification

### interactiveNotification
Used to disable reception of the interactive push notification with direct reply (default is enabled)

<p align="center">
<img src="https://s1.postimg.cc/63hyips04f/push.png"/>
</p>

## Color

### navigationBarTitleColor
Text color for the chat title.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
<img src="https://s26.postimg.cc/c96y4xw9l/title_Color.png"/>
</p>

### agentNameColor
Text color for agent's name.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/vmonmj9u5/agent_Name_Color.png"/>
</p>

### agentMessageBackgroundColor
Background color for agent message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/qy8nrcknh/agent_Message_Background_Color.png"/>
</p>

### agentMessageTextColor
Foreground color for agent's message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/p7pmpv34d/agent_Message_Text_Color.png"/>
</p>

### dateTextColor
Text color for the date label.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/dq99yen4d/date_Text_Color.png"/>
</p>

### disabledSendButtonColor
Text color of the send button on disabled state

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/ig3t0r3il/disabled_Send_Button_Color.png"/>
</p>

### errorIconColor
Color of the error icon which is displayed when the message could not be sent and no other retry will be operated.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://s1.postimg.cc/eeh1b82lr/Capture_d_e_cran_2017_02_15_a_14_59_22.png"/>
</p>

### inputBarBackgroundColor
Background color of the input bar.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/8k2q13xql/input_Bar_Background_Color.png"/>
</p>

### inputBarTintColor
Bar tint color of the input bar.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/lpi877rm5/input_Bar_Tint_Color.png"/>
</p>

### loadMoreMessagesButtonTextColor
Text color for the button "load more messages".

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/4dhvlry4t/load_More_Messages_Button_Text_Color.png"/>
</p>

The default display is the following:

<p align="center">
   <img src="http://s12.postimg.cc/mhkw6evt9/load_More_Messages_Button_Text_Colordefault.png"/>
</p>

### navigationBarColor
Background color for navigation bar (sets `backgroundColor` property).

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### navigationBarTintColor
Bar tint color for navigation bar (sets `barTintColor` property).

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.cc/5kvtdzo99/navigation_Bar_Tint_Color.png"/>
</p>

### systemMessageBackgroundColor
Background color for system message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

Similar to `systemMessageBackgroundColor`, but for system messages.

### systemMessageTextColor
Foreground color for system notification message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

Similar to `systemMessageTextColor`, but for system messages.

### tintColor
Tint color for aux controls: Close button, Send button, Share button, cursor etc.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://s26.postimg.cc/hd7uy1r15/share_Button.png"/>
</p>

### cursorTintColor
Tint color for cursor.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
<img src="https://s26.postimg.cc/ezuz45ixl/cursor.png"/>
</p>

### sendTintColor
Tint color for Send Button.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
<img src="https://s26.postimg.cc/5vwk3phcp/send_Button.png"/>
</p>

### navigationBarItemTintColor
Tint color for Navigation Item Button.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
<img src="https://s26.postimg.cc/a1c23d4ih/done_Button.png"/>
</p>

### userMessageBackgroundColor
Background color for user message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

Similar to `systemMessageBackgroundColor`, but for system messages.

### userMessageTextColor
Foreground color for user's message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

Similar to `systemMessageTextColor`, but for system messages.

## Font

### navigationBarTitleFont
Font for navigationBar's title.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://s31.postimg.cc/vsheyxoh7/navigation_bar_title_font.png"/>
</p>

### navigationBarItemTitleFont
Font for navigationBarItem's title.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://s31.postimg.cc/u0og47kln/navigation_bar_item_title_font.png"/>
</p>

### agentNameFont
Font for agent's name.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.cc/z7kj5redp/agent_Name_Font.png"/>
</p>

### dateFont
Font for the date label.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.cc/dozc4zlal/date_Font.png"/>
</p>

### defaultFont
Default font used for all other items listed in that category,

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.cc/6ctvzg32l/default_Font.png"/>
</p>

### messageFieldFont
Font for message input field.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.cc/cyb7cy8b1/message_Field_Font.png"/>
</p>

### messageFont
Font for user and agent messages.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.cc/694nwxmz1/message_Font.png"/>
</p>

### systemMessageFont
Font for system messages.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

Similar to `messageFont`, but for system messages.

## Insets

### agentAttachmentBubbleInsets
Insets for agent message bubbles (containing attachment).

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

Similar to `userAttachmentBubbleInsets`, but for agent messages.

### agentMessageBubbleInsets
Insets for agent message bubbles (containing text).

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

Similar to `userMessageBubbleInsets`, but for agent messages.

### agentNameInsets
Insets for agent name text.

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

<p align="center">
   <img src="http://s12.postimg.cc/q128ih959/agent_Name_Insets.png"/>
</p>

### systemMessageBubbleInsets
Insets for system message bubbles (containing text).

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

Similar to `userMessageBubbleInsets`, but for system messages.

### userAttachmentBubbleInsets
Insets for user message bubbles (containing attachment).

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

<p align="center">
   <img src="http://s12.postimg.cc/4ntziv24t/user_Attachment_Bubble_Insets.png"/>
</p>

In the screenshot, top=60, right=40, bottom=20, left=0.

### userMessageBubbleInsets
Insets for user message bubbles (containing text).

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

<p align="center">
   <img src="http://s12.postimg.cc/q01hgjm31/user_Message_Bubble_Insets.png"/>
</p>

In the screenshot, top=60, right=40, bottom=20, left=0.

## Images

### agentAttachmentBubbleImage
Resizable (9-part) image to mask agent's attachment (alpha channel is used as a mask).
By default, the same as `agentMessageBubbleImage`.

Must contain a dictionary with `top`, `left`, `bottom`, `right` and `imgName`.
The values will be used as arguments to `[[UIImage imgName] resizableImageWithCapInsets:UIEdgeInsetsMake(top, left, bottom, right) resizingMode:UIImageResizingModeStretch]`.
So, the `top`, `left`, `bottom` and `right` parameters will be used to define the stretchable area of your image.
E.g. `top=10`, `left=10`, `bottom=10`, `right=10`, and `imgName=myBubbleImage`

Similar to `userAttachmentBubbleImage`, but for agent messages.

### agentMessageBubbleImage
Resizable (9-part) image to decorate agent text bubble.

Must contain a dictionary with `top`, `left`, `bottom`, `right` and `imgName`.
The values will be used as arguments to `[[UIImage imgName] resizableImageWithCapInsets:UIEdgeInsetsMake(top, left, bottom, right) resizingMode:UIImageResizingModeStretch]`.
So, the `top`, `left`, `bottom` and `right` parameters will be used to define the stretchable area of your image.
E.g. `top=10`, `left=10`, `bottom=10`, `right=10`, and `imgName=myBubbleImage`

Similar to `userMessageBubbleImage`, but for agent messages.

### attachmentIcon
Icon to be displayed on "attach" button in the input bar.

Must contain a dictionary with `top`, `left`, `bottom`, `right` and `imgName`.
The values will be used as arguments to `[[UIImage imgName] resizableImageWithCapInsets:UIEdgeInsetsMake(top, left, bottom, right) resizingMode:UIImageResizingModeStretch]`.
So, the `top`, `left`, `bottom` and `right` parameters will be used to define the stretchable area of your image.
E.g. `top=10`, `left=10`, `bottom=10`, `right=10`, and `imgName=myAttachmentIcon`

<p align="center">
   <img src="http://s12.postimg.cc/ru556subx/attachment_Icon.png"/>
</p>

### systemMessageBubbleImage
Resizable (9-part) image to decorate system text bubble.

Must contain a dictionary with `top`, `left`, `bottom`, `right` and `imgName`.
The values will be used as arguments to `[[UIImage imgName] resizableImageWithCapInsets:UIEdgeInsetsMake(top, left, bottom, right) resizingMode:UIImageResizingModeStretch]`.
So, the `top`, `left`, `bottom` and `right` parameters will be used to define the stretchable area of your image.
E.g. `top=10`, `left=10`, `bottom=10`, `right=10`, and `imgName=myBubbleImage`

Similar to `userMessageBubbleImage`, but for system messages.

### userAttachmentBubbleImage
Resizable (9-part) image to mask user's attachment (alpha channel is used as a mask).
By default, the same as `userMessageBubbleImage`.

Must contain a dictionary with `top`, `left`, `bottom`, `right` and `imgName`.
The values will be used as arguments to `[[UIImage imgName] resizableImageWithCapInsets:UIEdgeInsetsMake(top, left, bottom, right) resizingMode:UIImageResizingModeStretch]`.
So, the `top`, `left`, `bottom` and `right` parameters will be used to define the stretchable area of your image.
E.g. `top=10`, `left=10`, `bottom=10`, `right=10`, and `imgName=myBubbleImage`

<p align="center">
   <img src="http://s12.postimg.cc/4zbfvmikt/user_Attachment_Bubble_Image.png"/>
</p>

In the screenshot, top=18, left=19, bottom=18, right=36.

### userMessageBubbleImage
Resizable (9-part) image to decorate user text bubble.

Must contain a dictionary with `top`, `left`, `bottom`, `right` and `imgName`.
The values will be used as arguments to `[[UIImage imgName] resizableImageWithCapInsets:UIEdgeInsetsMake(top, left, bottom, right) resizingMode:UIImageResizingModeStretch]`.
So, the `top`, `left`, `bottom` and `right` parameters will be used to define the stretchable area of your image.
E.g. `top=10`, `left=10`, `bottom=10`, `right=10`, and `imgName=myBubbleImage`

<p align="center">
   <img src="http://s12.postimg.cc/iisa1bwjx/user_Message_Bubble_Image.png"/>
</p>

In the screenshot, top=18, left=19, bottom=18, right=36.
