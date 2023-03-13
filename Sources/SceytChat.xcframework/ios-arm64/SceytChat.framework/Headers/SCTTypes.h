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
@class SCTPublicChannel;
@class SCTPrivateChannel;
@class SCTDirectChannel;
@class SCTUser;
@class SCTRole;
@class SCTMember;
@class SCTError;
@class SCTAttachment;
@class SCTMessageMarker;
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

typedef NS_ENUM(NSInteger, SCTUserActivityState) {
    SCTUserActivityStateActive,
    SCTUserActivityStateInactive,
    SCTUserActivityStateDeleted,
}NS_SWIFT_NAME(UserActivityState);

typedef NS_ENUM(NSInteger, SCTMessageQueryDirection) {
    SCTMessageQueryDirectionNext,
    SCTMessageQueryDirectionPrevious,
    SCTMessageQueryDirectionNear,
}NS_SWIFT_NAME(MessageQueryDirection);

typedef NS_ENUM(NSInteger, SCTQueryOrderType) {
    SCTQueryOrderChronological,
    SCTQueryOrderAscending,
    SCTQueryOrderDescending
}NS_SWIFT_NAME(QueryOrderType);

//The type for `SCTChannelListQuery`.
typedef NS_ENUM(NSInteger, SCTChannelQueryType) {
    //public and private channels
    SCTChannelQueryTypeAll,
    //only privates
    SCTChannelQueryTypePrivate,
    //only publics
    SCTChannelQueryTypePublic,
    //only one to one channels
    SCTChannelQueryTypeDirect
}NS_SWIFT_NAME(ChannelQueryType);

//The order type for `SCTChannelListQuery`.
typedef NS_ENUM(NSInteger, SCTChannelListOrder) {
    //Last message order for group channel.
    SCTChannelListOrderLastMessage,
    //creation date order for group channel.
    SCTChannelListOrderCreatedAt,
}NS_SWIFT_NAME(ChannelListOrder);

//The filter type for `SCTChannelListQuery`.
typedef NS_ENUM(NSInteger, SCTChannelListFilterKey) {
    SCTChannelListFilterSubject,
    SCTChannelListFilterURI,
    SCTChannelListFilterLabel,
    SCTChannelListFilterMember
}NS_SWIFT_NAME(ChannelListFilterKey);

//The filter type for `SCTChannelListQuery`.
typedef NS_ENUM(NSInteger, SCTChannelListFilterQueryType) {
    SCTChannelListFilterQueryNone,
    SCTChannelListFilterQueryContains,
    SCTChannelListFilterQueryBeginsWith,
    SCTChannelListFilterQueryEqual
}NS_SWIFT_NAME(ChannelListFilterQueryType);


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
    SCTMessageStateNone,
    SCTMessageStateEdited,
    SCTMessageStateDeleted,
}NS_SWIFT_NAME(MessageState);

typedef NS_ENUM(NSInteger, SCTLogLevel) {
    SCTLogLevelNone,
    SCTLogLevelFatal,
    SCTLogLevelError,
    SCTLogLevelWarning,
    SCTLogLevelInfo,
    SCTLogLevelVerbose
}NS_SWIFT_NAME(LogLevel);

typedef NS_ENUM(NSInteger, SCTErrorCode) {
    SCTErrorNone                   = 0,
    SCTErrorUnknown                = 10000,
    SCTErrorInvalidInitialization  = 10001,
    SCTErrorRequestTimeout         = 10002,
    SCTErrorConnectionRequired     = 10003,
    SCTErrorNetworkConnection      = 10004,
    SCTErrorAlreadyConnected       = 10005,
    SCTErrorAlreadyConnecting      = 10006,
    SCTErrorCanNotOpenFile         = 10007,
    SCTErrorQueryInProgress        = 10008,
    SCTErrorCodeInvalidPushToken   = 10009,
    
    SCTErrorBadRequest             = 40000,
    SCTErrorTooLargeMessage        = 40001,
    SCTErrorTooManyAttempts        = 40002,
    SCTErrorBadParam               = 40003,
    SCTErrorBadChannelType         = 40004,
    SCTErrorBadUsernameInToken     = 40005,
    SCTErrorChannelAlreadyExists   = 40006,
    SCTErrorMemberExist            = 40007,
    SCTErrorMemberNotExist         = 40008,
    SCTErrorMemberLimitExceeded    = 40009,
    SCTErrorInvalidMessageType     = 40010,
    SCTErrorInvalidAttachmentType  = 40011,
    SCTErrorUndefinedRole          = 40012,
    SCTErrorTooLargeMetadata       = 40013,
    SCTErrorBlockedChannel         = 40014,
    SCTErrorUserNotExist           = 40015,
    SCTErrorInvalidToken           = 40101,
    SCTErrorExpiredToken           = 40102,
    SCTErrorTokenNotActive         = 40103,
    SCTErrorUnauthorized           = 40104,
    SCTErrorNotAllowed             = 40105,
    SCTErrorAccountSuspended       = 40106,
    SCTErrorInvalidClientId        = 40107,
    SCTErrorDuplicateClientId      = 40108,
    SCTErrorItemNotFound           = 40400,
    SCTErrorChannelNotExists       = 40401,
    SCTErrorInactiveUser           = 40301,
    SCTErrorTooManyRequests        = 42900,
    SCTErrorTooManyForwarded       = 42901,
    SCTErrorInternal               = 50001,
    SCTErrorServiceUnavailable     = 50300,
    SCTErrorSessionNotFound        = 50004,
    
}NS_SWIFT_NAME(ErrorCode);

typedef void(^SCTCompletion)(SCTError * _Nullable)
NS_SWIFT_NAME(Completion);
typedef void(^SCTUserProfileCompletion)(SCTUser * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(UserProfileCompletion);
typedef void(^SCTChannelCompletion)(SCTChannel * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(ChannelCompletion);
typedef void(^SCTPublicChannelCompletion)(SCTPublicChannel * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(PublicChannelCompletion);
typedef void(^SCTPrivateChannelCompletion)(SCTPrivateChannel * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(PrivateChannelCompletion);
typedef void(^SCTDirectChannelCompletion)(SCTDirectChannel * _Nullable, SCTError * _Nullable)
NS_SWIFT_NAME(DirectChannelCompletion);
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
typedef void(^SCTMessageMarkerListQueryCompletion)(SCTMessageMarkerListQuery * _Nonnull, NSDictionary <NSString *, NSArray<SCTMessageMarker*> *> * _Nullable newLoadedMarkers, SCTError *_Nullable)
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
typedef void(^SCTContactsDiscoveryCompletion)(NSArray <SCTContactDiscovery *> * _Nullable discoveries, NSArray <SCTContact *> * _Nullable contacts, SCTError *_Nullable)
NS_SWIFT_NAME(ContactsDiscoveryCompletion);
typedef void(^SCTContactsCompletion)(NSArray <SCTContact *> * _Nullable contacts, SCTError *_Nullable)
NS_SWIFT_NAME(ContactsCompletion);

#endif /* SCTTypes_h */
