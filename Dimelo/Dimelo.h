//  Copyright (c) 2014 Dimelo. All rights reserved.

#import <UIKit/UIKit.h>

@class Dimelo;

/*!
 * Posted when `-[Dimelo unreadCount]` property is changed.
 */
extern NSString* const DimeloChatUnreadCountDidChangeNotification;

/*!
 * Posted when the user sends a message.
 */
extern NSString* const DimeloChatDidSendMessageNotification;

/*!
 * Posted when the chat receives new messages from the server
 * (even while the chat is not visible).
 */
extern NSString* const DimeloChatDidReceiveNewMessagesNotification;

/*!
 * Posted when the chat view is about to be displayed.
 */
extern NSString* const DimeloChatWillAppearNotification;

/*!
 * Posted when the chat view is displayed (animation completed).
 */
extern NSString* const DimeloChatDidAppearNotification;

/*!
 * Posted when the chat view is about to be closed.
 */
extern NSString* const DimeloChatWillDisappearNotification;

/*!
 * Posted when the chat view is closed (animation completed).
 */
extern NSString* const DimeloChatDidDisappearNotification;


/*!
 * The `DimeloDelegate` protocol allows you to react to remote notifications,
 * display network activity progress and react to events created by the chat views.
 */
@protocol DimeloDelegate<NSObject>

@required

/*!
 * Asks to display the chat view controller.
 *
 * You may use an existing instance or create a new one using `-[Dimelo chatViewController]`.
 *
 * Typical ways to display a chat view controller:
 *
 * 1. Modally, using _-[UIViewController presentViewController:animated:completion:]_.
 *
 * 2. In a tab view, by switching to an existing tab.
 *
 * 3. Using popover on iPad.
 *
 * This method is required as it is the only way for `Dimelo` to know how to
 * display a chat view controller in response to remote notifications.
 *
 * @param dimelo An API instance.
 *
 */
- (void) dimeloDisplayChatViewController:(Dimelo*)dimelo;

@optional

/*!
 * Asks if a notification bar should be displayed.
 *
 * By default, a standard notification slides from the top. When the user taps it,
 * the chat view is opened (via `dimeloDisplayChatViewController:`).
 *
 * @param dimelo   An API instance.
 * @param message  A message to be displayed in the notification.
 *                 If you override Dimelo notification bar, you may use this text
 *                 to display in your own notification.
 *
 * @return `YES` to allow notification.
 * @return `NO` if you want to display custom UI or simply ignore this notification.
 *
 */
- (BOOL) dimelo:(Dimelo*)dimelo shouldDisplayNotificationWithText:(NSString*)message;

/*!
 * Called when a network activity started.
 *
 * This is provided so your app could show status bar spinner
 * using `-[UIApplication networkActivityIndicatorVisible]`.
 *
 * This method can be called multiple times, for each network request.
 * Every call is guaranteed to be eventually balanced by `dimeloDidEndNetworkActivity:`.
 *
 * @param dimelo   An `Dimelo` API instance.
 *
 */
- (void) dimeloDidBeginNetworkActivity:(Dimelo*)dimelo;

/*!
 * Called when a network activity ended.
 *
 * This is provided so your app could hide status bar spinner
 * using `-[UIApplication networkActivityIndicatorVisible]`.
 *
 * This method can be called multiple times, for each network request.
 * This call is guaranteed to balance every `dimeloDidBeginNetworkActivity:`.
 *
 * @param dimelo   A `Dimelo` API instance.
 *
 */
- (void) dimeloDidEndNetworkActivity:(Dimelo*)dimelo;

/*!
 * Called when `-[Dimelo unreadCount]` property changes.
 *
 * Provided as a courtesy so that you do not need to subscribe to notifications separately
 * when handling these events in one delegate is enough for your use case.
 *
 * @param notification   NSNotification with name DimeloChatUnreadCountDidChangeNotification.
 *
 * @see DimeloChatUnreadCountDidChangeNotification
 */
- (void) dimeloUnreadCountDidChange:(NSNotification*)notification;

