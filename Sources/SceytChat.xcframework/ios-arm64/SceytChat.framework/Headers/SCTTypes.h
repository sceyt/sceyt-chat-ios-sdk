//
//  SCTTypes.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#ifndef SCTTypes_h
#define SCTTypes_h
#import <Foundation/Foundation.h>

@class SCTMessage;
@class SCTReaction;
@class SCTChannel;
@class SCTUser;
@class SCTRole;
@class SCTMember;
@class SCTError;
@class SCTAttachment;
@class SCTMarker;
@class SCTChannelInviteKeyRequest;
@class SCTChannelInviteKeyCreateParam;
@class SCTChannelInviteKeyUpdateParam;
@class SCTChannelInviteKeyRevokeParam;
@class SCTChannelInviteKeyDeleteParam;
@class SCTChannelInviteKeyGetInviteKeyParam;
@class SCTChannelInviteKeyGetInviteKeysParam;
@class SCTChannelInviteKeyGetRevokedParam;
@class SCTChannelInviteKeyRegenerateParam;
@class SCTChannelInviteKey;
@class SCTChannelInviteKeyResponse;
@class SCTMessageListMarker;
@class SCTAttachmentListQuery;
@class SCTMessageListQuery;
@class SCTReactionListQuery;
@class SCTChannelListQuery;
@class SCTMemberListQuery;
@class SCTUserListQuery;
@class SCTBlockedUserListQuery;
@class SCTBlockedMemberListQuery;
@class SCTBlockedChannelListQuery;
@class SCTHiddenChannelListQuery;
@class SCTMessageMarkerListQuery;
@class SCTMessageListQueryByType;
@class SCTContactDiscovery;
@class SCTContact;
@class SCTUserSettings;
@class SCTSignal;
@class SCTLinkDetails;
@class SCTPrivacyException;
@class SCTPrivacyExceptionListQuery;
@class SCTUnreadMentionsListQuery;
@class SCTMetaFilter;
@class SCTTurnServer;
@class SCTSignalCall;
@class SCTCallDetailRecord;
@class SCTCDRParticipant;
@class SCTCDRListQuery;
@class SCTPollOption;
@class SCTPollOptionBuilder;
@class SCTPollBuilder;
@class SCTPollVote;
@class SCTPollDetails;
@class SCTPollBuilder;
@class SCTPollVotesListQuery;
@class SCTChangedVotes;
@class SCTVoteDetails;
@class SCTFingerprint;
@class SCTFmtpParam;
@class SCTExtmapEntry;
@class SCTCodec;
@class SCTSsrc;
@class SCTSsrcGroup;
@class SCTIceCandidate;
@class SCTMedia;
@class SCTSDPData;

NS_SWIFT_NAME(UserId)
typedef NSString * SCTUserId NS_SWIFT_BRIDGED_TYPEDEF;
NS_SWIFT_NAME(ContactId)
typedef NSString * SCTContactId NS_SWIFT_BRIDGED_TYPEDEF;
NS_SWIFT_NAME(ChannelId)
typedef UInt64 SCTChannelId NS_SWIFT_BRIDGED_TYPEDEF;
NS_SWIFT_NAME(MessageId)
typedef UInt64 SCTMessageId NS_SWIFT_BRIDGED_TYPEDEF;
NS_SWIFT_NAME(AttachmentId)
typedef UInt64 SCTAttachmentId NS_SWIFT_BRIDGED_TYPEDEF;
NS_SWIFT_NAME(ReactionId)
typedef UInt64 SCTReactionId NS_SWIFT_BRIDGED_TYPEDEF;


typedef NS_ENUM(NSUInteger, SCTConnectionState) {
    SCTConnectionStateConnecting,
    SCTConnectionStateReconnecting,
    SCTConnectionStateConnected,
    SCTConnectionStateDisconnected,
    SCTConnectionStateFailed
}NS_SWIFT_NAME(ConnectionState);

