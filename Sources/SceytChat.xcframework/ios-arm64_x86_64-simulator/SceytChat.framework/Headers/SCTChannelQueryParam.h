//
//  SCTChannelQueryParam.h
//  SceytChat
//
//  Created by Hovsep on 2/27/23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ChannelQueryParam)
@interface SCTChannelQueryParam : NSObject

@property(nonatomic) NSUInteger messageCount;
@property(nonatomic) NSUInteger memberCount;

@property(nonatomic) BOOL includeLastMessage;

-(instancetype)init;

@end

NS_ASSUME_NONNULL_END
