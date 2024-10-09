//
//  SCTUserListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UserListQuery)
@interface SCTUserListQuery : NSObject

/// The user list query filter keyword.
@property (nonatomic, readonly, nullable) NSString *query;

/// Sets the number of users per page.
@property (nonatomic) NSUInteger limit;

/// The offset of user list query.
@property (nonatomic, readonly) NSUInteger offset;

/// The user list by order.
@property (nonatomic, readonly) SCTUserListOrder order;

/// Filter users by type.
@property (nonatomic, readonly) SCTUserListFilterType filterType;

/// The meta filter keys used to filter users by metadata keys.
@property (nonatomic, readonly, nullable) NSArray<NSString *> *metaFilterKeys;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// `init` is unavailable. Use `SCTUserListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get users.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTUserListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

@end

NS_SWIFT_NAME(UserListQuery.Builder)
@interface SCTUserListQueryBuilder : NSObject

/// Create a `UserListQuery` builder.
- (instancetype)init;

/// Filter users by query text.
/// @param query The filter query text.
- (instancetype)query:(nullable NSString *)query;

/// Sets the number of users per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// The offset of user list query.
/// @param offset The first query offset.
- (instancetype)offset:(NSUInteger)offset;

/// Get users by order.
/// @param order The query order.
- (instancetype)order:(SCTUserListOrder)order;

/// Set query filter type.
/// @param type Filter users by query type.
- (instancetype)filterType:(SCTUserListFilterType)type;

/// Set meta filter keys.
/// @param keys The array of metadata keys to filter users.
- (instancetype)metaFilterKeys:(NSArray<NSString *> *)keys;

/// Build a `UserListQuery`.
- (SCTUserListQuery *)build;

@end

NS_ASSUME_NONNULL_END
