//
//  SCTDirectChannel.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTChannel.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTMember;

NS_SWIFT_NAME(DirectChannel)
@interface SCTDirectChannel : SCTChannel

/// The channel peer user.
@property (nonatomic, readonly, nonnull) SCTMember *peer;

/// The channel label.
@property (nonatomic, readonly, nullable) NSString *label;

/// The channel metadata.
@property (nonatomic, readonly, nullable) NSString *metadata;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create a direct channel.
/// @param userId  The remote user id.
/// @param label The label of channel.
/// @param metadata The metadata of channel.
/// @param completion The handler block to execute.
+ (void)createWithPeer:(nonnull SCTUserId)userId
                 label:(nullable NSString *)label
              metadata:(nullable NSString *)metadata
            completion:(nonnull SCTDirectChannelCompletion)completion
NS_SWIFT_NAME(create(peer:label:metadata:completion:));

@end

NS_ASSUME_NONNULL_END
