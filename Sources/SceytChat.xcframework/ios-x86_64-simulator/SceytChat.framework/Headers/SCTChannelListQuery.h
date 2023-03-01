//
//  SCTChannelListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTError;
@class SCTChannelQueryParam;

NS_SWIFT_NAME(ChannelListQuery)
@interface SCTChannelListQuery : NSObject

/// The channel list query filter keyword.
@property (nonatomic, readonly, nullable) NSString *query;

/// Sets the number of channels per page.
@property (nonatomic) NSUInteger limit;

/// The offset of channel list query.
@property (nonatomic, readonly) NSUInteger offset;

/// The channel list by query type.
@property (nonatomic, readonly) SCTChannelQueryType type;

/// The channel list by order.
@property (nonatomic, readonly) SCTChannelListOrder order;

/// The channel list by filter key.
@property (nonatomic, readonly) SCTChannelListFilterKey filterKey;

/// The channel list filter query type.
@property (nonatomic, readonly) SCTChannelListFilterQueryType queryType;

/// The request params
/// @key  is `SCTChannelListParamKey`
@property (nonatomic, readonly) NSDictionary<NSNumber *, NSNumber *> *paramKeys;

/// The total channel count.
@property (nonatomic, readonly) NSUInteger totalCount;

/// The total unread message count.
@property (nonatomic, readonly) NSUInteger totalUnreadMessageCount;

/// The total unread channel count.
@property (nonatomic, readonly) NSUInteger totalUnreadChannelCount;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTChannelListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get channels.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTChannelListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(ChannelListQuery.Builder)
@interface SCTChannelListQueryBuilder: NSObject

/// Create ChannelListQuery builder.
- (instancetype)init;

/// Filter channels by query text.
/// @param query The filter query text.
- (instancetype)query:(nonnull NSString *)query;

/// Sets the number of channels per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// The offset of channel list query.
/// @param offset The first query offset.
- (instancetype)offset:(NSUInteger)offset;

/// Filter the channels by type.
/// @param type The query type.
- (instancetype)type:(SCTChannelQueryType)type;

/// Get channels by order.
/// @param order The query order.
- (instancetype)order:(SCTChannelListOrder)order;

/// Filter channels by key.
/// @param key The query filter key.
- (instancetype)filterKey:(SCTChannelListFilterKey)key;

/// Set query filter type.
/// @param type Filter channels by query type.
- (instancetype)queryType:(SCTChannelListFilterQueryType)type;

- (instancetype)requestParams:(SCTChannelQueryParam*)params
NS_SWIFT_NAME(requestParams(_:));


/// Built a ChannelListQuery.
- (SCTChannelListQuery *)build;

@end

NS_ASSUME_NONNULL_END
