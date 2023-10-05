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
   <img src="https://i.postimg.cc/qBmfxmXn/1.png"/>
</p>
<p align="center">
   <img src="https://i.postimg.cc/nrX3k1pY/2.png"/>
</p>

## Required Configuration

### domainName
Allows the SDK to send its requests to the right endpoint (e.g. if your Dimelo Digital url is `DIMELO_DOMAIN_NAME.engagement.dimelo.com`, then your `domainName` will be `DIMELO_DOMAIN_NAME`)

:warning: Will be ignored if `hostName` is set (see [hostName](#hostname))

### apiKey
Public API key that identifies all requests to Dimelo (used only for the
secure server-side authentication, see section "Setup with a server-side secret")

API Key is always represented in hex format, e.g. `ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70`.

### apiSecret
Secret API key, only embed in the app for client-side authentication, see section "Setup with a built-in secret").
This is not recommended to embed in .plist but rather to set it directly via a setter in the code of the application for better obfuscation.

API Key is always represented in hex format, e.g. `ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70`.


## Optional configuration

### hostName
Allows the SDK to send its requests to the right endpoint (e.g. if your Dimelo Digital url is `DIMELO_DOMAIN_NAME.engagement.dimelo.com`, then your `hostName` will be `DIMELO_DOMAIN_NAME.messaging.dimelo.com`)

:warning: Will take precedence on `domainName` (see [domainName](#domainname))

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

## date Format

### dateFormatter
Date format for the date label (should be a NSDateFormatter).

Programmatically: set Dimelo.dateFormatter property

Plist customization name: None

Note: This is an example on how to initialize `Customization.dateFormatter`:

Using Objective C:
```objectivec
NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
[dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm"];
dimelo.dateFormatter = dateFormatter;
```

Using Swift:

```swift
let dateFormatterGet = NSDateFormatter()
dateFormatterGet.dateFormat = "yyyy-MM-dd HH:mm"
dimelo.dateFormatter = dateFormatter
```
## Color

### webViewActivityIndicatorColor
Color applied to the activity indicator that is displayed in the webView when the page is loading.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/ZnzMVk7V/web-View-Activity-Indicator-Color.png"/>
</p>

### webViewCloseImageColor
Color applied to the webView "close" image.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/MG9NkMd2/web-View-Close-Image-Color.png"/>
</p>

### createNewThreadImageColor
Color for the create new thread image.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/2yH86cJk/create-New-Thread-Image-Color.png"/>
</p>

### videoCallRequestButtonColor
Color applied to the video call request button.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/FK76cgPW/video-Image.png"/>
</p>

### videoCallRequestButtonHighlightedColor
Color applied to the video call request button when highlighted.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/vmHfqbCD/video-Image-Highlighted-Color.png"/>
</p>

### webViewTitleTextColor
Color applied to the webView title.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/bwX6v401/web-View-Title-Text-Color.png"/>
</p>

### badgeTextColor
Text color for the badge label.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/1X5jL8g8/badge-Font.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/MZPPnKMY/badge-Font.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/3RbXxNS4/badge-Font.png"/>
</p>

### badgeBackgroundColor
Background color for the badge label.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/1X5jL8g8/badge-Font.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/MZPPnKMY/badge-Font.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/3RbXxNS4/badge-Font.png"/>
</p>

### threadsListSeparatorColor
Color for the threads list separator.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/5NFcBkCT/list-Threads-Separator-Color.png"/>
</p>

### lockedThreadImageTintColor
Tint color for the locked thread image in the threads list view.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/c1fmL0pX/closed-Thread-Image-Tint-Color.png"/>
</p>

### threadsListRefreshControlTintColor
Tint color for the threads list refresh control.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/8CLPZzr8/list-Threads-Refresh-Control-Tint-Color.png"/>
</p>

### createNewThreadBackgroundColor
Background color for the create new thread button.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/13pfjXD0/create-New-Thread-Image.png"/>
</p>

### createNewThreadTappedBackgroundColor
Background color for the tapped create new thread button.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/Jz31SFhy/create-New-Thread-Tapped-Background-Color.png"/>
</p>

### threadsListBackgroundColorSelection
Background color for the threads list item selection.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/t4wYrcS6/list-Threads-Background-Color-Selection.png"/>
</p>

### threadsListCompanyMessageBackgroundColor
Background color of the company message displayed in the threads list.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/C1R2163f/threads-List-Company-Message-Background-Color.png"/>
</p>

### threadsListCompanyMessageTitleTextColor
Text color applied to the title of the company message that is displayed in the threads list.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/DyTCkZwG/threads-List-Company-Message-Title-Text-Color.png"/>
</p>

### threadsListCompanyMessageSubtitleTextColor
Text color applied to the subtitle of the company message that is displayed in the threads list.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/SQ769GmX/threads-List-Company-Message-Subtitle-Text-Color.png"/>
</p>

### threadsListAgentNameTextColor
Text color for the threads list agent name.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/WzG1ffkN/list-Threads-Agent-Name-Font.png"/>
</p>

### threadsListMessageTextColor
Text color for the threads list message.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/447t1J2P/list-Threads-Message-Font.png"/>
</p>

### threadsListDateTextColor
Text color for the threads list date.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/8zBzb3Vt/list-Threads-Date-Font.png"/>
</p>

### attachmentActionSheetItemsTextColor
Text color for each attachment action sheet item button.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/GmksQ8D3/attachment-Action-Sheet-Items-Text-Color.png"/>
</p>

### attachmentActionSheetCancelButtonTextColor
Text color for the attachment action sheet cancel button.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/TwZD0rtw/cancel-Attachment-Action-Sheet-Text-Color.png"/>
</p>


### attachmentActionSheetItemsIconColor
Color for each attachment action sheet item icon.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/nh7qPSyJ/attachment-Action-Sheet-Items-Icon-Color.png"/>
</p>

### fragmentHeaderColor
Color for the fragment header.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/s2T0dpW5/fragment-Header-Color.png"/>
</p>

### closedThreadMessageTextColor
Color applied to the message that is displayed when the thread is closed.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/s26X9dnv/close-Text-Color.png"/>
</p>

### videoCallRequestedStatusMessageTextColor
Color applied to the status message text when a video call is requested.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/TP8FXW2p/started-Video-Message-Text-Color.png"/>
</p>

### webViewHeaderBackgroundColor
Color applied to the webView header background.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/sfbFp69g/web-View-Header-Background-Color.png"/>
</p>

### webViewBodyBackgroundColor
Color applied to the webView body background and the safe area zone background (on portrait and landscape mode).

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/bNRTzdJf/web-View-Body-Background-Color.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/jSDB53T8/web-View-Body-Background-Color2.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/rsyPLQgN/web-View-Body-Background-Color3.png"/>
</p>

### enableLightStatusBarStyle
Text color for status bar text (white or black).

Must be a boolean, default is the black color.

`enableLightStatusBarStyle=true`:

<p align="center">
<img src="https://i.postimg.cc/pLwbt22Q/light.png"/>
</p>

`enableLightStatusBarStyle=false`:

<p align="center">
<img src="https://i.postimg.cc/gjHHPg4p/default.png"/>
</p>

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
   <img src="https://i.postimg.cc/LX1QJzVJ/agent-Name-Color.png"/>
</p>

### agentTimeColor
Time color for agent's name.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/przP2h7v/agent-Time-Color.png"/>
</p>

### agentTemplateBorderColor
Border color for agent structured message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/jSWVR0hm/agent-Template-Border-Color.png"/>
</p>

### agentTemplateWithImageBodyBackgroundColor
Background color for template agent structured message.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/Y0g5Q1v7/agent-Template-With-Image-Body-Background-Color.png"/>
</p>

### agentStructuredMessageBodyBackgroundColor
Background color for body agent structured message view.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/76THQJ5s/agent-Structured-Message-Body-Background-Color.png"/>
</p>

### agentMessageBackgroundColor
Background color for agent message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/q7WfzB2v/agent-Message-Background-Color.png"/>
</p>

### agentMessageTextColor
Foreground color for agent's message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/qMJFB6WG/agent-Message-Text-Color.png"/>
</p>

### welcomeMessageTextColor
Text color for the welcome message.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/GhyY0f7h/welcome-message-text-color.png"/>
</p>

### agentStructuredMessageUrlMarginTop
Margin top for structured message url label.

<p align="center">
   <img src="https://i.postimg.cc/zfvTtNTt/agent-Structured-Message-Url-Margin-Top.png"/>
</p>

### agentStructuredMessageSubtitleMarginTop
Margin top for structured message subtitle label.

<p align="center">
   <img src="https://i.postimg.cc/CKx9cRv3/agent-Structured-Message-Subtitle-Margin-Top.png"/>
</p>

### agentStructuredMessageTitleColor
Foreground color for agent's structured message title text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/bJcngtgg/agent-Structured-Message-Title-Color.png"/>
</p>

### agentStructuredMessageSubtitleColor
Foreground color for agent's structured message subtitle text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/cLzksF1J/agent-Structured-Message-Subtitle-Color.png"/>
</p>

### agentStructuredMessageUrlColor
Foreground color for agent's structured message url text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/44rSkLdN/agent-Structured-Message-Url-Color.png"/>
</p>

### agentStructuredMessageItemColor
Foreground color for agent's structured message item text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/N0bN4bR7/agent-Structured-Message-Item-Color.png"/>
</p>

### agentStructuredMessageItemTappedColor
Foreground color for agent's structured message tapped item text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/N0bN4bR7/agent-Structured-Message-Item-Color.png"/>
</p>

### agentStructuredMessageItemBackgroundColor
Background color for agent's structured message item text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/YCsHFNR4/agent-Structured-Message-Item-Background-Color.png"/>
</p>

### agentStructuredMessageItemTappedBackgroundColor
Background color for agent's structured message tapped item.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/YCsHFNR4/agent-Structured-Message-Item-Background-Color.png"/>
</p>

### quickRepliesBorderWidth
Border width for quick replies.

<p align="center">
   <img src="https://i.postimg.cc/sgD5gLVR/quick-Replies-Border-Width.png"/>
</p>

### quickRepliesHorizontalSpacing
Horizontal spacing for quick replies.

<p align="center">
   <img src="https://i.postimg.cc/P529C0Yb/quick-Replies-Horizontal-Spacing.png"/>
</p>

### quickRepliesVerticalSpacing
Vertical spacing for quick replies.

<p align="center">
   <img src="https://i.postimg.cc/mDRHKppq/quick-Replies-Vertical-Spacing.png"/>
</p>

### quickRepliesBorderColor
Border color for quick replies.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/RZcN7QXZ/quick-Replies-Border-Color.png"/>
</p>

### quickRepliesTappedBorderColor
 Border color for tapped quick replies.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### quickRepliesTextColor
Text color for quick replies.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/28jDcdk5/quick-Replies-Text-Color.png"/>
</p>

### quickRepliesTappedTextColor
Text color for tapped quick replies.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### quickRepliesBackgroundColor
Background color for quick replies.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/GhTQ1Vhg/quick-Replies-Background-Color.png"/>
</p>

### quickRepliesTappedBackgroundColor
Background color for tapped quick replies.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### dateTextColor
Text color for the date label.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/RhvYMyPq/date-text-color.png"/>
</p>

### hourTimeTextColor
Text color for the hour label.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/pTRC88K6/hour-text-color.png"/>
</p>

### disabledSendButtonColor
Tint color of the send button image on disabled state

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/D0ffvyqY/disabled-Send-Button-Color.png"/>
</p>

### errorIconColor
Color of the error icon which is displayed when the message could not be sent and no other retry will be operated.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/L6JzVHPp/error-icon.png"/>
</p>

### inputBarBackgroundColor
Background color of the input bar.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/9M8g3RtG/input-Bar-Background-Color.png"/>
</p>

### inputBarTintColor
Bar tint color of the input bar.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
   <img src="https://i.postimg.cc/RCK6RXCg/input-Bar-Tint-Color.png"/>
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
Bar tint color for navigation bar before iOS 13 otherwise it's the background color for navigation bar (sets `navigationBarTintColor` property).

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
<img src="https://i.postimg.cc/VkBy6Tcb/cursor.png"/>
</p>

### sendTintColor
Tint color for Send Button image.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
<img src="https://i.postimg.cc/xjFVJRYd/send-Button.png"/>
</p>

### navigationBarItemTintColor
Tint color for Navigation Item Button embedded in a fragment or a view controller.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
<img src="https://s26.postimg.cc/a1c23d4ih/done_Button.png"/>
</p>

### userMessageBackgroundColor
Background color for user message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

Similar to `systemMessageBackgroundColor`, but for system messages.

### userDeletedMessageBackgroundColor
Background color for deleted user message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### userSelectedMessageBackgroundColor
Background color for selected user message cell for iOS12 and lower.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

<p align="center">
<img src="https://i.postimg.cc/MGBqLxrQ/user-Deleted-Message-Selected-Background-Color.png"/>
</p>

### userMessageTextColor
Foreground color for user's message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

Similar to `systemMessageTextColor`, but for system messages.

### userDeletedMessageTextColor
Foreground color for user's deleted message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

## Font

### webViewTitleFont
Font applied to the webView title.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/Y9cgNw9x/web-View-Title-Font.png"/>
</p>

### userDeletedMessageFont
Font applied to the user deleted message text.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/9MnLF6h6/user-Deleted-Message-Font.png"/>
</p>

### badgeFont
Font for the badge label.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/1X5jL8g8/badge-Font.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/MZPPnKMY/badge-Font.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/3RbXxNS4/badge-Font.png"/>
</p>

### backToAllChatsFont
Font for the backToAllChats label (in the header fragment).
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/gJMwH78f/rc-Back-To-All-Chats.png"/>
</p>

### threadsListCompanyMessageTitleFont
Font used for the company message title that is displayed in the threads list.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/zvJR79qy/threads-List-Company-Message-Title-Font.png"/>
</p>

### threadsListCompanyMessageSubtitleFont
Font used for the company message subtitle that is displayed in the threads list.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/76N55mSw/threads-List-Company-Message-Subtitle-Font.png"/>
</p>

### threadsListAgentNameFont
Font for the threads list agent name.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/WzG1ffkN/list-Threads-Agent-Name-Font.png"/>
</p>

### threadsListMessageFont
Font for the threads list message.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/447t1J2P/list-Threads-Message-Font.png"/>
</p>

### threadsListDateFont
Font for the threads list date.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/8zBzb3Vt/list-Threads-Date-Font.png"/>
</p>

### closedThreadMessageTextFont
Font applied to the message that is displayed when the thread is closed.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/C5fVq9tT/close-Font.png"/>
</p>

### videoCallRequestedStatusMessageTextFont
Font applied to the status message when a video call is requested.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/2S3LfV9R/started-Video-Message-Text-Font.png"/>
</p>

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
   <img src="https://i.postimg.cc/W1jH3WzC/agent-Name-Font.png"/>
</p>

### showAgentAvatarImage
Show or hide the agent avatar image.

Must be a boolean, default is `true`.

`showAgentAvatarImage=true`:

<p align="center">
<img src="https://i.postimg.cc/s2F4YkfW/1.png"/>
</p>

`showAgentAvatarImage=false`:

<p align="center">
<img src="https://i.postimg.cc/NMD8wL68/2.png"/>
</p>

### agentTimeFont
Font for agent's time.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/q7yVQHsH/3.png"/>
</p>

### agentStructuredMessageTitleFont
Font for agent's structured message title.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/bv6jQ7h9/agent-Structured-Message-Title-Font.png"/>
</p>

### agentStructuredMessageSubTitleFont
Font for agent's structured message subtitle.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/rwKHBDXx/agent-Structured-Message-Sub-Title-Font.png"/>
</p>

### agentStructuredMessageUrlFont
Font for agent's structured message url.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/bwynrnNS/agent-Structured-Message-Url-Font.png"/>
</p>

### agentStructuredMessageItemFont
Font for agent's structured message item.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/VNP3Xzpt/agent-Structured-Message-Item-Font.png"/>
</p>

### dateFont
Font for the date label.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/HkNFQSLP/date-font.png"/>
</p>

### hourTimeFont
Font for the hour label.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/dt4b0QcF/hour-font.png"/>
</p>

### defaultFont
Default font used for all other items listed in that category,

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/FzyxXvyR/default-Font.png"/>
</p>

### messageFieldFont
Font for message input field.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/LXzPnTnQ/message-Field-Font.png"/>
</p>

### messageFont
Font for user and agent messages.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

<p align="center">
   <img src="https://i.postimg.cc/BZm6Nk9c/message-Font.png"/>
</p>

### systemMessageFont
Font for system messages.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

Similar to `messageFont`, but for system messages.

## Insets

### agentAttachmentTitleInsets
Insets for file name and size label (inside the agent message bubble).

<p align="center">
   <img src="https://i.postimg.cc/Gt8ZF4nf/agent-Attachment-Title-Insets.png"/>
</p>

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

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

### agentStructuredMessageBodyInsets
Insets for agent structured message bubbles.

<p align="center">
   <img src="https://i.postimg.cc/XvmSXw3V/agent-Structured-Message-Body-Insets.png"/>
</p>

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=40`, `left=40`, `bottom=40` and `right=40`.

### agentStructuredMessageItemInsets
Insets for agent structured message item.

<p align="center">
   <img src="https://i.postimg.cc/fTLG72Lw/agent-Structured-Message-Item-Insets.png"/>
</p>

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=40`, `left=40`, `bottom=40` and `right=40`.

### quickRepliesInsets
Insets for quick replies.

<p align="center">
   <img src="https://i.postimg.cc/PqwydZqs/quick-Replies-Insets.png"/>
</p>

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=40`, `left=40`, `bottom=40` and `right=40`.

### quickRepliesPaddingInsets
Insets for quick replies item.

<p align="center">
   <img src="https://i.postimg.cc/qRdqDmMF/quick-Replies-Padding-Insets.png"/>
</p>

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=40`, `left=40`, `bottom=40` and `right=40`.

### agentNameInsets
Insets for agent name text.

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

<p align="center">
   <img src="https://i.postimg.cc/9FSygr5p/agent-Name-Insets.png"/>
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
   <img src="https://i.postimg.cc/d1khy9Dc/user-Attachment-Bubble-Insets.png"/>
</p>

In the screenshot, top=60, right=40, bottom=20, left=0.

### userMessageBubbleInsets
Insets for user message bubbles (containing text).

Must contain a dictionary with `top`, `left`, `bottom` and `right`.
The values will be used as arguments to `UIEdgeInsetsMake(top, left, bottom, right)`.
E.g. `top=10`, `left=10`, `bottom=10` and `right=10`.

<p align="center">
   <img src="https://i.postimg.cc/sgj1cz1c/user-Message-Bubble-Insets.png"/>
</p>

In the screenshot, top=60, right=40, bottom=20, left=0.

## Images

### attachmentActionSheetCameraIcon
UIImage for the attachment action sheet camera icon.

<p align="center">
   <img src="https://i.postimg.cc/KcQtmrfb/camera-Attachment-Action-Sheet-Icon.png"/>
</p>

### attachmentActionSheetGalleryIcon
UIImage for the attachment action sheet gallery icon.

<p align="center">
   <img src="https://i.postimg.cc/mD9R8wrH/gallery-Attachment-Action-Sheet-Icon.png"/>
</p>

### attachmentActionSheetDocumentIcon
UIImage for the attachment action sheet document icon.

<p align="center">
   <img src="https://i.postimg.cc/PxQVXp37/document-Attachment-Action-Sheet-Icon.png"/>
</p>

### attachmentActionSheetLocationIcon
UIImage for the attachment action sheet location icon.

<p align="center">
   <img src="https://i.postimg.cc/X7RfPNxB/location-Attachment-Action-Sheet-Icon.png"/>
</p>

### webViewCloseImage
UIImage used to represent the webView "close" button that is displayed in the header.

<p align="center">
   <img src="https://i.postimg.cc/tC1qbnDY/web-View-Close-Image.png"/>
</p>

### createNewThreadImage
UIImage for the create new thread button.

<p align="center">
   <img src="https://i.postimg.cc/13pfjXD0/create-New-Thread-Image.png"/>
</p>

### backToAllChatsItemImage
UIImage for the create new thread button.

<p align="center">
   <img src="https://i.postimg.cc/jj3mxtJM/back-To-All-Chats-Item-Image.png"/>
</p>

<p align="center">
   <img src="https://i.postimg.cc/KjBHDTpW/back-To-All-Chats-Item-Image.png"/>
</p>

### videoCallRequestButtonImage
UIImage used to represent the button to request a video call.

<p align="center">
   <img src="https://i.postimg.cc/FK76cgPW/video-Image.png"/>
</p>

### lockedThreadImage
UIImage to indicate that the thread is locked in the threads list view.

<p align="center">
   <img src="https://i.postimg.cc/WpZ9qMkm/closed-Thread-Image.png"/>
</p>

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
   <img src="https://i.postimg.cc/8PPVXzBj/attachment-Icon.png"/>
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
   <img src="https://i.postimg.cc/XJ78Sm2c/user-Message-Bubble-Image.png"/>
</p>

In the screenshot, top=18, left=19, bottom=18, right=36.

## Boolean

### enableThreads
Flag to set to enable/disable threads.

Must be a boolean, default is `NO`.

### displayAttachmentActionSheetIcons
* Flag to set to display/hide attachment action sheet icons

Must be a boolean, default is `YES`.

### embeddedAsFragment
Flag to set to embed or not the Dimelo view as a fragment.

Must be a boolean, default is `NO`.
