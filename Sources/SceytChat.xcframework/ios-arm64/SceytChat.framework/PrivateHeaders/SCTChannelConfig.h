//
//  SCTChannelConfig.h
//  SceytChat
//
//  Created by Hovsep on 6/3/23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Channel.Config)
@interface SCTChannelConfig : NSObject

@property (nonatomic, readonly, nonnull) NSString *name;

/// if true no visible to non member users
@property (nonatomic, readonly) BOOL search;

/// user’s can join
@property (nonatomic, readonly) BOOL join;

/// created for fixed users
@property (nonatomic, readonly) BOOL distinct;


@end

NS_ASSUME_NONNULL_END
