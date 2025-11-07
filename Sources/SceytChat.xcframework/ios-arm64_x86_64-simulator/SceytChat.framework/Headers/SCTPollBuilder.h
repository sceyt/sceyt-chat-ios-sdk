//
//  SCTPollBuilder.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SCTPollDetails;
@class SCTPollOption;

/**
 * Builder class for creating polls.
 *
 * Example usage:
 * @code
 * // Create a poll
 * SCTPollBuilder *pollBuilder = [[SCTPollBuilder alloc] init];
 * SCTPollDetails *poll = [[[[[pollBuilder
 *     name:@"What's your favorite color?"]
 *     addOptionWithText:@"Red"]
 *     addOptionWithText:@"Blue"]
 *     addOptionWithText:@"Green"]
 *     build];
 *
 * // Create a message with the poll
 * SCTMessage *message = [[[[SCTMessageBuilder alloc] init]
 *     type:@"poll"]
 *     poll:poll]
 *     build];
 *
 * // Send the poll message
 * [channel sendMessage:message completion:^(SCTMessage *message, SCTError *error) {
 *     if (!error) {
 *         NSLog(@"Poll sent successfully!");
 *     }
 * }];
 * @endcode
 */

NS_SWIFT_NAME(Poll.Builder)
@interface SCTPollBuilder : NSObject

/// Create poll builder.
- (instancetype)init;

/// Set the poll identifier (optional, will be auto-generated if not set).
/// @param pollId The poll identifier. Must not be empty if provided.
- (instancetype)id:(nonnull NSString *)pollId
NS_SWIFT_NAME(pollId(_:));

/// Set the poll name/question.
/// @param name The poll question text.
- (instancetype)name:(nonnull NSString *)name
NS_SWIFT_NAME(name(_:));

/// Set the poll description (optional).
/// @param description Additional context for the poll.
- (instancetype)pollDescription:(nullable NSString *)description
NS_SWIFT_NAME(description(_:));

/// Set poll options.
/// @param options Array of poll options.
- (instancetype)options:(nonnull NSArray<SCTPollOption *> *)options
NS_SWIFT_NAME(options(_:));

/// Add a single poll option.
/// @param option Poll option to add.
- (instancetype)addOption:(nonnull SCTPollOption *)option
NS_SWIFT_NAME(addOption(_:));

/// Add a poll option with just text (auto-generates ID).
/// @param optionText The option display text.
- (instancetype)addOptionWithText:(nonnull NSString *)optionText
NS_SWIFT_NAME(addOption(_:));

/// Set whether the poll is anonymous.
/// @param anonymous If YES, votes are anonymous. Default is NO.
- (instancetype)anonymous:(BOOL)anonymous
NS_SWIFT_NAME(anonymous(_:));

/// Set whether multiple votes are allowed.
/// @param allowMultipleVotes If YES, users can select multiple options. Default is NO.
- (instancetype)allowMultipleVotes:(BOOL)allowMultipleVotes
NS_SWIFT_NAME(allowMultipleVotes(_:));

/// Set whether vote retraction is allowed.
/// @param allowVoteRetract If YES, users can change their vote. Default is YES.
- (instancetype)allowVoteRetract:(BOOL)allowVoteRetract
NS_SWIFT_NAME(allowVoteRetract(_:));

/// Build the poll details.
- (SCTPollDetails *)build
NS_SWIFT_NAME(build());

@end

NS_ASSUME_NONNULL_END

