//
//  SCTUserEvent.h
//  SceytChat
//
//  Copyright © 2024 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UserEvent)
@interface SCTUserEvent : NSObject

@property (nonatomic, readonly, nonnull) NSString *id;
@property (nonatomic, readonly, nonnull) NSDictionary<NSString *, NSString *> *data;

@end

NS_ASSUME_NONNULL_END
