//
//  SCTDirectChannelOperator.h
//  SceytChat
//
//  Created by Hovsep on 8/23/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTChannelOperator.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DirectChannelOperator)
@interface SCTDirectChannelOperator : SCTChannelOperator

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Update the direct channel.
/// @param label The label of channel.
/// @param metadata The metadata of channel.
/// @param completion The handler block to execute.
- (void)updateWithLabel:(nullable NSString *)label
               metadata:(nullable NSString *)metadata
             completion:(nonnull SCTDirectChannelCompletion)completion
NS_SWIFT_NAME(update(label:metadata:completion:));

/// Delete the message.
/// @param messageId The message id which will be deleted.
/// @param completion The handler block to execute.
- (void)deleteMessageWithId:(SCTMessageId)messageId forMe:(BOOL)forMe completion:(SCTMessageCompletion)completion
NS_SWIFT_NAME(deleteMessage(id:forMe:completion:));

/// Delete the message.
/// @param message The message which will be deleted.
/// @param completion The handler block to execute.
- (void)deleteMessage:(nonnull SCTMessage *)message forMe:(BOOL)forMe completion:(nonnull SCTMessageCompletion)completion
NS_SWIFT_NAME(deleteMessage(_:forMe:completion:));

@end

NS_ASSUME_NONNULL_END
