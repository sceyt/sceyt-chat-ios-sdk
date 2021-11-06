//
//  SCTChannel.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTError;
@class SCTMessage;
@class SCTMember;

NS_SWIFT_NAME(Channel)
@interface SCTChannel : NSObject

/// The channel unique identifier.
@property (nonatomic, readonly) SCTChannelId id;

/// The channel creation date.
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

/// The channel last update date.
@property (nonatomic, readonly, nullable) NSDate *updatedAt;

/// Number of unread messages of the channel.
@property (nonatomic, readonly) NSUInteger unreadMessageCount;

/// The last read message id for the current user.
@property (nonatomic, readonly) SCTMessageId lastReadMessageId;

/// The last delivered message id for the current user.
@property (nonatomic, readonly) SCTMessageId lastDeliveredMessageId;

/// Last message of the channel.
@property (nonatomic, readonly, nullable) SCTMessage *lastMessage;

/// Number of members of the channel.
@property (nonatomic, readonly) NSUInteger memberCount;

/// Shows is channel market as unread from the current user.
@property (nonatomic, readonly) BOOL markedAsUnread;

/// Shows is channel muted from the current user.
@property (nonatomic, readonly) BOOL muted;

/// Shows channel mute expire date (nil for forever) if channel muted otherwise nil.
@property (nonatomic, readonly, nullable) NSDate *muteExpireDate;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Deletes the channel.. The user has to be an owner or should have a permission.
/// @param completion The handler block to execute.
- (void)deleteWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(delete(completion:));

/// Clear message history from channel only for current user.
/// @param completion The handler block to execute.
- (void)clearHistoryWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(clearHistory(completion:));

/// Hide the channel. After hide the channel will not visible in current user channels list.
/// @param completion The handler block to execute.
- (void)hideWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(hide(completion:));

/// Unhide the  channel.
/// @param completion The handler block to execute.
- (void)unhideWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(unhide(completion:));

/// Mark channel as unread for current user.
/// @param completion The handler block to execute.
- (void)markAsUnreadWithCompletion:(nullable SCTChannelCompletion)completion
NS_SWIFT_NAME(markAsUnread(completion:));

/// Mute the channel for time interval.
/// @param timeInterval The channel mute time interval.  0 for mute forever.
/// @param completion The handler block to execute.
- (void)muteTimeInterval:(NSTimeInterval)timeInterval completion:(nullable SCTChannelCompletion)completion
NS_SWIFT_NAME(mute(timeInterval:completion:));

/// Unmute the muted  channel.
/// @param completion The handler block to execute.
- (void)unmuteWithCompletion:(nullable SCTChannelCompletion)completion
NS_SWIFT_NAME(unmute(completion:));

/// Mark all messages as delivered on this channel.
- (void)markAllMessagesAsDelivered
NS_SWIFT_NAME(markAllMessagesAsDelivered());

/// Mark all messages as read on this channel.
- (void)markAllMessagesAsRead
NS_SWIFT_NAME(markAllMessagesAsRead());

/// Send start typing message.
- (void)startTyping
NS_SWIFT_NAME(startTyping());

/// Send stop typing message.
- (void)stopTyping
NS_SWIFT_NAME(stopTyping());

/// Send a message.
/// @param message The message which will be send.
/// @param completion The handler block to execute.
- (nonnull SCTMessage *)sendMessage:(nonnull SCTMessage *)message completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(sendMessage(_:completion:));

/// Edit the message.
/// @param message The message which will be edited.
/// @param completion The handler block to execute.
- (void)editMessage:(nonnull SCTMessage *)message completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(editMessage(_:completion:));

/// Resend the failed message.
/// @param failedMessage The message which will be resend.
/// @param completion The handler block to execute.
- (void)resendMessage:(nonnull SCTMessage *)failedMessage completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(resendMessage(_:completion:));

/// Delete the message.
/// @param messageId The message id which will be deleted.
/// @param completion The handler block to execute.
- (void)deleteMessageWithId:(SCTMessageId)messageId completion:(SCTMessageCompletion)completion;

/// Delete the message.
/// @param message The message which will be deleted.
/// @param completion The handler block to execute.
- (void)deleteMessage:(nonnull SCTMessage *)message completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(deleteMessage(_:completion:));

/// Add reaction to the message.
/// @param messageId  Id of the message to which the reaction will be added.
/// @param key The reaction key: any short string or emoji.
/// @param score number of reactions.
/// @param reason The reaction extra data.
/// @param enforceUnique If set to YES, new reaction will replace all reactions the user has (if any) on this message.
/// @param completion The handler block to execute.
- (void)addReactionWithMessageId:(SCTMessageId)messageId
                             key:(nonnull NSString *)key
                           score:(UInt16)score
                          reason:(nullable NSString *)reason
                   enforceUnique:(BOOL)enforceUnique
                      completion:(nonnull SCTReactionCompletion)completion
NS_SWIFT_NAME(addReaction(messageId:key:score:reason:enforceUnique:completion:));

/// Delete reaction from the message.
/// @param messageId Id of the message to which the reaction will be deleted.
/// @param key The reaction key.
/// @param completion The handler block to execute.
- (void)deleteReactionWithMessageId:(SCTMessageId)messageId key:(nonnull NSString *)key completion:(SCTReactionCompletion)completion
NS_SWIFT_NAME(deleteReaction(messageId:key:completion:));

@end

NS_ASSUME_NONNULL_END
