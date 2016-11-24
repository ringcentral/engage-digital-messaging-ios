## Dimelo iOS SDK master ##

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