/*!
 * Called when the user sends a message.
 *
 * Provided as a courtesy so that you do not need to subscribe to notifications separately
 * when handling these events in one delegate is enough for your use case.
 *
 * @param notification   NSNotification with name DimeloChatDidSendMessageNotification.
 *
 * @see DimeloChatDidSendMessageNotification
 */
- (void) dimeloChatDidSendMessage:(NSNotification*)notification;

/*!
 * Called when chat receives new messages from the server (even while the chat is not visible).
 *
 * Provided as a courtesy so that you do not need to subscribe to notifications separately
 * when handling these events in one delegate is enough for your use case.
 *
 * @param notification   NSNotification with name DimeloChatDidReceiveNewMessagesNotification.
 *
 * @see DimeloChatDidReceiveNewMessagesNotification
 */
- (void) dimeloChatDidReceiveNewMessages:(NSNotification*)notification;

/*!
 * Called when the chat view is about to be displayed.
 *
 * Provided as a courtesy so that you do not need to subscribe to notifications separately
 * when handling these events in one delegate is enough for your use case.
 *
 * @param notification   NSNotification with name DimeloChatWillAppearNotification.
 *
 * @see DimeloChatWillAppearNotification
 */
- (void) dimeloChatWillAppear:(NSNotification*)notification;

/*!
 * Called when the chat view is displayed (animation completed).
 *
 * Provided as a courtesy so that you do not need to subscribe to notifications separately
 * when handling these events in one delegate is enough for your use case.
 *
 * @param notification   NSNotification with name DimeloChatDidAppearNotification.
 *
 * @see DimeloChatDidAppearNotification
 */
- (void) dimeloChatDidAppear:(NSNotification*)notification;

/*!
 * Called when the chat view is about to be closed.
 *
 * Provided as a courtesy so that you do not need to subscribe to notifications separately
 * when handling these events in one delegate is enough for your use case.
 *
 * @param notification   NSNotification with name DimeloChatWillDisappearNotification.
 *
 * @see DimeloChatWillDisappearNotification
 */
- (void) dimeloChatWillDisappear:(NSNotification*)notification;

/*!
 * Called when the chat view is closed (animation completed).
 *
 * Provided as a courtesy so that you do not need to subscribe to notifications separately
 * when handling these events in one delegate is enough for your use case.
 *
 * @param notification   NSNotification with name DimeloChatDidDisappearNotification.
 *
 * @see DimeloChatDidDisappearNotification
 */
- (void) dimeloChatDidDisappear:(NSNotification*)notification;

@end


/*!
 * `Dimelo` is a central object to access Dimelo API.
 *
 * You instantiate Dimelo with an API key, configure the delegate, information
 * about the current user and use it to display a chat view controller.
 *
 * There are two modes in which API instance can be configured: a secure and less secure one.
 *
 * ### Recommended mode: with server-signed authentication token.
 *
 * ```
 * // Instantiate dimelo with public api key and a hostname.
 * Dimelo* dimelo = [[Dimelo alloc] initWithApiKey:@"public api key" hostname:@"api.example.com" delegate:self];
 *
 * // Assign optional properties to include in authenticated JWT token.
 * dimelo.userIdentifier = @"optional user account ID";
 * dimelo.authenticationInfo = @{ <extra fields to add to JWT token>  }
 *
 * // Retrieve a dictionary to be signed by your server within a JWT token:
 * NSDictionary* dict = dimelo.jwtDictionary;
 *
 * // Send dict to your server and receive a signed JWT token in response.
 * // Token must be signed with a secret key corresponding to public API key that you use in your app.
 *
 * // Assign a token to dimelo.jwt so it can be used in all communications.
 * dimelo.jwt = jwtFromServer;
 * ```
 *
 * Now Dimelo will be able to make requests to Dimelo servers, send and receive chat messages etc.
 *
 *
 * ### Unsafe mode which does not require signing a JWT token by your server:
 *
 * ```
 * // Instantiate dimelo with *secret* api key and a hostname.
 * Dimelo* dimelo = [[Dimelo alloc] initWithApiSecret:@"secret api key" hostname:@"api.example.com" delegate:self];
 *
 * // Assign optional properties to include in authenticated JWT token.
 * dimelo.userIdentifier = @"optional user account ID";
 * dimelo.authenticationInfo = @{ <extra fields to add to JWT token>  }
 *
 * // Dimelo will compute and sign a valid JWT token automatically each time you change one of the properties above.
 * // All communications will include the signed JWT token as if they were signed by your server.
 * ```
 *
 * **WARNING:** Note that anyone who extracts your secret API key will be able
 * to impersonate any user if they know their userIdentifier. User's data is
 * relatively safe if userIdentifier is not well-known or cannot be easily guessed.
 *
 */
