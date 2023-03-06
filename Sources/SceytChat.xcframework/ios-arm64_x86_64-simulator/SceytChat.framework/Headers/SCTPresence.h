//
//  SCTPresence.h
//  SceytChat
//
//  Created by Hovsep on 2/17/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTUser;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Presence)
@interface SCTPresence : NSObject
/// Shows the user current presence state
@property (nonatomic, readonly) SCTPresenceState state;
/// Shows the user current presence state status
@property (nonatomic, readonly, nullable) NSString *status;
/// Shows the user last active date.
@property (nonatomic, readonly, nullable) NSDate *lastActiveAt;

@end

NS_SWIFT_NAME(PresenceMessage)
@interface SCTPresenceMessage : NSObject
@property (nonatomic, readonly, nonnull) SCTUser *user;
@property (nonatomic, readonly, nonnull) SCTPresence *presence;
@end

NS_ASSUME_NONNULL_END
