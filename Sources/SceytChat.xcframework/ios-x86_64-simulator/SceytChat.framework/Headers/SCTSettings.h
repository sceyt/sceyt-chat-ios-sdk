//
//  SCTSettings.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Settings)
@interface SCTSettings : NSObject

/// Shows is current user muted.
@property (nonatomic, readonly) BOOL muted;

/// Shows current user mute expire date (nil for forever) if current user muted otherwise nil.
@property (nonatomic, readonly, nullable) NSDate *muteExpireDate;

/// The uploadable file size limit. (The unit is bytes.).
@property (nonatomic, readonly) NSUInteger uploadSizeLimit;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
