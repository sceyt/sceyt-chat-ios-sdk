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
    /// An invalid argument, e.g. a URL that isn't a file.
    SCTFileEncryptionErrorInvalidArgument = 1,
    /// A range outside the object or plaintext.
    SCTFileEncryptionErrorOutOfRange = 2,
    /// Malformed or unsupported encryption info, checkpoint, metadata or unique id. Show the attachment as
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

/// The unique id the upload was bound to: 16 bytes, base64url without padding.
@property (nonatomic, readonly, copy) NSString *uniqueId;

/// The 32-byte file key, base64url without padding.
@property (nonatomic, readonly, copy) NSString *key;

/// The original file's size in bytes, or `unknownPlainSize`.
@property (nonatomic, readonly) uint64_t plainSize;

/// The size of a file whose metadata has none (the "enc" layout): a download takes it from the
/// stored object. Safe, as every segment is authenticated with its index and whether it is the last.
@property (class, nonatomic, readonly) uint64_t unknownPlainSize;

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
/// @param uniqueId The attachment id, unique to the upload: 16 bytes, base64url without padding
///                 (22 characters), e.g. from `newUniqueId`. The encryption is bound to its decoded bytes.
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

/// Encrypts a stream given in pieces, like Tink's `StreamingAead.newEncryptingStream`: `write`
/// the plaintext in pieces of any size, e.g. 5 MB upload parts, then `close` once to seal the
/// last segment. All the output, joined, is what `SCTStreamingAeadFileEncryptionProvider encrypt`
/// gives for all the plaintext. Without `close` the output has no last segment and doesn't decrypt.
/// `checkpoint` saves where it is, to continue the encryption after an app restart
/// (`SCTStreamingAeadFileEncryptionProvider restoreEncryptingStream`). Thread safe; calls block.
///
/// The ciphertext of a plaintext part isn't the part's size: the held-back segment (up to 64 KiB)
/// makes it smaller, and the header and the 16-byte tag per segment make it larger. So 5 MiB of
/// plaintext can give less than 5 MiB of ciphertext, and S3 multipart uploads reject parts other
/// than the last below 5 MiB. Collect the ciphertext until it is at least the minimum part size
/// before uploading a part; what `close` returns, with any ciphertext not yet uploaded, is the
/// last part, of any size.
NS_SWIFT_NAME(EncryptingStream)
@interface SCTEncryptingStream : NSObject

/// The plaintext bytes written so far. For a restored stream, it starts where to write the
/// plaintext from again: up to 64 KiB before where the old stream was, as its last segment
/// wasn't sealed.
@property (nonatomic, readonly) uint64_t position;

/// The ciphertext bytes returned so far; for a restored stream, including those the old stream
/// returned. After a restore, the upload continues at this offset.
@property (nonatomic, readonly) uint64_t ciphertextPosition;

/// The state at the end of the ciphertext returned so far, for
/// `SCTStreamingAeadFileEncryptionProvider restoreEncryptingStream`. Save it after each part is
/// uploaded, in private storage. Its data has no key; the info has: keep it like the message. A
/// closed stream's checkpoint doesn't restore: there is nothing to continue.
@property (nonatomic, readonly, copy) SCTFileEncryptionCheckpoint *checkpoint;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// The ciphertext `plaintext` completes, possibly empty: the header on the first call, then whole
/// 64 KiB segments. As in Tink, the last segment of the plaintext so far stays buffered until more
/// comes or `close`. Fails with `SCTFileEncryptionErrorInvalidArgument` for more bytes than the
/// info's size, and with `SCTFileEncryptionErrorClosed` once closed or failed.
- (nullable NSData *)write:(NSData *)plaintext error:(NSError **)error NS_SWIFT_NAME(write(_:));

/// The rest of the ciphertext, sealed as the last segment. Fails with
/// `SCTFileEncryptionErrorInvalidArgument` if the info has a size other than the bytes written.
- (nullable NSData *)closeWithError:(NSError **)error NS_SWIFT_NAME(close());

@end

/// Decrypts a stream given in pieces, like Tink's `StreamingAead.newDecryptingStream`: `write` the
/// stored bytes in pieces of any size, then `close` once. Each segment's plaintext is returned
/// once it verifies; `close` verifies the last one. On an error
/// (`SCTFileEncryptionErrorAuthentication`: tampered, truncated, or a wrong key or unique id),
/// discard all the plaintext returned before. Thread safe; calls block.
NS_SWIFT_NAME(DecryptingStream)
@interface SCTDecryptingStream : NSObject