@interface Dimelo : NSObject


////////////////////////////////////////////////////////////////////////////////
/// @name Setting up an API client
////////////////////////////////////////////////////////////////////////////////


/*!
* returns API client configured with config from DimeloConfig.plist
*
* For correct operation you will have to provide a valid signed JWT token via `jwt` property.
* To do so, fill in `userIdentifier`, `authenticationInfo` and send the resulting `jwtDictionary` to your server.
*
* This is a recommended way to access Dimelo API.
*
*/
+ (instancetype)sharedInstance;

/*!
* Initializes API client with a public API key and a delegate.
*
* Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
*
* For correct operation you will have to provide a valid signed JWT token via `jwt` property.
* To do so, fill in `userIdentifier`, `authenticationInfo` and send the resulting `jwtDictionary` to your server.
*
* This is a recommended way to access Dimelo API.
*
* @param apiKey public hex-encoded API key, typically specific to your app.
* @param delegate an instance conforming to `DimeloDelegate` protocol.
*
*/
- (id) initWithApiKey:(NSString*)apiKey delegate:(id<DimeloDelegate>)delegate;

/*!
 * Initializes API client with a public API key, custom hostname and a delegate.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 * For correct operation you will have to provide a valid signed JWT token via `jwt` property.
 * To do so, fill in `userIdentifier`, `authenticationInfo` and send the resulting `jwtDictionary` to your server.
 *
 * This is a recommended way to access Dimelo API.
 *
 * @param apiKey public hex-encoded API key, typically specific to your app.
 * @param hostname a Dimelo API hostname specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id) initWithApiKey:(NSString*)apiKey hostname:(NSString*)hostname delegate:(id<DimeloDelegate>)delegate;

/*!
 * Initializes API client with a secret API key and a delegate.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 * This mode is less secure than `-initWithApiKey:delegate:` because shared secret is stored inside the app.
 *
 * @param apiSecret a hex-encoded API secret key, typically specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id) initWithApiSecret:(NSString*)apiSecret delegate:(id<DimeloDelegate>)delegate;

/*!
 * Initializes API client with a secret API key, custom hostname and a delegate.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 * This mode is less secure than `-initWithApiKey:hostname:delegate:` because shared secret is stored inside the app.
 *
 * @param apiSecret a hex-encoded API secret key, typically specific to your app.
 * @param hostname a Dimelo API hostname specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id) initWithApiSecret:(NSString*)apiSecret hostname:(NSString*)hostname delegate:(id<DimeloDelegate>)delegate;


/*!
 * Per-application API secret key, typically specific to your app.
 *
 * API secret is always represented in hex format, e.g. `@"ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70"`.
 */
- (void) setApiSecret:(NSString*)apiSecret;

/*!
 * Delegate object to present a chat view controller and react to various optional notifications.
 *
 * @see DimeloDelegate
 */
@property(nonatomic, weak) id<DimeloDelegate> delegate;

/*!
 * Per-application public API key that identifies all requests to Dimelo.
 *
 * API Key is always represented in hex format, e.g. `@"ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70"`.
 */
@property(nonatomic, copy) NSString* apiKey;

/*!
 * Per-application hostname used to connect to Dimelo backend.
 */
@property(nonatomic, copy) NSString* hostname;

/*!
 * Per-installation identifier generated when the component is instantiated for the first time within the app.
 */
