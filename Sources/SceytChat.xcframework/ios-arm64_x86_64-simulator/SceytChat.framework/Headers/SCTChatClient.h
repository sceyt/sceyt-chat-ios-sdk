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
@class SCTUserSettings;
@class SCTPresence;
@class SCTContact;
@class SCTContactDiscovery;
@protocol SCTChannelDelegate;
@protocol SCTChatClientDelegate;

NS_SWIFT_NAME(ChatClient)
@interface SCTChatClient : NSObject

/// The shared singleton instance of `SCTChatClient`.
@property (class, nonatomic, readonly, nonnull) SCTChatClient *sharedInstance
NS_SWIFT_NAME(shared);

/// The current user. Updated after successful `SCTChatClient` connect.
@property (nonatomic, readonly, nonnull) SCTUser *user;

/// The current user settings. Updated after successful `SCTChatClient` connect.
@property (nonatomic, readonly, nonnull) SCTSettings *settings;

/// The application id.
@property (nonatomic, readonly, nullable) NSString *appId;

/// The access token with which the current user was connected.
@property (nonatomic, readonly, nullable) NSString *accessToken;

/// The unique client id associated with the device.
@property (nonatomic, readonly, nullable) NSString *clientId;

/// The API  url.
@property (nonatomic, readonly, nullable) NSURL *apiUrl;

/// The client connection state.
@property (nonatomic, readonly) SCTConnectionState connectionState;

/// Set YES to automatically send ‘received’ receipt while getting incoming messages.
@property (nonatomic) BOOL autoSendMessageStatusReceived;

/// Sets a timeout on the connection. Defaults to 10 seconds.
@property (class, nonatomic) NSUInteger connectionTimeout;

/// Sets a timeout on the file transfer. Defaults to 60 seconds.
@property (class, nonatomic) NSUInteger fileTransferTimeout;

/// Enables automatic reconnection on network change events. Defaults to YES.
@property (class, nonatomic) BOOL networkAwareReconnection;

/// init is unavailable. Use `[SCTChatClient sharedInstance]` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Initializes `SCTChatClient` singleton instance. This must be called first before using any other method of `SceytChat`.
/// @param url The API URL with which to connect.
/// @param appId The application unique id.
/// @param clientId The current user unique id associated with the device.
+ (BOOL)initializeWithApiUrl:(nonnull NSString *)url appId:(nonnull NSString *)appId clientId:(nullable NSString *)clientId
NS_SWIFT_NAME(initialize(apiUrl:appId:clientId:));

/// Sets the SDK log level.
/// @param level The log level.
+ (void)setLogLevel:(SCTLogLevel)level;

/// Adds a `SCTChatClientDelegate`.
/// @param delegate `SCTChatClientDelegate` delegate.
/// @param identifier The identifier of the delegate.
- (void)addDelegate:(nonnull __weak id<SCTChatClientDelegate>)delegate identifier:(nonnull NSString *)identifier
NS_SWIFT_NAME(add(delegate:identifier:));

/// Gets the `SCTChatClientDelegate` by identifier.
/// @param identifier The delegate identifier.
- (nullable id<SCTChatClientDelegate>)delegateWithIdentifier:(nonnull NSString *)identifier
NS_SWIFT_NAME(delegate(identifier:));

/// Gets all registered delegates of `SCTChatClientDelegate`.
- (NSDictionary<NSString *, id<SCTChatClientDelegate>> * _Nonnull)delegates
NS_SWIFT_NAME(delegates());

/// Removes the `SCTChatClientDelegate` by identifier.
/// @param identifier The delegate identifier.
- (void)removeDelegateWithIdentifier:(nonnull NSString *)identifier
NS_SWIFT_NAME(removeDelegate(identifier:));

/// Removes all registered delegates of `SCTChatClientDelegate`.
- (void)removeAllDelegates
NS_SWIFT_NAME(removeAllDelegates());

/// Adds a `SCTChannelDelegate`.
/// @param delegate `SCTChannelDelegate` delegate.
/// @param identifier The delegate identifier.
- (void)addChannelDelegate:(nonnull __weak id<SCTChannelDelegate>)delegate identifier:(nonnull NSString *)identifier
NS_SWIFT_NAME(add(channelDelegate:identifier:));

/// Gets the `SCTChannelDelegate` by identifier.
/// @param identifier The delegate identifier.
- (nullable id<SCTChannelDelegate>)channelDelegateWithIdentifier:(nonnull NSString *)identifier
NS_SWIFT_NAME(channelDelegate(identifier:));

/// Gets all registered delegates of `SCTChatClientDelegate`.
- (NSDictionary<NSString *, id<SCTChannelDelegate>> * _Nonnull)channelDelegates
NS_SWIFT_NAME(channelDelegates());

