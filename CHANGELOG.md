## Dimelo iOS SDK master ##

## Dimelo iOS SDK 2.1.0 (October 7th, 2020) ##
- BREAKING CHANGE: remove disruptive `UNNotificationCenter` callbacks and replace them by helper methods to handle Engage Digital Messaging notifications
- Improvement: move Push Notifications related documentation to `Notifications.md` and add guidance on how to integrate new notification helper methods

## Dimelo iOS SDK 2.0.0 (July 21th, 2020) ##
- Feature: tapping the error icon alongside a message now allows to retry the message sending request
- Feature: support the structured messages (quick reply, template, carousel and rich link):
    - Add multiple customization keys ([listed in PlistCustomization.md](PlistCustomization.md))
    - The input accessory view is hidden when a quick reply disabling it is sent
    - Support gif and deeplinks in structured messages
- Feature: new design:
    - Support agent avatar (`showAgentAvatarImage = YES | NO` defaults to `YES`)
    - Support messages grouping (text, image, location, attachment, structured)
    - Add `hourTimeFont` and `hourTimeTextColor` keys to customize the hour part of the date
    - Add `agentTimeFont` and `agentTimeColor` keys to customize the time next to the agent name
    - Replace the send button by an icon. Use the existing `sendTintColor` (when active) and `disabledSendButtonColor` keys to customize the send icon
    - Add `rcHintInputText` key to customize the hint text in the input accessory view
    - Add `rcToday` localization key for the date
    - Automatically apply system date and time to the chat date and time
    - Welcome message is now displayed in the middle of the screen
    - Make the default colors compatible with the dark mode

## Dimelo iOS SDK 1.9.5 (May 13th, 2020) ##
- Fix: dismiss share action sheet when the chat disappear
- Feature: add `agentAttachmentTitleInsets` to customize insets for file name and size label inside the agent cell
- Fix: apply an ellipsis to attachments filename to fit them in the screen
- Improvement: add space in bottom safe area on compatible devices
- Improvement: use `WKWebView` instead of `UIWebView` in `AttachmentViewController` on device running on iOS 8+
- Fix: race condition when rotating the screen was breaking the attachment layout in `AttachmentViewController`

