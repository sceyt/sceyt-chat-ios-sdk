//
//  SCTReaction.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTUser;
@class SCTMessage;

NS_SWIFT_NAME(Reaction)
@interface SCTReaction : NSObject

/// The reaction id.
@property (nonatomic, readonly) SCTReactionId id;

/// The owner message id.
@property (nonatomic, readonly) SCTMessageId messageId;

/// The reaction key.
@property (nonatomic, readonly, nonnull) NSString *key;

/// The reaction score.
@property (nonatomic, readonly) UInt16 score;

/// The reaction reason.
@property (nonatomic, readonly, nullable) NSString *reason;

/// The date the reaction was last created.
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

/// The reaction owner.
@property (nonatomic, readonly, nonnull) SCTUser *user;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_SWIFT_NAME(ReactionScore)
@interface SCTReactionScore : NSObject

/// The reaction key.
@property (nonatomic, readonly, nonnull) NSString *key;

/// The total scores of the reaction.
@property (nonatomic, readonly) NSUInteger score;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
