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
@class SCTFingerprint;
@class SCTFmtpParam;
@class SCTExtmapEntry;
@class SCTCodec;
@class SCTSsrc;
@class SCTSsrcGroup;
@class SCTIceCandidate;
@class SCTMedia;
@class SCTSDPData;

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
@property (nonatomic, readonly, nonnull) SCTSDPData *sdpData;

- (instancetype)initWithId:(NSString *)id
                   version:(NSString *)version
                   sdpData:(SCTSDPData *)sdpData;
@end

NS_SWIFT_NAME(Signal.SessionDataBuilder)
@interface SCTSessionDataBuilder : NSObject
- (instancetype)initWithId: (NSString *)id;
- (instancetype)version:(nonnull NSString *)version;
- (instancetype)sdpData:(nonnull SCTSDPData *)sdpData;
- (SCTSessionData *) build;
@end

NS_SWIFT_NAME(Signal.SDPData)
@interface SCTSDPData : NSObject
@property (nonatomic, readonly, nonnull) NSString *sessionId;
@property (nonatomic, readonly) NSUInteger sessionVersion;
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *bundleGroup;
@property (nonatomic, readonly, nonnull) NSString *iceUfrag;
@property (nonatomic, readonly, nonnull) NSString *icePwd;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *iceOptions;
@property (nonatomic, readonly, nullable) SCTFingerprint *fingerprint;
@property (nonatomic, readonly) SCTSetup setup;
@property (nonatomic, readonly, nonnull) NSArray<SCTMedia *> *media;
@property (nonatomic, readonly, nonnull) NSString *sessionName;
@property (nonatomic, readonly, nonnull) NSString *originAddress;
@property (nonatomic, readonly, nonnull) NSString *connectionAddress;
@property (nonatomic, readonly, nonnull) NSString *msidSemantic;
@property (nonatomic, readonly) BOOL iceLite;
@property (nonatomic, readonly) BOOL extmapAllowMixed;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *stringPool;

- (instancetype)initWithSessionId:(NSString *)sessionId
                   sessionVersion:(NSUInteger)sessionVersion
                      bundleGroup:(NSArray<NSNumber *> *)bundleGroup
                          iceUfrag:(NSString *)iceUfrag
                           icePwd:(NSString *)icePwd
                       iceOptions:(NSArray<NSString *> *)iceOptions
                       fingerprint:(nullable SCTFingerprint *)fingerprint
                             setup:(SCTSetup)setup
                             media:(NSArray<SCTMedia *> *)media
                       sessionName:(NSString *)sessionName
                     originAddress:(NSString *)originAddress
                  connectionAddress:(NSString *)connectionAddress
                      msidSemantic:(NSString *)msidSemantic
                           iceLite:(BOOL)iceLite
                  extmapAllowMixed:(BOOL)extmapAllowMixed
                        stringPool:(NSArray<NSString *> *)stringPool;
@end

NS_SWIFT_NAME(Signal.Media)
@interface SCTMedia : NSObject
@property (nonatomic, readonly) SCTMediaType type;
@property (nonatomic, readonly, nonnull) NSString *mid;
@property (nonatomic, readonly) SCTMediaDirection direction;
@property (nonatomic, readonly, nonnull) NSString *msidStream;
@property (nonatomic, readonly, nonnull) NSString *msidTrackLabel;
@property (nonatomic, readonly) NSUInteger msidTrackId;
@property (nonatomic, readonly) BOOL rtcpMux;
@property (nonatomic, readonly) BOOL rtcpRsize;
@property (nonatomic, readonly, nonnull) NSArray<SCTExtmapEntry *> *extmaps;
@property (nonatomic, readonly, nonnull) NSArray<SCTCodec *> *codecs;
@property (nonatomic, readonly, nonnull) NSArray<SCTSsrcGroup *> *ssrcGroups;
@property (nonatomic, readonly, nonnull) NSArray<SCTSsrc *> *ssrcs;
@property (nonatomic, readonly, nonnull) NSString *connectionAddress;
@property (nonatomic, readonly, nonnull) NSArray<SCTIceCandidate *> *candidates;
@property (nonatomic, readonly) BOOL endOfCandidates;
@property (nonatomic, readonly, nonnull) NSString *rtcpAddress;
@property (nonatomic, readonly) NSUInteger iceUfragRef;
@property (nonatomic, readonly) NSUInteger icePwdRef;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *iceOptions;
@property (nonatomic, readonly, nullable) SCTFingerprint *fingerprint;
@property (nonatomic, readonly) SCTSetup setup;
@property (nonatomic, readonly) NSUInteger port;

