Engage Digital Messaging iOS
==========

Engage Digital provides a mobile messaging component that allows users of your app
to easily communicate  with your customer support agents. You can send text messages
and images, and receive push notifications and automatic server-provided replies.

The component integrates nicely in any iPhone or iPad app, allows presenting
the chat in tab, modal, popover or even customly designed containers and has
rich customization options to fit perfectly in your application.

Please refer to [Technical Website](http://mobile-messaging.dimelo.com) for other technical references.


API Reference
-------------

Please refer to [Engage Digital Messaging SDK iOS API Reference](https://rawcdn.githack.com/ringcentral/engage-digital-messaging-ios/64b957d54ad0d9a9da65e214f01524cae7977140/Reference/html/index.html) for advanced use. Alternatively, you may consult `Dimelo/Dimelo.h` file.

Supported Versions
------------------

The Engage Digital Messaging SDK is currently supporting **iOS 8.0 and above**.

Getting Started
---------------

Follow these three mandatory steps to integrate Engage Digital Messaging in your application:

1. [Install the Dimelo library either via CocoaPods or manually](#install-the-dimelo-library-either-via-cocoapods-or-manually).
2. [Choose your authentication method and initialize the SDK](#authentication-and-sdk-initialization).
3. [Display the Mobile Messaging in your application](#displaying-engage-digital-messaging-conversation-screen).
4. Set `dimelo.developmentAPNS` = `YES` in your development builds (the milage may vary depending on your build strategy (TestFlight, Fabric.io ...) to receive push notifications. Set it back to `NO` when using a distribution provisioning profil.

\
These are minimal steps to make the Mobile Messaging work in your app.
Read on how to customize the appearance and the behavior of the Mobile Messaging to perfectly fit in your app:
- [Customize the Mobile Messaging appearance](#customizing-engage-digital-messaging-sdk-appearance)
- [Add push notifications support](#push-notifications)
- [Add required permissions to activate map, photo, gallery and Camera](#required-permissions)
- [Add a Dimelo listener to react to SDK triggered events](#reacting-to-engage-digital-messaging-sdk-events)


You can see an example of Engage Digital Messaging implementation by downloading the [Sample App](https://github.com/ringcentral-tutorials/engage-digital-messaging-ios-demo).


Install the Dimelo library either via CocoaPods or manually
-----------------------------------------------------------

How To Install With CocoaPods
-----------------------------

1) Configure your project for CocoaPods (create a `Podfile` and a `xcworkspace`). Refer to [CocoaPods documentation](http://cocoapods.org) to learn how to do it.

2) Add "Dimelo-iOS" to your Podfile like so:

    pod 'Dimelo-iOS', :git => 'https://github.com/ringcentral/engage-digital-messaging-ios.git'

3) Run `pod install` to update your project.

4) Include header in your app delegate: `#include "Dimelo.h"`


How To Install Manually
-----------------------

1) Download contents from Github [Dimelo-iOS project](https://github.com/ringcentral/engage-digital-messaging-ios).

2) Drop the `Dimelo.xcframework` subfolder in your project.

3) Link your target with these frameworks:

 * Dimelo.xcframework
 * Accelerate.framework
 * MobileCoreServices.framework
 * SystemConfiguration.framework
 * CoreLocation.framework
 * MapKit.framework
 * AddressBookUI.framework

4) Include header in your app delegate: `#include "Dimelo.h"`

5) To support ***Bitcode*** when publishing to the App Store, create a ***Run Script*** after the ***Embed Frameworks*** and add this command : <br/>`bash "${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/Dimelo.framework/strip_frameworks.sh"`



Sample Code
-----------

The following code is a minimal configuration of Dimelo chat. It presents
the chat, handles push notifications and displays network activity in status bar.

DimeloConfig.plist

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>title</key>
    <string>Engage Digital Messaging Support</string>
</dict>
</plist>
```



AppDelegate.m

```
#import "AppDelegate.h"
#import "Dimelo.h"

@interface AppDelegate () <DimeloDelegate>
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    Dimelo* dimelo = [Dimelo sharedInstance];
    dimelo.delegate = self;

    //Authentify using build-in authentification
    NSString* secret = @"YOUR SECRET API KEY";
    NSString* domainName = @"YOUR DOMAIN NAME";

    [dimelo initWithApiSecret:secret domainName: domainName delegate: nil];

    // Authentify the user if you have an internal user_id otherwise this
    // is random
    dimelo.userIdentifier = @"application-user-id";
    dimelo.userName = @"John Doe";

    // Indicated in which environment your app is build
    // to receive APNs
    dimelo.developmentAPNS = NO;

    dispatch_async(dispatch_get_main_queue(), ^{

        [[Dimelo sharedInstance] displayChatView];

    });

    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    // Register the device token.
    [Dimelo sharedInstance].deviceToken = deviceToken;
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    if ([[Dimelo sharedInstance] consumeReceivedRemoteNotification:userInfo])
    {
        // Notification is consumed by Dimelo, do not do anything else with it.
        return;
    }

    // You app's handling of the notification.
    // ...
}


#pragma mark - Dimelo API callbacks


- (void) dimeloDisplayChatViewController:(Dimelo*)dimelo
{
    UIViewController* vc = [dimelo chatViewController];

    vc.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(closeChat:)];

    [self.window.rootViewController presentViewController:vc animated:YES completion:nil];
}

- (void) closeChat:(id)_
{
    [self.window.rootViewController dismissViewControllerAnimated:YES completion:nil];
}

- (void) dimeloDidBeginNetworkActivity:(Dimelo*)dimelo
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
    });
}

