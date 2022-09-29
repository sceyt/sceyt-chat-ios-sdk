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
@property (nonatomic, readonly, nullable) NSURL *avatarUrl;

/// The user metadata.
@property (nonatomic, readonly, nullable) NSString *metadata;

/// Shows is the user blocked by the application current user.
@property (nonatomic, readonly) BOOL blocked;

/// The user presence status.
@property (nonatomic, readonly) SCTPresence *presence;

/// The user activity status.
@property (nonatomic, readonly) SCTUserActivityState activityState;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
