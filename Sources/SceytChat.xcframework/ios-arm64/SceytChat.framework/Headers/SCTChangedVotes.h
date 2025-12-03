//
//  SCTChangedVotes.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCTPollVote;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ChangedVotes)
@interface SCTChangedVotes : NSObject

/// The list of votes that were added.
@property (nonatomic, readonly, nonnull) NSArray<SCTPollVote *> *addedVotes;

/// The list of votes that were removed.
@property (nonatomic, readonly, nonnull) NSArray<SCTPollVote *> *removedVotes;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

