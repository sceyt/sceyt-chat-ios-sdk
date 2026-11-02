//
//  SCTFileEncryption.h
//  SceytChat
//
//  Copyright © 2026 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Encryption of attachments for upload and download, implemented by the native SDK (shared with
/// Android). The UI kit prepares files and moves bytes; the SDK owns keys, the format,
/// encryption and verification.
///
/// All methods block: call them off the main thread. Objects are thread safe.

/// The error domain of file encryption errors.
FOUNDATION_EXPORT NSErrorDomain const SCTFileEncryptionErrorDomain
NS_SWIFT_NAME(FileEncryptionErrorDomain);

/// File encryption error codes, the same as the native FileEncryptionErrorCode.
typedef NS_ERROR_ENUM(SCTFileEncryptionErrorDomain, SCTFileEncryptionErrorCode) {
    /// An invalid argument, e.g. a missing or too long unique id, or a URL that isn't a file.
    SCTFileEncryptionErrorInvalidArgument = 1,
    /// A range outside the object or plaintext.
    SCTFileEncryptionErrorOutOfRange = 2,
    /// Malformed or unsupported encryption info, checkpoint or metadata. Show the attachment as
    /// unavailable, never as a plain file.
    SCTFileEncryptionErrorInvalidEncryption = 3,
    /// The file isn't the one the upload started with: start a new upload.
    SCTFileEncryptionErrorFileChanged = 4,
    /// The encrypted bytes didn't verify: tampered, truncated, wrong key or unique id.
    SCTFileEncryptionErrorAuthentication = 5,
    /// A file or the source couldn't be read.
    SCTFileEncryptionErrorIO = 6,
    /// The caller asked to stop.
    SCTFileEncryptionErrorInterrupted = 7,
    /// The object was closed.
    SCTFileEncryptionErrorClosed = 8,
} NS_SWIFT_NAME(FileEncryptionError);

/// The parameters to decrypt one file, the data of its `SCTFileEncryptionInfo`. Contains the file
/// key: never log it or store it with the stored object.
NS_SWIFT_NAME(FileEncryptionData)
@interface SCTFileEncryptionData : NSObject <NSCopying>

/// The unique id the upload was bound to, 1 to 64 UTF-8 bytes.
@property (nonatomic, readonly, copy) NSString *uniqueId;

/// The 32-byte file key, base64url without padding.
@property (nonatomic, readonly, copy) NSString *key;

/// The original file's size in bytes.
@property (nonatomic, readonly) uint64_t plainSize;

/// Initialize the data of an encrypted file.
/// @param uniqueId The unique id the upload was bound to.
/// @param key The 32-byte file key, base64url without padding.
/// @param plainSize The original file's size in bytes.
- (instancetype)initWithUniqueId:(NSString *)uniqueId key:(NSString *)key plainSize:(uint64_t)plainSize
NS_SWIFT_NAME(init(uniqueId:key:plainSize:));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// What an encrypted attachment carries to its recipients: the format and the data to decrypt
/// it. The UI kit stores and forwards it unchanged (see `SCTFileEncryptionMetadata`). The data
/// contains the file key: store and send it like the message itself, never with the stored object.
NS_SWIFT_NAME(FileEncryptionInfo)
@interface SCTFileEncryptionInfo : NSObject <NSCopying>

/// The encryption format, e.g. `SCTStreamingAeadFileEncryptionProvider.format`.
@property (nonatomic, readonly, copy) NSString *format;

/// The parameters to decrypt the file, including the key.
@property (nonatomic, readonly, copy) SCTFileEncryptionData *data;

/// Initialize encryption info.
/// @param format The encryption format.
/// @param data The parameters to decrypt the file.
- (instancetype)initWithFormat:(NSString *)format data:(SCTFileEncryptionData *)data
NS_SWIFT_NAME(init(format:data:));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// Local state to restore an upload session (`restoreUpload`): the session's encryption info and
/// SDK-defined data. The UI kit keeps it in private storage and gives it back unchanged; it is not
/// message metadata. The data has no key; store the info as securely as the message's keys.
NS_SWIFT_NAME(FileEncryptionCheckpoint)
@interface SCTFileEncryptionCheckpoint : NSObject <NSCopying>

