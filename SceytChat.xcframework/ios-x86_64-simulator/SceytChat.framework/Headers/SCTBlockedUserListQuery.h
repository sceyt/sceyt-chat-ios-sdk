//
//  SCTBlockedUserListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BlockedUserListQuery)
@interface SCTBlockedUserListQuery : NSObject

/// Sets the number of users per page.
@property (nonatomic) NSUInteger limit;

/// The offset of user list query.
@property (nonatomic, readonly) NSUInteger offset;

/// The total blocked user count.
@property (nonatomic, readonly) NSUInteger totalCount;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTBlockedUserListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get blocked users.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTBlockedUserListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(BlockedUserListQuery.Builder)
@interface SCTBlockedUserListQueryBuilder : NSObject

/// Create BlockedUserListQuery builder.
- (instancetype)init;

/// Sets the number of users per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// The offset of user list query.
/// @param offset The first query offset.
- (instancetype)offset:(NSUInteger)offset;

/// Built a BlockedUserListQuery.
- (SCTBlockedUserListQuery *)build;

@end

NS_ASSUME_NONNULL_END
