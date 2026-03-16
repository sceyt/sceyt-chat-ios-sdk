//
//  SCTSDPData.h
//  SceytChat
//
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

//MARK: - MappingEntry
NS_SWIFT_NAME(SDPData.MappingEntry)
@interface SCTMappingEntry : NSObject
@property (nonatomic, readonly) uint32_t id;
@property (nonatomic, readonly) uint32_t mapKey;

- (instancetype)initWithId:(uint32_t)id mapKey:(uint32_t)mapKey;
@end

//MARK: - FmtpParam
NS_SWIFT_NAME(SDPData.FmtpParam)
@interface SCTFmtpParam : NSObject
@property (nonatomic, readonly, nonnull) NSString *key;
@property (nonatomic, readonly, nonnull) NSString *value;

- (instancetype)initWithKey:(nonnull NSString *)key value:(nonnull NSString *)value;
@end

//MARK: - Codec
NS_SWIFT_NAME(SDPData.Codec)
@interface SCTCodec : NSObject
@property (nonatomic, readonly, nonnull) SCTMappingEntry *codecName;
@property (nonatomic, readonly, nonnull) NSArray<SCTFmtpParam *> *fmtp;
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *rtcpFeedbackIds; // Array of uint32_t

- (instancetype)initWithCodecName:(nonnull SCTMappingEntry *)codecName
                             fmtp:(nonnull NSArray<SCTFmtpParam *> *)fmtp
                  rtcpFeedbackIds:(nonnull NSArray<NSNumber *> *)rtcpFeedbackIds;
@end

//MARK: - Ssrc
NS_SWIFT_NAME(SDPData.Ssrc)
@interface SCTSsrc : NSObject
@property (nonatomic, readonly) uint32_t id;
@property (nonatomic, readonly, nullable) NSString *cname;
@property (nonatomic, readonly, nullable) NSString *msid;

- (instancetype)initWithId:(uint32_t)id cname:(nullable NSString *)cname msid:(nullable NSString *)msid;
@end

//MARK: - SsrcGroup
NS_SWIFT_NAME(SDPData.SsrcGroup)
@interface SCTSsrcGroup : NSObject
@property (nonatomic, readonly, nonnull) NSString *semantics;
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *ssrcs; // Array of uint32_t

- (instancetype)initWithSemantics:(nonnull NSString *)semantics ssrcs:(nonnull NSArray<NSNumber *> *)ssrcs;
@end

//MARK: - Fingerprint
NS_SWIFT_NAME(SDPData.Fingerprint)
@interface SCTFingerprint : NSObject
@property (nonatomic, readonly) SCTHashFunction hashFunc;
@property (nonatomic, readonly, nonnull) NSData *fingerprintHashValue; // Binary hash value

- (instancetype)initWithHashFunc:(SCTHashFunction)hashFunc fingerprintHashValue:(nonnull NSData *)fingerprintHashValue;
@end

//MARK: - IceCandidate
NS_SWIFT_NAME(SDPData.IceCandidate)
@interface SCTIceCandidate : NSObject
@property (nonatomic, readonly) uint32_t foundation;
@property (nonatomic, readonly) uint32_t component;
@property (nonatomic, readonly) SCTIceCandidateProtocol protocolType;
@property (nonatomic, readonly) uint32_t priority;
@property (nonatomic, readonly, nonnull) NSData *ip; // Binary IP
@property (nonatomic, readonly) uint32_t port;
@property (nonatomic, readonly) SCTIceCandidateType type;
@property (nonatomic, readonly, nullable) NSData *raddr; // Binary related address
@property (nonatomic, readonly) uint32_t rport;
@property (nonatomic, readonly) SCTIceCandidateTcpType tcptype;

- (instancetype)initWithFoundation:(uint32_t)foundation
                          component:(uint32_t)component
                       protocolType:(SCTIceCandidateProtocol)protocolType
                           priority:(uint32_t)priority
                                 ip:(nonnull NSData *)ip
                               port:(uint32_t)port
                               type:(SCTIceCandidateType)type
                              raddr:(nullable NSData *)raddr
                               rport:(uint32_t)rport
                            tcptype:(SCTIceCandidateTcpType)tcptype;
@end

