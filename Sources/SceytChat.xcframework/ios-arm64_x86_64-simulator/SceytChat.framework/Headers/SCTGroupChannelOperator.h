//
//  SCTGroupChannelOperator.h
//  SceytChat
//
//  Created by Hovsep on 8/23/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import "SCTChannelOperator.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(GroupChannelOperator)
@interface SCTGroupChannelOperator : SCTChannelOperator

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Change the channel owner.
/// @param userId the new owner user id.
/// @param completion The handler block to execute.
/// @note Only owner can set new owner.
- (void)changeOwnerWithNewOwnerId:(SCTUserId)userId completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(changeOwner(newOwnerId:completion:));

/// Change the channel members role.
/// @param members the new roles.
/// @param completion The handler block to execute.
/// @note The current user should hav a respectively  permission.
- (void)changeMembersRole:(NSArray<SCTMember *> *)members completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(changeMembersRole(_:completion:));

/// Add members to the channel.
/// @param members the user id and role to be added.
/// @param completion The handler block to execute.
/// @note The current user should hav a respectively  permission.
- (void)addMembers:(NSArray<SCTMember *> *)members completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(add(members:completion:));

/// Kick members from the channel.
/// @param ids the user ids to be kicked.
/// @param completion The handler block to execute.
- (void)kickMembersWithMemberIds:(NSArray<SCTUserId> *)ids completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(kickMembers(ids:completion:));

/// Block members for do not receive notifications from theirs.
/// @param ids the user ids to be blocked.
/// @param completion The handler block to execute.
- (void)blockMembersWithMemberIds:(NSArray<SCTUserId> *)ids completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(blockMembers(ids:completion:));

/// Unblock members.
/// @param ids the user ids to be unblocked.
/// @param completion The handler block to execute.
- (void)unblockMembersWithMemberIds:(NSArray<SCTUserId> *)ids completion:(nonnull SCTChannelMembersCompletion)completion
NS_SWIFT_NAME(unblockMembers(ids:completion:));

/// Leave the  channel. The channel will be disappeared from the current user channel list.
/// @param completion The handler block to execute.
- (void)leaveWithCompletion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(leave(completion:));

/// Block the  channel. After block no one can add the current user to the channel.
/// @param completion The handler block to execute.
/// @note The current user will live from the channel after block.
- (void)blockWithCompletion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(block(completion:));

/// Unblock the channel.
/// @param completion The handler block to execute.
/// @note After unblock the current user not joining to the channel automatically.
/// For SCTPublicChannel the current user shell join otherwise the operator user shell add the current user.
- (void)unblockWithCompletion:(nonnull SCTCompletion)completion
NS_SWIFT_NAME(unblock(completion:));

@end

NS_ASSUME_NONNULL_END
