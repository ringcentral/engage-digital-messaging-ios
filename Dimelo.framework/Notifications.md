# Push Notifications

## Mandatory steps

Engage Digital Messaging can receive push notifications from Engage Digital server.

Here are the mandatory steps you need to follow in order to add push notifications support to your application:

1. You need to have properly configured and generated Apple APNS cerficates ([see how to generate APNS certificate](GenerateAPNSCertificate.md)) and have them configured in your Engage Digital admin configuration interface.

2. You need to enable the `Push Notifications` capability in your application (more information on [Apple's documentation](https://developer.apple.com/documentation/usernotifications/registering_your_app_with_apns?language=objc)).

3. Your app should register for remote notifications using `UIApplication` APIs.
This is not strictly necessary as Engage Digital Messaging will attempt to do that automatically
when user sends the first message. But if you are interested in sending notifications
even before user has used the chat (e.g. a "welcome" message),
then you should register for remote notifications earlier in the app's lifecycle.

4. Set the `Dimelo.deviceToken` property with the token you receive in `-application:didRegisterForRemoteNotificationsWithDeviceToken:`.

5. Set the `Dimelo.developmentAPNS` property to `YES` in your development builds
in order to receive development push notifications. Do not forget to set this
back to `NO` when using a distribution provisioning profile.

## Integrating Engage Digital Messaging notifications into your application

The Engage Digital Messaging SDK for iOS provides helper methods to help you integrate Engage Digital Messaging notifications into your application notification workflow:

1. When receiving a notification through the `-application:didReceiveRemoteNotification:` callback you should let Engage Digital Messaging consume the notification using `-[Dimelo consumeReceivedRemoteNotification:]`. This method takes the notification payload as argument and will return a `BOOL` based on whether the notification should be handled by the SDK or not, here's an implementation example:

```objc
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    if ([[Dimelo sharedInstance] consumeReceivedRemoteNotification:userInfo]) {
        return;
    }

    NSLog(@"This remote notification is not from RingCentral and should therefore be handled by your application");
}
```

2. Engage Messaging SDK also handles interactive notification which allows the user to reply directly from the notification without having to open the application, this feature is enabled by default but can be disabled programmatically using `dimelo.interactiveNotification = NO;` or through a plist file (see [the related documentation](https://github.com/ringcentral/engage-digital-messaging-ios/blob/master/PlistCustomization.md#interactivenotification)).
In order to use this feature you will need to implement the `-application:handleActionWithIdentifier:forRemoteNotification:withResponseInfo:completionHandler:` callback in your application and let Engage Digital Messaging consume the notification using the `[Dimelo handleRemoteNotificationWithIdentifier: responseInfo: userInfo:]` method which will return a `BOOL` based on
whether the notification should be handled by the SDK or not and will also take care of sending the message if needed, here's an implementation example:

```objc
- (void)application:(UIApplication*)application handleActionWithIdentifier:(nullable NSString*)identifier forRemoteNotification:(NSDictionary*)userInfo withResponseInfo:(NSDictionary*)responseInfo completionHandler:(void (^) ())completionHandler {
    if (![[Dimelo sharedInstance] handleRemoteNotificationWithIdentifier: identifier responseInfo: responseInfo userInfo:userInfo]) {
        NSLog(@"This action hasn't been performed in response to a RingCentral notification and should therefore be handled by your application");
    }

    completionHandler();
}
```

3. When a RingCentral notification is received while the application is running in the foreground Engage Digital Messaging will display a temporary notification bar on top of the screen (looking similar to an iOS notification bar when another application is notified), tapping this notification will open the chat. You can control how this notification is displayed using the `-dimelo:shouldDisplayNotificationWithText:` delegate method. If you'd like to show your own notification bar, simply return `NO` from the aforementioned method and use the `text` argument to present the notification using your own UI.

<br/>

### Using the `NSNotificationCenter`

In order to use the `NSNotificationCenter` you will need to make your app delegate implement the `UNUserNotificationCenterDelegate` protocol in your app delegate header file:
```objc
#import <UserNotifications/UserNotifications.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, UNUserNotificationCenterDelegate>
```

Then, you'll need to set your app delegate as the notification center delegate (this must be done before your app finished launching otherwise you might miss some incoming notifications, see [Apple's documentation](https://developer.apple.com/documentation/usernotifications/unusernotificationcenterdelegate?language=objc)):

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    ...
    if (@available(iOS 10.0, *)) {
        UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
        center.delegate = self;
    }
    ...
}
```

<br/>

Once these steps have been completed you can start implementing methods to:

**Control how the notification is presented to the user** using the `-userNotificationCenter:willPresentNotification: withCompletionHandler:` in which you can call `-[Dimelo presentRingCentralNotification: withCompletionHandler:]`. This method will return a `BOOL` based on whether the notification should be handled by our SDK.

:warning: Please note that if the method returns `YES` it will call the `completionHandler` passed as argument, in this case you should not call it yourself.

Here's an implementation example:

```objc
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler {
    if (![[Dimelo sharedInstance] presentRingCentralNotification:notification withCompletionHandler:completionHandler]) {
        NSLog(@"This notification is not from RingCentral and should therefore be handled by your application");
        completionHandler(UNNotificationPresentationOptionAlert | UNNotificationPresentationOptionBadge);
    }
}
```

<br/>

You can also **control the notification's behavior when it's actioned by a user** using the `-userNotificationCenter: didReceiveNotificationResponse: withCompletionHandler:` callback.

The SDK provides the `-[Dimelo consumeNotificationResponse:]` helper method which takes the notification response as argument and will return a `BOOL` based on whether the notification should be handled by the SDK.

If the aforementioned helper method returns `YES` it means that the notification has been handled by the SDK and therefore you don't have to do anything with it.

:warning: This method doesn't take the `completionHandler` as an argument which means that you should call it in the `didReceiveNotificationResponse` method no matter if the notification is from RingCentral or not.

Here's an implementation example:

```objc
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(nonnull UNNotificationResponse *)response withCompletionHandler:(nonnull void (^)(void))completionHandler {
    if (![[Dimelo sharedInstance] consumeNotificationResponse:response]) {
        NSLog(@"This notification is not from RingCentral and should therefore be handled by your application");
    }

    completionHandler();
}
```
