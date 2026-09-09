//
//  SCTPinDetails+Internal.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import "SCTPinDetails.h"
#if SCEYT_STATIC
#import "SceytChat.hpp"
#else
#import <SceytChatNative/SceytChat.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface SCTPinDetails ()

- (instancetype)initWithCppPinDetails:(const SceytChat::PinDetails &)pin;
+ (instancetype)withCppPinDetails:(const SceytChat::PinDetails &)pin;

@end

NS_ASSUME_NONNULL_END