/// Removes the `SCTChannelDelegate` by identifier.
/// @param identifier The delegate identifier.
- (void)removeChannelDelegateWithIdentifier:(nonnull NSString *)identifier
NS_SWIFT_NAME(removeChannelDelegate(identifier:));

/// Removes all registered delegates of `SCTChannelDelegate`.
- (void)removeAllChannelDelegates
NS_SWIFT_NAME(removeAllChannelDelegates());

/// Sets a dispatch queue where to perform all the completion handlers.
/// @param queue A dispatch queue. Defaults to main queue.
+ (void)setCompletionHandlerQueue:(nullable dispatch_queue_t)queue
NS_SWIFT_NAME(setCompletionHandler(queue:));

/// Sets a dispatch queue where to perform all the delegates.
/// @param queue A dispatch queue. Defaults to main queue.
+ (void)setDelegateQueue:(nullable dispatch_queue_t)queue
NS_SWIFT_NAME(setDelegate(queue:));

/// Connects to the API with a given access token. This has to be called right after `initializeWithApiUrl:appId:clientId`.
/// @param token An access token issued for the current user.
- (void)connectWithToken:(nonnull NSString *)token
NS_SWIFT_NAME(connect(token:));

/// Reconnects to the API if the connection was previously disconnected.
/// @returns YES if the reconnection succeeds; otherwise, NO.
- (BOOL)reconnect
NS_SWIFT_NAME(reconnect());

/// Disconnects from the API.
- (void)disconnect
NS_SWIFT_NAME(disconnect());

/// Updates the access token to extend the connection before the current token expires.
/// @param token  An access token issued for the current user.
/// @param completion The completion handler to call after execution.
- (void)updateToken:(nonnull NSString *)token completion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(update(token:completion:));

/// Updates the current user profile.
/// @param firstName The first name.
/// @param lastName The last name.
/// @param avatarUrl The avatar url.
/// @param completion The completion handler to call after execution.
- (void)setUserProfileWithFirstName:(nullable NSString *)firstName lastName:(nullable NSString *)lastName avatarUrl:(nullable NSURL *)avatarUrl metadata:(nullable NSString *)metadata completion:(SCTUserProfileCompletion)completion
NS_SWIFT_NAME(setProfile(firstName:lastName:avatarUrl:metadata:completion:));

/// Sets the current user presence.
/// @param state The presence state.
/// @param status The presence status.
/// @param completion The completion handler to call after execution.
- (void)setPresenceState:(SCTPresenceState)state status:(nullable NSString *)status completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(setPresence(state:status:completion:));

- (void)updateUserSettings:(SCTUserSettings*)userSettings completion:(nullable SCTCompletion)completion;
- (void)getUserSettings:(nonnull SCTUserSettingsCompletion)completion;

/// Gets users with given user ids.
/// @param ids The user ids to get.
/// @param completion The completion handler to call after execution.
- (void)getUsersWithIds:(nonnull NSArray<SCTUserId> *)ids completion:(nonnull SCTGetUsersCompletion)completion
NS_SWIFT_NAME(getUsers(ids:completion:));

/// Blocks users with given user ids.
/// @param ids The user ids to block.
/// @param completion The completion handler to call after execution.
- (void)blockUsersWithIds:(nonnull NSArray<SCTUserId> *)ids completion:(nonnull SCTGetUsersCompletion)completion
NS_SWIFT_NAME(blockUsers(ids:completion:));

/// Unblocks users with given user ids.
/// @param ids The user ids to unblock.
/// @param completion The completion handler to call after execution.
- (void)unblockUsersWithIds:(nonnull NSArray<SCTUserId> *)ids completion:(nonnull SCTGetUsersCompletion)completion
NS_SWIFT_NAME(unblockUsers(ids:completion:));

/// Uploads a file from the local storage.
/// @param fileUrl The file URL on the location.
/// @param progressHandler The upload progress handler.
/// @param completion The completion handler to call after execution.
- (void)uploadFile:(nonnull NSURL *)fileUrl progressHandler:(nonnull SCTProgressCompletion)progressHandler completion:(nonnull SCTFileCompletion)completion
NS_SWIFT_NAME(upload(fileUrl:progressHandler:completion:));

/// Gets channel member roles associated with the Application.
/// @param completion The completion handler to call after execution.
- (void)getRoles:(nonnull SCTGetRolesCompletion)completion
NS_SWIFT_NAME(getRoles(completion:));

/// Gets the total unread count of channels and messages.
/// @param completion The completion handler to call after execution.
- (void)getTotalUnreadCount:(nonnull SCTGetUnreadCountCompletion)completion
NS_SWIFT_NAME(getTotalUnreadCount(completion:));

/// Gets the channel with given id.
/// @param channelId The channel id.
/// @param completion The completion handler to call after execution.
- (void)getChannelWithId:(SCTChannelId)channelId completion:(nonnull SCTChannelCompletion)completion
NS_SWIFT_NAME(getChannel(id:completion:));

