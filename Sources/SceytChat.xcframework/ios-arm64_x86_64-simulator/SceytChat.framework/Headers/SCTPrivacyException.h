//
//  SCTPrivacyException.h
//  SceytChat
//
//  Copyright © 2024 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PrivacyException)
@interface SCTPrivacyException : NSObject

@property (nonatomic, readonly) SCTUserId userId;
@property (nonatomic, readonly) SCTPrivacyKey key;
@property (nonatomic, readonly) NSDate *createdAt;
@end

NS_ASSUME_NONNULL_END
