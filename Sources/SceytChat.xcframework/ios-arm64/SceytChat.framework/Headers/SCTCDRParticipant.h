//
//  SCTCDRParticipant.h
//  SceytChat
//
//  Created for CDR recent calls support.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTUser;

NS_SWIFT_NAME(CDRRecord.Participant)
@interface SCTCDRParticipant : NSObject

@property (nonatomic, readonly, nonnull) SCTUser *user;
@property (nonatomic, readonly, nonnull) NSString *clientId;
@property (nonatomic, readonly) BOOL originator;
@property (nonatomic, readonly, nullable) NSDate *joinedAt;
@property (nonatomic, readonly, nullable) NSDate *leftAt;
@property (nonatomic, readonly, nullable) NSDate *mediaConnectedAt;
@property (nonatomic, readonly) SCTParticipantState state;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END