@property(nonatomic, readonly) NSString* installationIdentifier;

/*!
 * Per-user unique identifier used to link messages sent from different devices to a single person.
 *
 * User identifier could be an arbitrary string that makes sense in your application:
 * an email, an account number or a UUID.
 *
 * You can initialize and use Dimelo before user is logged-in, but after he has logged in,
 * set the `userIdentifier` to let Dimelo know the real identity of the user.
 *
 * If `userIdentifier` is nil, user will be uniquely identified on the server by the `installationIdentifier`.
 */
@property(nonatomic, copy) NSString* userIdentifier;

/*!
 * Additional fields to be added to the JWT dictionary under "extra" key.
 *
 * You must make sure only PropertyList-compatible items a present inside this dictionary.
 */
@property(nonatomic, copy) NSDictionary* authenticationInfo;

/*!
 * Optional name of the person to be sent to Dimelo.
 */
@property(nonatomic, copy) NSString* userName;

/*!
 * Complete serialized JWT token.
 *
 * If you use instantiation with public API key and your server signs JWT token, set this property
 * with a JWT provided by your server.
 *
 * If you instantiate `Dimelo` with a secret API key, this property is computed automatically.
 */
@property(nonatomic, copy) NSString* jwt;

/*!
 * JWT dictionary to be signed. Computed out of apiKey, installationIdentifier, userIdentifier, authenticationInfo.
 *
 * Send this dictionary to your app's server to sign with a shared secret corresponding to API key.
 *
 * If you instantiate `Dimelo` with API secret, this dictionary will be used to compute `jwt` property automatically.
 */
@property(nonatomic, readonly) NSDictionary* jwtDictionary;

/*!
 * Arbitrary contextual info attached to a message.
 *
 * Attached only to the first message after a new value was specified.
 *
 * Example: user selects a category of a problem ("Technical" or "Sales")
 * and then contacts the support. First message indicates what type of the problem user is talking about.
 */
@property(nonatomic, copy) NSDictionary* messageContextInfo;


////////////////////////////////////////////////////////////////////////////////
/// @name Displaying Chat View
////////////////////////////////////////////////////////////////////////////////


/*!
 * Asks delegate to display the chat view.
 *
 * This method is called internally, but it is also available for you to display
 * the chat from a single convenient place.
 *
 * @see -[DimeloDelegate dimeloDisplayChatViewController:]
 */
- (void) displayChatView;

/*!
 * Creates a new instance of a chat view controller.
 *
 * Use standard `-presentViewController:animated:completion:` and `—dismissViewController` messages to show/hide it.
 *
 * You can present it modally or in `UITabViewController`.
 *
 * Use _transitioningDelegate_ for custom presentation.
 *
 * @return A UIViewController containing a chat view.
 *
 * @see -[DimeloDelegate dimeloDisplayChatViewController:]
 */
- (UIViewController*) chatViewController;



////////////////////////////////////////////////////////////////////////////////
/// @name Remote Notifications
////////////////////////////////////////////////////////////////////////////////


/*!
 * Device token for remote notifications. Optional.
 *
 * Override `-application:didRegisterForRemoteNotificationsWithDeviceToken:` and
 * set this property to a provided deviceToken.
 */
@property(nonatomic, copy) NSData* deviceToken;

/*!
 * Flag to tell Dimelo server to send push notifications using development channel.
 *
 * Set this to `YES` in order to receive notifications on development builds.
 * By default, Dimelo server will send notifications to production environment and
 * development builds will not receive such notifications.
 *
 * Default is `NO`.
 */
@property(nonatomic) BOOL developmentAPNS;

