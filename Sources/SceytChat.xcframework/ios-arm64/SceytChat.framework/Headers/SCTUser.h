//
//  SCTUser.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTPresence;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(User)
@interface SCTUser : NSObject

/// The user unique id.
@property (nonatomic, readonly, nonnull) SCTUserId id;

/// The user  given name.
@property (nonatomic, readonly, nullable) NSString *firstName;

/// The user hereditary family name.
@property (nonatomic, readonly, nullable) NSString *lastName;

/// The user profile avatar url.
@property (nonatomic, readonly, nullable) NSString *avatarUrl;

/// The user username.
@property (nonatomic, readonly, nullable) NSString *username;

/// Shows is the user blocked by the application current user.
@property (nonatomic, readonly) BOOL blocked;

/// The user presence status.
@property (nonatomic, readonly) SCTPresence *presence;

/// The user state.
@property (nonatomic, readonly) SCTUserState state;

/// The user metadata as a dictionary.
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, NSString *> *metadataMap;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
