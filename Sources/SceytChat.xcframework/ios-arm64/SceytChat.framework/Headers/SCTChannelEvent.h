//
//  SCTChannelEvent.h
//  SceytChat
//
//  Created by Hovsep Keropyan on 07.09.23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTUser;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ChannelEvent)
@interface SCTChannelEvent : NSObject

@property (nonatomic, readonly) SCTChannelId channelId;
@property (nonatomic, readonly, nonnull) NSString *name;
@property (nonatomic, readonly, nonnull) SCTUser *user;

@end

NS_ASSUME_NONNULL_END
