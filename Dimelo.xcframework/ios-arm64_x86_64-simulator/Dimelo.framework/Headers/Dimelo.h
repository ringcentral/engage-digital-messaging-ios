//  Copyright (c) 2014 Dimelo. All rights reserved.

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>

//! Project version number for Dimelo.
FOUNDATION_EXPORT double DimeloVersionNumber;

//! Project version string for Dimelo.
FOUNDATION_EXPORT const unsigned char DimeloVersionString[];

extern NSString* const DimeloHTTPErrorDomain;

#ifndef DIMELO_TIME_TO_WAIT_FOR_RESEND
#define DIMELO_TIME_TO_WAIT_TO_RESEND 0.2f
#endif /* DIMELO_TIME_TO_WAIT_TO_RESEND */

#define RC_USER_MESSAGE_DEFAULT_BACKGROUND_COLOR [UIColor colorWithRed:68.0/255.0 green:129.0/255.0 blue:235.0/255.0 alpha:1.0] // #4481EB
#define RC_CREATE_THREAD_BUTTON_HIGHLIGHTED_COLOR [UIColor colorWithRed:59.0/255.0 green:113.0/255.0 blue:207.0/255.0 alpha:1.0] // #3B71CF
#define RC_BADGE_BACKGROUND_COLOR [UIColor colorWithRed:240.0/255.0 green:81.0/255.0 blue:42.0/255.0 alpha:1.0] // #F0512A
#define RC_VIDEO_CALL_REQUEST_BUTTON_COLOR [UIColor colorWithRed:189.0/255.0 green:189.0/255.0 blue:189.0/255.0 alpha:1.0] // #BDBDBD
#define RC_HIGHLIGHTED_VIDEO_CALL_REQUEST_BUTTON_COLOR [UIColor colorWithRed:103.0/255.0 green:103.0/255.0 blue:103.0/255.0 alpha:1.0] // #676767
#define RC_GRAY_900 [UIColor colorWithRed:33.0/255.0 green:33.0/255.0 blue:33.0/255.0 alpha:1.0] // #212121
#define RC_GRAY_800 [UIColor colorWithRed:117.0/255.0 green:117.0/255.0 blue:117.0/255.0 alpha:1.0] // #757575
#define RC_GRAY_700 [UIColor colorWithRed:161.0/255.0 green:161.0/255.0 blue:161.0/255.0 alpha:1.0] // #A1A1A1
#define RC_GRAY_600 [UIColor colorWithRed:171.0/255.0 green:171.0/255.0 blue:171.0/255.0 alpha:1.0] // #ABABAB
#define RC_GRAY_400 [UIColor colorWithRed:209.0/255.0 green:209.0/255.0 blue:209.0/255.0 alpha:1.0] // #D1D1D1
#define RC_GRAY_200 [UIColor colorWithRed:231.0/255.0 green:231.0/255.0 blue:231.0/255.0 alpha:1.0] // #E7E7E7
#define RC_GRAY_100 [UIColor colorWithRed:239.0/255.0 green:239.0/255.0 blue:240.0/255.0 alpha:1.0] // #EFEFF0
#define RC_LIST_THREADS_SELECTED_ITEM_BACKGROUND_COLOR [UIColor colorWithRed:217.0/255.0 green:217.0/255.0 blue:217.0/255.0 alpha:1.0] // #D9D9D9

#define DEFAULT_DATE_FORMATTER @"MMMM dd yyyy jj:mm"
#define DEFAULT_DATE_FORMATTER_WITHOUT_YEAR @"MMMM dd jj:mm"

#define RC_DEFAULT_DATE_FONT [UIFont systemFontOfSize:12.0 weight:UIFontWeightSemibold]

#define RC_DEFAULT_CLOSE_FONT [UIFont systemFontOfSize:12.0 weight:UIFontWeightMedium]

static NSString* const DIMELO_DEFAULT_HOSTNAME = @".messaging.dimelo.com";

@class Dimelo;

/*!
 * Posted when `-[Dimelo unreadCount]` property is changed.
 */
extern NSString* const DimeloChatUnreadCountDidChangeNotification;

/*!
 * Posted when `-[Dimelo welcomeMessage]` property is changed.
 */
extern NSString* const DimeloWelcomeMessageDidChangeNotification;

/*!
 * Posted when `-[Dimelo companyMessage]` property is changed.
 */
extern NSString* const RcCompanyMessageDidChangeNotification;

extern NSString* const RcVideoCallRequestDidChangeNotification;

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
 * Note: When the dimelo view is integrated as a fragment and to prevent input accessory view conflict, you should present it in full screen when it's opened from a push notification by calling:
 * if (dimelo.embeddedAsFragment && dimelo.openedFromNotification) {
 *    vc.modalPresentationStyle = UIModalPresentationFullScreen;
 * }
 *
 * @param dimelo An API instance.
 *
 */
- (void)dimeloDisplayChatViewController:(Dimelo *)dimelo;

@optional

/*!
 * Called when a URL is going to be opened by the SDK.
 *
 * @param url   NSURL the URL that is going to be opened.
 *
 * @return `YES`: prevents the Engage Messaging SDK from opening the URL.
 * @return `NO`: let the Engage Messaging SDK open the URL.
 *
 */
