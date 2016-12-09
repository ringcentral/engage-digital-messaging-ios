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
   <img src="http://s12.postimg.org/5ysjzuiz1/default.png"/>
</p>

## Required Configuration

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


## Localizable String

### title
Title of the conversation window. 

This will be used as an argument to NSLocalizedString.

<p align="center">
   <img src="http://s12.postimg.org/d3eymmfm5/title.png"/>
</p>

## Color

### agentNameColor
Text color for agent's name.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/vmonmj9u5/agent_Name_Color.png"/>
</p>

### agentMessageBackgroundColor
Background color for agent message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/qy8nrcknh/agent_Message_Background_Color.png"/>
</p>

### agentMessageTextColor
Foreground color for agent's message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/p7pmpv34d/agent_Message_Text_Color.png"/>
</p>

### dateTextColor
Text color for the date label.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/dq99yen4d/date_Text_Color.png"/>
</p>

### disabledSendButtonColor
Text color of the send button on disabled state

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/ig3t0r3il/disabled_Send_Button_Color.png"/>
</p>

### inputBarBackgroundColor
Background color of the input bar.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/8k2q13xql/input_Bar_Background_Color.png"/>
</p>

### inputBarTintColor
Bar tint color of the input bar.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/lpi877rm5/input_Bar_Tint_Color.png"/>
</p>

### loadMoreMessagesButtonTextColor
Text color for the button "load more messages".

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/4dhvlry4t/load_More_Messages_Button_Text_Color.png"/>
</p>

The default display is the following:

<p align="center">
   <img src="http://s12.postimg.org/mhkw6evt9/load_More_Messages_Button_Text_Colordefault.png"/>
</p>

### navigationBarColor
Background color for navigation bar (sets `backgroundColor` property).

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### navigationBarTintColor
Bar tint color for navigation bar (sets `barTintColor` property).

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/5kvtdzo99/navigation_Bar_Tint_Color.png"/>
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
Tint color for aux controls: Close button, Send button, cursor etc.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="http://s12.postimg.org/u2nx1vqtp/tint_Color.png"/>
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

### agentNameFont
Font for agent's name.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.org/z7kj5redp/agent_Name_Font.png"/>
</p>

### dateFont
Font for the date label.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.org/dozc4zlal/date_Font.png"/>
</p>

### defaultFont
Default font used for all other items listed in that category,

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.org/6ctvzg32l/default_Font.png"/>
</p>

### messageFieldFont
Font for message input field.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.org/cyb7cy8b1/message_Field_Font.png"/>
</p>

### messageFont
Font for user and agent messages.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="http://s12.postimg.org/694nwxmz1/message_Font.png"/>
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
   <img src="http://s12.postimg.org/q128ih959/agent_Name_Insets.png"/>
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
   <img src="http://s12.postimg.org/4ntziv24t/user_Attachment_Bubble_Insets.png"/>
</p>

In the screenshot, top=60, right=40, bottom=20, left=0.

### userMessageBubbleInsets
Insets for user message bubbles (containing text).

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

<p align="center">
   <img src="http://s12.postimg.org/q01hgjm31/user_Message_Bubble_Insets.png"/>
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
   <img src="http://s12.postimg.org/ru556subx/attachment_Icon.png"/>
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
   <img src="http://s12.postimg.org/4zbfvmikt/user_Attachment_Bubble_Image.png"/>
</p>

In the screenshot, top=18, left=19, bottom=18, right=36.

### userMessageBubbleImage
Resizable (9-part) image to decorate user text bubble.

Must contain a dictionary with `top`, `left`, `bottom`, `right` and `imgName`.
The values will be used as arguments to `[[UIImage imgName] resizableImageWithCapInsets:UIEdgeInsetsMake(top, left, bottom, right) resizingMode:UIImageResizingModeStretch]`.
So, the `top`, `left`, `bottom` and `right` parameters will be used to define the stretchable area of your image.
E.g. `top=10`, `left=10`, `bottom=10`, `right=10`, and `imgName=myBubbleImage`

<p align="center">
   <img src="http://s12.postimg.org/iisa1bwjx/user_Message_Bubble_Image.png"/>
</p>

In the screenshot, top=18, left=19, bottom=18, right=36.
