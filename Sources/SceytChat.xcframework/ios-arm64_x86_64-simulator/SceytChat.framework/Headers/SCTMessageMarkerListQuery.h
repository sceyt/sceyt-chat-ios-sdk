//
//  SCTMessageMarkerListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(MessageMarkerListQuery)
@interface SCTMessageMarkerListQuery : NSObject

/// The channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// The message id.
@property (nonatomic, readonly) SCTMessageId messageId;

/// The marker names.
@property (nonatomic, readonly) NSArray<NSString*>* markerNames;

/// Sets the number of markers per page.
@property (nonatomic) NSUInteger limit;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTMessageListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get markers.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTMessageMarkerListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(MessageMarkerListQuery.Builder)
@interface SCTMessageMarkerListQueryBuilder : NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create MessageMarkerListQuery builder.
/// @param channelId The channel id
/// @param messageId The message id of the channel
/// @param markerNames The requested marker
- (instancetype)initWithChannelId:(SCTChannelId)channelId messageId:(SCTMessageId)messageId markerNames:(NSArray<NSString*>*)markerNames;

/// Sets the number of markers per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// The offset of markers list query.
/// @param startAt The first query date.
- (instancetype)startAt:(NSDate *)startAt;

/// Built a MessageMarkerListQuery.
- (SCTMessageMarkerListQuery *)build;

@end

NS_ASSUME_NONNULL_END