- (BOOL)rcShouldDelegateUrlOpening:(NSURL *)url;

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
- (BOOL)dimelo:(Dimelo *)dimelo shouldDisplayNotificationWithText:(NSString *)message;

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
- (void)dimeloDidBeginNetworkActivity:(Dimelo *)dimelo;

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
- (void)dimeloDidEndNetworkActivity:(Dimelo *)dimelo;

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
- (void)dimeloUnreadCountDidChange:(NSNotification *)notification;

/*!
 * Called when `-[Dimelo welcomeMessage]` property changes.
 *
 * Provided as a courtesy so that you do not need to subscribe to notifications separately
 * when handling these events in one delegate is enough for your use case.
 *
 * @param notification   NSNotification with name DimeloWelcomeMessageDidChangeNotification.
 *
 * @see DimeloWelcomeMessageDidChangeNotification
 */
- (void)dimeloWelcomeMessageDidChange:(NSNotification *)notification;

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
- (void)dimeloChatDidSendMessage:(NSNotification *)notification;

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
- (void)dimeloChatDidReceiveNewMessages:(NSNotification *)notification;

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
- (void)dimeloChatWillAppear:(NSNotification *)notification;

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
- (void)dimeloChatDidAppear:(NSNotification *)notification;

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
- (void)dimeloChatWillDisappear:(NSNotification *)notification;

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
- (void)dimeloChatDidDisappear:(NSNotification *)notification;

/*!
 * Called when the chat view is opened (animation completed).
 * @param dimelo   An `Dimelo` API instance.
 */
-(void)onOpen:(Dimelo *)dimelo;

/*!
 * Called when the chat view is closed (animation completed).
 * @param dimelo   An `Dimelo` API instance.
 */
- (void)onClose:(Dimelo *)dimelo;

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
 * // Instantiate dimelo with public api key and an optional hostname.
 * Dimelo* dimelo = [[Dimelo sharedInstance] initWithApiKey:@"public api key" hostname:@"api.example.com" delegate:self];
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
 * // Instantiate dimelo with *secret* api key and an optional hostname.
 * Dimelo* dimelo = [[Dimelo sharedInstance] initWithApiSecret:@"secret api key" hostname:@"api.example.com" delegate:self];
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


typedef NS_ENUM(NSInteger, RcWebViewHeightMode) {
    RC_WEB_VIEW_FULL_MODE = 0,
    RC_WEB_VIEW_TALL_MODE = 1,
    RC_WEB_VIEW_COMPACT_MODE = 2
};

////////////////////////////////////////////////////////////////////////////////
/// Attachments state (retrieval & disabling)
////////////////////////////////////////////////////////////////////////////////

/*!
 * disable state of individual attachment category or all of them
 *
 */
+ (void)disableLibraryAttachment;
+ (void)disablePhotoLibraryAttachment;
+ (void)disableVideoLibraryAttachment;
+ (void)disableDocumentAttachment;
+ (void)disableCameraAttachment;
+ (void)disableLocationAttachment;
+ (void)disableAttachments;

/*!
 * Get state of individual attachment category or all of them
 *
 */
+ (bool)isLibraryAttachmentEnabled;
+ (bool)isPhotoLibraryAttachmentEnabled;
+ (bool)isVideoLibraryAttachmentEnabled;
+ (bool)isDocumentAttachmentEnabled;
+ (bool)isCameraAttachmentEnabled;
+ (bool)isLocationAttachmentEnabled;
+ (bool)isAttachmentsEnabled;

////////////////////////////////////////////////////////////////////////////////
/// @name Setting up an API client
////////////////////////////////////////////////////////////////////////////////


/*!
* Returns a shared API client initialized with config from DimeloConfig.plist
*
* For correct operation you will have to provide a valid signed JWT token via `jwt` property.
* To do so, fill in `userIdentifier`, `authenticationInfo` and send the resulting `jwtDictionary` to your server.
*
* This is a recommended way to access Dimelo API.
*
*/
+ (instancetype)sharedInstance;

