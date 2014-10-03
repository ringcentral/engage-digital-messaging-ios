Dimelo-iOS
==========

Dimelo provides a mobile chat component that allows users of your app
to easily communicate  with your customer support agents. You can send text messages
and images, and receive push notifications and automatic server-provided replies.

The component integrates nicely in any iPhone or iPad app, allows presenting
the chat in tab, modal, popover or even customly designed containers and has
rich customization options to fit perfectly in your application.

Getting Started
---------------

Follow these steps to integrate the Dimelo chat in your application.

1) Install the Dimelo library either via CocoaPods or manually (see below).

2) Configure a `Dimelo` instance with your API key, optional user identifier and
   other user-specific info. We recommend to keep this instance in an instance
   variable in your app delegate.

3) Set `dimelo.developmentAPNS` = `YES` in your development builds to receive
   push notifications. Set it back to `NO` before submitting to AppStore.

4) Specify a delegate for `Dimelo` instance (usually it is your app delegate) and
   implement `-dimeloDisplayChatViewController:` method. This method will be called by
   `Dimelo` when it needs to present a chat view. Your application determines
   how and where to display a chat view controller.

To display a chat, get its view controller using `-[Dimelo chatViewController]`
and present it either modally, in popover or in a UITabBarController.
See **Displaying Chat** section below for more options.

5) In your app delegate, in  `-application:didRegisterForRemoteNotificationsWithDeviceToken:`
   set `deviceToken` property on your `Dimelo` instance. This will allow your app
   to receive push notifications from the Dimelo server when your agent replies to a user.

6) Also in the app delegate, in `-application:didReceiveRemoteNotification:`
   pass the `userInfo` to `-[Dimelo consumeReceivedRemoteNotification:]`.

These are minimal steps to make chat work in your app. Read on to learn how
to customize the appearance and behaviour of the chat to fit perfectly in your app.

