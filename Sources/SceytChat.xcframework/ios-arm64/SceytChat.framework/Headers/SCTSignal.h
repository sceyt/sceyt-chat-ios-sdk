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
@class SCTSDPData;
@class SCTBroadcastOptions;
@class SCTCallSettings;
@class SCTCallOptions;
@class SCTJoinOptions;
@class SCTMediaState;
@class SCTParticipantMediaState;
@class SCTParticipantPermissions;
@class SCTCallPermissions;

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

@property (nonatomic, readonly) SCTSignalOptionsCase optionsCase;
@property (nonatomic, readonly, nullable) SCTCallOptions *callOptions;
@property (nonatomic, readonly, nullable) SCTJoinOptions *joinOptions;

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
@property (nonatomic, readonly) BOOL onHold;
@property (nonatomic, readonly) BOOL isCallSilenced;
@property (nonatomic, readonly) SCTParticipantState state;
@property (nonatomic, readonly) SCTParticipantConnectionState connectionState;
@property (nonatomic, readonly, nonnull) SCTParticipantMediaState *mediaState;
@property (nonatomic, readonly, nonnull) SCTParticipantPermissions *permissions;

- (instancetype)initWithId:(nonnull NSString *)id
                  clientId:(nonnull NSString *)clientId
                 presenter:(BOOL)presenter
                    onHold:(BOOL)onHold
            isCallSilenced:(BOOL)isCallSilenced
                     state:(SCTParticipantState)state
           connectionState:(SCTParticipantConnectionState)connectionState
                mediaState:(nonnull SCTParticipantMediaState *)mediaState
               permissions:(nonnull SCTParticipantPermissions *)permissions;
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
@property (nonatomic, readonly, nullable) NSDate *createdAt;
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *metadata;
@property (nonatomic, readonly) NSArray<SCTSignalParticipant *> *participants;
@property (nonatomic, readonly, nullable) SCTCallOptions *options;

- (instancetype)initWithId:(NSString *)callId
                sessionId:(NSString *)sessionId
                mediaFlow:(SCTMediaFlow)mediaFlow
                createdBy:(NSString *)createdBy
                createdAt:(nullable NSDate *)createdAt
                 metadata:(NSDictionary<NSString *, NSString *> *)metadata
             participants:(NSArray<SCTSignalParticipant *> *)participants
                  options:(nullable SCTCallOptions *)options;
@end

NS_SWIFT_NAME(Signal.SessionData)
@interface SCTSessionData : NSObject
@property (nonatomic, readonly, nonnull) NSString *id;
@property (nonatomic, readonly, nonnull) NSString *version;
@property (nonatomic, readonly, nullable) SCTSDPData *sdpData;

- (instancetype)initWithId:(NSString *)id
                   version:(NSString *)version
                   sdpData:(nullable SCTSDPData *)sdpData;
@end

NS_SWIFT_NAME(Signal.SessionDataBuilder)
@interface SCTSessionDataBuilder : NSObject
- (instancetype)initWithId: (NSString *)id;
- (instancetype)version:(nonnull NSString *)version;
- (instancetype)sdpData:(nonnull SCTSDPData *)sdpData;
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
- (instancetype)callOptions:(nonnull SCTCallOptions *)callOptions;
- (instancetype)joinOptions:(nonnull SCTJoinOptions *)joinOptions;

/// Create Signal
- (SCTSignal *)build;

@end


NS_SWIFT_NAME(Signal.BroadcastOptions)
@interface SCTBroadcastOptions : NSObject
@property (nonatomic, readonly) BOOL enabled;
@property (nonatomic, readonly, nullable) NSString *url;
- (instancetype)initWithEnabled:(BOOL)enabled url:(nullable NSString *)url;
@end


NS_SWIFT_NAME(Signal.CallSettings)
@interface SCTCallSettings : NSObject
@property (nonatomic, readonly, nonnull) SCTBroadcastOptions *broadcastOptions;
@property (nonatomic, readonly) int64_t startsAt;
@property (nonatomic, readonly) int64_t expiresAt;
@property (nonatomic, readonly) BOOL persistent;
@property (nonatomic, readonly) BOOL notifyOnParticipantJoin;
@property (nonatomic, readonly) int32_t maxParticipantsCount;
@property (nonatomic, readonly, nonnull) SCTCallPermissions *permissions;
- (instancetype)initWithBroadcastOptions:(nonnull SCTBroadcastOptions *)broadcastOptions
                                startsAt:(int64_t)startsAt
                               expiresAt:(int64_t)expiresAt
                              persistent:(BOOL)persistent
                  notifyOnParticipantJoin:(BOOL)notifyOnParticipantJoin
                     maxParticipantsCount:(int32_t)maxParticipantsCount
                              permissions:(nonnull SCTCallPermissions *)permissions;
@end


NS_SWIFT_NAME(Signal.CallOptions)
@interface SCTCallOptions : NSObject
@property (nonatomic, readonly, nonnull) NSString *callType;
@property (nonatomic, readonly, nonnull) SCTCallSettings *settings;
- (instancetype)initWithCallType:(nonnull NSString *)callType
                        settings:(nonnull SCTCallSettings *)settings;
@end


NS_SWIFT_NAME(Signal.JoinOptions)
@interface SCTJoinOptions : NSObject
@property (nonatomic, readonly) BOOL videoEnabled;
@property (nonatomic, readonly) BOOL muted;
@property (nonatomic, readonly) BOOL screenSharing;
- (instancetype)initWithVideoEnabled:(BOOL)videoEnabled
                               muted:(BOOL)muted
                       screenSharing:(BOOL)screenSharing;
@end


NS_SWIFT_NAME(Signal.MediaState)
@interface SCTMediaState : NSObject
@property (nonatomic, readonly) BOOL enabled;
@property (nonatomic, readonly, nonnull) NSString *changedBy;
- (instancetype)initWithEnabled:(BOOL)enabled changedBy:(nonnull NSString *)changedBy;
@end


NS_SWIFT_NAME(Signal.ParticipantMediaState)
@interface SCTParticipantMediaState : NSObject
@property (nonatomic, readonly, nonnull) SCTMediaState *audio;
@property (nonatomic, readonly, nonnull) SCTMediaState *video;
@property (nonatomic, readonly, nonnull) SCTMediaState *screenShare;
- (instancetype)initWithAudio:(nonnull SCTMediaState *)audio
                        video:(nonnull SCTMediaState *)video
                  screenShare:(nonnull SCTMediaState *)screenShare;
@end


NS_SWIFT_NAME(Signal.ParticipantPermissions)
@interface SCTParticipantPermissions : NSObject
@property (nonatomic, readonly) BOOL canPublishAudio;
@property (nonatomic, readonly) BOOL canPublishVideo;
- (instancetype)initWithCanPublishAudio:(BOOL)canPublishAudio canPublishVideo:(BOOL)canPublishVideo;
@end


NS_SWIFT_NAME(Signal.CallPermissions)
@interface SCTCallPermissions : NSObject
@property (nonatomic, readonly) BOOL allowPublishAudio;
@property (nonatomic, readonly) BOOL allowPublishVideo;
- (instancetype)initWithAllowPublishAudio:(BOOL)allowPublishAudio allowPublishVideo:(BOOL)allowPublishVideo;
@end


NS_ASSUME_NONNULL_END
