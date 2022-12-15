//
//  SCTAttachment.h
//  SceytChat
//
//  Copyright © 2021 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCTTypes.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Attachment)
@interface SCTAttachment : NSObject

/// An any URL.
@property (nonatomic, readonly) SCTMessageId messageId;

/// An any URL.
@property (nonatomic, readonly, nullable) NSString *url;

/// filePath for upload.
@property (nonatomic, readonly, nullable) NSString *filePath;

/// The attachment custom type.
@property (nonatomic, readonly, nonnull) NSString *type;

/// The file name.
@property (nonatomic, readonly, nullable) NSString *name;

/// The metadata for file.
@property (nonatomic, readonly, nullable) NSString *metadata;

/// The uploaded file size.
@property (nonatomic, readonly) NSUInteger uploadedFileSize;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Attachment uploader progress callback.
/// @param progress The upload progress callback.
- (void)setUploaderProgress:(nullable SCTProgressCompletion)progress;

/// Attachment uploader completion callback.
/// @param completion The upload completion callback.
- (void)setUploaderCompletion:(nullable SCTAttachmentCompletion)completion;

@end

NS_SWIFT_NAME(Attachment.Builder)
@interface SCTAttachmentBuilder: NSObject

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

/// Create message builder with attachment url.
/// @param url The attachment url.
/// @param type The attachment type.
- (instancetype)initWithUrl:(nonnull NSString *)url type:(nonnull NSString *)type;

/// Create message builder with attachment filePath.
/// @param filePath The attachment filePath which needs to upload .
/// @param type The attachment type.
- (instancetype)initWithFilePath:(nonnull NSString *)filePath type:(nonnull NSString *)type;

/// Set custom name to attachment.
/// @param name The attachment name.
- (instancetype)name:(nonnull NSString *)name;

/// Use metadata for describe attachment.
/// @param metadata The attachment metadata.
- (instancetype)metadata:(nonnull NSString *)metadata;

/// Built an Attachment.
- (SCTAttachment *)build;

@end

NS_ASSUME_NONNULL_END
