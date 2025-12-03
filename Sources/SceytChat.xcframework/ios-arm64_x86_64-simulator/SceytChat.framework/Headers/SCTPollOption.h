//
//  SCTPollOption.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PollOption)
@interface SCTPollOption : NSObject

/// The unique poll option identifier.
@property (nonatomic, readonly, nonnull) NSString *id;

/// The poll option name/text.
@property (nonatomic, readonly, nonnull) NSString *name;

/// Initialize a poll option with id and name.
/// @param id The option identifier.
/// @param name The option display text.
- (instancetype)initWithId:(nonnull NSString *)id
                      name:(nonnull NSString *)name
NS_SWIFT_NAME(init(id:name:));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

