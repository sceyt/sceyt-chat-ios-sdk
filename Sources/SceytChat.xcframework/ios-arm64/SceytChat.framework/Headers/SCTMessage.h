//
//  SCTMessage.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTUser;
@class SCTReaction;
@class SCTReactionScore;
@class SCTMessageMarkerCount;
@class SCTAttachment;
@class SCTMessageForwardInfo;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Message)
@interface SCTMessage : NSObject

/// The unique message id.
@property (nonatomic, readonly) SCTMessageId id;

/// Temporary id for checking ACK.
@property (nonatomic, readonly) NSInteger tid;

/// The message body.
@property (nonatomic, readonly, nonnull) NSString *body;

/// The message custom body.
@property (nonatomic, readonly, nonnull) NSString *type;

/// The message custom metadata.
@property (nonatomic, readonly, nullable) NSString *metadata;

/// The message created date.
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

/// The message updated date.
@property (nonatomic, readonly, nullable) NSDate *updatedAt;

/// Show the message is incoming or outgoing.
@property (nonatomic, readonly) BOOL incoming;

/// The transient message. If  the value is `YES` the message will no store in the server
@property (nonatomic, readonly) BOOL transient;

/// The silent message. If the value is `YES` the server will not send a push notification
@property (nonatomic, readonly) BOOL silent;

/// The message owner.
@property (nonatomic, readonly, nonnull) SCTUser *user;

/// The message update type.
@property (nonatomic, readonly) SCTMessageState state;

/// The message current status.
@property (nonatomic, readonly) SCTMessageDeliveryStatus deliveryStatus;

/// The message attachments.
@property (nonatomic, readonly, nullable) NSArray<SCTAttachment*> *attachments;

/// The  list of reactions to the message left by the current user.
@property (nonatomic, readonly, nullable) NSArray<SCTReaction *> *selfReactions;

/// The latest reactions to the message created by any user. There can be 100 reactions at max.
@property (nonatomic, readonly, nullable) NSArray<SCTReaction *> *lastReactions;

/// The reaction keys and scores to the message created by any user.
@property (nonatomic, readonly, nullable) NSArray<SCTReactionScore *> *reactionScores;

/// The list of users who was mentioned together with the message.
@property (nonatomic, readonly, nullable) NSArray <SCTUser *> *mentionedUsers;

/// The marker names and count to the message marked by any user.
@property (nonatomic, readonly, nullable) NSArray <SCTMessageMarkerCount *> *markerCount;

/// The  list of marker names to the message left by the current user.
@property (nonatomic, readonly, nullable) NSArray<NSString *> *selfMarkerNames;

/// Represents target user ids to mention when success to send the message.
/// This value is valid only when the message is a pending or failed message.
/// @see see `mentionedUsers` when the message is a succeeded message.
@property (nonatomic, readonly, nullable) NSArray<SCTUserId> *requestedMentionUserIds;

/// The parent message of replied message
@property (nonatomic, readonly, nullable) SCTMessage *parent;

/// The main message which forwarded
@property (nonatomic, readonly, nullable) SCTMessageForwardInfo *forwardInfo;


@property (nonatomic, readonly) BOOL repliedInThread;

@property (nonatomic, readonly) NSInteger replyCount;

@property (nonatomic, readonly) NSInteger displayCount;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_SWIFT_NAME(Message.Builder)
@interface SCTMessageBuilder: NSObject

/// Create message builder.
- (instancetype)init;

/// Use id for edit or delete the message.
/// @param id The message id.
- (instancetype)id:(SCTMessageId)id
NS_SWIFT_NAME(id(_:));

/// Use tid for resend the failed message.
/// @param tid The message tid.
- (instancetype)tid:(NSInteger)tid
NS_SWIFT_NAME(tid(_:));

/// Use body for send text message.
/// @param body The message body.
- (instancetype)body:(nonnull NSString *)body
NS_SWIFT_NAME(body(_:));

/// Set the message type, default value is `text`.
/// @param type The message type.
- (instancetype)type:(nonnull NSString *)type
NS_SWIFT_NAME(type(_:));

/// Use metadata for describe message.
/// @param metadata The message metadata.
- (instancetype)metadata:(nonnull NSString *)metadata
NS_SWIFT_NAME(metadata(_:));

/// Use attachments for send a file message.
/// @param attachments The message attachments.
- (instancetype)attachments:(nonnull NSArray<SCTAttachment*> *)attachments
NS_SWIFT_NAME(attachments(_:));

/// Represents target user ids to mention.
/// @see see `mentionedUsers` when the message is a succeeded message.
/// @param mentionUserIds The user ids to mention.
- (instancetype)mentionUserIds:(nonnull NSArray<SCTUserId> *)mentionUserIds
NS_SWIFT_NAME(mentionUserIds(_:));

/// Represents target user to mention.
/// @see see `mentionedUsers` when the message is a succeeded message.
/// @param mentionUsers The users to mention.
- (instancetype)mentionUsers:(nonnull NSArray<SCTUser *> *)mentionUsers
NS_SWIFT_NAME(mentionUserIds(_:));

/// Use id for reply the message.
/// @param id The parent message id.
- (instancetype)parentMessageId:(SCTMessageId)id
NS_SWIFT_NAME(parentMessageId(_:));

/// Set reply in thread YES for replay in a parent message thread.
/// @param replyInThread If YES will send message in parent message thread.
- (instancetype)replyInThread:(BOOL)replyInThread
NS_SWIFT_NAME(replyInThread(_:));

/// Create transient message
/// @param transient `YES` to no store message in the server`
- (instancetype)transient:(BOOL)transient
NS_SWIFT_NAME(transient(_:));

/// Create silent message
/// @param silent `YES` to do not send a push notification for the messa
- (instancetype)silent:(BOOL)silent
NS_SWIFT_NAME(silent(_:));

/// Add custom read count.
/// @param displayCount Default value is 1
- (instancetype)displayCount:(NSInteger)displayCount
NS_SWIFT_NAME(displayCount(_:));

/// Built a message.
- (SCTMessage *)build
NS_SWIFT_NAME(build());

@end

NS_ASSUME_NONNULL_END