## Dimelo iOS SDK 1.9.4 (January 20th, 2020) ##
- Fix: the SDK now takes the application's current notification categories into account when adding its own notification category
- Fix: text input is not resized well when rotating device during attachment prompt
- Fix: force the display of the location, gallery and camera view in full screen mode on iOS13+ devices to avoid bug where input accessory view is not displayed anymore after opening one of these views
- Feature: allow to initialize the `Dimelo` instance using a hostname:
*  add `initializeWithApiKeyAndHostName: apiKey hostName: hostName delegate: delegate`  method to configure Dimelo with an api key and a hostname.
*  add `initializeWithApiSecretAndHostName: apiSecret hostName: hostName  delegate: delegate`  method to configure Dimelo with an api secret and a hostname.
- Feature: add [`enableLightStatusBarStyle`](https://github.com/ringcentral/engage-digital-messaging-ios/blob/master/PlistCustomization.md#enableLightStatusBarStyle) option to set the light status bar style
- Feature: add [`dimeloAttachmentSizeLabelMegaByteUnit`](https://github.com/ringcentral/engage-digital-messaging-ios/blob/master/Localization.md#dimeloAttachmentSizeLabelMegaByteUnit) and  [`dimeloAttachmentSizeLabelKiloByteUnit`](https://github.com/ringcentral/engage-digital-messaging-ios/blob/master/Localization.md#dimeloAttachmentSizeLabelKiloByteUnit) keys to customize the size unit of the attachment.
- Improvement: open gallery or camera view on the main thread
- Fix: add `initializeWithApiSecret: secret domainName: domainName delegate: delegate`  and `initializeWithApiKey: apiKey domainName: domainName delegate: delegate` to be used in swift call

## Dimelo iOS SDK 1.9.3 (October 7, 2019) ##
- Fix: Input text overlap on tab bar when using a UITabBarController
- Fix: Input text disappears when using a UITabBarController
- Fix: crash when opening Apple Maps when a location is tapped on iOS 13+ devices
- Fix: race condition when rotating the screen while scrolling was breaking the layout
- Feature: support foreground notification on iOS 10+ devices
- Feature: add text customization for notification direct reply [button](https://github.com/ringcentral/engage-digital-messaging-ios/blob/master/Localization.md#dimelonotificationdirectreplybuttontitle) and [placeholder](https://github.com/ringcentral/engage-digital-messaging-ios/blob/master/Localization.md#dimelonotificationdirectreplyinputtextplaceholder) on iOS 10+ devices
- Fix: prevent direct reply notification crash on iOS 8

## Dimelo iOS SDK 1.9.2 (June 18, 2019) ##
- Improvement: open Apple Maps when a location is tapped
- Fix: remove unused white space above messages in chat view
- Improvement: better support for iPhone X safe area in landscape mode

## Dimelo iOS SDK 1.9.1 (January 16, 2019) ##
- Improvement: better resizing of input text size according to the entered text
- Improvement: disable network calls to Dimelo mobile API when source is disabled
- Fix: compiler Warning: `umbrella header for module 'Dimelo' does not include header 'DimeloChatInputAccessoryView.h'` (#31)
- Fix: prevent sending empty body in send message request

## Dimelo iOS SDK 1.9.0 (November 2, 2018) ##
- BREAKING CHANGE: new mandatory domain name configuration (first part of your Dimelo Digital URL: **domain-name**.engagement.dimelo.com):
  * `setApiSecret: apiSecret` is now deprecated in favor of `initWithApiSecret: secret domainName: domainName delegate: delegate`.
  * `setApiKey: apiKey` is now deprecated in favor of `initWithApiKey: apiKey domainName: domainName delegate: delegate`.
  * `setHostname: hostName` is not available anymore.
- Feature: add `disableNotification` attribute to disable the notification permission prompt
- Feature: add local draft saving for unsent text messages
- Improvement: log a warning when an invalid key is used for installations or users extra values.

## Dimelo iOS SDK 1.8.0 (August 7, 2018) ##
- Fix: resize input text size according to the entered text.
- Enhancement: show notifiaction when using a wrong installation identifier.

## Dimelo iOS SDK 1.7.9 (June 6, 2018) ##
- Fix: rare crash when notification is clicked
- Feature: support the right to left alignment for text message.
- Feature: add navigationBarTitleFont and navigationBarItemTitleFont to customize the navigationBar and the navigationBar item titles fonts.

## Dimelo iOS SDK 1.7.8 (April 4, 2018) ##
- Fix: prevent multiple tap on attachements from opening multiple zoom views
- Fix: Text entry field disappears by clicking on the local notification.
- Improvement: disable sending empty message in dictation mode.
- Fix: fix bitcode error message when the ENABLE_BITCODE flag is enabled (#22)
- Fix: always ask the GPS, the camera and the photo gallery permissions when it is refused for the first time.
- Fix: center the GPS button on device running on iOS older than 11.

## Dimelo iOS SDK 1.7.7 (February 1, 2018) ##
- Improvement: update cocoapods to use Dimelo.framework.
- Fix: fix crash when using safeAreaInsets on device running on iOS older than 11.
- Fix: fix ui bug when the keyboard height decrease in talk mode.

## Dimelo iOS SDK 1.7.6 (November 7th, 2017) ##
- Fix: Support safe area for iPhone X when local notification is shown.
- Enhancement: When using server-side authentication parse JWT token and set user informations with its content
- Feature: Support any kind of attachment for agent only
- Feature: add onOpen and onClose callback
- Enhancement: Add the interactive push notification with direct reply
- Feature: Add new API to send a customer message
- Feature: Support French and German localizations with the possibility to customize them

## Dimelo iOS SDK 1.7.5 (August 29th, 2017) ##
- Fix: change CFBundleSupportedPlatforms key from iphonesimulators to iPhoneOS

## Dimelo iOS SDK 1.7.4 (August 17th, 2017) ##
- Fix: improve image quality
- Fix: missing binary for simulator architecture in Dimelo.framework

## Dimelo iOS SDK 1.7.3 (August 14th, 2017) ##
- Fix: internal sdk header version

## Dimelo iOS SDK 1.7.2 (August 14th, 2017) ##
- Fix: rare crash at first message receive on low memory device(#8)
- Fix: prevent some push notifications to be lost if the SDK is not properly initialized (no userIdentifier)

## Dimelo iOS SDK 1.7.1 (February 15th, 2017) ##
- Fix: now, only attachments (images and locations) are clickable, not the entire UICollectionViewCell content (before, clicking an empty space would open the attachment, which does not make sense).
- Fix: The view displaying the image attachment didn't keep the ratio of the image. This is now fixed.
- Enhancement: Better handling of server-side failures. In very particular case, the server might refuse the attachment the user tries to send and return a 400 error. Until now, the application would try to send the message undefinitely. Now, the application will only retry to send the message 3 times if the message is impacted by an error 400+. If all attemps are reached, the message will be marked as unsent (by opening a dialog window and displaying a warning icon next to the message) and the application will process the next messages. Offline messages are not concerned by this change.
- Fix: display of unsent images was broken. Now fixed.
- Better: rename Unsent label into "Waiting for connection". The previous one was confusing.

## Dimelo iOS SDK 1.7.0 (February 6th, 2017) ##
- Feature: GIF can now be displayed when clicking on the relevant attachment. GIF images have a small label that helps to easily which images are GIF and which are not.
- Fix display bug when applying trimming on a sent message
- Enhancement: Provide .framework for easier integration

## Dimelo iOS SDK 1.6.1 (January 25th, 2017) ##
- Fix: Fix consumeReceivedRemoteNotification sometimes returning NO while it should.

## Dimelo iOS SDK 1.6.0 (January 18th, 2017) ##
- Feature: Make attachments optional. It is now possible to disable the ability to send images and/or photos and/or location.
- Fix: Rollback the installationId fix of v1.5.1 and apply another one instead based on userIdentifier: notification that provides a different userIdentifier than the current one will be skipped.

## Dimelo iOS SDK 1.5.2 (December 19th, 2016) ##
- Fix: Patch blinking effect of the welcome message at application startup.

## Dimelo iOS SDK 1.5.1 (December 9th, 2016) ##
- Feature: Ability to set language (useful for welcome message feature for example)
- Fix: Check installationId when receiving a new notification. Only process notifications where the notificationId matches the current installationId.
- Fix: Solve an issue causing the background of the Dimelo Chat not to be displayed in a particular case.

## Dimelo iOS SDK 1.5.0 (November 24th, 2016) ##

- Feature: Add ability to define a welcome message which is displayed whenever the conversation is empty.
- Improvement: Better handling of Camera, Gallery and Location permissions (do not display the associated actions if the permissions are not provided).
- Improvement: Harmonize customization options with what is available for the Android SDK.

## Dimelo iOS SDK 1.4.0 (October 19, 2016) ##

- Feature: add the unreadCount feature to poll the number of unread messages
- Feature: add ability to customize the text color of the send button (on disabled state)

## Dimelo iOS SDK 1.3.1 (September 12, 2016) ##

- Fix: remove call to containsString (iOS 7 compatibility)
- Fix: remove location and share image titles (bring it on par with the Android SDK)

## Dimelo iOS SDK 1.3.0 (June 14, 2016) ##

- Feature: remove local cache file
- Better: No more incompatibility with existing versions of TTTAttributedLabel
- Better: documentation and code samples are now more clear
- Better: bitcode support
- Fix: Manually setting JWT token with {{dimelo.jwt=}} now sends the new info to the server for update

## Dimelo iOS SDK 1.2.5 (January 29, 2016) ##

- Fix: close keyboard when opening attachment dialog

## Dimelo iOS SDK 1.2.4 (June 26, 2015) ##

- Fix: image sent were gone after killing the app

## Dimelo iOS SDK 1.2.3 (April 1, 2015) ##

- Fix: update badge count if different from the unreadCount returned by the server

## Dimelo iOS SDK 1.2.2 (March 10, 2015) ##

- Fix: adding location as a first message was crashing the SDK
- Fix: multiple environment + offline messages created discrepency between
  chat view, connection status and messages to be sent.

## Dimelo iOS SDK 1.2.1 (March 4, 2015) ##

* Doc: better onboarding
* Fix: DimeloConfig.plist usage remain optional

## Dimelo iOS SDK 1.2.0 (February 26, 2015) ##

* Feature: geolocation attachment now takes radius into account
* Feature: geolocation can be manually selected via address
* Feature: Radius selected during geolocation is sent to the agent console
* Improvement: a image is now displayed during map calculation for nicer UX
* Doc: complete configuration plist is now included, empty configuration is not included
* Fix: scroll up to history is no longer automatically scrolled down every 15s

## Dimelo iOS SDK 1.1.0 (February 09, 2015) ##

* Improvement: iOS SDK now rely on plist for customization rather than raw APIs
* Feature: Real support for offline messages
* Feature: Geolocation can now be shared and read
* Fix: imagePicker properly supported under iOS8

## Dimelo iOS SDK 1.0.1 (November 26, 2014) ##

* Fix: developmentAPNS flag was not preserved across registration
* Fix: iOS8 APNs deviceToken was not requested again if app was requested in
a previous installation
