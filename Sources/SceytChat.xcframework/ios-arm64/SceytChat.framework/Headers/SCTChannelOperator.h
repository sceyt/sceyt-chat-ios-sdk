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

/// Update the public channel.
/// @param uri The Uniform Resource Identifier of the channel.
/// @param subject The subject of  channel.
/// @param metadata The metadata of channel.
/// @param avatarUrl The avatar URL of channel.
/// @param completion The handler block to execute.
- (void)updateWithUri:(nonnull NSString *)uri
              subject:(nonnull NSString *)subject
             metadata:(nullable NSString *)metadata
            avatarUrl:(nullable NSString *)avatarUrl
           completion:(nonnull SCTChannelCompletion)completion
NS_SWIFT_NAME(update(uri:subject:metadata:avatarUrl:completion:));

/// Deletes the channel. The user has to be an owner or should have a permission.
/// @param completion The handler block to execute.
- (void)deleteWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(delete(completion:));

/// Leave the  channel. The channel will be disappeared from the current user channel list.
/// @param completion The handler block to execute.
- (void)leaveWithCompletion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(leave(completion:));

/// Hide the channel. After hide the channel will not visible in current user channels list.
/// @param completion The handler block to execute.
- (void)hideWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(hide(completion:));

/// Unhide the  channel.
/// @param completion The handler block to execute.
- (void)unhideWithCompletion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(unhide(completion:));

/// Block the  channel. After block no one can add the current user to the channel.
/// @param completion The handler block to execute.
/// @note The current user will live from the channel after block.
- (void)blockWithCompletion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(block(completion:));

/// Unblock the channel.
/// @param completion The handler block to execute.
/// @note After unblock the current user not joining to the channel automatically.
/// For SCTPublicChannel the current user shell join otherwise the operator user shell add the current user.
- (void)unblockWithCompletion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(unblock(completion:));

/// Pin the channel.
/// @param completion The handler block to execute.
- (void)pinWithCompletion:(nonnull SCTChannelCompletion)completion
NS_SWIFT_NAME(pin(completion:));

/// Unpin the Channel
/// @param completion The handler block to execute.
- (void)unpinWithCompletion:(nonnull SCTChannelCompletion)completion
NS_SWIFT_NAME(unpin(completion:));

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
NS_SWIFT_NAME(startTyping()) __attribute((deprecated("use sendEvent:event.")));

/// Send stop typing message.
- (void)stopTyping
NS_SWIFT_NAME(stopTyping()) __attribute((deprecated("use sendEvent:event.")));

/// Send stop typing message.
- (void)sendEvent:(nonnull NSString*)event
NS_SWIFT_NAME(sendEvent(_:));

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
/// @param deleteType The type of deleting message.
/// @param completion The handler block to execute.
- (void)deleteMessageWithId:(SCTMessageId)messageId type:(SCTDeleteMessageType)deleteType completion:(SCTMessageCompletion)completion
NS_SWIFT_NAME(deleteMessage(id:type:completion:));

/// Delete the message.
/// @param message The message which will be deleted.
/// @param deleteType The type of deleting message.
/// @param completion The handler block to execute.
- (void)deleteMessage:(nonnull SCTMessage *)message type:(SCTDeleteMessageType)deleteType completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(deleteMessage(_:type:completion:));


/// Delete all messages from the.
/// @param forEveryone Delete messages for all users or current user.
/// @param completion The handler block to execute.
- (void)deleteAllMessages:(BOOL)forEveryone completion:(nullable SCTCompletion)completion
NS_SWIFT_NAME(deleteAllMessages(forEveryone:completion:));

/// Gets the messages with given ids.
/// @param messageIds The message ids
/// @param completion The handler block to execute.
- (void)getMessagesWithId:(NSArray<NSNumber *> *)messageIds completion:(SCTMessageListCompletion)completion
NS_SWIFT_NAME(getMessages(ids:completion:));


/// Set message retention period
/// @param timeInterval after the period the messages will be deleted
/// @param completion The handler block to execute.
- (void)setMessageRetentionPeriod:(NSTimeInterval)timeInterval completion:(SCTChannelCompletion)completion
NS_SWIFT_NAME(setMessageRetentionPeriod(timeInterval:completion:));

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