/// The session's encryption info.
@property (nonatomic, readonly, copy) SCTFileEncryptionInfo *encryptionInfo;

/// SDK-defined state of the session, without the key.
@property (nonatomic, readonly, copy) NSString *data;

/// Initialize a checkpoint, e.g. from storage.
/// @param encryptionInfo The session's encryption info.
/// @param data The checkpoint data saved before.
- (instancetype)initWithEncryptionInfo:(SCTFileEncryptionInfo *)encryptionInfo data:(NSString *)data
NS_SWIFT_NAME(init(encryptionInfo:data:));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// Encrypted bytes read by range, implemented by the app for downloads (a cache file, HTTP Range
/// requests, ...). Reads may come from several threads.
NS_SWIFT_NAME(CiphertextRangeSource)
@protocol SCTCiphertextRangeSource <NSObject>

/// The size of the stored encrypted object in bytes.
@property (nonatomic, readonly) uint64_t ciphertextSize;

/// Exactly `length` bytes at `offset`, or nil and an error, which reaches the reader's caller
/// unchanged. Return the same bytes for repeated and overlapping reads.
- (nullable NSData *)readCiphertextRange:(uint64_t)offset length:(NSUInteger)length error:(NSError **)error
NS_SWIFT_NAME(readCiphertextRange(offset:length:));

@optional
/// Called once when the reader that owns this source is closed.
- (void)close;

@end

/// An encryption session of one prepared file: `readCiphertextRange` makes any range of the
/// encrypted file on demand, for a transport to upload. No encrypted copy is stored.
NS_SWIFT_NAME(PreparedUpload)
@protocol SCTPreparedUpload <NSObject>

/// The size of the encrypted file in bytes.
@property (nonatomic, readonly) uint64_t ciphertextSize;

/// The size of the original file in bytes.
@property (nonatomic, readonly) uint64_t plaintextSize;

/// The identity of this encrypted stream: the same after a valid restore, new per session.
@property (nonatomic, readonly, copy) NSString *sourceId;

/// What the message carries so recipients can decrypt the file.
@property (nonatomic, readonly, copy) SCTFileEncryptionInfo *encryptionInfo;

/// The current state to restore this session, including the ranges read so far.
@property (nonatomic, readonly, copy) SCTFileEncryptionCheckpoint *checkpoint;

/// Exactly `length` bytes of the encrypted file at `offset`. The range is recorded: the same
/// range made again after a restore from a changed file fails with
/// `SCTFileEncryptionErrorFileChanged`.
- (nullable NSData *)readCiphertextRange:(uint64_t)offset length:(NSUInteger)length error:(NSError **)error
NS_SWIFT_NAME(readCiphertextRange(offset:length:));

/// Ends the session: later reads fail with `SCTFileEncryptionErrorClosed`.
- (void)close;

@end

/// The verified plaintext of an encrypted attachment, read by range: a player can seek.
NS_SWIFT_NAME(PlaintextReader)
@protocol SCTPlaintextReader <NSObject>

/// The size of the original file in bytes.
@property (nonatomic, readonly) uint64_t plaintextSize;

/// Exactly `length` bytes at `offset`, each fetched record verified first.
- (nullable NSData *)read:(uint64_t)offset length:(NSUInteger)length error:(NSError **)error
NS_SWIFT_NAME(read(offset:length:));

/// Later reads fail with `SCTFileEncryptionErrorClosed`; the source is closed. Safe to call twice.
- (void)close;

@end

/// Encrypts files for upload and decrypts downloads.
NS_SWIFT_NAME(FileEncryptionProvider)
@protocol SCTFileEncryptionProvider <NSObject>