/*!
 * Attempts to process the remote notification.
 *
 * Returns YES if this notification belongs to this Dimelo instance and user. Otherwise returns NO.
 *
 * If the app was activated due to this notification, delegate is asked to display the chat.
 *
 * If the app was active already, it displays the notification on top of the screen. When user taps it, delegate is asked to display the chat.
 *
 * If it returns YES do not pass the notification data to the rest of your app.
 *
 * Recommended usage:
 *
 * ```
 * - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
 * {
 *     if ([self.dimelo consumeReceivedRemoteNotification:userInfo]) {
 *         return;
 *     }
 *     // You app's handling of this notification...
 * }
 * ```
 *
 * @param dictionary a `userInfo` dictionary provided by the OS.
 * @return `YES` if notification is consumed by Dimelo and should not be processed by your app.
 * @return `NO` if notification does not belong to Dimelo and should be processed by your app.
 *
 */
- (BOOL) consumeReceivedRemoteNotification:(NSDictionary*)dictionary;


////////////////////////////////////////////////////////////////////////////////
/// @name Accessing Unread Count
////////////////////////////////////////////////////////////////////////////////

/*!
 * Number of unread messages or other events to which user hasn't reacted yet.
 *
 * You can display this as a badge on a button that opens the chat.
 *
 * Default value is 0.
 */
@property(nonatomic, readonly) NSInteger unreadCount;

/*!
 * Whether the app's icon badge is automatically updated with `unreadCount` value.
 *
 * If YES, updates app's icon badge automatically to reflect unreadCount.
 *
 * Set it to NO to fully control app's badge number.
 *
 * The badge is updated also by push notifications. To avoid Dimelo notifications changing
 * your app's badge number, disable automatic badge update on the Dimelo administration website.
 *
 * Default is YES.
 */
@property(nonatomic) BOOL updateAppBadgeNumber;

/*!
 * Sends notifications to `NSNotificationCenter` and notifies the delegate about `unreadCount` change. Does not affect the value itself.
 *
 * This method is called automatically when `unreadCount` is changed due to new data received from the server.
 * It may be useful to call it manually when you want to refresh counters after the views are presented without
 * them having explicit references to Dimelo instance (NSNotification `object` will store reference to `Dimelo` instance).
 */
- (void) noteUnreadCountDidChange;



////////////////////////////////////////////////////////////////////////////////
/// @name Basic Customization
////////////////////////////////////////////////////////////////////////////////


/*!
 * Tint color for aux controls: Close button, Send button, cursor etc.
 */
@property(nonatomic) UIColor* tintColor;

/*!
 * Bar tint color for navigation bar (sets `barTintColor` property).
 */
@property(nonatomic) UIColor* navigationBarTintColor;

/*!
 * Background color for navigation bar (sets `backgroundColor` property).
 */
@property(nonatomic) UIColor* navigationBarColor;

/*!
 * Title for the chat.
 *
 * Used only if `titleView` is nil.
 */
@property(nonatomic, copy) NSString* title;

/*!
 * Title view for the chat.
 *
 * If not nil, overrides `title` value.
 */
@property(nonatomic) UIView* titleView;

/*!
 * Background view of the chat.
 *
 * You may customize its backgroundColor or place arbitrary views inside it.
 */
@property(nonatomic, readonly) UIView* backgroundView;

/*!
 * Font for user and agent messages.
 */
@property(nonatomic) UIFont* messageFont;

/*!
 * Font for system messages.
 */
@property(nonatomic) UIFont* systemMessageFont;

/*!
 * Foreground color for user's message text.
 */
@property(nonatomic) UIColor* userMessageTextColor;

/*!
 * Foreground color for agent's message text.
 */
@property(nonatomic) UIColor* agentMessageTextColor;

/*!
 * Foreground color for system notification message text.
 */
@property(nonatomic) UIColor* systemMessageTextColor;

/*!
 * Background color for user message bubbles.
 *
 * This color is applied when `userMessageBubbleImage` has template rendering mode (see UIImageRenderingMode).
 * Default image is configured this way.
 */
@property(nonatomic) UIColor* userMessageBackgroundColor;

/*!
 * Background color for agent message bubbles.
 *
 * This color is applied when `agentMessageBubbleImage` has template rendering mode (see UIImageRenderingMode).
 * Default image is configured this way.
 */
@property(nonatomic) UIColor* agentMessageBackgroundColor;

