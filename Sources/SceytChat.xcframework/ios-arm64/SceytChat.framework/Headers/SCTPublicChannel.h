//
//  SCTPublicChannel.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "SCTTypes.h"
#import "SCTGroupChannel.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PublicChannel)
@interface SCTPublicChannel : SCTGroupChannel

/// The channel uri.
@property (nonatomic, readonly, nonnull) NSString *uri;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create a public channel.
/// @param uri The Uniform Resource Identifier of the channel.
/// @param subject The subject of  channel.
/// @param members The members of channel.
/// @param label The label of channel.
/// @param metadata The metadata of channel.
/// @param avatarUrl The avatar URL of channel.
/// @param completion The handler block to execute.
+ (void)createWithUri:(nonnull NSString *)uri
              subject:(nonnull NSString *)subject
              members:(nullable NSArray<SCTMember *> *)members
                label:(nullable NSString *)label
             metadata:(nullable NSString *)metadata
            avatarUrl:(nullable NSURL *)avatarUrl
           completion:(nonnull SCTPublicChannelCompletion)completion
NS_SWIFT_NAME(create(uri:subject:members:label:metadata:avatarUrl:completion:));

@end

NS_ASSUME_NONNULL_END
