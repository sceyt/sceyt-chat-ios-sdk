//
//  SCTPrivateChannelOperator.h
//  SceytChat
//
//  Created by Hovsep on 8/23/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import "SCTGroupChannelOperator.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PrivateChannelOperator)
@interface SCTPrivateChannelOperator : SCTGroupChannelOperator

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Update the private channel.
/// @param subject The subject of  channel.
/// @param label The label of channel.
/// @param metadata The metadata of channel.
/// @param avatarUrl The avatar URL of channel.
/// @param completion The handler block to execute.
- (void)updateWithSubject:(nonnull NSString *)subject
                    label:(nullable NSString *)label
                 metadata:(nullable NSString *)metadata
                avatarUrl:(nullable NSURL *)avatarUrl
               completion:(nonnull SCTPrivateChannelCompletion)completion
NS_SWIFT_NAME(update(subject:label:metadata:avatarUrl:completion:));

/// Add members to the channel.
/// @param members the user id and role to be added.
/// @param accessPriorHistory Defaults to YES. the added members can see messages from the current state.
/// @param completion The handler block to execute.
/// @note The current user should hav a respectively  permission.
- (void)addMembers:(NSArray<SCTMember *> *)members accessPriorHistory:(BOOL)accessPriorHistory completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(add(members:accessPriorHistory:completion:));

@end

NS_ASSUME_NONNULL_END
