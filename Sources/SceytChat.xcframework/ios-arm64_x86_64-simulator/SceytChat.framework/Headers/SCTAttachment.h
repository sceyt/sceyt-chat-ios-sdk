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

/// The unique attachment id.
@property (nonatomic, readonly) SCTAttachmentId id;

/// The owner message id.
@property (nonatomic, readonly) SCTMessageId messageId;

/// The owner user id.
@property (nonatomic, readonly) SCTUserId userId;

/// The attachment created date.
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

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

/// The  file size.
@property (nonatomic, readonly) NSUInteger fileSize;

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

/// Set remote uploaded file size
/// @param fileSize The attachment fileSize
- (instancetype)fileSize:(NSUInteger)fileSize;

/// Built an Attachment.
- (SCTAttachment *)build;

@end

NS_ASSUME_NONNULL_END
