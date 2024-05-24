//
//  SCTUserSettings.h
//  SceytChat
//
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTMute;
@class SCTPresence;
@class SCTPrivacySetting;
@class SCTPrivacySettings;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UserSettings)
@interface SCTUserSettings : NSObject

/// The uploadable file size limit. (The unit is bytes.).
@property (nonatomic, readonly) NSUInteger uploadSizeLimit;

@property (nonatomic, readonly, nullable) SCTMute *mute;

@property (nonatomic, readonly, nullable) SCTPresence *presence;

@property (nonatomic, readonly, nullable) SCTPrivacySettings *privacySettings;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end


NS_SWIFT_NAME(UserSettings.Builder)
@interface SCTUserSettingsBuilder: NSObject

- (instancetype)init;

- (instancetype)mute:(SCTMute *)mute;
- (instancetype)presence:(SCTPresence *)presence;
- (instancetype)privacySettings:(NSArray<SCTPrivacySetting*> *)settings;

/// Create UserSettings
- (SCTUserSettings *)build;

@end

NS_ASSUME_NONNULL_END
