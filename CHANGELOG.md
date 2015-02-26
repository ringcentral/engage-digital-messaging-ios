## Dimelo iOS SDK master ##

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
