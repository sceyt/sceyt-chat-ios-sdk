//
//  SCTChannelOperator.h
//  SceytChat
//
//  Created by Hovsep on 8/23/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ChannelOperator)
@interface SCTChannelOperator : NSObject

/// The channel unique identifier.
@property (nonatomic, readonly) SCTChannelId channelId;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// default init
/// @param channelId The operating channel id
- (instancetype)initWithChannelId:(SCTChannelId)channelId;

/// Deletes the channel. The user has to be an owner or should have a permission.
/// @param completion The handler block to execute.
- (void)deleteWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(delete(completion:));

/// Clear message history from channel only for current user.
/// @param completion The handler block to execute.
- (void)clearHistoryWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(clearHistory(completion:));

/// Delete all messages from channel only for all user.
/// @param completion The handler block to execute.
- (void)deleteAllMessagesWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(deleteAllMessages(completion:));

/// Hide the channel. After hide the channel will not visible in current user channels list.
/// @param completion The handler block to execute.
- (void)hideWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(hide(completion:));

/// Unhide the  channel.
/// @param completion The handler block to execute.
- (void)unhideWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(unhide(completion:));

/// Mark channel as read for current user.
/// @param completion The handler block to execute.
- (void)markAsReadWithCompletion:(nullable SCTChannelCompletion)completion
NS_SWIFT_NAME(markAsRead(completion:));

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

/// Mark messages as delivered on this channel.
/// @param messageIds the `SCTMessageId` list.
/// @param completion The handler block to execute.
- (void)markMessagesAsReceivedWithIds:(NSArray<NSNumber*>*)messageIds completion:(nullable SCTMessageMarkerListCompletion)completion
NS_SWIFT_NAME(markMessagesAsReceived(ids:completion:));

/// Mark messages as read on this channel.
/// @param messageIds the `SCTMessageId` list.
/// @param completion The handler block to execute.
- (void)markMessagesAsDisplayedWithIds:(NSArray<NSNumber*>*)messageIds completion:(nullable SCTMessageMarkerListCompletion)completion
NS_SWIFT_NAME(markMessagesAsDisplayed(ids:completion:));

/// Mark messages  on this channel.
/// @param markerName the marker name.
/// @param messageIds the `SCTMessageId` list.
/// @param completion The handler block to execute.
- (void)markMessages:(NSString *)markerName messageIds:(nonnull NSArray<NSNumber*>*)messageIds completion:(nullable SCTMessageMarkerListCompletion)completion
NS_SWIFT_NAME(markMessages(markerName:ids:completion:));

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

- (void)forwardMessagesWithIds:(nonnull NSArray<NSNumber*>*)messageIds toChannelIds:(nonnull NSArray<NSNumber*>*)channelIds completion:(nonnull SCTForwardMessageCompletion)completion
NS_SWIFT_NAME(forwardMessages(ids:toChannelIds:completion:));


/// Resend the failed message.
/// @param failedMessage The message which will be resend.
/// @param completion The handler block to execute.
- (void)resendMessage:(nonnull SCTMessage *)failedMessage completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(resendMessage(_:completion:));

/// Delete the message.
/// @param messageId The message id which will be deleted.
/// @param forMe If set to YES, only the message for the current user will be deleted.
/// @param completion The handler block to execute.
- (void)deleteMessageWithId:(SCTMessageId)messageId forMe:(BOOL)forMe completion:(SCTMessageCompletion)completion
NS_SWIFT_NAME(deleteMessage(id:forMe:completion:));

/// Delete the message.
/// @param message The message which will be deleted.
/// @param forMe If set to YES, only the message for the current user will be deleted.
/// @param completion The handler block to execute.
- (void)deleteMessage:(nonnull SCTMessage *)message forMe:(BOOL)forMe completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(deleteMessage(_:forMe:completion:));

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

/// Gets the messages with given ids.
/// @param messageIds The message ids
/// @param completion The completion handler to call after execution.
- (void)getMessagesWithId:(NSArray<NSNumber *> *)messageIds completion:(SCTMessageListCompletion)completion
NS_SWIFT_NAME(getMessages(ids:completion:));

@end

NS_ASSUME_NONNULL_END
