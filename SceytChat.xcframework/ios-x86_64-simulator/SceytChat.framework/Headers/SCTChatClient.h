//
//  SCTChatClient.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTUser;
@class SCTSettings;
@protocol SCTChannelDelegate;
@protocol SCTChatClientDelegate;

NS_SWIFT_NAME(ChatClient)
@interface SCTChatClient : NSObject

#if DEBUG
- (instancetype)initOnce;
+ (void)setActiveClient:(SCTChatClient *)client;
- (void)releaseInstance
NS_SWIFT_NAME(release());
#else

#endif

/// Gets a singleton instance of `SCTChatClient`.
@property (class, nonatomic, readonly, nonnull) SCTChatClient *sharedInstance
NS_SWIFT_NAME(shared);

///  The settings. The object is valid when the connection succeed.
@property (nonatomic, readonly) SCTSettings *settings;

///  The current user object. The object is valid when the connection succeed.
@property (nonatomic, readonly) SCTUser *user;

/// The Application unique id.
@property (nonatomic, readonly, nullable) NSString *appId;

/// The access token with which the user was authenticated.
@property (nonatomic, readonly, nullable) NSString *authToken;

/// The client id with which the user was connected.
@property (nonatomic, readonly, nullable) NSString *clientId;

/// The client connection url
@property (nonatomic, readonly, nullable) NSURL *connectUrl;

/// The client connection status.
@property (nonatomic, readonly) SCTConnectStatus connectStatus;

/// Set YES for auto send 'delivered' for received message.
@property(nonatomic) BOOL enableAutoSendMessageStatusDelivered;

/// Sets the timeout for connection.
/// @note The default value is 10 seconds.
@property (class, nonatomic) NSUInteger connectionTimeout;

/// Sets the timeout for file transfer.
/// @note The default value is 60 seconds.
@property (class, nonatomic) NSUInteger fileTransferTimeout;

/// Turns on or off the reconnection by network awareness.
/// If YES, the reconnection by network Awareness is turned.
/// @note default value YES.
@property (class, nonatomic) BOOL enableNetworkAwarenessReconnection;

/// init is unavailable. Use `[SCTChatClient sharedInstance]` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Setup `SCTChatClient` singleton instance with API URL.  This method has to be run first in order to use SceytChat.
/// @param url The API region url.
/// @param appId The Application unique id.
/// @param clientId The current user unique id.
+ (BOOL)setupWithAPIUrl:(nonnull NSString *)url appId:(nonnull NSString *)appId clientId:(nullable NSString *)clientId
NS_SWIFT_NAME(setup(apiUrl:appId:clientId:));

/// Set the SDK log level.
/// @param level The log level.
+ (void)setLogLevel:(SCTLogLevel)level;

/// Add the SCTChatClientDelegate.
/// @param delegate SCTChatClientDelegate delegate.
/// @param identifier The identifier for the delegate.
- (void)addDelegate:(nonnull __weak id<SCTChatClientDelegate>)delegate identifier:(nullable NSString *)identifier
NS_SWIFT_NAME(add(delegate:identifier:));

/// Get the delegate for client by identifier.
/// @param identifier The identifier for the delegate.
- (nullable id<SCTChatClientDelegate>)delegateWithIdentifier:(nullable NSString *)identifier
NS_SWIFT_NAME(delegate(identifier:));

/// Remove the client delegate by identifier.
/// @param identifier The identifier for the delegate.
- (void)removeDelegateWithIdentifier:(nullable NSString *)identifier
NS_SWIFT_NAME(removeDelegate(identifier:));

/// Remove all client delegates.
- (void)removeAllDelegates
NS_SWIFT_NAME(removeAllDelegates());

/// Get all registered client delegates.
- (NSDictionary<NSString *, id<SCTChatClientDelegate>> * _Nonnull)delegates
NS_SWIFT_NAME(delegates());

/// Add the SCTChannelDelegate.
/// @param delegate SCTChannelDelegate delegate.
/// @param identifier The identifier for the delegate.
- (void)addChannelDelegate:(nonnull __weak id<SCTChannelDelegate>)delegate identifier:(nullable NSString *)identifier
NS_SWIFT_NAME(add(channelDelegate:identifier:));

/// Get the delegate for channels by identifier.
/// @param identifier The identifier for the delegate.
- (nullable id<SCTChannelDelegate>)channelDelegateWithIdentifier:(nullable NSString *)identifier
NS_SWIFT_NAME(channelDelegate(identifier:));

/// Remove the channels delegate by identifier.
/// @param identifier The identifier for the delegate.
- (void)removeChannelDelegateWithIdentifier:(nullable NSString *)identifier
NS_SWIFT_NAME(removeChannelDelegate(identifier:));

/// Remove all channels delegates.
- (void)removeAllChannelDelegates
NS_SWIFT_NAME(removeAllChannelDelegates());

