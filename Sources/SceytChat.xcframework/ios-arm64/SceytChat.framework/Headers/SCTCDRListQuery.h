//
//  SCTCDRListQuery.h
//  SceytChat
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTCallDetailRecord;
@class SCTError;

typedef NS_ENUM(NSInteger, SCTCDROrder) {
    SCTCDROrderAsc = 0,
    SCTCDROrderDesc = 1
} NS_SWIFT_NAME(CDROrder);

NS_SWIFT_NAME(CDRListQuery)
@interface SCTCDRListQuery : NSObject

@property (nonatomic) NSUInteger limit;
@property (nonatomic, readonly) BOOL hasNext;
@property (atomic, readonly) BOOL loading;
@property (nonatomic, readonly) SCTCDROrder order;
@property (nonatomic, readonly) int64_t sessionId;
@property (nonatomic, readonly, nullable) NSString *nextToken;
@property (nonatomic, readonly) NSUInteger participantCount;

- (instancetype)init NS_UNAVAILABLE;
- (void)loadNextWithCompletion:(SCTCDRListQueryCompletion)completion NS_SWIFT_NAME(loadNext(_:));

/// Get next CDR records by setting a specific session id before loading.
/// @param sessionId The session id to position the query.
/// @param completion The handler block to execute.
- (void)loadNextBySessionId:(int64_t)sessionId completion:(SCTCDRListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(sessionId:_:));

/// Get next CDR records by setting a specific next token before loading.
/// @param nextToken The next page token to continue from.
/// @param completion The handler block to execute.
- (void)loadNextByNextToken:(NSString *)nextToken completion:(SCTCDRListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(nextToken:_:));

/// Get previous CDR records.
/// @param completion The handler block to execute.
- (void)loadPreviousWithCompletion:(SCTCDRListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(_:));

/// Get previous CDR records by setting a specific session id before loading.
/// @param sessionId The session id to position the query.
/// @param completion The handler block to execute.
- (void)loadPreviousBySessionId:(int64_t)sessionId completion:(SCTCDRListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(sessionId:_:));

/// Get previous CDR records by setting a specific next token before loading.
/// @param nextToken The previous page token to continue from.
/// @param completion The handler block to execute.
- (void)loadPreviousByNextToken:(NSString *)nextToken completion:(SCTCDRListQueryCompletion)completion
NS_SWIFT_NAME(loadPrevious(nextToken:_:));


@end

NS_SWIFT_NAME(CDRListQuery.Builder)
@interface SCTCDRListQueryBuilder : NSObject

- (instancetype)init;
- (instancetype)order:(SCTCDROrder)order;
- (instancetype)limit:(NSUInteger)limit;
- (instancetype)sessionId:(int64_t)sessionId;
- (instancetype)nextToken:(NSString *)nextToken;
- (instancetype)participantCount:(NSUInteger)participantCount;
- (SCTCDRListQuery *)build;

@end

NS_ASSUME_NONNULL_END