/// The stored bytes written so far.
@property (nonatomic, readonly) uint64_t position;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// The plaintext of the segments `ciphertext` completes, possibly empty. As in Tink, a segment is
/// decrypted only once more bytes follow it.
- (nullable NSData *)write:(NSData *)ciphertext error:(NSError **)error NS_SWIFT_NAME(write(_:));

/// The last segment's plaintext. Fails with `SCTFileEncryptionErrorAuthentication` if the stream
/// was truncated.
- (nullable NSData *)closeWithError:(NSError **)error NS_SWIFT_NAME(close());

@end

/// The SDK's provider: Tink's AES-256-GCM-HKDF streaming format with 64 KiB segments and a key
/// commitment (`format`). Uploads it prepares can be sent with `SCTChatClient uploadEncrypted`.
NS_SWIFT_NAME(StreamingAeadFileEncryptionProvider)
@interface SCTStreamingAeadFileEncryptionProvider : NSObject <SCTFileEncryptionProvider>

/// "tink-aes256-gcm-hkdf-64k+commit-v1".
@property (class, nonatomic, readonly, copy) NSString *format;

/// A random unique id for `prepareUpload`: 16 random bytes, base64url without padding.
+ (NSString *)newUniqueId NS_SWIFT_NAME(newUniqueId());

/// A new random key for `encrypt` and `decrypt`, bound to `uniqueId`. Bytes encrypted
/// with it are in `format`, the same as encrypted files, so a download of them decrypts them.
///
/// The result's plain size is `SCTFileEncryptionData.unknownPlainSize`, as the bytes aren't known
/// yet: to put the info in attachment metadata (`SCTFileEncryptionMetadata`), use one with the
/// size of the bytes encrypted. The info contains the key: never log it. Fails with
/// `SCTFileEncryptionErrorInvalidEncryption` if `uniqueId` isn't 16 bytes of base64url.
/// @param uniqueId 16 bytes, base64url without padding (22 characters), e.g. from `newUniqueId`.
+ (nullable SCTFileEncryptionInfo *)prepareWithUniqueId:(NSString *)uniqueId error:(NSError **)error
NS_SWIFT_NAME(prepare(uniqueId:));

/// The info for a key you already have, e.g. from a message, as `prepare(uniqueId:)` gives it:
/// for `encrypt` and `decrypt`. Its plain size is `SCTFileEncryptionData.unknownPlainSize`.
/// The info contains the key: never log it. Fails with `SCTFileEncryptionErrorInvalidEncryption` if
/// the key or the unique id is malformed.
/// @param uniqueId The unique id the key is bound to: 16 bytes, base64url without padding.
/// @param key The 32-byte key, base64url without padding, as `SCTFileEncryptionData.key`.
+ (nullable SCTFileEncryptionInfo *)prepareWithUniqueId:(NSString *)uniqueId key:(NSString *)key error:(NSError **)error
NS_SWIFT_NAME(prepare(uniqueId:key:));

/// `plaintext` encrypted with `info`, in `format`. Each call picks a new random salt and nonce
/// prefix, so one key may encrypt several byte arrays. Fails with
/// `SCTFileEncryptionErrorInvalidEncryption` if `info` is malformed or of another format, and with
/// `SCTFileEncryptionErrorInvalidArgument` if `info` has a size that isn't the plaintext's. Blocks:
/// call it off the main thread for large data.
+ (nullable NSData *)encrypt:(NSData *)plaintext info:(SCTFileEncryptionInfo *)info error:(NSError **)error
NS_SWIFT_NAME(encrypt(_:info:));

/// The plaintext of `ciphertext`, all of it verified first: bytes from `encrypt`, or the
/// stored object of an encrypted upload. Fails with `SCTFileEncryptionErrorAuthentication`, and
/// returns no plaintext, if the bytes were tampered with or truncated or the key or unique id is
/// wrong; if `info` has a size, the ciphertext must be of a plaintext of that size. Blocks: call
/// it off the main thread for large data.
+ (nullable NSData *)decrypt:(NSData *)ciphertext info:(SCTFileEncryptionInfo *)info error:(NSError **)error
NS_SWIFT_NAME(decrypt(_:info:));