/*!
 * Background color for system message bubbles.
 *
 * This color is applied when `systemMessageBubbleImage` has template rendering mode (see UIImageRenderingMode).
 * Default image is configured this way.
 */
@property(nonatomic) UIColor* systemMessageBackgroundColor;

/*!
 * Font for the date label.
 */
@property(nonatomic) UIFont* dateFont;

/*!
 * Text color for the date label.
 */
@property(nonatomic) UIColor* dateTextColor;

/*!
 * Date formatter instance used to format the date label.
 */
@property(nonatomic) NSDateFormatter* dateFormatter;

/*!
 * Font for agent's name.
 */
@property(nonatomic) UIFont* agentNameFont;

/*!
 * Text color for agent's name.
 */
@property(nonatomic) UIColor* agentNameColor;

/*!
 * Text color for the button "load more messages".
 *
 * If this property is nil (default), this button is colored using `tintColor`.
 *
 */
@property(nonatomic) UIColor* loadMoreMessagesButtonTextColor;


////////////////////////////////////////////////////////////////////////////////
/// @name Advanced Customization
////////////////////////////////////////////////////////////////////////////////


/*!
 * Insets for agent name label placed under the message bubble.
 *
 * These insets should be in sync with `agentMessageBubbleImage`.
 */
@property(nonatomic) UIEdgeInsets agentNameInsets;

/*!
 * Resizable (9-part) image to decorate user text bubble.
 *
 * @see userMessageBubbleImage
 */
@property(nonatomic) UIImage*     userMessageBubbleImage;

/*!
 * Resizable (9-part) image to decorate agent text bubble.
 *
 * @see agentMessageBubbleInsets
 */
@property(nonatomic) UIImage*     agentMessageBubbleImage;

/*!
 * Resizable (9-part) image to decorate system text bubble.
 *
 * @see systemMessageBubbleInsets
 */
@property(nonatomic) UIImage*     systemMessageBubbleImage;

/*!
 * Insets for text in user's message bubble.
 *
 * @see userMessageBubbleImage
 */
@property(nonatomic) UIEdgeInsets userMessageBubbleInsets;

/*!
 * Insets for text in agent's message bubble.
 *
 * @see agentMessageBubbleImage
 */
@property(nonatomic) UIEdgeInsets agentMessageBubbleInsets;

/*!
 * Insets for text in system message bubble.
 *
 * @see systemMessageBubbleImage
 */
@property(nonatomic) UIEdgeInsets systemMessageBubbleInsets;

/*!
 * Resizable (9-part) image to mask user's attachment (alpha channel is used as a mask).
 *
 * By default, the same as `userMessageBubbleImage`.
 *
 * @see userAttachmentBubbleInsets
 */
@property(nonatomic) UIImage*     userAttachmentBubbleImage;

/*!
 * Resizable (9-part) image to mask agent's attachment (alpha channel is used as a mask).
 *
 * By default, the same as `agentMessageBubbleImage`.
 *
 * @see agentAttachmentBubbleInsets
 */
@property(nonatomic) UIImage*     agentAttachmentBubbleImage;

/*!
 * Insets for user's attachment preview bubble.
 *
 * @see userAttachmentBubbleImage
 */
@property(nonatomic) UIEdgeInsets userAttachmentBubbleInsets;

/*!
 * Insets for agent's attachment preview bubble.
 *
 * @see agentAttachmentBubbleImage
 */
@property(nonatomic) UIEdgeInsets agentAttachmentBubbleInsets;

/*!
 * Bar tint color of the input bar.
 */
@property(nonatomic) UIColor* inputBarTintColor;

/*!
 * Background color of the input bar.
 */
@property(nonatomic) UIColor* inputBarBackgroundColor;

/*!
 * Icon to be displayed on "attach" button in the input bar.
 */
@property(nonatomic) UIImage* attachmentIcon;

/*!
 * Keyboard appearance for a system keyboard.
 *
 * Default is `UIKeyboardAppearanceDefault`.
 */
@property(nonatomic) UIKeyboardAppearance keyboardAppearance;


@end


