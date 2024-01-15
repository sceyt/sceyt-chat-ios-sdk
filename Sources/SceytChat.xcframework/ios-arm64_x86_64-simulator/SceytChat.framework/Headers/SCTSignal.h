//
//  SCTSignal.h
//  SceytChat
//
//  Created by Hovsep Keropyan on 23.09.23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTSignalIce;
@class SCTSignalParticipant;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Signal)
@interface SCTSignal : NSObject

@property (nonatomic, readonly) SCTMessageId id;
@property (nonatomic, readonly, nonnull) NSString *sessionId;
@property (nonatomic, readonly) SCTSignalType type;
@property (nonatomic, readonly, nonnull) NSString *roomId;
@property (nonatomic, readonly, nonnull) NSString *roomOwner;

@property (nonatomic, readonly, nonnull) NSString *signal;
@property (nonatomic, readonly) NSInteger code;
@property (nonatomic, readonly) NSInteger timestamp;

@property (nonatomic, readonly, nonnull) NSString *from;
@property (nonatomic, readonly, nonnull) NSString *to;
@property (nonatomic, readonly, nonnull) NSString *message;
@property (nonatomic, readonly, nonnull) NSString *sdp;
@property (nonatomic, readonly, nullable) SCTSignalIce *ice;
@property (nonatomic, readonly, nonnull) NSString *info;
@property (nonatomic, readonly) BOOL presenter;

@property (nonatomic, readonly, nullable) NSArray<SCTSignalParticipant*> *participants;
@property (nonatomic, readonly, nullable) NSArray<SCTSignalParticipant*> *invitedParticipants;

@property (nonatomic, readonly, nonnull) NSString *data;
@property (nonatomic, readonly) BOOL videoEnabled;

@property (nonatomic, readonly, nonnull) NSString *hostname;
@property (nonatomic, readonly, nonnull) NSString *username;
@property (nonatomic, readonly, nonnull) NSString *password;

@end

NS_SWIFT_NAME(Signal.Ice)
@interface SCTSignalIce : NSObject
@property (nonatomic, readonly, nonnull) NSString *candidate;
@property (nonatomic, readonly, nullable) NSString *sdpMid;
@property (nonatomic, readonly) NSInteger sdpMLineIndex;

- (instancetype)initWithCandidate:(nonnull NSString *)candidate sdpMid:(nullable NSString *)sdpMid sdpMLineIndex:(NSInteger)sdpMLineIndex;
@end


NS_SWIFT_NAME(Signal.Participant)
@interface SCTSignalParticipant : NSObject
@property (nonatomic, readonly, nonnull) NSString *id;
@property (nonatomic, readonly, nullable) NSString *data;
@property (nonatomic, readonly) BOOL owner;
@property (nonatomic, readonly) BOOL presenter;
@property (nonatomic, readonly) BOOL videoEnabled;
@property (nonatomic, readonly) BOOL muted;
@property (nonatomic, readonly) BOOL onHold;

- (instancetype)initWithId:(nonnull NSString *)id videoEnabled:(BOOL)videoEnabled data:(nullable NSString *)data presenter:(BOOL)presenter muted:(BOOL)muted onHold:(BOOL)onHold;
- (instancetype)initWithId:(nonnull NSString *)id;
@end



NS_SWIFT_NAME(Signal.Builder)
@interface SCTSignalBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithRoomId:(NSString *)roomId;

- (instancetype)type:(SCTSignalType)type;
- (instancetype)signal:(nonnull NSString *)signal;
- (instancetype)sessionId:(nonnull NSString *)sessionId;
- (instancetype)code:(NSInteger)code;
- (instancetype)timestamp:(NSInteger)timestamp;

- (instancetype)from:(nonnull NSString *)from;
- (instancetype)to:(nonnull NSString *)to;
- (instancetype)message:(nonnull NSString *)message;
- (instancetype)sdp:(nonnull NSString *)sdp;
- (instancetype)ice:(nonnull SCTSignalIce *)ice;
- (instancetype)info:(nonnull NSString *)info;
- (instancetype)presenter:(BOOL)presenter;
- (instancetype)participants:(nonnull NSArray<SCTSignalParticipant*> *)participants;
- (instancetype)data:(nonnull NSString *)data;
- (instancetype)videoEnabled:(BOOL)videoEnabled;

/// Create Signal
- (SCTSignal *)build;

@end


NS_ASSUME_NONNULL_END
