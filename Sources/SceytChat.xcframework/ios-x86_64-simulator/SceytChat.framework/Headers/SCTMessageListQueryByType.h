//
//  SCTMessageListQueryByType.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(MessageListQueryByType)
@interface SCTMessageListQueryByType : NSObject

/// The channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// The message type.
@property (nonatomic, readonly) NSString *type;

/// Sets the number of channels per page.
@property (nonatomic) NSUInteger limit;

/// Get messages reversed.
@property (nonatomic, readonly) BOOL reversed;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTMessageListQueryByTypeBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get next messages.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTMessageListQueryByTypeCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

/// Get next messages.
/// @param messageId Get messages after the message
/// @param completion The handler block to execute.
- (void)loadNextByMessageId:(SCTMessageId)messageId completion:(SCTMessageListQueryByTypeCompletion)completion
NS_SWIFT_NAME(loadNext(messageId:_:));

/// Get next messages.
/// @param date Get messages after the date
/// @param completion The handler block to execute.
- (void)loadNextByDate:(NSDate *)date completion:(SCTMessageListQueryByTypeCompletion)completion
NS_SWIFT_NAME(loadNext(date:_:));

@end

NS_SWIFT_NAME(MessageListQueryByType.Builder)
@interface SCTMessageListQueryByTypeBuilder : NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create MessageListQueryByType builder for get messages of the channel.
/// @param channelId The channel id to load messages.
- (instancetype)initWithChannelId:(SCTChannelId)channelId type:(nonnull NSString *)type;

/// Sets the number of messages per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

///Built a MessageListQueryByType.
- (SCTMessageListQueryByType *)build;

@end

NS_ASSUME_NONNULL_END