/// Get all registered channel delegates.
- (NSDictionary<NSString *, id<SCTChannelDelegate>> * _Nonnull)channelDelegates
NS_SWIFT_NAME(channelDelegates());

/// Sets dispatch queue for every completion handler.
/// @param queue Dispatch queue for every completion handler.
/// @note Default queue is the main queue.
+ (void)setCompletionHandlerQueue:(nullable dispatch_queue_t)queue
NS_SWIFT_NAME(setCompletionHandler(queue:));

/// Sets dispatch queue for every delegate.
/// @param queue Dispatch queue for every delegate.
/// @note Default queue is the main queue.
+ (void)setDelegateQueue:(nullable dispatch_queue_t)queue
NS_SWIFT_NAME(setDelegate(queue:));

/// Connect with authentication token.
/// @param token JSON Web token (JWT).
/// @param completion Success if error is null.
- (void)connectWithToken:(nonnull NSString *)token completion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(connect(token:completion:));

/// Update token till expire existing token.
/// @param token JSON Web token (JWT).
/// @param completion Success if error is null.
- (void)updateToken:(nonnull NSString *)token completion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(update(token:completion:));

/// Update current user information.
/// @param firstName the  given name.
/// @param lastName the hereditary family name.
/// @param avatarUrl profile avatar url.
/// @param completion The handler block to execute.
- (void)setUserProfileWithFirstName:(nullable NSString *)firstName lastName:(nullable NSString *)lastName avatarUrl:(nullable NSURL *)avatarUrl metadata:(nullable NSString *)metadata completion:(SCTUserProfileCompletion)completion
NS_SWIFT_NAME(setProfile(firstName:lastName:avatarUrl:metadata:completion:));

/// Get users with user ids.
/// @param ids user ids.
/// @param completion The handler block to execute.
- (void)getUsersWithIds:(nonnull NSArray<SCTUserId> *)ids completion:(nonnull SCTGetUsersCompletion)completion
NS_SWIFT_NAME(getUsers(ids:completion:));

/// Block the users by ids.
/// @param ids The users ids to be blocked.
/// @param completion The handler block to execute.
- (void)blockUsersWithIds:(nonnull NSArray<SCTUserId> *)ids completion:(nonnull SCTGetUsersCompletion)completion
NS_SWIFT_NAME(blockUsers(ids:completion:));

/// Unblock the users by ids.
/// @param ids The users ids to be unblocked.
/// @param completion The handler block to execute.
- (void)unblockUsersWithIds:(nonnull NSArray<SCTUserId> *)ids completion:(nonnull SCTGetUsersCompletion)completion
NS_SWIFT_NAME(unblockUsers(ids:completion:));

/// Upload any file and get url.
/// @param fileUrl local file url.
/// @param progressHandler upload progress handler.
/// @param completion upload completion handler.
- (void)uploadFile:(nonnull NSURL *)fileUrl progressHandler:(nonnull SCTProgressCompletion)progressHandler completion:(nonnull SCTFileCompletion)completion
NS_SWIFT_NAME(upload(fileUrl:progressHandler:completion:));

/// Get channel member roles defined for the App.
/// @param completion The handler block to execute.
- (void)getRoles:(nonnull SCTGetRolesCompletion)completion
NS_SWIFT_NAME(getRoles(completion:));

/// Get total unreads: unread channels count and unread messages  count.
/// @param completion The handler block to execute.
- (void)getTotalUnreads:(nonnull SCTGetUnreadsCompletion)completion
NS_SWIFT_NAME(getTotalUnreads(completion:));

/// Get Channel by id.
/// @param channelId channel id.
/// @param completion The handler block to execute.
- (void)getChannelWithId:(SCTChannelId)channelId completion:(nonnull SCTChannelCompletion)completion
NS_SWIFT_NAME(getChannel(id:completion:));

/// Mute the current user for time interval.
/// @param timeInterval The current user mute time interval.  0 for mute forever.
/// @param completion The handler block to execute.
- (void)muteTimeInterval:(NSTimeInterval)timeInterval completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(mute(timeInterval:completion:));

/// Unmute the current user.
/// @param completion The handler block to execute.
- (void)unmuteWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(unmute(completion:));

/// Register the current device remote notifications token.
/// @param deviceToken  Device token for PushKit which usually comes from `didRegisterForRemoteNotificationsWithDeviceToken`.
/// @param completion  Success if error is null.
- (void)registerDevicePushToken:(nonnull NSData *)deviceToken completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(registerDevicePushToken(_:completion:));

/// Unregister the registered the current device remote notifications token.
/// @param completion Success if error is null.
- (void)unregisterDevicePushTokenWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(unregisterDevicePushToken(completion:));

/// Disconnect the client.
- (void)disconnect
NS_SWIFT_NAME(disconnect());

@end

NS_ASSUME_NONNULL_END
