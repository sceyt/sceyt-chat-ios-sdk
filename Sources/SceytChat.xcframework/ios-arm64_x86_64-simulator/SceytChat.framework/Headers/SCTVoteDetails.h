//
//  SCTVoteDetails.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCTPollVote;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(VoteDetails)
@interface SCTVoteDetails : NSObject

/// The number of votes per option (optionId -> vote count).
@property (nonatomic, readonly, nonnull) NSDictionary<NSString *, NSNumber *> *votesPerOption;

/// The list of all votes (may be empty for anonymous polls).
@property (nonatomic, readonly, nonnull) NSArray<SCTPollVote *> *votes;

/// The list of current user's votes.
@property (nonatomic, readonly, nonnull) NSArray<SCTPollVote *> *ownVotes;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

