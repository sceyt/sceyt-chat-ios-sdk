//
//  SCTMemberListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(MemberListQuery)
@interface SCTMemberListQuery : NSObject

/// Sets the number of channels per page.
@property (nonatomic) NSUInteger limit;

/// The offset of channel list query.
@property (nonatomic, readonly) NSUInteger offset;

/// The channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// The member list query order.
@property (nonatomic, readonly) SCTMemberListOrder order;

/// The member list query type.
@property (nonatomic, readonly) SCTMemberListQueryType queryType;

/// The member list order type.
@property (nonatomic, readonly) SCTQueryOrderType orderType;

/// The total channel count.
@property (nonatomic, readonly) NSUInteger totalMemberCount;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Get channels.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTMemberListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(MemberListQuery.Builder)
@interface SCTMemberListQueryBuilder : NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create MemberListQuery builder.
/// @param channelId The channel id for get members of the channel.
- (instancetype)initWithChannelId:(SCTChannelId)channelId;

/// Sets the number of members per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// The offset of member list query.
/// @param offset The first query offset.
- (instancetype)offset:(NSUInteger)offset;

/// Get members by order.
/// @param order The query order.
- (instancetype)order:(SCTMemberListOrder)order;

/// Set query filter type.
/// @param type Filter members by query type.
- (instancetype)queryType:(SCTMemberListQueryType)type;

/// Get members by order.
/// @param type The query order type.
- (instancetype)orderType:(SCTQueryOrderType)type;

/// Built a MemberListQuery.
- (SCTMemberListQuery *)build;

@end

NS_ASSUME_NONNULL_END
