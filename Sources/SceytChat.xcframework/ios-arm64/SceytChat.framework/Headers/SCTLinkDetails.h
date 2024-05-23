//
//  SCTLinkDetails.h
//  SceytChat
//
//  Copyright © 2023 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SCTLinkDetailImage;
@class SCTLinkDetailVideo;
@class SCTLinkDetailAudio;
@class SCTLinkDetailFavicon;

NS_SWIFT_NAME(LinkDetails)
@interface SCTLinkDetails : NSObject

@property (nonatomic, readonly, nullable) NSString *title;
@property (nonatomic, readonly, nullable) NSString *type;
@property (nonatomic, readonly, nullable) NSString *info;
@property (nonatomic, readonly, nullable) NSString *locale;
@property (nonatomic, readonly, nullable) NSString *siteName;

@property (nonatomic, readonly, nullable) NSArray<NSString *> *localeAlternates;
@property (nonatomic, readonly, nullable) NSArray<SCTLinkDetailImage *> *images;

@property (nonatomic, readonly, nullable) SCTLinkDetailFavicon *favicon;

@end

NS_SWIFT_NAME(LinkDetails.Image)
@interface SCTLinkDetailImage : NSObject

@property (nonatomic, readonly, nullable) NSString *url;
@property (nonatomic, readonly, nullable) NSString *secureUrl;
@property (nonatomic, readonly, nullable) NSString *type;
@property (nonatomic, readonly) CGFloat width;
@property (nonatomic, readonly) CGFloat height;

@end


NS_SWIFT_NAME(LinkDetails.Favicon)
@interface SCTLinkDetailFavicon : NSObject

@property (nonatomic, readonly, nullable) NSString *url;

@end


NS_ASSUME_NONNULL_END
