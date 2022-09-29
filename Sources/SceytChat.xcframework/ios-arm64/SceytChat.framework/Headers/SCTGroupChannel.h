//
//  SCTGroupChannel.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"
#import "SCTChannel.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTUser;
@class SCTRole;
@class SCTMember;

NS_SWIFT_NAME(GroupChannel)
@interface SCTGroupChannel : SCTChannel

/// The channel subject.
@property (nonatomic, readonly, nonnull) NSString *subject;

/// The channel label.
@property (nonatomic, readonly, nullable) NSString *label;

/// The channel metadata.
@property (nonatomic, readonly, nullable) NSString *metadata;

/// The channel avatar url.
@property (nonatomic, readonly, nullable) NSURL *avatarUrl;

/// The current user role of the channel.
@property (nonatomic, readonly, nullable) SCTRole *myRole;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