//MARK: - Poll Operations

/// Add a vote to a poll.
/// @param messageId Id of the message containing the poll.
/// @param pollId The poll identifier.
/// @param optionIds Array of option identifiers to vote for.
/// @param completion The handler block to execute.
- (void)addPollVoteWithMessageId:(SCTMessageId)messageId
                          pollId:(nonnull NSString *)pollId
                       optionIds:(nonnull NSArray<NSString *> *)optionIds
                      completion:(nonnull SCTPollVoteCompletion)completion
NS_SWIFT_NAME(addPollVote(messageId:pollId:optionIds:completion:));

/// Delete a vote from a poll.
/// @param messageId Id of the message containing the poll.
/// @param pollId The poll identifier.
/// @param optionIds Array of option identifiers to remove votes from.
/// @param completion The handler block to execute.
- (void)deletePollVoteWithMessageId:(SCTMessageId)messageId
                             pollId:(nonnull NSString *)pollId
                          optionIds:(nonnull NSArray<NSString *> *)optionIds
                         completion:(nonnull SCTPollVoteCompletion)completion
NS_SWIFT_NAME(deletePollVote(messageId:pollId:optionIds:completion:));

/// Retract all votes from a poll.
/// @param messageId Id of the message containing the poll.
/// @param pollId The poll identifier.
/// @param completion The handler block to execute.
- (void)retractPollVoteWithMessageId:(SCTMessageId)messageId
                              pollId:(nonnull NSString *)pollId
                          completion:(nonnull SCTPollVoteCompletion)completion
NS_SWIFT_NAME(retractPollVote(messageId:pollId:completion:));

/// Close a poll.
/// @param messageId Id of the message containing the poll.
/// @param pollId The poll identifier.
/// @param completion The handler block to execute.
- (void)closePollWithMessageId:(SCTMessageId)messageId
                        pollId:(nonnull NSString *)pollId
                    completion:(nonnull SCTClosePollCompletion)completion
NS_SWIFT_NAME(closePoll(messageId:pollId:completion:));

/// Change the channel owner.
/// @param userId the new owner user id.
/// @param completion The handler block to execute.
/// @note Only owner can set new owner.
- (void)changeOwnerWithNewOwnerId:(SCTUserId)userId completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(changeOwner(newOwnerId:completion:));

/// Change the channel members role.
/// @param members the new roles.
/// @param completion The handler block to execute.
/// @note The current user should hav a respectively  permission.
- (void)changeMembersRole:(NSArray<SCTMember *> *)members completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(changeMembersRole(_:completion:));

/// Add members to the channel.
/// @param members the user id and role to be added.
/// @param completion The handler block to execute.
/// @note The current user should hav a respectively  permission.
- (void)addMembers:(NSArray<SCTMember *> *)members completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(add(members:completion:));

/// Add members to the channel.
/// @param members the user id and role to be added.
/// @param accessPriorHistory Defaults to YES. the added members can see messages from the current state.
/// @param completion The handler block to execute.
/// @note The current user should hav a respectively  permission.
- (void)addMembers:(NSArray<SCTMember *> *)members accessPriorHistory:(BOOL)accessPriorHistory completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(add(members:accessPriorHistory:completion:));

/// Kick members from the channel.
/// @param ids the user ids to be kicked.
/// @param completion The handler block to execute.
- (void)kickMembersWithMemberIds:(NSArray<SCTUserId> *)ids completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(kickMembers(ids:completion:));

/// Block members for do not receive notifications from theirs.
/// @param ids the user ids to be blocked.
/// @param completion The handler block to execute.
- (void)blockMembersWithMemberIds:(NSArray<SCTUserId> *)ids completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(blockMembers(ids:completion:));

/// Unblock members.
/// @param ids the user ids to be unblocked.
/// @param completion The handler block to execute.
- (void)unblockMembersWithMemberIds:(NSArray<SCTUserId> *)ids completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(unblockMembers(ids:completion:));

/// Join the public channel.
/// @param completion The handler block to execute.
- (void)joinWithCompletion:(nonnull SCTChannelCompletion)completion
NS_SWIFT_NAME(join(completion:));

@end

NS_ASSUME_NONNULL_END