typedef NS_ENUM(NSInteger, SCTPresenceState) {
    SCTPresenceStateOffline,
    SCTPresenceStateOnline,
    SCTPresenceStateInvisible,
    SCTPresenceStateAway,
    SCTPresenceStateDND,
}NS_SWIFT_NAME(PresenceState);

typedef NS_ENUM(NSUInteger, SCTDeleteMessageType) {
    SCTDeleteMessageTypeDeleteHard,
    SCTDeleteMessageTypeDeleteForEveryone,
    SCTDeleteMessageTypeDeleteForMe
}NS_SWIFT_NAME(DeleteMessageType);

typedef NS_ENUM(NSInteger, SCTUserState) {
    SCTUserStateActive,
    SCTUserStateInactive,
    SCTUserStateDeleted,
}NS_SWIFT_NAME(UserState);

//The search operator types.
typedef NS_ENUM(NSInteger, SCTSearchQueryOperator) {
    SCTSearchQueryOperatorNone,
    SCTSearchQueryOperatorContains,
    SCTSearchQueryOperatorBegins,
    SCTSearchQueryOperatorEQ,
    SCTSearchQueryOperatorLT,
    SCTSearchQueryOperatorLTE,
    SCTSearchQueryOperatorGT,
    SCTSearchQueryOperatorGTE,
    SCTSearchQueryOperatorIn,
    SCTSearchQueryOperatorBetween,
}NS_SWIFT_NAME(SearchQueryOperator);

typedef NS_ENUM(NSInteger, SCTMessageQueryDirection) {
    SCTMessageQueryDirectionNext,
    SCTMessageQueryDirectionPrevious,
    SCTMessageQueryDirectionNear,
}NS_SWIFT_NAME(MessageQueryDirection);

typedef NS_ENUM(NSInteger, SCTMessageQuerySearchKey) {
    SCTMessageQuerySearchKeyBody,
    SCTMessageQuerySearchKeyType,
    SCTMessageQuerySearchKeyAttachmentType,
}NS_SWIFT_NAME(MessageQuerySearchKey);

typedef NS_ENUM(NSInteger, SCTQueryOrderType) {
    SCTQueryOrderChronological,
    SCTQueryOrderAscending,
    SCTQueryOrderDescending
}NS_SWIFT_NAME(QueryOrderType);

//The order type for `SCTChannelListQuery`.
typedef NS_ENUM(NSInteger, SCTChannelListOrder) {
    //Last message order for group channel.
    SCTChannelListOrderLastMessage,
    //creation date order for group channel.
    SCTChannelListOrderCreatedAt,
}NS_SWIFT_NAME(ChannelListOrder);

//The filter type for `SCTChannelListQuery`.
typedef NS_ENUM(NSInteger, SCTChannelListFilterKey) {
    SCTChannelListFilterNone,
    SCTChannelListFilterSubject,
    SCTChannelListFilterURI,
    SCTChannelListFilterLabel,
    SCTChannelListFilterUser
}NS_SWIFT_NAME(ChannelListFilterKey);

//The order type for `SCTUserListOrder`.
typedef NS_ENUM(NSInteger, SCTUserListOrder) {
    SCTUserListOrderFirstName,
    SCTUserListOrderLastName,
}NS_SWIFT_NAME(UserListOrder);

//The order type for `SCTMemberListOrder`.
typedef NS_ENUM(NSInteger, SCTMemberListOrder) {
    SCTMemberListOrderUsername,
    SCTMemberListOrderFirstName,
    SCTMemberListOrderLastName,
}NS_SWIFT_NAME(MemberListOrder);

//The filter type for `SCTUserListFilterType`.
typedef NS_ENUM(NSInteger, SCTUserListFilterType) {
    SCTUserListFilterTypeAll,
    SCTUserListFilterTypeUsername,
    SCTUserListFilterTypeFirstName,
    SCTUserListFilterTypeLastName,
}NS_SWIFT_NAME(UserListFilterType);

