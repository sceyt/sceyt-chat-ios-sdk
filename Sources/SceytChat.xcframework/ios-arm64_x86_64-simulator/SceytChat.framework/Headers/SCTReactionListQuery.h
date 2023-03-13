//
//  SCTReactionListQuery.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ReactionListQuery)
@interface SCTReactionListQuery : NSObject

/// Shows if there is a next page.
@property (nonatomic, readonly) BOOL hasNext;

/// Sets the number of reactions per page.
@property (nonatomic) NSUInteger limit;

/// The offset of reaction list query.
@property (nonatomic, readonly) NSUInteger offset;

/// Shows if the query is loading.
@property (atomic, readonly) BOOL loading;

/// init is unavailable. Use `SCTReactionListQueryBuilder` instead.
- (instancetype)init NS_UNAVAILABLE;

/// Get reaction.
/// @param completion The handler block to execute.
- (void)loadNextPageWithCompletion:(SCTReactionListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(_:));

/// Get reaction.
/// @param reactionId Load reactions after the reaction id
/// @param completion The handler block to execute.
- (void)loadNextPageByReactionId:(SCTReactionId)reactionId completion:(SCTReactionListQueryCompletion)completion
NS_SWIFT_NAME(loadNext(reactionId:completion:));

@end

NS_SWIFT_NAME(ReactionListQuery.Builder)
@interface SCTReactionListQueryBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithMessageId:(SCTMessageId)messageId;
- (instancetype)limit:(NSUInteger)limit;
- (instancetype)key:(NSString*)key;
- (instancetype)offset:(NSUInteger)offset;
- (SCTReactionListQuery *)build;

@end

NS_ASSUME_NONNULL_END


