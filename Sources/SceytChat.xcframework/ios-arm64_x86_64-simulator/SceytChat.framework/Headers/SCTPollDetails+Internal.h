//
//  SCTPollDetails+Internal.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import "SCTPollDetails.h"
#import "SCTChatClient+Internal.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCTPollDetails ()

- (instancetype)initWithCppPollDetails:(const SceytChat::PollDetails &)poll;
+ (instancetype)withCppPollDetails:(const SceytChat::PollDetails &)poll;

@end

NS_ASSUME_NONNULL_END

