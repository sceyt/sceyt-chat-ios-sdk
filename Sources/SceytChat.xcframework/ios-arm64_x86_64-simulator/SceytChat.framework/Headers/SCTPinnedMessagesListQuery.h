//
//  SCTPinnedMessagesListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PinnedMessagesListQuery)
@interface SCTPinnedMessagesListQuery : NSObject

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Sets the number of pinned messages per page.
@property (nonatomic) NSUInteger limit;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// The channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// The pin scope to filter by.
@property (nonatomic, readonly) SCTPinTypeFilter pinType;

/// The order of the returned pinned messages.
@property (nonatomic, readonly) SCTPinnedMessagesOrder order;

/// init is unavailable. Use `SCTPinnedMessagesListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Load next page of pinned messages.
/// @param completion The handler block to execute.
- (void)loadNextPageWithCompletion:(SCTPinnedMessagesListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(PinnedMessagesListQuery.Builder)
@interface SCTPinnedMessagesListQueryBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithChannelId:(SCTChannelId)channelId;
- (instancetype)limit:(NSUInteger)limit;
- (instancetype)pinType:(SCTPinTypeFilter)pinType;
- (instancetype)order:(SCTPinnedMessagesOrder)order;
- (SCTPinnedMessagesListQuery *)build;

@end

NS_ASSUME_NONNULL_END