/// `encrypt` in pieces, like Tink's encrypting stream (`SCTEncryptingStream`). With a size in
/// `info`, exactly that many bytes must be written. Fails with
/// `SCTFileEncryptionErrorInvalidEncryption` if `info` is malformed or of another format.
+ (nullable SCTEncryptingStream *)newEncryptingStreamWithInfo:(SCTFileEncryptionInfo *)info error:(NSError **)error
NS_SWIFT_NAME(newEncryptingStream(info:));

/// Continues the encrypting stream saved in `checkpoint` (`SCTEncryptingStream checkpoint`), e.g.
/// after an app restart: the same key, salt and nonce prefix, at the end of the ciphertext the old
/// stream had returned, so its output continues it. Write the plaintext again from the stream's
/// `position`; those must be the same bytes as before: other bytes reuse nonces, which leaks both.
/// If the source may have changed, start over with a new unique id. Fails with
/// `SCTFileEncryptionErrorInvalidEncryption` if the checkpoint is malformed, isn't of an encrypting
/// stream, or is of a closed one.
+ (nullable SCTEncryptingStream *)restoreEncryptingStreamWithCheckpoint:(SCTFileEncryptionCheckpoint *)checkpoint
                                                                  error:(NSError **)error
NS_SWIFT_NAME(restoreEncryptingStream(checkpoint:));

/// `decrypt` in pieces, like Tink's decrypting stream (`SCTDecryptingStream`). With a size in
/// `info`, the ciphertext must be of a plaintext of that size.
+ (nullable SCTDecryptingStream *)newDecryptingStreamWithInfo:(SCTFileEncryptionInfo *)info error:(NSError **)error
NS_SWIFT_NAME(newDecryptingStream(info:));

@end

/// Another encrypted file that belongs to an attachment, e.g. its video's thumbnail.
NS_SWIFT_NAME(FileEncryptionRendition)
@interface SCTFileEncryptionRendition : NSObject

/// E.g. "thumbnail".
@property (nonatomic, readonly, copy) NSString *role;
/// What decrypts it; its size is `SCTFileEncryptionData unknownPlainSize`.
@property (nonatomic, readonly, copy) SCTFileEncryptionInfo *info;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// Keeps an attachment's encryption info in its metadata JSON, next to the other keys. Writes the
/// SDK's layout under `field`: {"format": ..., "data": {"v": 2, "uniqueId": ..., "key": ...,
/// "plainSize": ...}}. Reads it, or the layout other clients write under `encField`: {"v": 1,
/// "alg": ..., "attachmentId": ..., "key": ..., "renditions": [{"role": ..., "attachmentId": ...,
/// "key": ...}]}, which has no size (`SCTFileEncryptionData unknownPlainSize`).
NS_SWIFT_NAME(FileEncryptionMetadata)
@interface SCTFileEncryptionMetadata : NSObject

/// "sceyt_file_encryption".
@property (class, nonatomic, readonly, copy) NSString *field;

/// "enc".
@property (class, nonatomic, readonly, copy) NSString *encField;

/// The encryption info of an attachment, or nil without an error for a plain one (no metadata,
/// metadata that isn't a JSON object, or neither field). Fails with
/// `SCTFileEncryptionErrorInvalidEncryption` if a field is there but malformed: show the
/// attachment as unavailable, never treat it as plain. With both fields, `field` is read.
+ (nullable SCTFileEncryptionInfo *)readFromMetadata:(nullable NSString *)metadata error:(NSError **)error
NS_SWIFT_NAME(read(metadata:)) __attribute__((swift_error(nonnull_error)));

/// The other encrypted files of the attachment (the "enc" renditions); empty if there are none.
/// Fails with `SCTFileEncryptionErrorInvalidEncryption` if they are malformed.
+ (nullable NSArray<SCTFileEncryptionRendition *> *)readRenditionsFromMetadata:(nullable NSString *)metadata
                                                                         error:(NSError **)error
NS_SWIFT_NAME(readRenditions(metadata:));

/// The metadata with `info` added or replaced under `field`; other keys are kept. Fails with
/// `SCTFileEncryptionErrorInvalidArgument` if the metadata isn't nil, empty or a JSON object, or
/// if the size is `SCTFileEncryptionData unknownPlainSize`.
+ (nullable NSString *)writeInfo:(SCTFileEncryptionInfo *)info
                      toMetadata:(nullable NSString *)metadata
                           error:(NSError **)error
NS_SWIFT_NAME(write(_:to:));

/// The metadata without encryption info of either layout, e.g. for a new plain attachment made
/// from this one.
+ (nullable NSString *)removeFromMetadata:(nullable NSString *)metadata
NS_SWIFT_NAME(remove(from:));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
