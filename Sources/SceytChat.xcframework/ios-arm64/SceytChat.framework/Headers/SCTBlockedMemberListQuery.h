//
//  SCTBlockedMemberListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"


NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BlockedMemberListQuery)
@interface SCTBlockedMemberListQuery : NSObject

/// The channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// Sets the number of channels per page.
@property (nonatomic) NSUInteger limit;

/// The offset of channel list query.
@property (nonatomic, readonly) NSUInteger offset;

// The total channel count.
@property (nonatomic, readonly) NSUInteger totalMemberCount;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTBlockedMemberListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get channels.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTBlockedMemberListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(BlockedMemberListQuery.Builder)
@interface SCTBlockedMemberListQueryBuilder : NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create BlockedMemberListQuery builder.
/// @param channelId The channel  id for get blocked members of the channel.
- (instancetype)initWithChannelId:(SCTChannelId)channelId;

/// Sets the number of members per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// The offset of member list query.
/// @param offset The first query offset.
- (instancetype)offset:(NSUInteger)offset;

/// Built a BlockedMemberListQuery.
- (SCTBlockedMemberListQuery *)build;

@end

NS_ASSUME_NONNULL_END