See also **Sample Code** section in the end of this README or
download the [Sample App](https://github.com/dimelo/Dimelo-iOS-SampleApp).

Displaying the Chat
-------------------

Dimelo provides an opaque `UIViewController` instance that you can display how you want
(created by `-[Dimelo chatViewController]`). You may put it as a tab in a `UITabBarController`,
show in a popover or present modally. You can also use `transitioningDelegate`
to present chat view controller in a very custom way.

You can present chat manually (e.g. user taps a button to open "support"),
or the chat may appear automatically (mediated by the delegate method `-dimeloDisplayChatViewController:`).

The chat is displayed automatically in two cases:

1. When the user launches or activates the app using a push notification.

2. When the user taps in-app notification bar that slides from the top in case
   a new message arrives while chat is not visible.

To display the chat manually and reuse the code in `-dimeloDisplayChatViewController:`,
call `-[Dimelo displayChatView]`. When necessary, you can request another instance of
a chat view controller (`-[Dimelo chatViewController]`) to show the chat in some other context.

Authentication
--------------

With each HTTP request, Dimelo sends a JWT ([JSON Web Token](http://self-issued.info/docs/draft-ietf-oauth-json-web-token.html)).
This token contains user-specific info that you specify (`userIdentifier`, `userName` etc.)
and a HMAC signature. User identifier allows Dimelo to separate messages from
different users in the agent's backend. If user identifier is missing (`nil`),
then unique installation identifier is used to identify the user (created automatically).

We support two kinds of authentication modes: with server-side secret and a built-in secret.

#### 1. Setup with a built-in secret

This is a convenient mode for testing and secure enough when user identifiers are unpredictable.

You configure `Dimelo` instance with the *secret* key (`-initWithApiSecret:hostname:delegate:`)
and it creates and signs JWT automatically when needed (as if it was provided by the server).
You simply set necessary user-identifying information and JWT will be computed on the fly.
You do not need any cooperation with your server in this setup.

The security issue here is that built-in secret is rather easy to extract from the app's binary build.
Anyone could then sign JWTs with arbitrary user identifying info to access other users'
chats and impersonate them. To mitigate that risk make sure to use this mode
only during development, or ensure that user identifiers are not predictable (e.g. random UUIDs).

#### 2. Setup with a server-side secret

This is a more secure mode. Dimelo will provide you with two keys: a public API key and a secret key.
The public one will be used to configure `Dimelo` instance and identify your app.
The secret key will be stored on your server and used to sign JWT token on your server.

When you configure Dimelo with a public API key (`-initWithApiKey:hostname:delegate:`),
you will have to set `jwt` property manually with a value received from your server.
This way your server will prevent one user from impersonating another.

1. Set authentication-related properties (`userIdentifier`, `userName`, `authenticationInfo`).
2. Get a dictionary for JWT using `-[Dimelo jwtDictionary]`. This will also contain public API key, `installationIdentifier` etc.
3. Send this dictionary to your server.
4. Check the authenticity of the JWT dictionary on the server and compute a valid signed JWT token.
Use a corresponding secret API key to make a HMAC-SHA256 signature.
*Note:* use raw binary value of the secret key (decoded from hex) to make a
signature. Using hex string as-is will yield incorrect signature.
5. Send the signed JWT string back to your app.
6. In the app, set the `Dimelo.jwt` property with a received string.

You have to do this authentication only once per user identifier,
but before you try to use Dimelo chat. Your application should prevent
user from opening a chat until you receive a JWT token.



Push Notifications
------------------

Dimelo chat can receive push notifications from Dimelo server.
To make them work, three things must be done on your part:

1. Your app should register for remote notifications using `UIApplication` APIs.
   This is not strictly necessary as the Dimelo chat will attempt to do that automatically
   when user sends the first message. But if you are interested in sending notifications
   even before user has used the chat (e.g. a "welcome" message),
   then you should register for remote notifications earlier in the app's lifecycle.

2. Set the `Dimelo.deviceToken` property when you receive the token in `-application:didRegisterForRemoteNotificationsWithDeviceToken:`.

3. Set the `Dimelo.developmentAPNS` property to `YES` in your development builds
   in order to receive development push notifications. Do not forget to set this
   back to `NO` before submitting to AppStore.

4. Let Dimelo consume the notification inside `-application:didReceiveRemoteNotification:`
   using `-[Dimelo consumeReceivedRemoteNotification:]`. If this method returns `YES`,
   it means that Dimelo recognized the notification as its own and you should not
   process the notification yourself. The chat will be updated automatically with a new message.

If the notification was received as a result of a user action
(e.g. user opened it from the lock screen), the chat will be displayed automatically.

When the notification is received while your app is running, but the chat is not visible,
Dimelo will display a temporary notification bar on top of the screen (looking similar
to a iOS notification bar when another application is notified).
If the user taps that bar, a chat will open.

You may control whether to display this bar or maybe show the notification differently
using `-dimelo:shouldDisplayNotificationWithText:` delegate method.
If you'd like to show your own notification bar, return `NO` from this method
and use `text` argument to present the notification using your own UI.



Badge Count
-----------

By default, `Dimelo` updates app's badge number automatically based on number of unread messages.
If your application has its own unread count, you might want to disable this behaviour by setting
`updateAppBadgeNumber` property to `NO`. Then you can access the Dimelo-only unread count using `unreadCount` property.



Customizing Chat Appearance
---------------------------

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

Check the **API Reference** to learn about all customization options.


Reacting To Chat Events
-----------------------

We provide two ways to react to various events in the char:

1. By implementing a `DimeloDelegate` protocol.

2. By subscribing to `DimeloChat*Notification` notifications.

For your convenince all notifications have a corresponding delegate method (e.g. `-dimeloUnreadCountDidChange:`), so you don't have to subscribe to them explicitly if you
wish to process events in `DimeloDelegate` object.

Two particular events that might be interesting to you are `-dimeloDidBeginNetworkActivity:`
and `-dimeloDidEndNetworkActivity:`. Dimelo does not change the status bar network activity
indicator to avoid conflicts with your app. If you would like to indicate it, you should
override these methods and update the activity indicator accordingly.

Please refer to **API Reference** documentation (in ./Reference folder) for more information.



How To Install With CocoaPods
-----------------------------

1) Configure your project for CocoaPods (create a `Podfile` and a `xcworkspace`). Refer to [CocoaPods documentation](http://cocoapods.org) to learn how to do it.

2) Add "Dimelo-iOS" to your Podfile like so:

    pod 'Dimelo-iOS', :git => 'https://github.com/dimelo/Dimelo-iOS.git'

3) Run `pod install` to update your project.

4) Include header in your app delegate: `#include "Dimelo.h"`

