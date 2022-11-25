//
//  SCTContact.h
//  SceytChat
//
//  Created by Hovsep on 11/16/22.
//  Copyright © 2022 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

@class SCTUser;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Contact)
@interface SCTContact : NSObject
@property (nonatomic, readonly, nonnull) SCTContactId id;
@property (nonatomic, readonly, nonnull) SCTUser *user;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *keys;
@property (nonatomic, readonly, nullable) NSString *metadata;
@property (nonatomic, readonly, nullable) NSString *firstName;
@property (nonatomic, readonly, nullable) NSString *lastName;

@end

NS_SWIFT_NAME(ContactDiscovery)
@interface SCTContactDiscovery : NSObject

@property (nonatomic, readonly, nonnull) NSString *key;
@property (nonatomic, readonly, nullable) NSString *metadata;
@property (nonatomic, readonly, nullable) NSString *firstName;
@property (nonatomic, readonly, nullable) NSString *lastName;

@end


NS_SWIFT_NAME(Contact.Builder)
@interface SCTContactBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create Contact builder.
/// @param id The Contact  id .
- (instancetype)initWithId:(SCTContactId)id;

- (instancetype)metadata:(nonnull NSString *)metadata;
- (instancetype)firstName:(nonnull NSString *)firstName;
- (instancetype)lastName:(nonnull NSString *)lastName;

/// Create Contact
- (SCTContact *)build;

@end


NS_SWIFT_NAME(ContactDiscovery.Builder)
@interface SCTContactDiscoveryBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create Contact builder.
/// @param key The Discovery key .
- (instancetype)initWithKey:(NSString *)key;

- (instancetype)metadata:(nonnull NSString *)metadata;
- (instancetype)firstName:(nonnull NSString *)firstName;
- (instancetype)lastName:(nonnull NSString *)lastName;

/// Create ContactDiscovery
- (SCTContactDiscovery *)build;

@end

NS_ASSUME_NONNULL_END
