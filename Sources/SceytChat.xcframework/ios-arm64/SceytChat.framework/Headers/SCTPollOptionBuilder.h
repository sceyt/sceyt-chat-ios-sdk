//
//  SCTPollOptionBuilder.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SCTPollOption;

NS_SWIFT_NAME(PollOption.Builder)
@interface SCTPollOptionBuilder : NSObject

/// Create poll option builder.
- (instancetype)init;

/// Set the option id (optional - will be auto-generated if not provided).
/// @param id The option identifier.
- (instancetype)id:(nonnull NSString *)id
NS_SWIFT_NAME(id(_:));

/// Set the option name/text.
/// @param name The option display text.
- (instancetype)name:(nonnull NSString *)name
NS_SWIFT_NAME(name(_:));

/// Build the poll option.
- (SCTPollOption *)build
NS_SWIFT_NAME(build());

@end

NS_ASSUME_NONNULL_END

