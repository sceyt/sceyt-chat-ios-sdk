//
//  SCTForwardingDetails.h
//  SceytChat
//
//  Created by Hovsep on 11/23/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ForwardingDetails)
@interface SCTForwardingDetails : NSObject

/// The unique message id.
@property (nonatomic, readonly) SCTMessageId messageId;

/// The unique channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// The message owner.
@property (nonatomic, readonly, nonnull) SCTUser *user;

/// The message forwarded hops.
@property (nonatomic, readonly) NSUInteger hops;


@end


NS_ASSUME_NONNULL_END
