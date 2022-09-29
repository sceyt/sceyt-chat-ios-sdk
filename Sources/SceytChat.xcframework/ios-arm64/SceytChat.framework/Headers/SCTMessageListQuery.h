//
//  SCTMessageListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(MessageListQuery)
@interface SCTMessageListQuery : NSObject

/// The channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// Sets the number of channels per page.
@property (nonatomic) NSUInteger limit;

/// Get messages reversed.
@property (nonatomic, readonly) BOOL reversed;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTMessageListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get next messages.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTMessageListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

/// Get next messages.
/// @param messageId Get messages after the message
/// @param completion The handler block to execute.
- (void)loadNextByMessageId:(SCTMessageId)messageId completion:(SCTMessageListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(messageId:_:));

/// Get next messages.
/// @param date Get messages after the date
/// @param completion The handler block to execute.
- (void)loadNextByDate:(NSDate *)date completion:(SCTMessageListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(date:_:));

/// Get previous messages.
/// @param completion The handler block to execute.
- (void)loadPreviousWithCompletion:(SCTMessageListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(_:));

/// Get previous messages.
/// @param messageId Get messages before the message
/// @param completion The handler block to execute.
- (void)loadPreviousByMessageId:(SCTMessageId)messageId completion:(SCTMessageListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(messageId:_:));

/// Get previous messages.
/// @param date Get messages before the date
/// @param completion The handler block to execute.
- (void)loadPreviousByDate:(NSDate*)date completion:(SCTMessageListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(date:_:));

/// Get near messages of the given message id.
/// @param messageId The existing message id.
/// @param completion The handler block to execute.
- (void)loadNearByMessageId:(SCTMessageId)messageId completion:(SCTMessageListQueryCompletion)completion
NS_SWIFT_NAME(loadNear(messageId:completion:));

/// Get near messages of the given date.
/// @param date The date.
/// @param completion The handler block to execute.
- (void)loadNearByDate:(nonnull NSDate *)date completion:(SCTMessageListQueryCompletion)completion
NS_SWIFT_NAME(loadNear(date:completion:));

@end

NS_SWIFT_NAME(MessageListQuery.Builder)
@interface SCTMessageListQueryBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create MessageListQuery builder for get messages off the channel.
/// @param channelId The channel id to load messages.
- (instancetype)initWithChannelId:(SCTChannelId)channelId;

/// Create MessageListQuery builder for get messages off the channel.
/// @param threadId The thread message id to load messages.
- (instancetype)initWithThreadId:(SCTMessageId)threadId;

/// Sets the number of messages per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// Reverse the got messages.
/// @param reverse If YES, the latest message is the index 0.
- (instancetype)reversed:(BOOL)reverse;

/// Built a MessageListQuery.
- (SCTMessageListQuery *)build;

@end

NS_ASSUME_NONNULL_END