//MARK: - Media
NS_SWIFT_NAME(SDPData.Media)
@interface SCTMedia : NSObject
@property (nonatomic, readonly) SCTMediaType type;
@property (nonatomic, readonly, nullable) NSString *mid;
@property (nonatomic, readonly) SCTMediaDirection direction;
@property (nonatomic, readonly, nullable) NSString *msidStream;
@property (nonatomic, readonly, nullable) NSString *msidTrackLabel;
@property (nonatomic, readonly) uint64_t msidTrackId;
@property (nonatomic, readonly) BOOL rtcpMux;
@property (nonatomic, readonly) BOOL rtcpRsize;
@property (nonatomic, readonly, nonnull) NSArray<SCTMappingEntry *> *extmaps;
@property (nonatomic, readonly, nonnull) NSArray<SCTCodec *> *codecs;
@property (nonatomic, readonly, nonnull) NSArray<SCTSsrcGroup *> *ssrcGroups;
@property (nonatomic, readonly, nonnull) NSArray<SCTSsrc *> *ssrcs;
@property (nonatomic, readonly, nullable) NSString *connectionAddress;
@property (nonatomic, readonly, nonnull) NSArray<SCTIceCandidate *> *candidates;
@property (nonatomic, readonly) BOOL endOfCandidates;
@property (nonatomic, readonly, nullable) NSString *rtcpAddress;
@property (nonatomic, readonly) uint32_t iceUfragRef;
@property (nonatomic, readonly) uint32_t icePwdRef;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *iceOptions;
@property (nonatomic, readonly, nullable) SCTFingerprint *fingerprint;
@property (nonatomic, readonly) SCTDTLSSetup setup;
@property (nonatomic, readonly) uint32_t port;

- (instancetype)initWithType:(SCTMediaType)type
                          mid:(nullable NSString *)mid
                    direction:(SCTMediaDirection)direction
                   msidStream:(nullable NSString *)msidStream
               msidTrackLabel:(nullable NSString *)msidTrackLabel
                  msidTrackId:(uint64_t)msidTrackId
                      rtcpMux:(BOOL)rtcpMux
                    rtcpRsize:(BOOL)rtcpRsize
                      extmaps:(nonnull NSArray<SCTMappingEntry *> *)extmaps
                       codecs:(nonnull NSArray<SCTCodec *> *)codecs
                   ssrcGroups:(nonnull NSArray<SCTSsrcGroup *> *)ssrcGroups
                        ssrcs:(nonnull NSArray<SCTSsrc *> *)ssrcs
            connectionAddress:(nullable NSString *)connectionAddress
                  candidates:(nonnull NSArray<SCTIceCandidate *> *)candidates
           endOfCandidates:(BOOL)endOfCandidates
                rtcpAddress:(nullable NSString *)rtcpAddress
                iceUfragRef:(uint32_t)iceUfragRef
                 icePwdRef:(uint32_t)icePwdRef
                 iceOptions:(nonnull NSArray<NSString *> *)iceOptions
                 fingerprint:(nullable SCTFingerprint *)fingerprint
                       setup:(SCTDTLSSetup)setup
                        port:(uint32_t)port;
@end

//MARK: - SDPData
NS_SWIFT_NAME(SDPData)
@interface SCTSDPData : NSObject
@property (nonatomic, readonly, nonnull) NSString *sessionId;
@property (nonatomic, readonly) uint32_t sessionVersion;
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *bundleGroup; // Array of uint32_t
@property (nonatomic, readonly, nullable) NSString *iceUfrag;
@property (nonatomic, readonly, nullable) NSString *icePwd;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *iceOptions;
@property (nonatomic, readonly, nullable) SCTFingerprint *fingerprint;
@property (nonatomic, readonly) SCTDTLSSetup setup;
@property (nonatomic, readonly, nonnull) NSArray<SCTMedia *> *media;
@property (nonatomic, readonly, nullable) NSString *sessionName;
@property (nonatomic, readonly, nullable) NSString *originAddress;
@property (nonatomic, readonly, nullable) NSString *connectionAddress;
@property (nonatomic, readonly, nullable) NSString *msidSemantic;
@property (nonatomic, readonly) BOOL iceLite;
@property (nonatomic, readonly) BOOL extmapAllowMixed;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *stringPool;

- (instancetype)initWithSessionId:(nonnull NSString *)sessionId
                    sessionVersion:(uint32_t)sessionVersion
                       bundleGroup:(nonnull NSArray<NSNumber *> *)bundleGroup
                          iceUfrag:(nullable NSString *)iceUfrag
                           icePwd:(nullable NSString *)icePwd
                       iceOptions:(nonnull NSArray<NSString *> *)iceOptions
                       fingerprint:(nullable SCTFingerprint *)fingerprint
                             setup:(SCTDTLSSetup)setup
                             media:(nonnull NSArray<SCTMedia *> *)media
                       sessionName:(nullable NSString *)sessionName
                      originAddress:(nullable NSString *)originAddress
                  connectionAddress:(nullable NSString *)connectionAddress
                       msidSemantic:(nullable NSString *)msidSemantic
                            iceLite:(BOOL)iceLite
                    extmapAllowMixed:(BOOL)extmapAllowMixed
                         stringPool:(nonnull NSArray<NSString *> *)stringPool;
@end

NS_ASSUME_NONNULL_END

