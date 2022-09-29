//
//  SCTPrivateChannel.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"
#import "SCTGroupChannel.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PrivateChannel)
@interface SCTPrivateChannel : SCTGroupChannel

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create a private channel.
/// @param subject The subject of  channel.
/// @param members The members of channel.
/// @param label The label of channel.
/// @param metadata The metadata of channel.
/// @param avatarUrl The avatar URL of channel.
/// @param completion The handler block to execute.
+ (void)createWithSubject:(nonnull NSString *)subject
                  members:(nullable NSArray<SCTMember *> *)members
                    label:(nullable NSString *)label
                 metadata:(nullable NSString *)metadata
                avatarUrl:(nullable NSURL *)avatarUrl
               completion:(nonnull SCTPrivateChannelCompletion)completion
NS_SWIFT_NAME(create(subject:members:label:metadata:avatarUrl:completion:));

@end

NS_ASSUME_NONNULL_END