- (void) dimeloDidEndNetworkActivity:(Dimelo*)dimelo
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
    });
}


@end

```

Migration to Dimelo 1.8.1
-------------------------

Dimelo 1.8.1 uses a new mandatory domain name setting (first part of your Dimelo Digital URL: **domain-name**.engagement.dimelo.com), so these changes **must** be taken into consideration:
* `setApiSecret: apiSecret` is now deprecated in favor of `initWithApiSecret: secret domainName: domainName delegate: delegate` for objecive C call or `initializeWithApiSecret: secret domainName: domainName delegate: delegate` for Swift call.
* `setApiKey: apiKey` is now deprecated in favor of `initWithApiKey: apiKey domainName: domainName delegate: delegate` for Objective C call or `initializeWithApiKey: apiKey domainName: domainName delegate: delegate` for Swift call.
* `setHostname: hostName` is not available anymore.


Authentication and SDK initialization
-------------------------------------

With each HTTP request, Dimelo sends a JWT ([JSON Web Token](http://self-issued.info/docs/draft-ietf-oauth-json-web-token.html)).
This token contains user-specific info that you specify (`userIdentifier`, `userName` etc.) and a HMAC signature. User identifier allows Dimelo to identify author of messages from different in the agent's backend.
If user identifier is missing (`nil`), then an autogenerated unique installation identifier is used to identify the user (created automatically).

If your app rely on a uniq imutable technical identifier to identify user use `userIdentifier` to also identify them at the Agent interface level.

Use `userName` to provide to agent a human name for the user.

We support two kinds of authentication modes: with **built-in secret** and with a **server-side secret**.

#### 1. Setup with a built-in secret

This is a convenient mode for testing and secure enough when user identifiers are unpredictable.

Here's how to create the Dimelo instance and initialize it using a built-in secret:

- Using Objective-C:
```objectivec
Dimelo dimelo = [Dimelo sharedInstance];
[dimelo initWithApiSecret: SOURCE_API_SECRET domainName: DIMELO_DOMAIN_NAME delegate: DIMELO_LISTENER];
/*
  SOURCE_API_SECRET can be found in your source configuration
  DIMELO_DOMAIN_NAME is your Dimelo Digital domain name (e.g. if your Dimelo Digital url is "DIMELO_DOMAIN_NAME.engagement.dimelo.com", then your domainName will be "DIMELO_DOMAIN_NAME")
  DIMELO_LISTENER is an optionnal parameter that we will cover later in this document
*/
```

- Using Swift:
```swift
let dimelo: Dimelo = Dimelo.sharedInstance()
dimelo.initialize(withApiSecret: SOURCE_API_SECRET, domainName: DIMELO_DOMAIN_NAME, delegate: DIMELO_LISTENER)
/*
  SOURCE_API_SECRET can be found in your source configuration
  DIMELO_DOMAIN_NAME is your Dimelo Digital domain name (e.g. if your Dimelo Digital url is "DIMELO_DOMAIN_NAME.engagement.dimelo.com", then your domainName will be "DIMELO_DOMAIN_NAME")
  DIMELO_LISTENER is an optionnal parameter that we will cover later in this document
*/
```

*Note:* To support hostname configuration, here's how to create the Dimelo instance and initialize it using a built-in secret:

- Using Objective-C:
```objectivec
Dimelo dimelo = [Dimelo sharedInstance];
[dimelo initializeWithApiSecretAndHostName: SOURCE_API_SECRET hostName: DIMELO_HOST_NAME delegate: DIMELO_LISTENER];
/*
  SOURCE_API_SECRET can be found in your source configuration
  DIMELO_HOST_NAME is your hostname (e.g. if your Dimelo Digital url is "DIMELO_DOMAIN_NAME.engagement.dimelo.com", then your hostName will be "DIMELO_DOMAIN_NAME.messaging.dimelo.com")
  DIMELO_LISTENER is an optionnal parameter that we will cover later in this document
*/
```

- Using Swift:
```swift
let dimelo: Dimelo = Dimelo.sharedInstance()
dimelo.initialize(withApiSecretAndHostName: SOURCE_API_SECRET, hostName: DIMELO_HOST_NAME, delegate: DIMELO_LISTENER)
/*
  SOURCE_API_SECRET can be found in your source configuration
  DIMELO_HOST_NAME is your hostname (e.g. if your Dimelo Digital url is "DIMELO_DOMAIN_NAME.engagement.dimelo.com", then your hostName will be "DIMELO_DOMAIN_NAME.messaging.dimelo.com")
  DIMELO_LISTENER is an optionnal parameter that we will cover later in this document
*/
```

Then it will create and sign JWT automatically when needed (as if it was provided by the server).

You simply set necessary user-identifying information and JWT will be computed on the fly.
You do not need any cooperation with your server in this setup.

The security issue here is that built-in secret is rather easy to extract from the app's binary build.
Anyone could then sign JWTs with arbitrary user identifying info to access other users'
chats and impersonate them. To mitigate that risk make sure to use this mode
only during development, or ensure that user identifiers are not predictable (e.g. random UUIDs).

#### 2. Setup with a server-side secret (better security but more complicated)

This is a more secure mode. Engage Digital will provide you with two keys: a public API key and a secret key.
The public one will be used to configure `Dimelo` instance and identify your app.
The secret key will be stored on your server and used to sign JWT token on your server.

Here's how create the Dimelo instance and initialize it using a server-side secret:

- Using Objective-C:
```objectivec
Dimelo dimelo = [Dimelo sharedInstance];
[dimelo initWithApiKey: SOURCE_API_KEY domainName: DIMELO_DOMAIN_NAME delegate: DIMELO_LISTENER];
/*
  SOURCE_API_KEY can be found in your source configuration
  DIMELO_DOMAIN_NAME is your Dimelo Digital domain name (e.g. if your Dimelo Digital url is "DIMELO_DOMAIN_NAME.engagement.dimelo.com", then your domainName will be "DIMELO_DOMAIN_NAME")
  DIMELO_LISTENER is an optionnal parameter that we will cover later in this document
*/
```

- Using Swift:
```swift
let dimelo: Dimelo = Dimelo.sharedInstance()
dimelo.initialize(withApiKey: SOURCE_API_KEY, domainName: DIMELO_DOMAIN_NAME, delegate: DIMELO_LISTENER)
/*
  SOURCE_API_KEY can be found in your source configuration
  DIMELO_DOMAIN_NAME is your Dimelo Digital domain name (e.g. if your Dimelo Digital url is "DIMELO_DOMAIN_NAME.engagement.dimelo.com", then your domainName will be "DIMELO_DOMAIN_NAME")
  DIMELO_LISTENER is an optionnal parameter that we will cover later in this document
*/
```

*Note:* To support hostname configuration, here's how to create the Dimelo instance and initialize it using a server-side secret:

- Using Objective-C:
```objectivec
Dimelo dimelo = [Dimelo sharedInstance];
[dimelo initializeWithApiKeyAndHostName: SOURCE_API_KEY hostName: DIMELO_HOST_NAME delegate: DIMELO_LISTENER];
/*
  SOURCE_API_KEY can be found in your source configuration
  DIMELO_HOST_NAME is your hostname (e.g. if your Dimelo Digital url is "DIMELO_DOMAIN_NAME.engagement.dimelo.com", then your hostName will be "DIMELO_DOMAIN_NAME.messaging.dimelo.com")
  DIMELO_LISTENER is an optionnal parameter that we will cover later in this document
*/
```

- Using Swift:
```swift
let dimelo: Dimelo = Dimelo.sharedInstance()
dimelo.initialize(withApiKeyAndHostName: SOURCE_API_KEY, hostName: DIMELO_HOST_NAME, delegate: DIMELO_LISTENER)
/*
  SOURCE_API_KEY can be found in your source configuration
  DIMELO_HOST_NAME is your hostname (e.g. if your Dimelo Digital url is "DIMELO_DOMAIN_NAME.engagement.dimelo.com", then your hostName will be "DIMELO_DOMAIN_NAME.messaging.dimelo.com")
  DIMELO_LISTENER is an optionnal parameter that we will cover later in this document
*/
```

Once this is done you will have to set `jwt` property manually with a value received from your server.
This way your server will prevent one user from impersonating another.

1. Set authentication-related properties (`userIdentifier`, `userName`, `authenticationInfo`).
2. Get a dictionary for JWT using `[Dimelo  jwtDictionary]`. This will also contain public API key, `installationIdentifier` etc.
3. Send this dictionary to your server.
4. Check the authenticity of the JWT dictionary on the server and compute a valid signed JWT token.
Use a corresponding secret API key to make a HMAC-SHA256 signature.
*Note:* use raw binary value of the secret key (decoded from hex) to make a
signature. Using hex string as-is will yield incorrect signature.
5. Send the signed JWT string back to your app.
6. In the app, set the `Dimelo.jwt` property with a received string.

/!\ `[Dimelo setUserIdentifier];`, `[Dimelo setAuthenticationInfo];` and `[Dimelo setUserName];` must only be called **BEFORE** `[Dimelo setJwt];` otherwise your JWT will be emptied and your request will end up in a 404 error.

You have to do this authentication only once per user identifier,
but before you try to use Engage Digital Messaging. Your application should prevent
user from opening a Mobile Messaging until you receive a JWT token.


Displaying Engage Digital Messaging conversation screen
--------------------------------------------

Dimelo provides an opaque `UIViewController` instance that you can display how you want (created by `-[Dimelo chatViewController]`). You may put it as a tab in a `UITabBarController`, show in a popover or present modally. You can also use `transitioningDelegate` to present chat view controller in a very custom way.

You can present chat manually (e.g. user taps a button to open "support"),
or the chat may appear automatically (mediated by the delegate method `-dimeloDisplayChatViewController:`).

*Note:* When the dimelo view is integrated as a fragment and to prevent input accessory view conflict, you should present it in full screen when it's opened from a push notification by calling:
```objectivec
if (dimelo.embeddedAsFragment && dimelo.openedFromNotification) {
    vc.modalPresentationStyle = UIModalPresentationFullScreen;
}
```

The chat is displayed automatically in two cases:

1. When the user launches or activates the app using a push notification.

2. When the user taps in-app notification bar that slides from the top in case
   a new message arrives while chat is not visible.

To display the chat manually and reuse the code in `-dimeloDisplayChatViewController:`, call `-[Dimelo displayChatView]`. When necessary, you can request another instance of a chat view controller (`-[Dimelo chatViewController]`) to show the chat in some other context.

*Note:* When the dimelo view is integrated as a fragment and to prevent input accessory view conflict, you should present it in full screen when it's opened from a push notification by calling:
```objectivec
if (dimelo.embeddedAsFragment && dimelo.openedFromNotification) {
    vc.modalPresentationStyle = UIModalPresentationFullScreen;
}
```

Customizing Engage Digital Messaging SDK Appearance
----------------------------------------

[see how to customize Dimelo using plist](PlistCustomization.md)

We provide a lot of properties for you to make the chat look native to your application.

For your convenience, properties are organized in two groups: Basic and Advanced.
In many cases it would be enough to adjust the Basic properties only.

You can customize global tint color, navigation bar colors and title.
You can also change the font and the color of any text in the chat view.

Advanced options include images and content insets for text bubbles.
We use 5 kinds of messages. Each kind can be customized independently.

1. User's text message.
2. User's image attachment.
3. Agent's text message.
4. Agent's image attachment.
5. System text notification (automatic reply from the server).

All bubble images must be 9-part sliced resizable images to fit arbitrary content.

Text bubbles may have images in two rendering modes: normal and template.
In *normal mode*, the image is displayed as-is.
In *template mode* it is colored using properties `userMessageBackgroundColor`, `agentMessageBackgroundColor` etc.
Default images use template mode.

If you provide a custom bubble image for text, you should also update
`{user,agent,system}MessageBubbleInsets` properties to arrange your text correctly within a bubble.

Attachment bubbles only use alpha channel of the image to mask the image preview.
Insets do not apply to attachment bubbles.

You can also create a `DimeloConfig.plist` file and add it to your project.
The library will use it to configure the `Dimelo` shared instance.

:warning: Following some changes in iOS13+, we cannot use `barTintColor` to customize the navigation bar tint color anymore. See [this Apple developer thread](https://developer.apple.com/forums/thread/122100) for more information.


Push Notifications
------------------

Please refer to the [Notifications.md](Notifications.md) file for guidance on how to integrate the Engage Digital Messaging SDK notifications into your application.

:warning: If you are upgrading from a previous version to 2.1.0+ you should know that the Engage Digital Messaging SDK doesn't automatically handle notifications anymore and now provides helper methods that need to be called in the host application.


Badge Count
-----------

By default, `Dimelo` updates app's badge number automatically based on number of unread messages.
If your application has its own unread count, you might want to disable this behaviour by setting
`updateAppBadgeNumber` property to `NO`. Then you can access the Dimelo-only unread count using `unreadCount` property.

*Note:* If you use `fetchUnreadCountWithCompletionHandler`, all treatments that updates the UI must be done in *main thread*:

```
[[Dimelo sharedInstance] fetchUnreadCountWithCompletionHandler:^(NSInteger unreadCount, NSError *error) {
    dispatch_async(dispatch_get_main_queue(), ^{
         // update UI
    });
}];
```

Required Permissions
--------------------

To access all the features of the Engage Digital Messaging SDK, some permissions have to be defined inside your project info.plist:

|XCode Key|Raw Info.plist Key|Used for|
|---------|------------------|--------|
|Privacy - Photo Library Usage Description|NSPhotoLibraryUsageDescription|Used to allow the user to choose images from its photo album to send them as attachment|
|Privacy - Camera Usage Description|NSCameraUsageDescription|Used to allow the user to take pictures from its camera to send them as attachment|
|Privacy - Location When In Use Usage Description|NSLocationWhenInUseUsageDescription|User to allow the user to send a location as attachment|

:warning: Starting with iOS14 `NSPhotoLibraryUsageDescription` is not needed anymore as the Engage Digital Messaging SDK uses the new [`PHPickerViewController`](https://developer.apple.com/documentation/photokit/phpickerviewcontroller?language=objc) which does not require to prompt user for permission.

If these permissions are not provided, the corresponding options will be hidden from the user.

To support localization, add these keys (`NSPhotoLibraryUsageDescription`, `NSCameraUsageDescription` and `NSLocationWhenInUseUsageDescription`) to the `InfoPlist.strings` file.


Localization
------------

Please refer to [Localization.md](Localization.md) for guidance on strings customization


Reacting To Engage Digital Messaging SDK Events
------------------------------------

We provide two ways to react to various events in the char:

1. By implementing a `DimeloDelegate` protocol.

2. By subscribing to `DimeloChat*Notification` notifications.

For your convenince all notifications have a corresponding delegate method (e.g. `-dimeloUnreadCountDidChange:`), so you don't have to subscribe to them explicitly if you
wish to process events in `DimeloDelegate` object.

Two particular events that might be interesting to you are `-dimeloDidBeginNetworkActivity:`, `-dimeloDidEndNetworkActivity:`. Engage Digital Messaging does not change the status bar network activity
indicator to avoid conflicts with your app. If you would like to indicate it, you should
override these methods and update the activity indicator accordingly.

*Note:* If you have treatments that updates the UI in `dimeloUnreadCountDidChange`, `dimeloDidBeginNetworkActivity` or `dimeloDidEndNetworkActivity` you have to do it in *main thread*: `dispatch_async(dispatch_get_main_queue(), ^{})`

Use `-onOpen:` and `-onClose:` events to get informations using `dimelo` parameter when the chat view is just opened or closed.

Use the `-rcShouldDelegateUrlOpening:` event to control what should happen when a URL is going to be opened by the Engage Digital Messaging iOS SDK:
- return `NO` to let the Engage Digital Messaging iOS SDK open the URL.
- return `YES` to prevent the Engage Digital Messaging iOS SDK from opening the URL so that you can apply your own logic.

Please refer to [API reference](https://rawcdn.githack.com/ringcentral/engage-digital-messaging-ios/64b957d54ad0d9a9da65e214f01524cae7977140/Reference/html/index.html) documentation for more information.


Manually opening a WebView
--------------------------

The Engage Digital Messaging iOS SDK exposes the `(void)openWebView:(NSURL *)url heightMode:(RcWebViewHeightMode)heightMode` method to allow you to manually open a WebView.

This method takes 2 parameters:
- The `url` parameter is a `NSURL` that represents the URL you want to open in the WebView.
- The `heightMode` parameter is a `RcWebViewHeightMode` that represents the height of the WebView (based on the WebView's container size), its value can be:

|Value|Container's height|
|-----|------------------|
|`RC_WEB_VIEW_FULL_MODE`|100%|
|`RC_WEB_VIEW_TALL_MODE`|75%|
|`RC_WEB_VIEW_COMPACT_MODE`|50%|
