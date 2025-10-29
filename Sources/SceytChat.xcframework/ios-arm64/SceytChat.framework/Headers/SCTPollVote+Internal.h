//
//  SCTPollVote+Internal.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import "SCTPollVote.h"
#if SCEYT_STATIC
#import "SceytChat.hpp"
#else
#import <SceytChatNative/SceytChat.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface SCTPollVote ()

- (instancetype)initWithCppPollVote:(const SceytChat::PollVote &)vote;
+ (instancetype)withCppPollVote:(const SceytChat::PollVote &)vote;
+ (NSArray<SCTPollVote *> *)withCppPollVotes:(const std::vector<SceytChat::PollVote> &)votes;

@end

NS_ASSUME_NONNULL_END

