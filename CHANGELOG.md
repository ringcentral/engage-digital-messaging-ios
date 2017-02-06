## Dimelo iOS SDK master ##

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
