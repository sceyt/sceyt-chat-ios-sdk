//
//  SCTClientDelegate.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTChatClient;

NS_SWIFT_NAME(ChatClientDelegate)
@protocol SCTChatClientDelegate <NSObject>
@optional

/// Invoked when connection status changes.
/// @param chatClient the chat client.
/// @param status current connection status.
- (void)chatClient:(SCTChatClient *)chatClient connectStatusDidChange:(SCTConnectStatus)status
NS_SWIFT_NAME(chatClient(_:didChange:));

/// Invoked when the client's token will expire soon.
/// @param chatClient the chat client.
/// @param timeInterval after which token will expire.
- (void)chatClient:(SCTChatClient *)chatClient tokenWillExpire:(NSTimeInterval)timeInterval
NS_SWIFT_NAME(chatClient(_:tokenWillExpire:));

/// Invoked when the client's token has expired.
/// @param chatClient the chat client.
- (void)chatClientTokenExpired:(SCTChatClient *)chatClient
NS_SWIFT_NAME(chatClientTokenExpired(_:));

@end

NS_ASSUME_NONNULL_END
