//
//  SCTMute.h
//  SceytChat
//
//  Created by Hovsep Keropyan on 16.05.23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Mute)
@interface SCTMute : NSObject

/// Shows is current user muted.
@property (nonatomic, readonly) BOOL muted;

/// Shows current user mute expire date (nil for forever) if current user muted otherwise nil.
@property (nonatomic, readonly, nullable) NSDate *muteExpireDate;

@end

NS_SWIFT_NAME(Mute.Builder)
@interface SCTMuteBuilder: NSObject

- (instancetype)init;

- (instancetype)mute:(BOOL)mute;
- (instancetype)duration:(NSTimeInterval)duration;

/// Create Mute
- (SCTMute *)build;

@end

NS_ASSUME_NONNULL_END
