//
//  SCTMarker.h
//  SceytChat
//
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Marker)
@interface SCTMarker : NSObject
@property (nonatomic, readonly) SCTMessageId messageId;
@property (nonatomic, readonly, nonnull) SCTUser *user;
@property (nonatomic, readonly, nonnull) NSString *name;
@property (nonatomic, readonly, nonnull) NSDate *createdAt;
@end

NS_SWIFT_NAME(MarkerTotal)
@interface SCTMarkerTotal : NSObject

/// The marker name.
@property (nonatomic, readonly, nonnull) NSString *name;

/// The total scores of the marker.
@property (nonatomic, readonly) NSUInteger count;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_SWIFT_NAME(MessageListMarker)
@interface SCTMessageListMarker : NSObject

/// list of `SCTMessageId`s
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *messageIds;
@property (nonatomic, readonly) SCTChannelId channelId;
@property (nonatomic, readonly, nonnull) SCTUser *user;
@property (nonatomic, readonly, nonnull) NSString *name;
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

@end

NS_ASSUME_NONNULL_END
