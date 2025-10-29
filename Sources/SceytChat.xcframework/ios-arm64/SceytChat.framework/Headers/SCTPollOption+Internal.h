//
//  SCTPollOption+Internal.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import "SCTPollOption.h"
#if SCEYT_STATIC
#import "SceytChat.hpp"
#else
#import <SceytChatNative/SceytChat.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface SCTPollOption ()

- (instancetype)initWithCppPollOption:(const SceytChat::PollOption &)option;
+ (instancetype)withCppPollOption:(const SceytChat::PollOption &)option;
+ (NSArray<SCTPollOption *> *)withCppPollOptions:(const std::vector<SceytChat::PollOption> &)options;

@end

NS_ASSUME_NONNULL_END

