//
//  SCTSignal.h
//  SceytChat
//
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTSignalIce;
@class SCTTurnServer;
@class SCTSignalError;
@class SCTSignalParticipant;
@class SCTSignalCall;
@class SCTSessionData;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Signal)
@interface SCTSignal : NSObject

@property (nonatomic, readonly, nonnull) NSString *sessionId;
@property (nonatomic, readonly) SCTMediaFlow mediaFlow;
@property (nonatomic, readonly, nonnull) NSString *callId;
@property (nonatomic, readonly) SCTSignalEvent event;

@property (nonatomic, readonly, nonnull) NSString *from;
@property (nonatomic, readonly, nonnull) NSString *to;
@property (nonatomic, readonly, nullable) SCTSignalIce *ice;
@property (nonatomic, readonly, nullable) SCTSignalError *error;
@property (nonatomic, readonly) NSDictionary<NSString*, NSString*>* metadata;

@property (nonatomic, readonly, nullable) NSArray<SCTSignalParticipant*> *participants;
@property (nonatomic, readonly, nonnull) NSArray<SCTTurnServer*> *turnServers;
@property (nonatomic, readonly, nullable) NSArray<SCTSignalCall*> *calls;
@property (nonatomic, readonly, nullable) SCTSessionData *sessionData;

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
@property (nonatomic, readonly, nonnull) NSString *clientId;
@property (nonatomic, readonly) BOOL presenter;
@property (nonatomic, readonly) BOOL videoEnabled;
@property (nonatomic, readonly) BOOL muted;
@property (nonatomic, readonly) BOOL onHold;
@property (nonatomic, readonly) BOOL screenSharing;
@property (nonatomic, readonly) BOOL isCallSilenced;
@property (nonatomic, readonly) SCTParticipantState state;
@property (nonatomic, readonly) SCTParticipantConnectionState connectionState;

- (instancetype)initWithId:(nonnull NSString *)id clientId:(nonnull NSString *)clientId videoEnabled:(BOOL)videoEnabled presenter:(BOOL)presenter muted:(BOOL)muted onHold:(BOOL)onHold screenSharing:(BOOL)screenSharing isCallSilenced:(BOOL)isCallSilenced state: (SCTParticipantState)state connectionState:(SCTParticipantConnectionState)connectionState;
- (instancetype)initWithId:(nonnull NSString *)id;
@end

NS_SWIFT_NAME(Signal.Error)
@interface SCTSignalError : NSObject
@property (nonatomic, readonly) NSInteger code;
@property (nonatomic, readonly, nonnull) NSString *message;
- (instancetype)initWithCode:(NSInteger)code message:(nonnull NSString *)message;
@end

NS_SWIFT_NAME(Signal.TurnServer)
@interface SCTTurnServer : NSObject
@property (nonatomic, readonly, nonnull) NSString *url;
@property (nonatomic, readonly, nonnull) NSString *username;
@property (nonatomic, readonly, nonnull) NSString *password;
- (instancetype)initWithUrl:(NSString *)url
                   username:(NSString *)username
                   password:(NSString *)password;
@end

NS_SWIFT_NAME(Signal.Call)
@interface SCTSignalCall : NSObject
@property (nonatomic, readonly) NSString *callId;
@property (nonatomic, readonly) NSString *sessionId;
@property (nonatomic, readonly) SCTMediaFlow mediaFlow;
@property (nonatomic, readonly) NSString *createdBy;
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *metadata;
@property (nonatomic, readonly) NSArray<SCTSignalParticipant *> *participants;

- (instancetype)initWithId:(NSString *)callId
                sessionId:(NSString *)sessionId
                mediaFlow:(SCTMediaFlow)mediaFlow
                createdBy:(NSString *)createdBy
                metadata:(NSDictionary<NSString *, NSString *> *)metadata
                participants:(NSArray<SCTSignalParticipant *> *)participants;
@end

NS_SWIFT_NAME(Signal.SessionData)
@interface SCTSessionData : NSObject
@property (nonatomic, readonly, nonnull) NSString *id;
@property (nonatomic, readonly, nonnull) NSString *version;
@property (nonatomic, readonly, nonnull) NSString *sdp;

- (instancetype)initWithId:(NSString *)id
                   version:(NSString *)version
                       sdp:(NSString *)sdp;
@end

NS_SWIFT_NAME(Singal.SessionData)
@interface SCTSessionDataBuilder : NSObject
- (instancetype)initWithId: (NSString *)id;
- (instancetype)version:(nonnull NSString *)version;
- (instancetype)sdp:(nonnull NSString *)sdp;
- (SCTSessionDataBuilder *) build;
@end

NS_SWIFT_NAME(Signal.Builder)
@interface SCTSignalBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCallId:(NSString *)callId;
- (instancetype)mediaFlow:(SCTMediaFlow)mediaFlow;
- (instancetype)event:(SCTSignalEvent)event;
- (instancetype)sessionId:(nonnull NSString *)sessionId;

- (instancetype)from:(nonnull NSString *)from;
- (instancetype)to:(nonnull NSString *)to;
- (instancetype)ice:(nonnull SCTSignalIce *)ice;
- (instancetype)participants:(nonnull NSArray<SCTSignalParticipant*> *)participants;
- (instancetype)metadata:(nonnull NSDictionary<NSString *, NSString *> *)metadata;
- (instancetype)calls:(nonnull NSArray<SCTSignalCall*> *)calls;
- (instancetype)turnServers:(nonnull NSArray<SCTTurnServer *> *)turnServers;
- (instancetype)sessionData:(nonnull SCTSessionData *)sessionData;

/// Create Signal
- (SCTSignal *)build;

@end


NS_ASSUME_NONNULL_END
