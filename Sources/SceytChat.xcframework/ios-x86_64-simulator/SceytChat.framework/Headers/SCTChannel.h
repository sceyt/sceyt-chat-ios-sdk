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

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
