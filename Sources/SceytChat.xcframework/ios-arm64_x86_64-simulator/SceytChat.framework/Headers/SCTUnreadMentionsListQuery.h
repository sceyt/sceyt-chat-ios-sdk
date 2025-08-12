//
//  SCTUnreadMentionsListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UnreadMentionsListQuery)
@interface SCTUnreadMentionsListQuery : NSObject

/// The channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// Sets the number of message IDs per page.
@property (nonatomic) NSUInteger limit;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTUnreadMentionsListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get next unread mention message IDs.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTUnreadMentionsListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

/// Get next unread mention message IDs.
/// @param messageId Get message IDs after the message
/// @param completion The handler block to execute.
- (void)loadNextByMessageId:(SCTMessageId)messageId completion:(SCTUnreadMentionsListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(messageId:_:));

/// Get previous unread mention message IDs.
/// @param completion The handler block to execute.
- (void)loadPreviousWithCompletion:(SCTUnreadMentionsListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(_:));

/// Get previous unread mention message IDs.
/// @param messageId Get message IDs before the message
/// @param completion The handler block to execute.
- (void)loadPreviousByMessageId:(SCTMessageId)messageId completion:(SCTUnreadMentionsListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(messageId:_:));

@end

NS_SWIFT_NAME(UnreadMentionsListQuery.Builder)
@interface SCTUnreadMentionsListQueryBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create UnreadMentionsListQuery builder for get unread mention message IDs of the channel.
/// @param channelId The channel id to load unread mention message IDs.
- (instancetype)initWithChannelId:(SCTChannelId)channelId;

/// Sets the number of message IDs per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// Built an UnreadMentionsListQuery.
- (SCTUnreadMentionsListQuery *)build;

@end

NS_ASSUME_NONNULL_END 