/*!
 * Initializes a new API client with a public API key, custom domainName and a delegate for Objective C call.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 * For correct operation you will have to provide a valid signed JWT token via `jwt` property.
 * To do so, fill in `userIdentifier`, `authenticationInfo` and send the resulting `jwtDictionary` to your server.
 *
 * This is a recommended way to access Dimelo API.
 *
 * @param apiKey public hex-encoded API key, typically specific to your app.
 * @param domainName a Dimelo API domainName specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id)initWithApiKey:(NSString *)apiKey domainName:(NSString *)domainName delegate:(id<DimeloDelegate>)delegate NS_SWIFT_UNAVAILABLE("Use initializeWithApiKey:domainName:delegate: instead.") __attribute__((deprecated("initWithApiKey:apiKey domainName:domainName delegate:delegate is deprecated, please use initializeWithToken:token hostname:hostname jwtKeyId:jwtKeyId jwtSecret:jwtSecret delegate:delegate or initializeWithToken:token hostname:hostname delegate:delegate")));

/*!
 * Initializes a new API client with a api API key, custom hostName and a delegate.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 *
 * @param apiKey public hex-encoded API key, typically specific to your app.
 * @param hostName a Dimelo API hostName specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id)initializeWithApiKeyAndHostName:(NSString *)apiKey hostName:(NSString *)hostName delegate:(id<DimeloDelegate>)delegate  __attribute__((deprecated("initializeWithApiKeyAndHostName:apiKey hostName:hostName delegate:delegate is deprecated, please use initializeWithToken:token hostname:hostname jwtKeyId:jwtKeyId jwtSecret:jwtSecret delegate:delegate or initializeWithToken:token hostname:hostname delegate:delegate")));

/*!
 * Initializes a new API client with a public API key, custom domainName and a delegate for Swift call.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 * For correct operation you will have to provide a valid signed JWT token via `jwt` property.
 * To do so, fill in `userIdentifier`, `authenticationInfo` and send the resulting `jwtDictionary` to your server.
 *
 * This is a recommended way to access Dimelo API.
 *
 * @param apiKey public hex-encoded API key, typically specific to your app.
 * @param domainName a Dimelo API domainName specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id)initializeWithApiKey:(NSString *)apiKey domainName:(NSString *)domainName delegate:(id<DimeloDelegate>)delegate __attribute__((deprecated("initializeWithApiKey:apiKey domainName:domainName delegate:delegate is deprecated, please use initializeWithToken:token hostname:hostname jwtKeyId:jwtKeyId jwtSecret:jwtSecret delegate:delegate or initializeWithToken:token hostname:hostname delegate:delegate")));


/*!
 * Initializes a new API client with a secret API key, custom domainName and a delegate for objective C call.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 * This mode is less secure than `-initWithApiKey:domainName:delegate:` because shared secret is stored inside the app.
 *
 * @param apiSecret a hex-encoded API secret key, typically specific to your app.
 * @param domainName a Dimelo API domainName specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id)initWithApiSecret:(NSString *)apiSecret domainName:(NSString *)domainName delegate:(id<DimeloDelegate>)delegate NS_SWIFT_UNAVAILABLE("Use initializeWithApiSecret:domainName:delegate: instead.")  __attribute__((deprecated("initWithApiSecret:apiSecret domainName:domainName delegate:delegate is deprecated, please use initializeWithToken:token hostname:hostname jwtKeyId:jwtKeyId jwtSecret:jwtSecret delegate:delegate or initializeWithToken:token hostname:hostname delegate:delegate")));

/*!
 * Initializes a new API client with a secret API key, custom hostName and a delegate.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 * This mode is less secure than `-initializeWithApiKeyAndHostName:hostName:delegate:` because shared secret is stored inside the app.
 *
 * @param apiSecret a hex-encoded API secret key, typically specific to your app.
 * @param hostName a Dimelo API hostName specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id)initializeWithApiSecretAndHostName:(NSString *)apiSecret hostName:(NSString *)hostName delegate:(id<DimeloDelegate>)delegate __attribute__((deprecated("initializeWithApiSecretAndHostName:apiSecret hostName:hostName delegate:delegate is deprecated, please use initializeWithToken:token hostname:hostname jwtKeyId:jwtKeyId jwtSecret:jwtSecret delegate:delegate or initializeWithToken:token hostname:hostname delegate:delegate")));

/*!
 * Initializes a new API client with a secret API key, custom domainName and a delegate for Swift call.
 *
 * Delegate must not be nil as it is needed to correctly show the chat in various usage scenarios.
 *
 * This mode is less secure than `-initializeWithApiKey:domainName:delegate:` because shared secret is stored inside the app.
 *
 * @param apiSecret a hex-encoded API secret key, typically specific to your app.
 * @param domainName a Dimelo API domainName specific to your app.
 * @param delegate an instance conforming to `DimeloDelegate` protocol.
 *
 */
- (id)initializeWithApiSecret:(NSString *)apiSecret domainName:(NSString *)domainName delegate:(id<DimeloDelegate>)delegate __attribute__((deprecated("initializeWithApiSecret:apiSecret domainName:domainName delegate:delegate is deprecated, please use initializeWithToken:token hostname:hostname jwtKeyId:jwtKeyId jwtSecret:jwtSecret delegate:delegate or initializeWithToken:token hostname:hostname delegate:delegate")));

/*!
 * Per-application API secret key, typically specific to your app.
 *
 * API secret is always represented in hex format, e.g. `@"ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70"`.
 */

- (void)setApiSecret:(NSString *)apiSecret __attribute__((deprecated("setApiSecret:apiSecret is deprecated, please use initWithApiSecret:apiSecret domainName:domainName delegate:delegate")));

/*!
 * Initializes a new instance with a token, hostname, JWT key ID, JWT secret key and a delegate.
 *
 * @param token an Engage Messaging token specific to your app.
 * @param hostname an Engage Messaging hostname specific to your app.
 * @param jwtKeyId an Engage Messaging JWT key ID specific to your app.
 * @param jwtSecret your JWT secret key (should be defined in your RingCX/Engage Digital configuration).
 * @param delegate an instance conforming to the `DimeloDelegate` protocol.
 *
 */
- (id)initializeWithToken:(NSString *)token hostname:(NSString *)hostname jwtKeyId:(NSString *)jwtKeyId jwtSecret:(NSString *)jwtSecret delegate:(id<DimeloDelegate>)delegate;

/*!
 * Initializes a new instance with a token, hostname and a delegate.
 *
 * @param token an Engage Messaging token specific to your app.
 * @param hostname an Engage Messaging hostname specific to your app.
 * @param delegate an instance conforming to the `DimeloDelegate` protocol.
 *
 */
- (id)initializeWithToken:(NSString *)token hostname:(NSString *)hostname delegate:(id<DimeloDelegate>)delegate;