//The query type for `SCTMemberListQueryType`.
typedef NS_ENUM(NSInteger, SCTMemberListQueryType) {
    SCTMemberListQueryAll,
    SCTMemberListQueryPrivileged,
}NS_SWIFT_NAME(MemberListQueryType);

typedef NS_ENUM(NSInteger, SCTMessageDeliveryStatus) {
    SCTMessageDeliveryStatusPending,
    SCTMessageDeliveryStatusSent,
    SCTMessageDeliveryStatusReceived,
    SCTMessageDeliveryStatusDisplayed,
    SCTMessageDeliveryStatusFailed
}NS_SWIFT_NAME(MessageDeliveryStatus);

typedef NS_ENUM(NSInteger, SCTMessageState) {
    SCTMessageStateUnmodified,
    SCTMessageStateEdited,
    SCTMessageStateDeleted,
    SCTMessageStateModerated,
}NS_SWIFT_NAME(MessageState);

typedef NS_ENUM(NSInteger, SCTLogLevel) {
    SCTLogLevelNone,
    SCTLogLevelFatal,
    SCTLogLevelError,
    SCTLogLevelWarning,
    SCTLogLevelInfo,
    SCTLogLevelVerbose
}NS_SWIFT_NAME(LogLevel);

typedef NS_ENUM(NSInteger, SCTPrivacyAccess) {
    SCTPrivacyAccessDefault,
    SCTPrivacyAccessAnybody,
    SCTPrivacyAccessNobody,
    SCTPrivacyAccessContacts,
}NS_SWIFT_NAME(PrivacyAccess);

typedef NS_ENUM(NSInteger, SCTPrivacyKey) {
    SCTPrivacyKeyLastActiveAt,
    SCTPrivacyKeyPresenceState,
    SCTPrivacyKeyPresenceStatus,
    SCTPrivacyKeyProfilePhoto,
    SCTPrivacyKeyAddToChannels,
    SCTPrivacyKeyForwardMessages,
    SCTPrivacyKeyReadReceipts,
    SCTPrivacyKeyCall,
    SCTPrivacyKeyCallWithRing,
}NS_SWIFT_NAME(PrivacyKey);

typedef NS_ENUM(NSInteger, SCTPrivacyType) {
    SCTPrivacyTypeInclusion,
    SCTPrivacyTypeExclusion,
}NS_SWIFT_NAME(PrivacyType);

typedef NS_ENUM(NSInteger, SCTMediaFlow) {
    p2p,
    sfu,
}NS_SWIFT_NAME(MediaFlow);

typedef NS_ENUM(NSInteger, SCTMediaType) {
    SCTMediaTypeAudio = 0,
    SCTMediaTypeVideo = 1,
    SCTMediaTypeUnspecified = 2,
}NS_SWIFT_NAME(MediaType);

typedef NS_ENUM(NSInteger, SCTMediaDirection) {
    SCTMediaDirectionSendRecv = 0,
    SCTMediaDirectionSendOnly = 1,
    SCTMediaDirectionRecvOnly = 2,
    SCTMediaDirectionInactive = 3,
    SCTMediaDirectionUnspecified = 4,
}NS_SWIFT_NAME(MediaDirection);

typedef NS_ENUM(NSInteger, SCTHashFunction) {
    SCTHashFunctionSHA256 = 0,
    SCTHashFunctionSHA1 = 1,
    SCTHashFunctionSHA384 = 2,
    SCTHashFunctionSHA512 = 3,
    SCTHashFunctionMD5 = 4,
}NS_SWIFT_NAME(HashFunction);

typedef NS_ENUM(NSInteger, SCTSetup) {
    SCTSetupActive = 0,
    SCTSetupPassive = 1,
    SCTSetupActPass = 2,
}NS_SWIFT_NAME(Setup);

typedef NS_ENUM(NSInteger, SCTIceCandidateProtocol) {
    SCTIceCandidateProtocolUDP = 0,
    SCTIceCandidateProtocolTCP = 1,
}NS_SWIFT_NAME(IceCandidateProtocol);

