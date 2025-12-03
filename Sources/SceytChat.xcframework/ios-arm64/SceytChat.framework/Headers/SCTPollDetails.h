//
//  SCTPollDetails.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCTPollOption;
@class SCTPollVote;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PollDetails)
@interface SCTPollDetails : NSObject

/// The unique poll identifier.
@property (nonatomic, readonly, nonnull) NSString *id;

/// The poll name/question.
@property (nonatomic, readonly, nonnull) NSString *name;

/// The poll description.
@property (nonatomic, readonly, nullable) NSString *pollDescription;

/// The list of poll options.
@property (nonatomic, readonly, nonnull) NSArray<SCTPollOption *> *options;

/// Indicates if the poll is anonymous.
@property (nonatomic, readonly) BOOL anonymous;

/// Indicates if multiple votes are allowed.
@property (nonatomic, readonly) BOOL allowMultipleVotes;

/// Indicates if vote retraction is allowed.
@property (nonatomic, readonly) BOOL allowVoteRetract;

/// The number of votes per option.
@property (nonatomic, readonly, nonnull) NSDictionary<NSString *, NSNumber *> *votesPerOption;

/// The list of all votes (may be empty for anonymous polls).
@property (nonatomic, readonly, nonnull) NSArray<SCTPollVote *> *votes;

/// The list of current user's votes.
@property (nonatomic, readonly, nonnull) NSArray<SCTPollVote *> *ownVotes;

/// The date when the poll was created.
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

/// The date when the poll was last updated.
@property (nonatomic, readonly, nonnull) NSDate *updatedAt;

/// The date when the poll was closed (nil if not closed).
@property (nonatomic, readonly, nullable) NSDate *closedAt;

/// Indicates if the poll is closed.
@property (nonatomic, readonly) BOOL closed;

/// init is unavailable. Use `SCTPollBuilder` to create poll instances.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