@property (nonatomic, readonly) NSString *domainName;
@property (nonatomic, readonly) NSString *hostName;

/*!
 * Flag to check the opening of the dimelo view from the push notification.
 * Default is `NO`.
 */
@property (nonatomic, readonly) BOOL openedFromNotification;

/*!
 * Delegate object to present a chat view controller and react to various optional notifications.
 *
 * @see DimeloDelegate
 */
@property (nonatomic, weak) id<DimeloDelegate> delegate;

/*!
 * Per-application public API key that identifies all requests to Dimelo.
 *
 * API Key is always represented in hex format, e.g. `@"ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70"`.
 */
@property (nonatomic, copy) NSString *apiKey __attribute__((deprecated("apiKey or setApiKey:apiKey is deprecated, please use initWithApiKey:apiKey domainName:domainName delegate:delegate")));

/*!
 * Per-installation identifier generated when the component is instantiated for the first time within the app.
 */
@property (nonatomic, readonly) NSString *installationIdentifier;

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
@property (nonatomic, copy) NSString *userIdentifier;

/*!
 * Additional fields to be added to the JWT dictionary under "extra" key.
 *
 * You must make sure only PropertyList-compatible items a present inside this dictionary (keys must not be empty, whitespace only or contain the characters "$" or ".").
 */
@property (nonatomic, copy) NSDictionary *authenticationInfo;

/*!
 * Optional name of the person to be sent to Dimelo.
 */
@property (nonatomic, copy) NSString *userName;

@property (nonatomic, copy) NSString *token;

@property (nonatomic, copy) NSString *jwtKeyId;

@property (nonatomic, copy) NSString *jwtSecret;

/*!
 * Complete serialized JWT token.
 *
 * If you use instantiation with public API key and your server signs JWT token, set this property
 * with a JWT provided by your server.
 *
 * If you instantiate `Dimelo` with a secret API key, this property is computed automatically.
 */
@property (nonatomic, copy) NSString *jwt;

/*!
 * JWT dictionary to be signed. Computed out of apiKey, installationIdentifier, userIdentifier, authenticationInfo.
 *
 * Send this dictionary to your app's server to sign with a shared secret corresponding to API key.
 *
 * If you instantiate `Dimelo` with API secret, this dictionary will be used to compute `jwt` property automatically.
 */
@property (nonatomic, readonly) NSDictionary *jwtDictionary;

/*!
 * Arbitrary contextual info attached to a message.
 *
 * Attached only to the first message after a new value was specified.
 *
 * Example: user selects a category of a problem ("Technical" or "Sales")
 * and then contacts the support. First message indicates what type of the problem user is talking about.
 * You must make sure only PropertyList-compatible items a present inside this dictionary (keys must not be empty, whitespace only or contain the characters "$" or ".").
 */
@property (nonatomic, copy) NSDictionary *messageContextInfo;


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
- (void)displayChatView;

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
- (UIViewController *)chatViewController;


////////////////////////////////////////////////////////////////////////////////
/// @name Remote Notifications
////////////////////////////////////////////////////////////////////////////////


/*!
 * Device token for remote notifications. Optional.
 *
 * Override `-application:didRegisterForRemoteNotificationsWithDeviceToken:` and
 * set this property to a provided deviceToken.
 */
@property (nonatomic, copy) NSData *deviceToken;

/*!
 * Flag to tell Dimelo server to send push notifications using development channel.
 *
 * Set this to `YES` in order to receive notifications on development builds.
 * By default, Dimelo server will send notifications to production environment and
 * development builds will not receive such notifications.
 *
 * Default is `NO`.
 */
@property (nonatomic) BOOL developmentAPNS;

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
- (BOOL)consumeReceivedRemoteNotification:(NSDictionary *)dictionary;


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
@property (nonatomic, readonly) NSInteger unreadCount;

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
@property (nonatomic) BOOL updateAppBadgeNumber;

/*!
 * Sends notifications to `NSNotificationCenter` and notifies the delegate about `unreadCount` change. Does not affect the value itself.
 *
 * This method is called automatically when `unreadCount` is changed due to new data received from the server.
 * It may be useful to call it manually when you want to refresh counters after the views are presented without
 * them having explicit references to Dimelo instance (NSNotification `object` will store reference to `Dimelo` instance).
 */
- (void)noteUnreadCountDidChange;

/*!
 * Fetch unreadCount.
 *
 * In case of error completion will be called with NSNotFound value and the corresponding error.
 * Completion is called on main thread.
 *
 * NSErrors of domain DimeloHTTPErrorDomain will mirror the HTTP code from Dimelo backend's response in their own code property.
 * You may want to handle special HTTP code responses like 429 Too many requests for example.
 */
- (void)fetchUnreadCountWithCompletionHandler:(void (^)(NSInteger unreadCount, NSError *error))completion;


////////////////////////////////////////////////////////////////////////////////
/// @name Application language
////////////////////////////////////////////////////////////////////////////////
@property (nonatomic) NSString *language;


////////////////////////////////////////////////////////////////////////////////
/// @name Basic Customization
////////////////////////////////////////////////////////////////////////////////

/*!
 * Color for the webView activity indicator.
 */
@property (nonatomic) UIColor* webViewActivityIndicatorColor;

/*!
 * Color for the webView close image.
 */
@property (nonatomic) UIColor* webViewCloseImageColor;

/*!
 * Color for the create new thread image.
 */
