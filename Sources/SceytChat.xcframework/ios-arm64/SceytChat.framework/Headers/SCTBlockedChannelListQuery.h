//
//  SCTBlockedChannelListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BlockedChannelListQuery)
@interface SCTBlockedChannelListQuery : NSObject

/// Sets the number of channels per page.
@property (nonatomic) NSUInteger limit;

/// The offset of channel list query.
@property (nonatomic, readonly) NSUInteger offset;

/// The total channel count.
@property (nonatomic, readonly) NSUInteger totalCount;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTBlockedChannelListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get channels.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTBlockedChannelListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(BlockedChannelListQuery.Builder)
@interface SCTBlockedChannelListQueryBuilder: NSObject

/// Create BlockedChannelListQuery builder.
- (instancetype)init;

/// Sets the number of channels per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// The offset of channel list query.
/// @param offset The first query offset.
- (instancetype)offset:(NSUInteger)offset;

/// Built a BlockedChannelListQuery.
- (SCTBlockedChannelListQuery *)build;

@end

NS_ASSUME_NONNULL_END
