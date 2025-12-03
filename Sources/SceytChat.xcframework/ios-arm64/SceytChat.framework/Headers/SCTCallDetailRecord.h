//
//  SCTCallDetailRecord.h
//  SceytChat
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"
#import "SCTCDRParticipant.h"

NS_ASSUME_NONNULL_BEGIN


NS_SWIFT_NAME(CDRRecord)
@interface SCTCallDetailRecord : NSObject

@property (nonatomic, readonly) int64_t sessionId;
@property (nonatomic, readonly, nonnull) NSString *callId;
@property (nonatomic, readonly, nonnull) NSString *originatorId;
@property (nonatomic, readonly) SCTMediaFlow mediaFlow;
@property (nonatomic, readonly, nullable) NSDictionary<NSString*, NSString*> *metadata;
@property (nonatomic, readonly, nullable) NSDate *startedAt;
@property (nonatomic, readonly, nullable) NSDate *endedAt;
@property (nonatomic, readonly) CDRCallState state;
@property (nonatomic, readonly, nonnull) NSArray<SCTCDRParticipant*> *participants;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END