@property (nonatomic) UIColor *createNewThreadImageColor;

/*!
 * Color applied to the button to scroll to the bottom of the conversation image.
 */
@property (nonatomic) UIColor *scrollToBottomImageColor;

/*!
 * Color applied to the video call request button.
 */
@property (nonatomic) UIColor *videoCallRequestButtonColor;

/*!
 * Highlighted Color applied to the video call request button.
 */
@property (nonatomic) UIColor *videoCallRequestButtonHighlightedColor;

/*!
 * Text color for the badge label.
 */
@property (nonatomic) UIColor *badgeTextColor;

/*!
 * Background color for the badge label.
 */
@property (nonatomic) UIColor *badgeBackgroundColor;

/*!
 * Color for the threads list separator.
 */
@property (nonatomic) UIColor *threadsListSeparatorColor;

/*!
 * Tint color for the locked thread image in the threads list view.
 */
@property (nonatomic) UIColor *lockedThreadImageTintColor;

/*!
 * Tint color for the threads list refresh control.
 */
@property (nonatomic) UIColor *threadsListRefreshControlTintColor;

/*!
 * Background color for the create new thread button.
 */
@property (nonatomic) UIColor *createNewThreadBackgroundColor;

/*!
 * Background color applied to the button to scroll to the bottom of the conversation.
 */
@property (nonatomic) UIColor *scrollToBottomBackgroundColor;

/*!
 * Background color for the tapped create new thread button.
 */
@property (nonatomic) UIColor *createNewThreadTappedBackgroundColor;

/*!
 * Background color applied to the button to scroll to the bottom of the conversation when it's tapped.
 */
@property (nonatomic) UIColor *scrollToBottomTappedBackgroundColor;

/*!
 * Background color for the threads list item selection.
 */
@property (nonatomic) UIColor *threadsListBackgroundColorSelection;

/*!
 * Background color for the webView header.
 */
@property (nonatomic) UIColor* webViewHeaderBackgroundColor;

/*!
 * Color applied to the webView body background and the safe area zone background (on portrait and landscape mode).
 */
@property (nonatomic) UIColor* webViewBodyBackgroundColor;

/*!
 * Background color for the threads list company message.
 */
@property (nonatomic) UIColor* threadsListCompanyMessageBackgroundColor;

/*!
 * Text color for the threads list company message title.
 */
@property (nonatomic) UIColor* threadsListCompanyMessageTitleTextColor;

/*!
 * Text color for the threads list company message subtitle.
 */
@property (nonatomic) UIColor* threadsListCompanyMessageSubtitleTextColor;

/*!
 * Text color for the threads list agent name.
 */
@property (nonatomic) UIColor *threadsListAgentNameTextColor;

/*!
 * Text color for the threads list message.
 */
@property (nonatomic) UIColor *threadsListMessageTextColor;

/*!
 * Text color for the threads list date.
 */
@property (nonatomic) UIColor *threadsListDateTextColor;

/*!
 * Text color for each attachment action sheet item button.
 */
@property (nonatomic) UIColor *attachmentActionSheetItemsTextColor;

/*!
 * Text color for the attachment action sheet cancel button.
 */
@property (nonatomic) UIColor *attachmentActionSheetCancelButtonTextColor;

/*!
 * Tint color for aux controls: Close button, Send button, cursor etc.
 */
@property (nonatomic) UIColor *tintColor;

/*!
 * Tint color for cursor: 
 */
@property (nonatomic) UIColor *cursorTintColor;

/*!
 * Tint color for Navigation Item Button embedded in a fragment or a view controller.
 */
@property (nonatomic) UIColor *navigationBarItemTintColor;

/*!
 * Tint color for send Button:
 */
@property (nonatomic) UIColor *sendTintColor;

/*!
 * Bar tint color for navigation bar (sets `barTintColor` property).
 */
@property (nonatomic) UIColor *navigationBarTintColor;

/*!
 * Background color for navigation bar (sets `backgroundColor` property).
 */
@property (nonatomic) UIColor *navigationBarColor;

/*!
 * Icon color for each attachment action sheet icon.
 */
@property (nonatomic) UIColor *attachmentActionSheetItemsIconColor;

/*!
 * Title for the chat.
 *
 * Used only if `titleView` is nil.
 */
@property (nonatomic, copy) NSString *title;

/*!
 * Title view for the chat.
 *
 * If not nil, overrides `title` value.
 */
@property (nonatomic) UIView *titleView;

/*!
 * Background view of the chat.
 *
 * You may customize its backgroundColor or place arbitrary views inside it.
 */
@property (nonatomic, readonly) UIView *backgroundView;

/*!
 * Font for the webView title.
 */
@property (nonatomic) UIFont* webViewTitleFont;

@property (nonatomic) UIFont *userDeletedMessageFont;

/*!
 * Font for the badge label.
 */
@property (nonatomic) UIFont *badgeFont;

/*!
 * Font for the backToAllChats label (in the header fragment).
 */
@property (nonatomic) UIFont *backToAllChatsFont;

/*!
 * Font for user and agent messages.
 */
@property (nonatomic) UIFont *messageFont;

/*!
 * Font for the threads list company message title.
 */
@property (nonatomic) UIFont* threadsListCompanyMessageTitleFont;

/*!
 * Font for the threads list company message subtitle.
 */
@property (nonatomic) UIFont* threadsListCompanyMessageSubtitleFont;