- (instancetype)initWithType:(SCTMediaType)type
                          mid:(NSString *)mid
                     direction:(SCTMediaDirection)direction
                    msidStream:(NSString *)msidStream
                 msidTrackLabel:(NSString *)msidTrackLabel
                    msidTrackId:(NSUInteger)msidTrackId
                       rtcpMux:(BOOL)rtcpMux
                      rtcpRsize:(BOOL)rtcpRsize
                        extmaps:(NSArray<SCTExtmapEntry *> *)extmaps
                         codecs:(NSArray<SCTCodec *> *)codecs
                     ssrcGroups:(NSArray<SCTSsrcGroup *> *)ssrcGroups
                          ssrcs:(NSArray<SCTSsrc *> *)ssrcs
              connectionAddress:(NSString *)connectionAddress
                     candidates:(NSArray<SCTIceCandidate *> *)candidates
               endOfCandidates:(BOOL)endOfCandidates
                     rtcpAddress:(NSString *)rtcpAddress
                     iceUfragRef:(NSUInteger)iceUfragRef
                       icePwdRef:(NSUInteger)icePwdRef
                      iceOptions:(NSArray<NSString *> *)iceOptions
                      fingerprint:(nullable SCTFingerprint *)fingerprint
                            setup:(SCTSetup)setup
                            port:(NSUInteger)port;
@end

NS_SWIFT_NAME(Signal.Codec)
@interface SCTCodec : NSObject
@property (nonatomic, readonly) NSUInteger id;
@property (nonatomic, readonly, nonnull) NSArray<SCTFmtpParam *> *fmtp;
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *rtcpFeedbackIds;

- (instancetype)initWithId:(NSUInteger)id
                      fmtp:(NSArray<SCTFmtpParam *> *)fmtp
            rtcpFeedbackIds:(NSArray<NSNumber *> *)rtcpFeedbackIds;
@end

NS_SWIFT_NAME(Signal.Ssrc)
@interface SCTSsrc : NSObject
@property (nonatomic, readonly) NSUInteger id;
@property (nonatomic, readonly, nonnull) NSString *cname;
@property (nonatomic, readonly, nonnull) NSString *msid;

- (instancetype)initWithId:(NSUInteger)id
                     cname:(NSString *)cname
                      msid:(NSString *)msid;
@end

NS_SWIFT_NAME(Signal.SsrcGroup)
@interface SCTSsrcGroup : NSObject
@property (nonatomic, readonly, nonnull) NSString *semantics;
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *ssrcs;

- (instancetype)initWithSemantics:(NSString *)semantics
                            ssrcs:(NSArray<NSNumber *> *)ssrcs;
@end

NS_SWIFT_NAME(Signal.IceCandidate)
@interface SCTIceCandidate : NSObject
@property (nonatomic, readonly) NSUInteger foundation;
@property (nonatomic, readonly) NSUInteger component;
@property (nonatomic, readonly) SCTIceCandidateProtocol protocolType;
@property (nonatomic, readonly) NSUInteger priority;
@property (nonatomic, readonly, nonnull) NSString *ip;
@property (nonatomic, readonly) NSUInteger port;
@property (nonatomic, readonly) SCTIceCandidateType type;
@property (nonatomic, readonly, nonnull) NSString *raddr;
@property (nonatomic, readonly) NSUInteger rport;
@property (nonatomic, readonly) SCTIceCandidateTcpType tcptype;

- (instancetype)initWithFoundation:(NSUInteger)foundation
                          component:(NSUInteger)component
                       protocolType:(SCTIceCandidateProtocol)protocolType
                           priority:(NSUInteger)priority
                                 ip:(NSString *)ip
                               port:(NSUInteger)port
                               type:(SCTIceCandidateType)type
                              raddr:(NSString *)raddr
                               rport:(NSUInteger)rport
                            tcptype:(SCTIceCandidateTcpType)tcptype;
@end

NS_SWIFT_NAME(Signal.Fingerprint)
@interface SCTFingerprint : NSObject
@property (nonatomic, readonly) SCTHashFunction hashFunc;
@property (nonatomic, readonly, nonnull) NSString *fingerprintHashValue;

- (instancetype)initWithHashFunc:(SCTHashFunction)hashFunc
                fingerprintHashValue:(NSString *)fingerprintHashValue;
@end

NS_SWIFT_NAME(Signal.FmtpParam)
@interface SCTFmtpParam : NSObject
@property (nonatomic, readonly, nonnull) NSString *key;
@property (nonatomic, readonly, nonnull) NSString *value;

- (instancetype)initWithKey:(NSString *)key
                      value:(NSString *)value;
@end

NS_SWIFT_NAME(Signal.ExtmapEntry)
@interface SCTExtmapEntry : NSObject
@property (nonatomic, readonly) NSUInteger id;
@property (nonatomic, readonly) NSUInteger mapKey;

- (instancetype)initWithId:(NSUInteger)id
                    mapKey:(NSUInteger)mapKey;
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
