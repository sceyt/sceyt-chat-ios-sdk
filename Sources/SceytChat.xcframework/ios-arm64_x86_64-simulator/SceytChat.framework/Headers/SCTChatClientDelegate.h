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
/// @param state current connection status.
/// @param error reason for what happened
- (void)chatClient:(SCTChatClient *)chatClient connectionStateDidChange:(SCTConnectionState)state error:(nullable SCTError*)error
NS_SWIFT_NAME(chatClient(_:didChange:error:));

/// Invoked when the client's token will expire soon.
/// @param chatClient the chat client.
/// @param timeInterval after which token will expire.
- (void)chatClient:(SCTChatClient *)chatClient tokenWillExpire:(NSTimeInterval)timeInterval
NS_SWIFT_NAME(chatClient(_:tokenWillExpire:));

/// Invoked when the client's token has expired.
/// @param chatClient the chat client.
- (void)chatClientTokenExpired:(SCTChatClient *)chatClient
NS_SWIFT_NAME(chatClientTokenExpired(_:));

- (void)chatClient:(SCTChatClient *)chatClient didReceiveDirectMessage:(SCTMessage *)message
NS_SWIFT_NAME(chatClient(_:didReceiveDirectMessage:));

- (void)chatClient:(SCTChatClient *)chatClient didReceiveSignal:(SCTSignal *)signal
NS_SWIFT_NAME(chatClient(_:didReceiveSignal:));

@end

NS_ASSUME_NONNULL_END
