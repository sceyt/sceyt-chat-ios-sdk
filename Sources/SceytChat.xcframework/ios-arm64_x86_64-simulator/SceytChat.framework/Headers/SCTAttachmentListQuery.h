//
//  SCTAttachmentListQuery.h
//  SceytChat
//
//  Created by Hovsep on 1/12/23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(AttachmentListQuery)
@interface SCTAttachmentListQuery : NSObject

/// The channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// Sets the number of attachments per page.
@property (nonatomic) NSUInteger limit;

/// Get messages reversed.
@property (nonatomic, readonly) BOOL reversed;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTAttachmentListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get next attachments.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTAttachmentListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

/// Get next attachments.
/// @param attachmentId Get messages after the message
/// @param completion The handler block to execute.
- (void)loadNextByAttachmentId:(SCTAttachmentId)attachmentId completion:(SCTAttachmentListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(attachmentId:_:));

/// Get next attachments.
/// @param date Get attachments after the date
/// @param completion The handler block to execute.
- (void)loadNextByDate:(NSDate *)date completion:(SCTAttachmentListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(date:_:));

/// Get previous attachments.
/// @param completion The handler block to execute.
- (void)loadPreviousWithCompletion:(SCTAttachmentListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(_:));

/// Get previous attachments.
/// @param attachmentId Get attachments before the message
/// @param completion The handler block to execute.
- (void)loadPreviousByAttachmentId:(SCTAttachmentId)attachmentId completion:(SCTAttachmentListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(attachmentId:_:));

/// Get previous attachments.
/// @param date Get attachments before the date
/// @param completion The handler block to execute.
- (void)loadPreviousByDate:(NSDate*)date completion:(SCTAttachmentListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(date:_:));

/// Get near attachments of the given attachment id.
/// @param attachmentId The existing attachment id.
/// @param completion The handler block to execute.
- (void)loadNearByAttachmentId:(SCTAttachmentId)attachmentId completion:(SCTAttachmentListQueryCompletion)completion
NS_SWIFT_NAME(loadNear(attachmentId:completion:));

/// Get near attachments of the given date.
/// @param date The date.
/// @param completion The handler block to execute.
- (void)loadNearByDate:(nonnull NSDate *)date completion:(SCTAttachmentListQueryCompletion)completion
NS_SWIFT_NAME(loadNear(date:completion:));

@end

NS_SWIFT_NAME(AttachmentListQuery.Builder)
@interface SCTAttachmentListQueryBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create AttachmentListQuery builder for get attachments of the channel.
/// @param channelId The channel id to load messages.
- (instancetype)initWithChannelId:(SCTChannelId)channelId types:(NSArray<NSString *> *)types;

/// Sets the number of messages per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// Reverse the got messages.
/// @param reverse If YES, the latest message is the index 0.
- (instancetype)reversed:(BOOL)reverse;

/// Built a AttachmentListQuery.
- (SCTAttachmentListQuery *)build;

@end

NS_ASSUME_NONNULL_END
