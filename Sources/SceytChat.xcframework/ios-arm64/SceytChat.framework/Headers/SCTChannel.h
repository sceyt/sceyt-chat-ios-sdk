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

/// The parent channel unique identifier.
@property (nonatomic, readonly) SCTChannelId parentChannelId;

/// The channel uri.
@property (nonatomic, readonly, nonnull) NSString *uri;

/// The channel type.
@property (nonatomic, readonly, nonnull) NSString *type;

/// The channel subject.
@property (nonatomic, readonly, nonnull) NSString *subject;

/// The channel avatar url.
@property (nonatomic, readonly, nullable) NSString *avatarUrl;

/// The channel metadata.
@property (nonatomic, readonly, nullable) NSString *metadata;

/// The channel creation date.
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

/// The channel last update date.
@property (nonatomic, readonly, nullable) NSDate *updatedAt;

/// The channel messages deletion date.
@property (nonatomic, readonly, nullable) NSDate *messagesClearedAt;

/// Number of members of the channel.
@property (nonatomic, readonly) NSUInteger memberCount;

/// Last message of the channel.
@property (nonatomic, readonly, nullable) SCTUser *createdBy;

/// The current user role of the channel.
@property (nonatomic, readonly, nullable) NSString *userRole;

/// Shows is channel market as unread from the current user.
@property (nonatomic, readonly) BOOL unread;

/// Number of unread messages of the channel.
@property (nonatomic, readonly) NSUInteger newMessageCount;

/// Number of unread current user mentions of the channel.
@property (nonatomic, readonly) NSUInteger newMentionCount;

/// Number of unread reactions of the channel.
@property (nonatomic, readonly) NSUInteger newReactionMessageCount;

/// Shows is channel hidden from the current user.
@property (nonatomic, readonly) BOOL hidden;

/// Shows is channel archived from the current user.
@property (nonatomic, readonly) BOOL archived;

/// Shows is channel muted from the current user.
@property (nonatomic, readonly) BOOL muted;

/// Shows channel mute expire date (nil for forever) if channel muted otherwise nil.
@property (nonatomic, readonly, nullable) NSDate *muteTill;

/// The channel pinned date.
@property (nonatomic, readonly, nullable) NSDate *pinnedAt;

/// The last delivered message id for the current user.
@property (nonatomic, readonly) SCTMessageId lastReceivedMessageId;

/// The last read message id for the current user.
@property (nonatomic, readonly) SCTMessageId lastDisplayedMessageId;

/// The  message retention period.
@property (nonatomic, readonly) NSTimeInterval messageRetentionPeriod;

/// Last message of the channel.
@property (nonatomic, readonly, nullable) SCTMessage *lastMessage;

/// Requested last messages of the channel.
@property (nonatomic, readonly, nullable) NSArray<SCTMessage*> *messages;

/// Requested last active members of the channel.
@property (nonatomic, readonly, nullable) NSArray<SCTMember*> *members;

/// The current user last messages reactions
@property (nonatomic, readonly, nullable) NSArray<SCTReaction*> *lastReactions;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

+ (void)createWithType:(nonnull NSString *)name
                   uri:(nullable NSString *)uri
               subject:(nullable NSString *)subject
              metadata:(nullable NSString *)metadata
             avatarUrl:(nullable NSString *)avatarUrl
               members:(nullable NSArray<SCTMember *> *)members
            completion:(nonnull SCTChannelCompletion)completion
NS_SWIFT_NAME(create(type:uri:subject:metadata:avatarUrl:members:completion:));


@end


NS_ASSUME_NONNULL_END
