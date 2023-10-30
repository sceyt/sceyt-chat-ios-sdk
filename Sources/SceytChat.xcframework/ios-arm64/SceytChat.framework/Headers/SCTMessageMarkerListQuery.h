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

/// The message id.
@property (nonatomic, readonly) SCTMessageId messageId;

/// The marker name.
@property (nonatomic, readonly) NSString * markerName;

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
/// @param messageId The message id of the channel
/// @param markerName The requested marker
- (instancetype)initWithMessageId:(SCTMessageId)messageId markerName:(NSString *)markerName;

/// Sets the number of markers per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// Built a MessageMarkerListQuery.
- (SCTMessageMarkerListQuery *)build;

@end

NS_ASSUME_NONNULL_END
