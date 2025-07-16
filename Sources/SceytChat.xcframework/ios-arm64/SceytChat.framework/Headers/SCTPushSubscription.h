//
//  SCTPushSubscription.h
//  SceytChat
//
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PushSubscription)
@interface SCTPushSubscription : NSObject

/// The client identifier for the push subscription.
@property (nonatomic, readonly, nullable) NSString *clientId;

/// The data token for push notifications.
@property (nonatomic, readonly, nullable) NSString *dataToken;

/// The VoIP token for push notifications.
@property (nonatomic, readonly, nullable) NSString *voipToken;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END 