/*!
 * Font for the threads list agent name.
 */
@property (nonatomic) UIFont *threadsListAgentNameFont;

/*!
 * Font for the threads list message.
 */
@property (nonatomic) UIFont *threadsListMessageFont;

/*!
 * Font for the threads list date.
 */
@property (nonatomic) UIFont *threadsListDateFont;

/*!
 * Font for system messages.
 */
@property (nonatomic) UIFont *systemMessageFont;

/*!
 * Foreground color for user's message text.
 */
@property (nonatomic) UIColor *userMessageTextColor;

@property (nonatomic) UIColor *userDeletedMessageTextColor;

/*!
 * Foreground color for agent's message text.
 */
@property (nonatomic) UIColor *agentMessageTextColor;

/*!
 * Text color for welcome's message.
 */
@property (nonatomic) UIColor *welcomeMessageTextColor;

/*!
 * Color for the fragment header.
 */
@property (nonatomic) UIColor *fragmentHeaderColor;

/*!
 * Foreground color for agent's structured message title text.
 */
@property (nonatomic) UIColor *agentStructuredMessageTitleColor;

/*!
 * Border color for quick replies.
 */
@property (nonatomic) UIColor *quickRepliesBorderColor;

/*!
 * Border color for tapped quick replies.
 */
@property (nonatomic) UIColor *quickRepliesTappedBorderColor;

/*!
 * Text color for quick replies.
 */
@property (nonatomic) UIColor *quickRepliesTextColor;

/*!
 * Text color for tapped quick replies.
 */
@property (nonatomic) UIColor *quickRepliesTappedTextColor;

/*!
 * Background color for quick replies.
 */
@property (nonatomic) UIColor *quickRepliesBackgroundColor;

/*!
 * Background color for tapped quick replies.
 */
@property (nonatomic) UIColor *quickRepliesTappedBackgroundColor;

/*!
 * Border width for quick replies.
 */
@property (nonatomic) CGFloat quickRepliesBorderWidth;

/*!
 * Horizontal spacing for quick replies.
 */
@property (nonatomic) CGFloat quickRepliesHorizontalSpacing;

/*!
 * Margin top for structured message subtitle label.
 */
@property (nonatomic) CGFloat agentStructuredMessageSubtitleMarginTop;

/*!
 * Margin top for structured message url label.
 */
@property (nonatomic) CGFloat agentStructuredMessageUrlMarginTop;

/*!
 * Vertical spacing for quick replies.
 */
@property (nonatomic) CGFloat quickRepliesVerticalSpacing;

/*!
 * Foreground color for agent's structured message subtitle text.
 */
@property (nonatomic) UIColor *agentStructuredMessageSubtitleColor;

/*!
 * Foreground color for agent's structured message url text.
 */
@property (nonatomic) UIColor *agentStructuredMessageUrlColor;

/*!
 * Foreground color for agent's structured message item text.
 */
@property (nonatomic) UIColor *agentStructuredMessageItemColor;

/*!
 * Foreground color for agent's structured message tapped item text.
 */
@property (nonatomic) UIColor *agentStructuredMessageItemTappedColor;

/*!
 * Background color for agent's structured message item text.
 */
@property (nonatomic) UIColor *agentStructuredMessageItemBackgroundColor;

/*!
 * Background color for agent's structured message tapped item.
 */
@property (nonatomic) UIColor *agentStructuredMessageItemTappedBackgroundColor;

/*!
 * Foreground color for system notification message text.
 */
@property (nonatomic) UIColor *systemMessageTextColor;

/*!
 * Text color for webView title.
 */
@property (nonatomic) UIColor* webViewTitleTextColor;

/*!
 * Background color for user message bubbles.
 *
 * This color is applied when `userMessageBubbleImage` has template rendering mode (see UIImageRenderingMode).
 * Default image is configured this way.
 */
@property (nonatomic) UIColor *userMessageBackgroundColor;

@property (nonatomic) UIColor *userDeletedMessageBackgroundColor;

@property (nonatomic) UIColor *userSelectedMessageBackgroundColor;

/*!
 * Background color for agent message bubbles.
 *
 * This color is applied when `agentMessageBubbleImage` has template rendering mode (see UIImageRenderingMode).
 * Default image is configured this way.
 */
@property (nonatomic) UIColor *agentMessageBackgroundColor;

/*!
 * Background color for body agent structured message view.
 */
@property (nonatomic) UIColor *agentStructuredMessageBodyBackgroundColor;

/*!
 * Background color for template agent structured message.
 */
@property (nonatomic) UIColor *agentTemplateWithImageBodyBackgroundColor;

/*!
 * Border color for agent structured message bubbles.
 */
@property (nonatomic) UIColor *agentTemplateBorderColor;

/*!
 * Background color for system message bubbles.
 *
 * This color is applied when `systemMessageBubbleImage` has template rendering mode (see UIImageRenderingMode).
 * Default image is configured this way.
 */
@property (nonatomic) UIColor *systemMessageBackgroundColor;

/*!
 * Font for the date label.
 */
@property (nonatomic) UIFont *dateFont;

@property (nonatomic) UIFont* closedThreadMessageTextFont;

@property (nonatomic) UIFont *videoCallRequestedStatusMessageTextFont;

/*!
 * Font for the hour label.
 */
@property (nonatomic) UIFont *hourTimeFont;

/*!
 * Text color for the date label.
 */
