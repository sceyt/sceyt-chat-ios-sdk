//
//  SCTPinDetails.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PinDetails)
@interface SCTPinDetails : NSObject

/// Indicates if the message is pinned.
@property (nonatomic, readonly) BOOL pinned;

/// The date until the message stays pinned (nil if the pin never expires).
@property (nonatomic, readonly, nullable) NSDate *pinnedTill;

/// The pin scope, shared for all channel members or personal for the current user.
@property (nonatomic, readonly) SCTPinType pinType;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
