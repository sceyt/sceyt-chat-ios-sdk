//
//  SCTPrivacyExceptionsQuery.h
//  SceytChat
//
//  Copyright © 2024 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PrivacyExceptionListQuery)
@interface SCTPrivacyExceptionListQuery : NSObject

/// Privacy query with key
@property (nonatomic, readonly) SCTPrivacyKey key;

/// Privacy query with type
@property (nonatomic, readonly) SCTPrivacyType type;

/// Sets the number of users per page.
@property (nonatomic) NSUInteger limit;

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTPrivacyExceptionsQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get Privacy Exceptions.
/// @param completion The handler block to execute.
- (void)loadNextWithCompletion:(SCTPrivacyExceptionListCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

/// Adds users to an Exception List.
/// @param userIds Array of user IDs to add. Each SCTUserId should be a valid identifier.
/// @param completion The handler block to execute.
- (void)addUsersWithIds:(NSArray<SCTUserId> *)userIds completion:(SCTPrivacyExceptionUserListCompletion)completion
NS_SWIFT_NAME(addUsers(ids:completion:));

/// Removes users from an Exception List.
/// @param userIds Array of user IDs to remove. Each SCTUserId should exist in the list.
/// @param completion The handler block to execute.
- (void)removeUsersWithIds:(NSArray<SCTUserId> *)userIds completion:(SCTPrivacyExceptionUserListCompletion)completion
NS_SWIFT_NAME(removeUsers(ids:completion:));

/// Adds and Removes users to an Exception List.
/// @param addUserIds  Array of user IDs to add. Each SCTUserId should be a valid identifier.
/// @param removeUserIds Array of user IDs to remove. Each SCTUserId should exist in the list.
/// @param completion The handler block to execute.
- (void)updateUsersWithAddUserIds:(NSArray<SCTUserId> *)addUserIds removeUserIds:(NSArray<SCTUserId> *)removeUserIds completion:(SCTPrivacyExceptionUpdateUserListCompletion)completion
NS_SWIFT_NAME(update(addUserIds:removeUserIds:completion:));

/// Resets the privacy settings to their default values.
/// @param completion The handler block to execute.
- (void)resetWithCompletion:(SCTCompletion)completion
NS_SWIFT_NAME(reset(_:));

@end

NS_SWIFT_NAME(PrivacyExceptionListQuery.Builder)
@interface SCTPrivacyExceptionListQueryBuilder : NSObject

/// Create SCTPrivacyExceptionListQuery builder.
- (instancetype)initWithKey:(SCTPrivacyKey)key type:(SCTPrivacyType)type;

/// Sets the number of users per page.
/// @param limit The query limit per request.
- (instancetype)limit:(NSUInteger)limit;

/// Built a SCTPrivacyExceptionListQuery.
- (SCTPrivacyExceptionListQuery *)build;

@end

NS_ASSUME_NONNULL_END