typedef NS_ENUM(NSInteger, SCTIceCandidateType) {
    SCTIceCandidateTypeHost = 0,
    SCTIceCandidateTypeSrflx = 1,
    SCTIceCandidateTypePrflx = 2,
    SCTIceCandidateTypeRelay = 3,
}NS_SWIFT_NAME(IceCandidateType);

typedef NS_ENUM(NSInteger, SCTIceCandidateTcpType) {
    SCTIceCandidateTcpTypeActive = 0,
    SCTIceCandidateTcpTypePassive = 1,
    SCTIceCandidateTcpTypeSO = 2,
}NS_SWIFT_NAME(IceCandidateTcpType);

typedef NS_ENUM(NSInteger, CDRCallState) {
    CDRCallStateOngoing,
    CDRCallStateClosed,
}NS_SWIFT_NAME(CallState);

typedef NS_ENUM(NSUInteger, SCTSignalEvent) {
    SCTSignalEventJoin,
    SCTSignalEventLeave,
    SCTSignalEventOffer,
    SCTSignalEventAnswer,
    SCTSignalEventConnect,
    SCTSignalEventError,
    SCTSignalEventKick,
    SCTSignalEventSuccess,
    SCTSignalEventInvite,
    SCTSignalEventDecline,
    SCTSignalEventRinging,
    SCTSignalEventInfo,
    SCTSignalEventUpdate,
    SCTSignalEventClose,
    SCTSignalEventIce,
    SCTSignalEventGetCall,
    SCTSignalEventSwitchMediaFlow,
    SCTSignalEventNoAnswer,
    SCTSignalEventMediaConnected,
    SCTSignalEventMute,
    SCTSignalEventUnMute,
    SCTSignalEventHold,
    SCTSignalEventUnHold,
    SCTSignalEventVideoOn,
    SCTSignalEventVideoOff,
    SCTSignalEventScreenShareOn,
    SCTSignalEventScreenShareOff,
}NS_SWIFT_NAME(Signal.Event);

typedef NS_ENUM(NSUInteger, SCTParticipantState) {
    SCTParticipantStateIdle,
    SCTParticipantStateRinging,
    SCTParticipantStateJoined,
    SCTParticipantStateLeft,
    SCTParticipantStateDeclined,
    SCTParticipantStateKicked,
    SCTParticipantStateNoAnswer,
}NS_SWIFT_NAME(ParticipantState);

typedef NS_ENUM(NSUInteger, SCTParticipantConnectionState) {
    SCTParticipantConnectionStateIdle,
    SCTParticipantConnectionStateConnecting,
    SCTParticipantConnectionStateConnected,
    SCTParticipantConnectionStateReconnecting,
    SCTParticipantConnectionStateDisconnected,
}NS_SWIFT_NAME(ParticipantMediaConnectionState);

