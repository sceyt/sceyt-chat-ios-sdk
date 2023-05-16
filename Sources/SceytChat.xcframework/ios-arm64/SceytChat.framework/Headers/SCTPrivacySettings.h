//
//  SCTPrivacySettings.h
//  SceytChat
//
//  Created by Hovsep Keropyan on 16.05.23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"


NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PrivacySetting)
@interface SCTPrivacySetting : NSObject

@property (nonatomic, readonly) SCTPrivacyKey key;
@property (nonatomic, readonly) SCTPrivacyValue value;

@end

NS_SWIFT_NAME(PrivacySettings)
@interface SCTPrivacySettings : NSObject

@property (nonatomic, readonly) SCTPrivacyValue lastActiveAt;

@property (nonatomic, readonly) SCTPrivacyValue presenceState;

@property (nonatomic, readonly) SCTPrivacyValue presenceStatus;

@property (nonatomic, readonly) SCTPrivacyValue profilePhoto;

@property (nonatomic, readonly) SCTPrivacyValue addToChannels;

@property (nonatomic, readonly) SCTPrivacyValue forwardMessages;

@property (nonatomic, readonly) SCTPrivacyValue readReceipts;

@property (nonatomic, readonly) NSArray<SCTPrivacySetting*> *settings;

@end


NS_SWIFT_NAME(PrivacySetting.Builder)
@interface SCTPrivacySettingBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (SCTPrivacySetting *)buildWithLastActiveAt:(SCTPrivacyValue)value;
+ (SCTPrivacySetting *)buildWithPresenceState:(SCTPrivacyValue)value;
+ (SCTPrivacySetting *)buildWithPresenceStatus:(SCTPrivacyValue)value;
+ (SCTPrivacySetting *)buildWithProfilePhoto:(SCTPrivacyValue)value;
+ (SCTPrivacySetting *)buildWithAddToChannels:(SCTPrivacyValue)value;
+ (SCTPrivacySetting *)buildWithForwardMessages:(SCTPrivacyValue)value;
+ (SCTPrivacySetting *)buildWithReadReceipts:(SCTPrivacyValue)value;

@end

NS_ASSUME_NONNULL_END
