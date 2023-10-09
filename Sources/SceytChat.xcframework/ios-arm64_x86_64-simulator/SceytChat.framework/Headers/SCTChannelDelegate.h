//
//  SCTChannelDelegate.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTUser;
@class SCTMember;
@class SCTChannel;
@class SCTMessage;
@class SCTReaction;
@class SCTChannelEvent;
@class SCTReactionEvent;
@class SCTMessageListMarker;

NS_SWIFT_NAME(ChannelDelegate)
@protocol SCTChannelDelegate <NSObject>
@optional

/// A callback when a channel is created with current user.
/// @param channel The created channel.
- (void)channelDidCreate:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidCreate(_:));

/// A callback when a channel is updated.
/// @param channel The updated channel.
- (void)channelDidUpdate:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidUpdate(_:));

/// A callback when a channel was deleted.
/// @param channelId The deleted channel id.
- (void)channelDidDelete:(SCTChannelId)channelId
NS_SWIFT_NAME(channelDidDelete(id:));

/// A callback when  unread counts are updated.
/// @param channel The channel in which unreadCount updated.
/// @param totalUnreadChannelCount The number of unread channels.
/// @param totalUnreadMessageCount the number of unread messages.
- (void)channelDidUpdateUnreadCount:(nonnull SCTChannel *)channel totalUnreadChannelCount:(NSUInteger)totalUnreadChannelCount totalUnreadMessageCount:(NSUInteger)totalUnreadMessageCount
NS_SWIFT_NAME(channelDidUpdateUnreadCount(_:totalUnreadChannelCount:totalUnreadMessageCount:));

/// A callback when a channel was hidden from the another device of the current user.
/// @param channel The hidden channel.
- (void)channelDidHide:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidHide(_:));

/// A callback when a channel was unhidden from the another device of the current user.
/// @param channel The unhidden channel.
- (void)channelDidUnhide:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidUnhide(_:));

// A callback when a channel was muted from the another device of the current user.
/// @param channel The muted channel.
- (void)channelDidMute:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidMute(_:));

/// A callback when a channel was unmuted from the another device of the current user.
/// @param channel The unmuted channel.
- (void)channelDidUnmute:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidUnmute(_:));

/// A callback when a channel was blocked from the another device of the current user.
/// @param channel The blocked channel.
- (void)channelDidBlock:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidBlock(_:));

/// A callback when a channel was unblocked from the another device of the current user.
/// @param channel The unblocked channel.
- (void)channelDidUnblock:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidUnblock(_:));

/// A callback when a delete all message from channel from the another device of the current user Delete all messages from channel only for current user.
/// @param channel The  delete all messages from the channel.
- (void)channelDidDeleteAllMessagesForMe:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidDeleteAllMessagesForMe(_:));

/// A callback when a delete all messages of the channel for all members of the channel.
/// @param channel The  channel from where deleted all messages.
- (void)channelDidDeleteAllMessagesForEveryone:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidDeleteAllMessagesForEveryone(_:));

/// A callback when a channel was marked as read from the another device of the current user.
/// @param channel The marked channel.
- (void)channelDidMarkAsRead:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidMarkAsRead(_:));

/// A callback when a channel was marked as unread from the another device of the current user.
/// @param channel The marked channel.
- (void)channelDidMarkAsUnread:(nonnull SCTChannel *)channel
NS_SWIFT_NAME(channelDidMarkAsUnread(_:));

/// A callback when a channel owner was changed.
/// @param channel The updated channel.
/// @param newOwner The channel new owner.
/// @param oldOwner The channel previous owner.
- (void)channel:(nonnull SCTChannel *)channel ownerDidChange:(nonnull SCTMember *)newOwner oldOwner:(nonnull SCTMember *)oldOwner
NS_SWIFT_NAME(channel(_:didChange:oldOwner:));

/// A callback when  member joined to a channel.
/// @param channel The channel.
/// @param member The new joined channel.
- (void)channel:(nonnull SCTChannel *)channel memberDidJoin:(nonnull SCTMember *)member
NS_SWIFT_NAME(channel(_:didJoin:));

/// A callback when  members added to a channel from operator.
/// @param channel The channel.
/// @param members The added members.
- (void)channel:(nonnull SCTChannel *)channel membersDidAdd:(nonnull NSArray<SCTMember *> *)members
NS_SWIFT_NAME(channel(_:didAdd:));

/// A callback when  member live from the channel.
/// @param channel The channel.
/// @param member The lived member.
- (void)channel:(nonnull SCTChannel *)channel memberDidLeave:(nonnull SCTMember *)member
NS_SWIFT_NAME(channel(_:didLeave:));

