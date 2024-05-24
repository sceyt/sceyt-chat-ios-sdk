//
//  SCTPrivacySettings.h
//  SceytChat
//
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTPrivacyValue;

NS_SWIFT_NAME(PrivacySetting)
@interface SCTPrivacySetting : NSObject

/// Represents a single privacy setting, encapsulating its key and current value.
@property (nonatomic, readonly) SCTPrivacyKey key;

/// Holds the value of the privacy setting, defined as a SCTPrivacyValue object.
@property (nonatomic, readonly) SCTPrivacyValue *value;

@end


NS_SWIFT_NAME(PrivacySettings)
@interface SCTPrivacySettings : NSObject

/// Privacy setting for the current user's 'last active' status.
@property (nonatomic, readonly) SCTPrivacyValue *lastActiveAt;

/// Privacy setting controlling the visibility of the current user's presence state.
@property (nonatomic, readonly) SCTPrivacyValue *presenceState;

/// Privacy setting for managing how the current user's presence status is shared.
@property (nonatomic, readonly) SCTPrivacyValue *presenceStatus;

/// Privacy setting for the current user's profile photo visibility.
@property (nonatomic, readonly) SCTPrivacyValue *profilePhoto;

/// Privacy setting related to adding the current user to channels.
@property (nonatomic, readonly) SCTPrivacyValue *addToChannels;

/// Privacy setting for forwarding messages.
@property (nonatomic, readonly) SCTPrivacyValue *forwardMessages;

/// Privacy setting governing the visibility of read receipts for the current user.
@property (nonatomic, readonly) SCTPrivacyValue *readReceipts;

/// Privacy setting for call-related information of the current user.
@property (nonatomic, readonly) SCTPrivacyValue *call;

/// Array of SCTPrivacySetting objects, representing the collection of all privacy settings for the current user.
@property (nonatomic, readonly) NSArray<SCTPrivacySetting*> *settings;

@end

NS_SWIFT_NAME(PrivacyValue)
@interface SCTPrivacyValue : NSObject

/// Defines the level of access granted in the privacy setting.
@property (nonatomic, readonly) SCTPrivacyAccess access;

/// The number of specific inclusions  in the privacy setting.
@property (nonatomic, readonly) NSInteger inclusionsCount;

/// The number of specific exclusions in the privacy setting.
@property (nonatomic, readonly) NSInteger exclusionsCount;

/// Initializes a new SCTPrivacyValue with a specified level of access.
/// - Parameter access: Specifies the access level for the privacy setting.
- (instancetype)initWithAccess:(SCTPrivacyAccess)access NS_DESIGNATED_INITIALIZER;

/// Unavailable. Use initWithAccess: to initialize SCTPrivacyValue.
- (instancetype)init NS_UNAVAILABLE;

@end


NS_SWIFT_NAME(PrivacySetting.Builder)
@interface SCTPrivacySettingBuilder : NSObject

/// Unavailable. Use the class methods for building SCTPrivacySetting instances.
- (instancetype)init NS_UNAVAILABLE;

/// Builds a privacy setting for the 'last active' status of the current user.
/// - Parameter value: The SCTPrivacyValue to apply for this setting.
+ (SCTPrivacySetting *)buildWithLastActiveAt:(SCTPrivacyValue *)value
NS_SWIFT_NAME(build(withLastActiveAt:));

/// Builds a privacy setting for the presence state of the current user.
/// - Parameter value: The SCTPrivacyValue to apply for this setting.
+ (SCTPrivacySetting *)buildWithPresenceState:(SCTPrivacyValue *)value
NS_SWIFT_NAME(build(withPresenceState:));

/// Builds a privacy setting for the presence status of the current user.
/// - Parameter value: The SCTPrivacyValue to apply for this setting.
+ (SCTPrivacySetting *)buildWithPresenceStatus:(SCTPrivacyValue *)value
NS_SWIFT_NAME(build(withPresenceStatus:));

/// Builds a privacy setting for the profile photo visibility of the current user.
/// - Parameter value: The SCTPrivacyValue to apply for this setting.
+ (SCTPrivacySetting *)buildWithProfilePhoto:(SCTPrivacyValue *)value
NS_SWIFT_NAME(build(withProfilePhoto:));

/// Builds a privacy setting for adding the current user to channels.
/// - Parameter value: The SCTPrivacyValue to apply for this setting.
+ (SCTPrivacySetting *)buildWithAddToChannels:(SCTPrivacyValue *)value
NS_SWIFT_NAME(build(withAddToChannels:));

/// Builds a privacy setting for forwarding messages from the current user.
/// - Parameter value: The SCTPrivacyValue to apply for this setting.
+ (SCTPrivacySetting *)buildWithForwardMessages:(SCTPrivacyValue *)value
NS_SWIFT_NAME(build(withForwardMessages:));

/// Builds a privacy setting for the visibility of read receipts for the current user.
/// - Parameter value: The SCTPrivacyValue to apply for this setting.
+ (SCTPrivacySetting *)buildWithReadReceipts:(SCTPrivacyValue *)value
NS_SWIFT_NAME(build(withReadReceipts:));

/// Builds a privacy setting for call information related to the current user.
/// - Parameter value: The SCTPrivacyValue to apply for this setting.
+ (SCTPrivacySetting *)buildWithCall:(SCTPrivacyValue *)value
NS_SWIFT_NAME(build(withCall:));

@end

NS_ASSUME_NONNULL_END