5) Follow the [API reference](Reference/html/index.html) to configure and use Dimelo instance.



How To Install Manually
-----------------------

1) Download contents from Github [Dimelo-iOS project](https://github.com/dimelo/Dimelo-iOS).

<img src=HowToImages/01-downloaded-folder@2x.png width=250></img>

2) Drop `Dimelo` subfolder in your project.

<img src=HowToImages/02-drag-to-project@2x.png width=400></img>

3) Make sure to copy the files, convert folders to groups and check the correct target.

<img src=HowToImages/03-copy-groups-target@2x.png width=400></img>

You will see Dimelo files in your project tree:

<img src=HowToImages/04-view-in-sidebar@2x.png width=250></img>

4) Make sure `Dimelo.bundle`, `libDimelo-iOS.a` and `Dimelo*.xib` files are included in your target.

<img src=HowToImages/05-check-xib-bundle-a-for-target@2x.png width=250></img>

5) Link your target with these frameworks:

 * Accelerate.framework
 * MobileCoreServices.framework
 * SystemConfiguration.framework

<img src=HowToImages/06-add-frameworks@2x.png width=400></img>

6) Include header in your app delegate: `#include "Dimelo.h"`

7) Follow the [API reference](Reference/html/index.html) to configure and use Dimelo instance.



API Reference
-------------

You will find API documentation in `./Reference` folder. Alternatively, you may consult `Dimelo/Dimelo.h` file.


Files and folders
-----------------

Dimelo package contains the following files and folders:


##### ./Dimelo

A folder with necessary headers and resources to be installed in your app.
If you don't use CocoaPods, you can simply drag and drop this folder into
your Xcode project (don't forget to link extra system frameworks too, see above).

##### ./Dimelo/Dimelo.bundle

A bundle with Dimelo default images. This should be copied as-is into your app
during the build process.

##### ./Dimelo/Dimelo.h

Primary header file. You should import it to use Dimelo API.

##### ./Dimelo/Dimelo*.h

Private header files to make XIB files work correctly.

##### ./Dimelo/*.xib

Required user interface XIB files. These are not supposed to be edited.

##### ./Dimelo/libDimelo-iOS.a

A static lib to be linked with your app. It is build for multiple platforms,
including iOS simulators.

##### ./Dimelo-iOS.podspec

A CocoaPods specification.

##### ./LICENSE

A license file.

##### ./README.md

You are reading this.

##### ./Reference

An appledoc-style API reference generated from `Dimelo.h`.


Sample Code
-----------

The following code is a minimal configuration of Dimelo chat. It presents
the chat, handles push notifications and displays network activity in status bar.


```
#import "AppDelegate.h"
#import "Dimelo.h"

@interface AppDelegate () <DimeloDelegate>
@property(nonatomic) Dimelo* dimelo;
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    NSString* secret = @"<ENTER YOUR API SECRET HERE>";

    self.dimelo = [[Dimelo alloc] initWithApiSecret:secret delegate:self];

    // When any of these properties are set, JWT is recomputed instantly.
    self.dimelo.userIdentifier = @"U-1000555777";
    self.dimelo.authenticationInfo = @{@"bankBranch": @"Test-1234" };
    self.dimelo.title = NSLocalizedString(@"Support Chat", @"Sample App");

    dispatch_async(dispatch_get_main_queue(), ^{

        [self.dimelo displayChatView];

    });

    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    // Register the device token.
    self.dimelo.deviceToken = deviceToken;
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    if ([self.dimelo consumeReceivedRemoteNotification:userInfo])
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
    [UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
}

- (void) dimeloDidEndNetworkActivity:(Dimelo*)dimelo
{
    [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
}


@end
```





