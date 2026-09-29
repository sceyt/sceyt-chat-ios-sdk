//
//  SCTPinnedMessage.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTUser;
@class SCTMessage;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PinnedMessage)
@interface SCTPinnedMessage : NSObject

/// The unique pin identifier.
@property (nonatomic, readonly) NSInteger id;

/// The user who pinned the message.
@property (nonatomic, readonly, nonnull) SCTUser *pinnedBy;

/// The pinned message.
@property (nonatomic, readonly, nonnull) SCTMessage *message;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
