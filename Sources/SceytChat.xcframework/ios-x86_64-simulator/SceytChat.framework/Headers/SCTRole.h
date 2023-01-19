//
//  SCTRole.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Role)
@interface SCTRole : NSObject

/// The role name.
@property (nonatomic, readonly, nonnull) NSString *name;

/// The role priority.
@property (nonatomic, readonly) NSInteger priority;

/// The role permissions.
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *permissions;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