/// A new upload of the file (after any resizing or transcoding): a new key and session.
/// @param fileURL The local file to upload.
/// @param uniqueId Any string of 1 to 64 UTF-8 bytes unique to the upload, e.g. the attachment id.
- (nullable id<SCTPreparedUpload>)prepareUploadWithFileURL:(NSURL *)fileURL
                                                  uniqueId:(NSString *)uniqueId
                                                     error:(NSError **)error
NS_SWIFT_NAME(prepareUpload(fileURL:uniqueId:));

/// The upload saved in `checkpoint`: the same key and session, so the same encrypted bytes.
/// Fails with `SCTFileEncryptionErrorFileChanged` if the file's size or modification time differs.
/// @param fileURL The same local file.
/// @param checkpoint The checkpoint saved from the session.
- (nullable id<SCTPreparedUpload>)restoreUploadWithFileURL:(NSURL *)fileURL
                                                checkpoint:(SCTFileEncryptionCheckpoint *)checkpoint
                                                     error:(NSError **)error
NS_SWIFT_NAME(restoreUpload(fileURL:checkpoint:));

/// A reader of the decrypted file. Checks the format, the source size against the trusted
/// plaintext size and the key commitment before returning. On success the reader owns the
/// source and closes it; on failure the source stays the caller's.
/// @param source The stored encrypted object.
/// @param encryptionInfo The info from the attachment's metadata.
- (nullable id<SCTPlaintextReader>)openDownloadWithSource:(id<SCTCiphertextRangeSource>)source
                                           encryptionInfo:(SCTFileEncryptionInfo *)encryptionInfo
                                                    error:(NSError **)error
NS_SWIFT_NAME(openDownload(source:encryptionInfo:));

@end

/// The SDK's provider: Tink's AES-256-GCM-HKDF streaming format with 64 KiB segments and a key
/// commitment (`format`). Uploads it prepares can be sent with `SCTChatClient uploadEncrypted`.
NS_SWIFT_NAME(StreamingAeadFileEncryptionProvider)
@interface SCTStreamingAeadFileEncryptionProvider : NSObject <SCTFileEncryptionProvider>

/// "tink-aes256-gcm-hkdf-64k+commit-v1".
@property (class, nonatomic, readonly, copy) NSString *format;

/// A random unique id for `prepareUpload`: a version 4 UUID string, lowercase.
+ (NSString *)newUniqueId NS_SWIFT_NAME(newUniqueId());

@end

/// Keeps an attachment's encryption info in its metadata JSON under `field`, next to the other
/// keys, as {"format": ..., "data": {"v": 2, "uniqueId": ..., "key": ..., "plainSize": ...}}.
NS_SWIFT_NAME(FileEncryptionMetadata)
@interface SCTFileEncryptionMetadata : NSObject

/// "sceyt_file_encryption".
@property (class, nonatomic, readonly, copy) NSString *field;

/// The encryption info of an attachment, or nil without an error for a plain one (no metadata,
/// metadata that isn't a JSON object, or no `field`). Fails with
/// `SCTFileEncryptionErrorInvalidEncryption` if the field is there but malformed: show the
/// attachment as unavailable, never treat it as plain.
+ (nullable SCTFileEncryptionInfo *)readFromMetadata:(nullable NSString *)metadata error:(NSError **)error
NS_SWIFT_NAME(read(metadata:)) __attribute__((swift_error(nonnull_error)));

/// The metadata with `info` added or replaced; other keys are kept. Fails with
/// `SCTFileEncryptionErrorInvalidArgument` if the metadata isn't nil, empty or a JSON object.
+ (nullable NSString *)writeInfo:(SCTFileEncryptionInfo *)info
                      toMetadata:(nullable NSString *)metadata
                           error:(NSError **)error
NS_SWIFT_NAME(write(_:to:));

/// The metadata without encryption info, e.g. for a new plain attachment made from this one.
+ (nullable NSString *)removeFromMetadata:(nullable NSString *)metadata
NS_SWIFT_NAME(remove(from:));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
