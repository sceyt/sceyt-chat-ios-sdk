//
//  SCTError.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SceytError)
@interface SCTError : NSError

@property (nonatomic, readonly, nonnull) NSString *type;
@property (nonatomic, readonly, nonnull) NSString *message;

@end

NS_ASSUME_NONNULL_END
