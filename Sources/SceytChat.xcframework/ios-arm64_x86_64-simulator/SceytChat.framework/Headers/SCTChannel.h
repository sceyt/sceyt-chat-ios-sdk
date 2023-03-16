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

/// Number of unread current user mentions of the channel.
@property (nonatomic, readonly) NSUInteger unreadMentionCount;

/// Number of unread reactions of the channel.
@property (nonatomic, readonly) NSUInteger unreadReactionCount;

/// The last read message id for the current user.
@property (nonatomic, readonly) SCTMessageId lastDisplayedMessageId;

/// The last delivered message id for the current user.
@property (nonatomic, readonly) SCTMessageId lastReceivedMessageId;

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

/// The channel messages deletion date.
@property (nonatomic, readonly, nullable) NSDate *messagesDeletionDate;

/// Requested last messages of the channel.
@property (nonatomic, readonly, nullable) NSArray<SCTMessage*> *lastMessages;

/// Requested last active members of the channel.
@property (nonatomic, readonly, nullable) NSArray<SCTMember*> *lastActiveMembers;

/// The current user last messages reactions
@property (nonatomic, readonly, nullable) NSArray<SCTReaction*> *userMessageReactions;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end


NS_ASSUME_NONNULL_END
