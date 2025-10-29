//
//  SCTPollVote.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCTUser;

NS_SWIFT_NAME(PollVote)
@interface SCTPollVote : NSObject

/// The unique poll vote identifier.
@property (nonatomic, readonly, nonnull) NSString *id;

/// The poll identifier.
@property (nonatomic, readonly, nonnull) NSString *pollId;

/// The selected option identifier.
@property (nonatomic, readonly, nonnull) NSString *optionId;

/// The date when the vote was created.
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

/// The user who voted.
@property (nonatomic, readonly, nonnull) SCTUser *user;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end