typedef void(^SCTCompletion)(SCTError * _Nullable)
NS_SWIFT_NAME(Completion);
typedef void(^SCTUserProfileCompletion)(SCTUser * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(UserProfileCompletion);
typedef void(^SCTChannelCompletion)(SCTChannel * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(ChannelCompletion);
typedef void(^SCTGetUsersCompletion)(NSArray <SCTUser *> * _Nullable, SCTError *_Nullable)
NS_SWIFT_NAME(GetUsersCompletion);
typedef void(^SCTGetRolesCompletion)(NSArray <SCTRole *> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(GetRolesCompletion);
typedef void(^SCTGetUnreadCountCompletion)(NSUInteger totalUnreadChannelCount, NSUInteger totalUnreadMessageCount, SCTError * _Nullable)
NS_SWIFT_NAME(GetUnreadCountCompletion);
typedef void(^SCTMessageCompletion)(SCTMessage * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(MessageCompletion);
typedef void(^SCTReactionCompletion)(SCTReaction * _Nullable, SCTMessage * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(ReactionCompletion);
typedef void(^SCTPollVoteCompletion)(SCTChangedVotes * _Nullable, SCTMessage * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(PollVoteCompletion);
typedef void(^SCTClosePollCompletion)(SCTVoteDetails * _Nullable, SCTMessage * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(ClosePollCompletion);
typedef void(^SCTReactionListQueryCompletion)(SCTReactionListQuery * _Nonnull, NSArray <SCTReaction *> * _Nullable newLoadedReactions, SCTError *_Nullable)
NS_SWIFT_NAME(ReactionListQueryCompletion);
typedef void(^SCTMessageMarkerListCompletion)(SCTMessageListMarker * _Nullable, SCTError *_Nullable)
NS_SWIFT_NAME(MessageMarkerListCompletion);
typedef void(^SCTChannelMembersCompletion)(SCTChannel * _Nullable, NSArray<SCTMember*> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(ChannelMembersCompletion);
typedef void(^SCTProgressCompletion)(double progress)
NS_SWIFT_NAME(ProgressCompletion);
typedef void(^SCTAttachmentCompletion)(SCTAttachment * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(AttachmentCompletion);
typedef void(^SCTFileCompletion)(NSURL * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(FileCompletion);
typedef void(^SCTMessageListQueryCompletion)(SCTMessageListQuery * _Nonnull, NSArray<SCTMessage *> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(MessageListQueryCompletion);
typedef void(^SCTMessageListCompletion)(NSArray<SCTMessage *> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(MessageListCompletion);
typedef void(^SCTMessageListQueryByTypeCompletion)(SCTMessageListQueryByType * _Nonnull, NSArray<SCTMessage *> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(MessageListQueryByTypeCompletion);
typedef void(^SCTAttachmentListQueryCompletion)(SCTAttachmentListQuery * _Nonnull, NSArray<SCTAttachment *> * _Nullable, NSArray <SCTUser *> * _Nullable ownerUsers, SCTError * _Nullable)
NS_SWIFT_NAME(AttachmentListQueryCompletion);
typedef void(^SCTMessageMarkerListQueryCompletion)(SCTMessageMarkerListQuery * _Nonnull, NSArray<SCTMarker *> * _Nullable newLoadedMarkers, SCTError *_Nullable)
NS_SWIFT_NAME(MessageMarkerListQueryCompletion);
typedef void(^SCTChannelListQueryCompletion)(SCTChannelListQuery * _Nonnull, NSArray <SCTChannel *> * _Nullable newLoadedChannels, SCTError *_Nullable)
NS_SWIFT_NAME(ChannelListQueryCompletion);
typedef void(^SCTBlockedChannelListQueryCompletion)(SCTBlockedChannelListQuery * _Nonnull, NSArray <SCTChannel *> * _Nullable newLoadedChannels, SCTError *_Nullable)
NS_SWIFT_NAME(BlockedChannelListQueryCompletion);
typedef void(^SCTHiddenChannelListQueryCompletion)(SCTHiddenChannelListQuery * _Nonnull, NSArray <SCTChannel *> * _Nullable newLoadedChannels, SCTError *_Nullable)
NS_SWIFT_NAME(HiddenChannelListQueryCompletion);
typedef void(^SCTMemberListQueryCompletion)(SCTMemberListQuery * _Nonnull, NSArray <SCTMember *> * _Nullable newLoadedMembers, SCTError *_Nullable)
NS_SWIFT_NAME(MemberListQueryCompletion);
typedef void(^SCTUserListQueryCompletion)(SCTUserListQuery * _Nonnull, NSArray <SCTUser *> * _Nullable newLoadedMembers, SCTError *_Nullable)
NS_SWIFT_NAME(UserListQueryCompletion);
typedef void(^SCTBlockedUserListQueryCompletion)(SCTBlockedUserListQuery * _Nonnull, NSArray <SCTUser *> * _Nullable newLoadedMembers, SCTError *_Nullable)
NS_SWIFT_NAME(BlockedUserListQueryCompletion);
typedef void(^SCTBlockedMemberListQueryCompletion)(SCTBlockedMemberListQuery * _Nonnull, NSArray <SCTMember *> * _Nullable newLoadedMembers, SCTError *_Nullable)
NS_SWIFT_NAME(BlockedMemberListQueryCompletion);
typedef void(^SCTPrivacyExceptionListCompletion)(SCTPrivacyExceptionListQuery * _Nonnull, NSArray<SCTPrivacyException *> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(PrivacyExceptionListCompletion);
typedef void(^SCTPrivacyExceptionUserListCompletion)(SCTPrivacyExceptionListQuery * _Nonnull, NSArray<SCTUserId> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(PrivacyExceptionUserListCompletion);
typedef void(^SCTPrivacyExceptionUpdateUserListCompletion)(SCTPrivacyExceptionListQuery * _Nonnull, NSArray<SCTUserId> * _Nullable added, NSArray<SCTUserId> * _Nullable removed, SCTError * _Nullable)
NS_SWIFT_NAME(PrivacyExceptionUpdateUserListCompletion);

typedef void(^SCTContactsDiscoveryCompletion)(NSArray <SCTContactDiscovery *> * _Nullable discoveries, NSArray <SCTContact *> * _Nullable contacts, SCTError *_Nullable)
NS_SWIFT_NAME(ContactsDiscoveryCompletion);
typedef void(^SCTContactsCompletion)(NSArray <SCTContact *> * _Nullable contacts, SCTError *_Nullable)
NS_SWIFT_NAME(ContactsCompletion);
typedef void(^SCTUserSettingsCompletion)(SCTUserSettings * _Nullable settings, SCTError *_Nullable)
NS_SWIFT_NAME(UserSettingsCallback);
typedef void(^SCTSignalCompletion)(SCTSignal * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(SignalCompletion);
typedef void(^SCTLinkDetailsCompletion)(SCTLinkDetails * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(LinkDetailsCompletion);

@class SCTUnreadMentionsListQuery;
typedef void(^SCTUnreadMentionsListQueryCompletion)(SCTUnreadMentionsListQuery * _Nonnull, NSArray<NSNumber *> * _Nullable messageIds, SCTError * _Nullable)
NS_SWIFT_NAME(UnreadMentionsListQueryCompletion);

typedef void(^SCTCDRListQueryCompletion)(SCTCDRListQuery * _Nonnull, NSArray<SCTCallDetailRecord *> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(CDRListQueryCompletion);

//MARK: - Poll Completion Handlers
typedef void(^SCTPollVotesListQueryCompletion)(SCTPollVotesListQuery * _Nonnull, NSArray<SCTPollVote *> * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(PollVotesListQueryCompletion);

//MARK: - Channel Invite Key Completion Handlers
typedef void(^SCTChannelInviteKeyCompletion)(SCTChannelInviteKey * _Nullable inviteKey, SCTError * _Nullable)
NS_SWIFT_NAME(ChannelInviteKeyCompletion);
typedef void(^SCTChannelInviteKeysCompletion)(NSArray<SCTChannelInviteKey *> * _Nullable inviteKeys, SCTError * _Nullable)
NS_SWIFT_NAME(ChannelInviteKeysCompletion);

//MARK: - Channel Invite Key Types

typedef NS_ENUM(NSInteger, SCTChannelInviteKeyRequestEvent) {
    SCTChannelInviteKeyRequestEventCreateChannelInviteKey = 0,
    SCTChannelInviteKeyRequestEventUpdateChannelInviteKey = 1,
    SCTChannelInviteKeyRequestEventGetChannelInviteKey = 2,
    SCTChannelInviteKeyRequestEventGetChannelInviteKeys = 3,
    SCTChannelInviteKeyRequestEventRegenerateChannelInviteKey = 4,
    SCTChannelInviteKeyRequestEventRevokeChannelInviteKey = 5,
    SCTChannelInviteKeyRequestEventDeleteRevokedChannelInviteKey = 6,
    SCTChannelInviteKeyRequestEventGetRevokedChannelInviteKeys = 7
}NS_SWIFT_NAME(ChannelInviteKeyRequestEvent);

@interface SCTChannelInviteKeyRequest : NSObject

@property (nonatomic, assign) SCTChannelInviteKeyRequestEvent event;
@property (nonatomic, nonnull) NSString *requestId;

// Parameters for different operations
@property (nonatomic, nonnull) SCTChannelInviteKeyCreateParam *createParam;
@property (nonatomic, nonnull) SCTChannelInviteKeyUpdateParam *updateParam;
@property (nonatomic, nonnull) SCTChannelInviteKeyRevokeParam *revokeParam;
@property (nonatomic, nonnull) SCTChannelInviteKeyDeleteParam *deleteParam;
@property (nonatomic, nonnull) SCTChannelInviteKeyGetInviteKeyParam *getInviteKeyParam;
@property (nonatomic, nonnull) SCTChannelInviteKeyGetInviteKeysParam *getInviteKeysParam;
@property (nonatomic, nonnull) SCTChannelInviteKeyGetRevokedParam *getRevokedParam;
@property (nonatomic, nonnull) SCTChannelInviteKeyRegenerateParam *regenerateParam;

@end

@interface SCTChannelInviteKeyCreateParam : NSObject
@property (nonatomic, nonnull) NSString *channelId;
@property (nonatomic, assign) uint32_t maxUses;
@property (nonatomic, assign) uint64_t expiresAt;
@property (nonatomic, assign) BOOL accessPriorHistory;
@end

@interface SCTChannelInviteKeyUpdateParam : NSObject
@property (nonatomic, nonnull) NSString *channelId;
@property (nonatomic, nonnull) NSString *key;
@property (nonatomic, assign) uint32_t maxUses;
@property (nonatomic, assign) uint64_t expiresAt;
@property (nonatomic, assign) BOOL accessPriorHistory;
@end

@interface SCTChannelInviteKeyRevokeParam : NSObject
@property (nonatomic, nonnull) NSString *channelId;
@property (nonatomic, nonnull) NSArray<NSString *> *keys;
@end

@interface SCTChannelInviteKeyDeleteParam : NSObject
@property (nonatomic, nonnull) NSString *channelId;
@property (nonatomic, nonnull) NSArray<NSString *> *keys;
@end

@interface SCTChannelInviteKeyGetInviteKeyParam : NSObject
@property (nonatomic, nonnull) NSString *channelId;
@property (nonatomic, nonnull) NSString *key;
@end

@interface SCTChannelInviteKeyGetInviteKeysParam : NSObject
@property (nonatomic, nonnull) NSString *channelId;
@end

@interface SCTChannelInviteKeyGetRevokedParam : NSObject
@property (nonatomic, nonnull) NSString *channelId;
@end

@interface SCTChannelInviteKeyRegenerateParam : NSObject
@property (nonatomic, nonnull) NSString *channelId;
@property (nonatomic, nonnull) NSString *key;
@end


@interface SCTChannelInviteKey : NSObject
@property (nonatomic, nonnull) NSString *key;
@property (nonatomic, assign) uint64_t channelId;
@property (nonatomic, nonnull) SCTMember *createdBy;
@property (nonatomic, assign) uint32_t maxUses;
@property (nonatomic, assign) uint64_t expiresAt;
@property (nonatomic, assign) BOOL revoked;
@property (nonatomic, assign) uint64_t revokedAt;
@property (nonatomic, assign) BOOL accessPriorHistory;
@property (nonatomic, assign) BOOL isPrimary;
@end

@interface SCTChannelInviteKeyResponse : NSObject
@property (nonatomic, nullable) SCTChannelInviteKey *createResponse;
@property (nonatomic, nullable) SCTChannelInviteKey *regenerateResponse;
@property (nonatomic, nullable) SCTChannelInviteKey *getInviteKeyResponse;
@property (nonatomic, nullable) NSArray<SCTChannelInviteKey *> *getInviteKeysResponse;
@property (nonatomic, nullable) NSArray<SCTChannelInviteKey *> *getRevokedResponse;
@end
#endif /* SCTTypes_h */

