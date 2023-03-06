//
//  SCTPublicChannelOperator.h
//  SceytChat
//
//  Created by Hovsep on 8/23/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import "SCTGroupChannelOperator.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PublicChannelOperator)
@interface SCTPublicChannelOperator : SCTGroupChannelOperator

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Update the public channel.
/// @param uri The Uniform Resource Identifier of the channel.
/// @param subject The subject of  channel.
/// @param label The label of channel.
/// @param metadata The metadata of channel.
/// @param avatarUrl The avatar URL of channel.
/// @param completion The handler block to execute.
- (void)updateWithUri:(nonnull NSString *)uri
              subject:(nonnull NSString *)subject
                label:(nullable NSString *)label
             metadata:(nullable NSString *)metadata
            avatarUrl:(nullable NSURL *)avatarUrl
           completion:(nonnull SCTPublicChannelCompletion)completion
NS_SWIFT_NAME(update(uri:subject:label:metadata:avatarUrl:completion:));

/// Join the public channel.
/// @param completion The handler block to execute.
- (void)joinWithCompletion:(nonnull SCTPublicChannelCompletion)completion
NS_SWIFT_NAME(join(completion:));

@end

NS_ASSUME_NONNULL_END