/// A callback when  members kicked from a channel by operator.
/// @param channel The channel.
/// @param members The kicked members.
- (void)channel:(nonnull SCTChannel *)channel membersDidKick:(nonnull NSArray<SCTMember *> *)members
NS_SWIFT_NAME(channel(_:didKick:));

/// A callback when  members role changed by operator.
/// @param channel The channel.
/// @param members The members with new roles.
- (void)channel:(nonnull SCTChannel *)channel membersRoleDidChange:(nonnull NSArray<SCTMember *> *)members
NS_SWIFT_NAME(channel(_:didChangeRole:));

/// A callback when  members blocked from the another device of the current user.
/// @param channel The channel.
/// @param members The blocked members.
- (void)channel:(nonnull SCTChannel *)channel membersDidBlock:(nonnull NSArray<SCTMember *> *)members
NS_SWIFT_NAME(channel(_:didBlock:));

/// A callback when  members unblocked from the another device of the current user.
/// @param channel The channel.
/// @param members The unblocked members.
- (void)channel:(nonnull SCTChannel *)channel membersDidUnblock:(nonnull NSArray<SCTMember *> *)members
NS_SWIFT_NAME(channel(_:didUnblock:));

/// A callback when a message is received.
/// @param channel The channel where the message is received.
/// @param message The received message.
- (void)channel:(nonnull SCTChannel *)channel messageDidReceive:(nonnull SCTMessage *)message
NS_SWIFT_NAME(channel(_:didReceive:));

/// A callback when a message is edited.
/// @param channel The channel where the message is edited.
/// @param user The editor.
/// @param message The edited message.
- (void)channel:(nonnull SCTChannel *)channel user:(nonnull SCTUser *)user didEditMessage:(nonnull SCTMessage *)message
NS_SWIFT_NAME(channel(_:user:didEdit:));

/// A callback when a message is deleted.
/// @param channel The channel where the message is deleted.
/// @param user The deleter.
/// @param message The deleted message.
- (void)channel:(nonnull SCTChannel *)channel user:(nonnull SCTUser *)user didDeleteMessage:(nonnull SCTMessage *)message
NS_SWIFT_NAME(channel(_:user:didDelete:));

/// A callback when updating a channel messages marker
/// @param channelId The channel id
/// @param marker the marker object
- (void)channel:(SCTChannelId)channelId didReceiveMessageListMarker:(SCTMessageListMarker *)marker
NS_SWIFT_NAME(channel(channelId:didReceive:));

/// A callback when a reaction is received.
/// @param channel The channel where the message reactions are added.
/// @param user The reaction  creator.
/// @param message The message where added the reaction.
/// @param reaction The added reaction.
- (void)channel:(nonnull SCTChannel *)channel user:(nonnull SCTUser *)user message:(nonnull SCTMessage *)message reactionDidAdd:(nonnull SCTReaction *)reaction
NS_SWIFT_NAME(channel(_:user:message:didAdd:));

/// A callback when a reaction is received.
/// @param channel The channel where the message reactions are deleted.
/// @param user The reaction  deleter.
/// @param message The message where deleted the reaction.
/// @param reaction The deleted reaction.
- (void)channel:(nonnull SCTChannel *)channel user:(nonnull SCTUser *)user message:(nonnull SCTMessage *)message reactionDidDelete:(nonnull SCTReaction *)reaction
NS_SWIFT_NAME(channel(_:user:message:didDelete:));

/// A callback when a user starts typing.
/// @param channel The channel where the user starts typing.
/// @param member The user who typing now.
- (void)channel:(nonnull SCTChannel *)channel memberDidStartTyping:(nonnull SCTMember *)member
NS_SWIFT_NAME(channel(_:didStartTyping:)) __attribute((deprecated("use channel:didReceiveChannelEvent.")));;

/// A callback when a user send an event.
/// @param channel The channel where the user sends an event.
/// @param channelEvent The event
- (void)channel:(nonnull SCTChannel *)channel didReceiveChannelEvent:(nonnull SCTChannelEvent *)channelEvent
NS_SWIFT_NAME(channel(_:didReceive:));


/// A callback when a user stops typing.
/// @param channel The channel where the user stops typing.
/// @param member The user who stoped typing.
- (void)channel:(nonnull SCTChannel *)channel memberDidStopTyping:(nonnull SCTMember *)member
NS_SWIFT_NAME(channel(_:didStopTyping:));

@end

NS_ASSUME_NONNULL_END
