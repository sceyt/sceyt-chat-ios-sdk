//
//  SCTPollVotesListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PollVotesListQuery)
@interface SCTPollVotesListQuery : NSObject

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Sets the number of poll votes per page.
@property (nonatomic) NSUInteger limit;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTPollVotesListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Load next page of poll votes.
/// @param completion The handler block to execute.
- (void)loadNextPageWithCompletion:(SCTPollVotesListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(PollVotesListQuery.Builder)
@interface SCTPollVotesListQueryBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithPollId:(NSString *)pollId;
- (instancetype)limit:(NSUInteger)limit;
- (instancetype)optionId:(NSString *)optionId;
- (SCTPollVotesListQuery *)build;

@end

NS_ASSUME_NONNULL_END