/// Registers the current device to receive remote notifications.
/// @param deviceToken A globally unique token that identifies this device to APNs.
/// @param completion The completion handler to call after execution.
- (void)registerDevicePushToken:(nonnull NSData *)deviceToken completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(registerDevicePushToken(_:completion:));

/// Unregisters the current device to stop receiving remote notifications.
/// @param completion The completion handler to call after execution.
- (void)unregisterDevicePushTokenWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(unregisterDevicePushToken(completion:));

/// Registers the current device to receive Voice-over-IP (VoIP) call invitations.
/// @param voipToken A globally unique token that identifies this device to APNs.
/// @param completion The completion handler to call after execution.
- (void)registerVoIPToken:(NSData *)voipToken completion:(SCTCompletion)completion
NS_SWIFT_NAME(registerVoIPToken(_:completion:));

/// Unregisters the current device to stop receiving Voice-over-IP (VoIP) call invitations.
/// @param completion The completion handler to call after execution.
- (void)unregisterVoIPTokenWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(unregisterVoIPToken(completion:));

/// Mutes the current user's remote notifications for given period.
/// @param timeInterval The mute time interval.  Set 0 to mute forever.
/// @param completion The completion handler to call after execution.
- (void)muteTimeInterval:(NSTimeInterval)timeInterval completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(mute(timeInterval:completion:));

/// Unmutes the current user's remote notifications.
/// @param completion The completion handler to call after execution.
- (void)unmuteWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(unmute(completion:));

/// Reports the channel for moderation. Only group channels can be reported with this method.
/// @param channelId The channel id to report.
/// @param messageIds Optional message ids to add to the report.
/// @param report The report name.
/// @param description Optional description to add to the report.
/// @param completion The completion handler to call after execution.
- (void)reportChannel:(SCTChannelId)channelId messageIds:(nullable NSArray<NSNumber*> *)messageIds report:(nonnull NSString *)report description:(nullable NSString *)description completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(reportChannel(id:messageIds:report:description:completion:));

/// Reports messages for moderation. Only messages from group channels can be reported with this method.
/// @param messageIds The Message ids to report.
/// @param channelId The channel id from where the messages are reported.
/// @param report The report name.
/// @param description Optional description to add to the report.
/// @param completion The completion handler to call after execution.
- (void)reportMessages:(nonnull NSArray<NSNumber*> *)messageIds channelId:(SCTChannelId)channelId report:(nonnull NSString *)report description:(nullable NSString *)description completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(reportMessages(ids:channelId:report:description:completion:));

/// Reports a user for moderation. The remote peer of a Direct channel can be reported with this method.
/// @param userId The user id to report.
/// @param messageIds Optional message ids to add to the report.
/// @param report The report name.
/// @param description Optional description to add to the report.
/// @param completion The completion handler to call after execution.
- (void)reportUser:(nonnull SCTUserId)userId messageIds:(nullable NSArray<NSNumber*> *)messageIds report:(nonnull NSString *)report description:(nullable NSString *)description completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(reportUser(id:messageIds:report:description:completion:));


/// Send a direct message.to a user
/// @param message The message which will be send.
/// @param userId The user id
/// @param completion The handler block to execute.
+ (nonnull SCTMessage *)sendMessage:(nonnull SCTMessage *)message toUser:(SCTUserId)userId completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(sendMessage(_:to:completion:));


- (void)addContactDiscoveries:(NSArray<SCTContactDiscovery*>*)contactDiscoveries completion:(nullable SCTContactsDiscoveryCompletion)completion
NS_SWIFT_NAME(addContactDiscoveries(_:completion:));
- (void)getAllContactDiscoveriesWithCompletion:(nullable SCTContactsDiscoveryCompletion)completion
NS_SWIFT_NAME(getAllContactDiscoveries(completion:));

- (void)deleteContactDiscoveriesWithKeys:(NSArray<NSString*>*)discoveryKeys completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(deleteContactDiscoveries(keys:completion:));
- (void)deleteAllContactDiscoveriesWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(deleteAllContactDiscoveries(completion:));

- (void)addContacts:(NSArray<SCTContact*>*)contacts completion:(nullable SCTContactsCompletion)completion
NS_SWIFT_NAME(addContacts(_:completion:));
- (void)getAllContactsWithCompletion:(nullable SCTContactsCompletion)completion
NS_SWIFT_NAME(getAllContacts(completion:));

- (void)deleteContactsWithIds:(NSArray<SCTContactId>*)ids completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(deleteContacts(ids:completion:));
- (void)deleteAllContactsWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(deleteAllContacts(completion:));

@end

NS_ASSUME_NONNULL_END