@property (nonatomic) UIColor *dateTextColor;

@property (nonatomic) UIColor* closedThreadMessageTextColor;

@property (nonatomic) UIColor *videoCallRequestedStatusMessageTextColor;

/*!
 * Text color for the hour label.
 */
@property (nonatomic) UIColor *hourTimeTextColor;

/*!
 * Date formatter instance used to format the date label.
 */
@property (nonatomic) NSDateFormatter *dateFormatter;

/*!
 * Color for the error icon.
 */
@property (nonatomic) UIColor *errorIconColor;

/*!
 * Font for agent's name.
 */
@property (nonatomic) UIFont *agentNameFont;

/*!
 * Font for agent's time.
 */
@property (nonatomic) UIFont *agentTimeFont;

/*!
 * Font for agent's structured message title.
 */
@property (nonatomic) UIFont *agentStructuredMessageTitleFont;

/*!
 * Font for agent's structured message subtitle.
 */
@property (nonatomic) UIFont *agentStructuredMessageSubTitleFont;

/*!
 * Font for agent's structured message url.
 */
@property (nonatomic) UIFont *agentStructuredMessageUrlFont;

/*!
 * Font for agent's structured message item.
 */
@property (nonatomic) UIFont *agentStructuredMessageItemFont;

/*!
 * Font for navigation bar title.
 */
@property (nonatomic) UIFont *navigationBarTitleFont;

/*!
 * Font for navigation bar item title.
 */
@property (nonatomic) UIFont *navigationBarItemTitleFont;

/*!
 * Text color for agent's name.
 */
@property (nonatomic) UIColor *agentNameColor;

/*!
 * Time color for agent's name.
 */
@property (nonatomic) UIColor *agentTimeColor;

/*!
 * Text color for the button "load more messages".
 *
 * If this property is nil (default), this button is colored using `tintColor`.
 *
 */
@property (nonatomic) UIColor *loadMoreMessagesButtonTextColor;

/*!
 * Color for the button "send" in the disabled state.
 *
 * If this property is nil (default), this button is colored into [UIColor grayColor].
 *
 */
@property (nonatomic) UIColor *disabledSendButtonColor;

/*!
 * Font for the message field input
 *
 * If this property is nil (default), default font is used
 *
 */
@property (nonatomic) UIFont *messageFieldFont;

/*!
 * Default font
 *
 * If this property is nil (default), default system font is used
 *
 */
@property (nonatomic) UIFont *defaultFont;

////////////////////////////////////////////////////////////////////////////////
/// @name Advanced Customization
////////////////////////////////////////////////////////////////////////////////


/*!
 * Insets for agent name label placed under the message bubble.
 *
 * These insets should be in sync with `agentMessageBubbleImage`.
 */
@property (nonatomic) UIEdgeInsets agentNameInsets;

/*!
 * UIImage for webView close button.
 */
@property (nonatomic) UIImage* webViewCloseImage;

/*!
 * UIImage for camera attachment action sheet Icon.
 */
@property (nonatomic) UIImage *attachmentActionSheetCameraIcon;

/*!
 * UIImage for gallery attachment action sheet Icon.
 */
@property (nonatomic) UIImage *attachmentActionSheetGalleryIcon;

/*!
 * UIImage for document attachment action sheet Icon.
 */
@property (nonatomic) UIImage *attachmentActionSheetDocumentIcon;

/*!
 * UIImage for location attachment action sheet Icon.
 */
@property (nonatomic) UIImage *attachmentActionSheetLocationIcon;

/*!
 * UIImage for the create new thread button.
 */
@property (nonatomic) UIImage *createNewThreadImage;

/*!
 * UIImage for the button to scroll to the bottom of the conversation
 */
@property (nonatomic) UIImage *scrollToBottomImage;

/*!
 * UIImage for the back to all chats item (applied for the fragment and the view controller).
 */
@property (nonatomic) UIImage *backToAllChatsItemImage;

/*!
 * UIImage used to represent the button to request a video call.
 */
@property (nonatomic) UIImage *videoCallRequestButtonImage;

/*!
 * UIImage to indicate that the thread is locked in the threads list view.
 */
@property (nonatomic) UIImage *lockedThreadImage;

/*!
 * Resizable (9-part) image to decorate user text bubble.
 *
 * @see userMessageBubbleImage
 */
@property (nonatomic) UIImage *userMessageBubbleImage;

/*!
 * Resizable (9-part) image to decorate agent text bubble.
 *
 * @see agentMessageBubbleInsets
 */
@property (nonatomic) UIImage *agentMessageBubbleImage;

/*!
 * Insets for text in user's message bubble.
 *
 * @see userMessageBubbleImage
 */
@property (nonatomic) UIEdgeInsets userMessageBubbleInsets;

/*!
 * Insets for text in agent's message bubble.
 *
 * @see agentMessageBubbleImage
 */
@property (nonatomic) UIEdgeInsets agentMessageBubbleInsets;

/*!
 * Insets for text in agent's structured message bubble.
 */
@property (nonatomic) UIEdgeInsets agentStructuredMessageBodyInsets;

/*!
 * Insets for quick replies item.
 */
@property (nonatomic) UIEdgeInsets quickRepliesPaddingInsets;

/*!
 * Insets for quick replies.
 */
@property (nonatomic) UIEdgeInsets quickRepliesInsets;

/*!
 * Insets for text in agent's structured message item.
 */
