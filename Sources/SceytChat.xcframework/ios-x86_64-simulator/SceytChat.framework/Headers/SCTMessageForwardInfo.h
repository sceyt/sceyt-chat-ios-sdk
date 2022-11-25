//
//  SCTMessageForwardInfo.h
//  SceytChat
//
//  Created by Hovsep on 11/23/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCTMessageForwardInfo : NSObject

/// The unique message id.
@property (nonatomic, readonly) SCTMessageId messageId;

/// The unique channel id.
@property (nonatomic, readonly) SCTChannelId channelId;

/// The message owner.
@property (nonatomic, readonly, nonnull) SCTUser *user;


@end


NS_ASSUME_NONNULL_END
