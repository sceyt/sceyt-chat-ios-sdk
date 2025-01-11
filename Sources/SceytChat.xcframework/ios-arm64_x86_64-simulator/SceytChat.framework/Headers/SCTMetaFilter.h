//
//  SCTMetaFilter.h
//  SceytChat
//
//  Created by Marat Hambikyan on 09.01.25.
//  Copyright © 2025 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(MetaFilter)
@interface SCTMetaFilter: NSObject

@property (nonatomic, readonly, nonnull) NSArray<NSString*> *keys;

@end


NS_SWIFT_NAME(MetaFilter.Builder)
@interface SCTMetaFilterBuilder: NSObject

/// Create meta filter builder.
- (instancetype)init;

- (instancetype)keys:(nonnull NSArray<NSString*> *)keys;

// Build the meta filter.
- (SCTMetaFilter *)build;

@end


NS_ASSUME_NONNULL_END