@property (nonatomic) UIEdgeInsets agentStructuredMessageItemInsets;

/*!
 * Insets for text in system message bubble.
 */
@property (nonatomic) UIEdgeInsets systemMessageBubbleInsets;

/*!
 * Resizable (9-part) image to mask user's attachment (alpha channel is used as a mask).
 *
 * By default, the same as `userMessageBubbleImage`.
 *
 * @see userAttachmentBubbleInsets
 */
@property (nonatomic) UIImage *userAttachmentBubbleImage;

/*!
 * Resizable (9-part) image to mask agent's attachment (alpha channel is used as a mask).
 *
 * By default, the same as `agentMessageBubbleImage`.
 *
 * @see agentAttachmentBubbleInsets
 */
@property (nonatomic) UIImage *agentAttachmentBubbleImage;

/*!
 * Resizable (9-part) image to decorate system text bubble.
 *
 * @see systemMessageBubbleInsets
 */
@property (nonatomic) UIImage *systemMessageBubbleImage;

/*!
 * Insets for user's attachment preview bubble.
 *
 * @see userAttachmentBubbleImage
 */
@property (nonatomic) UIEdgeInsets userAttachmentBubbleInsets;

/*!
 * Insets for agent's attachment preview bubble.
 *
 * @see agentAttachmentBubbleImage
 */
@property (nonatomic) UIEdgeInsets agentAttachmentBubbleInsets;

/*!
* Insets for file name and size label (inside the agent message bubble).
*
*/
@property (nonatomic) UIEdgeInsets agentAttachmentTitleInsets;

/*!
*  Insets for file name and size label (inside the user message bubble).
*
*/
@property (nonatomic) UIEdgeInsets userAttachmentTitleInsets;

/*!
 * Bar tint color of the input bar.
 */
@property (nonatomic) UIColor *inputBarTintColor;

/*!
 * Background color of the input bar.
 */
@property (nonatomic) UIColor *inputBarBackgroundColor;

/*!
 * Icon to be displayed on "attach" button in the input bar.
 */
@property (nonatomic) UIImage *attachmentIcon;

/*!
 * Keyboard appearance for a system keyboard.
 *
 * Default is `UIKeyboardAppearanceDefault`.
 */
@property (nonatomic) UIKeyboardAppearance keyboardAppearance;

/*!
 * sdk version.
 */
@property (nonatomic) NSString *sdkVersion;

/*!
 * navigation bar title color.
 */
@property (nonatomic) UIColor *navigationBarTitleColor;

/*!
 * Flag to set the notification interactive or not when Category key is present in the aps.
 * Default is `NO`.
 */
@property (nonatomic) BOOL interactiveNotification;

/*!
 * Flag to set to embed or not the Dimelo view as a fragment.
 * Default is `NO`.
 */
@property (nonatomic) BOOL embeddedAsFragment;

/*!
 * Flag to enable/disable the button to scroll to the bottom of the conversation.
 * Default is `NO`.
 */
@property (nonatomic) BOOL showScrollToBottomButton;

/*!
 * Flag to set to disable reception of the push notification
 * Default is `NO`.
 */
@property (nonatomic) BOOL disableNotification;

@property (nonatomic) BOOL enableLightStatusBarStyle;

@property (nonatomic) BOOL showAgentAvatarImage;

/*!
* Flag to set to enable/disable threads
* Default is `NO`.
*/
@property (nonatomic) BOOL enableThreads;

/*!
* Flag to set to display/hide attachment action sheet icons
* Default is `YES`.
*/
@property (nonatomic) BOOL displayAttachmentActionSheetIcons;

/*!
 * Called when reply notification is called.
 *
 * @param identifier   NSString this is the handleActionWithIdentifier identifier parameter (ACTION_SEND)
 * @param responseInfo   NSDictionary this is the handleActionWithIdentifier withResponseInfo parameter
 */
- (void)handleRemoteNotificationWithIdentifier:(NSString *)identifier responseInfo:(NSDictionary *)responseInfo __attribute((deprecated("Please use (BOOL)handleRemoteNotificationWithIdentifier:(NSString *)identifier responseInfo:(NSDictionary *)responseInfo userInfo:(NSDictionary *)userInfo; instead")));
- (BOOL)handleRemoteNotificationWithIdentifier:(NSString *)identifier responseInfo:(NSDictionary *)responseInfo userInfo:(NSDictionary *)userInfo;

////////////////////////////////////////////////////////////////////////////////
/// @name API to send a customer message
////////////////////////////////////////////////////////////////////////////////

/*!
 * Called to send a customer message
 *
 * @param messageText   NSString this is the message content
 */
- (void)sendMessage:(NSString *)messageText;

- (NSString *)getDimeloDefaultHostName;

- (BOOL)consumeNotificationResponse:(UNNotificationResponse *)response;
- (BOOL)presentRingCentralNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler;

/*!
 * Called to open a webView
 *
 * @param url   NSURL this is the url to open
 * @param heightMode   RcWebViewHeightMode this is the webview height (must be RcWebViewHeightMode enum value: RC_WEB_VIEW_FULL_MODE, RC_WEB_VIEW_COMPACT_MODE or RC_WEB_VIEW_TALL_MODE. Default is RC_WEB_VIEW_FULL_MODE)
 */
- (void)openWebView:(NSURL *)url heightMode:(RcWebViewHeightMode)heightMode;
@end


