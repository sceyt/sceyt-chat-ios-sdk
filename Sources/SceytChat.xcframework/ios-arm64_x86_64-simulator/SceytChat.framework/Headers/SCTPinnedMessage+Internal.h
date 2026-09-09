//
//  SCTPinnedMessage+Internal.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import "SCTPinnedMessage.h"
#if SCEYT_STATIC
#import "SceytChat.hpp"
#else
#import <SceytChatNative/SceytChat.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface SCTPinnedMessage ()

- (instancetype)initWithCppPinnedMessage:(const SceytChat::PinnedMessage &)pinnedMessage;
+ (instancetype)withCppPinnedMessage:(const SceytChat::PinnedMessage &)pinnedMessage;
+ (NSArray<SCTPinnedMessage *> *)withCppPinnedMessages:(const std::vector<SceytChat::PinnedMessage> &)pinnedMessages;

@end

NS_ASSUME_NONNULL_END
