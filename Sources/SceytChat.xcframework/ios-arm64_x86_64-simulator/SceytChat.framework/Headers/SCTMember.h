//
//  SCTMember.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTUser.h"
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTRole;

NS_SWIFT_NAME(Member)
@interface SCTMember : SCTUser

/// The member role.
@property (nonatomic, readonly, nonnull) NSString *role;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_SWIFT_NAME(Member.Builder)
@interface SCTMemberBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create Member builder.
/// @param id The User  id .
- (instancetype)initWithId:(SCTUserId)id;

/// Set Member role.
/// @params roleName The member role name.
- (instancetype)roleName:(nonnull NSString *)roleName;

/// Create Member for add to a channel.
- (SCTMember *)build;

@end

NS_ASSUME_NONNULL_END
