//
//  SCTChannelListRequestParams.h
//  SceytChat
//
//  Created by Hovsep on 2/27/23.
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ChannelListRequestParams)
@interface SCTChannelListRequestParams : NSObject

@property(nonatomic) NSUInteger lastMessages;
@property(nonatomic) NSUInteger lastActiveMembers;
@property(nonatomic) BOOL numberOfMembers;
@property(nonatomic) BOOL lastMessage;

-(instancetype)init;

@end

NS_ASSUME_NONNULL_END
