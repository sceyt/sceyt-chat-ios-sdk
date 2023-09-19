//
//  SCTMessageBodyAttribute.h
//  SceytChat
//
//  Created by Hovsep Keropyan on 13.09.23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Message.BodyAttribute)
@interface SCTMessageBodyAttribute : NSObject

@property (nonatomic, readonly) NSInteger offset;

@property (nonatomic, readonly) NSInteger length;

@property (nonatomic, readonly, nonnull) NSString *type;

@property (nonatomic, readonly, nullable) NSString *metadata;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOffset:(NSInteger)offset length:(NSInteger)length type:(nonnull NSString *)type metadata:(nullable NSString*)metadata;

@end

NS_ASSUME_NONNULL_END
