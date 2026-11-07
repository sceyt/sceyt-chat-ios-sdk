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
    /// An invalid argument, e.g. a URL that isn't a file, or an attachment id or header of the
    /// wrong size.
    SCTFileEncryptionErrorInvalidArgument = 1,
    /// A range outside the object or plaintext.
    SCTFileEncryptionErrorOutOfRange = 2,
    /// A malformed attachment key or checkpoint, or an unknown key version. Show the attachment as
    /// unavailable, never as a plain file.
    SCTFileEncryptionErrorInvalidEncryption = 3,
    /// The file isn't the one the upload started with: start a new upload.
    SCTFileEncryptionErrorFileChanged = 4,
    /// The encrypted bytes didn't verify: tampered, truncated, or a header that isn't the key's or
    /// the cipher's.
    SCTFileEncryptionErrorAuthentication = 5,
    /// A file or the source couldn't be read.
    SCTFileEncryptionErrorIO = 6,
    /// The caller asked to stop.
    SCTFileEncryptionErrorInterrupted = 7,
    /// The object was closed.
    SCTFileEncryptionErrorClosed = 8,
} NS_SWIFT_NAME(FileEncryptionError);

/// The size of an attachment id in bytes.
FOUNDATION_EXPORT const NSUInteger SCTAttachmentIdSize NS_SWIFT_NAME(AttachmentCipher.attachmentIdSize);

/// The size of an attachment cipher's header in bytes.
FOUNDATION_EXPORT const NSUInteger SCTAttachmentHeaderSize NS_SWIFT_NAME(AttachmentCipher.headerSize);

@class SCTEncryptingStream;
@class SCTDecryptingStream;

/// Bytes read by range, like Tink's `RandomAccessStream`: a plaintext file to encrypt, a stored
/// object to decrypt (the app implements it over the remote object: a cache file, HTTP Range
/// requests, ...), or an `SCTAttachmentCipher`'s random-access view of either. Reads may come from
/// several threads.
NS_SWIFT_NAME(RandomAccessStream)
@protocol SCTRandomAccessStream <NSObject>

/// The exact number of bytes.
@property (nonatomic, readonly) uint64_t size;

/// Exactly `length` bytes at `offset`, or nil and an error, which reaches the view's caller
/// unchanged. Return the same bytes for repeated and overlapping reads.
- (nullable NSData *)pread:(uint64_t)offset length:(NSUInteger)length error:(NSError **)error
NS_SWIFT_NAME(pread(offset:length:));

@optional
/// Called once when the view that owns this source is closed.
- (void)close;

@end

/// A cipher's random-access view (`newEncryptingRandomAccessStreamWithSource:`,
/// `newDecryptingRandomAccessStreamWithSource:`): a `SCTRandomAccessStream` that owns its source.
NS_SWIFT_NAME(RandomAccessView)
@interface SCTRandomAccessView : NSObject <SCTRandomAccessStream>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// Later reads fail with `SCTFileEncryptionErrorClosed`; the source is closed. Safe to call twice.
- (void)close;

@end

/// The encryption of one attachment, shaped like Tink's `StreamingAead` plus a random-access
/// encrypting view. One cipher is one stored object: its key, attachment id, salt and nonce prefix
/// are fixed when it is created, so every encryption it makes gives the same bytes for the same
/// plaintext. Two values leave it:
///
/// - `attachmentKey`: base64url without padding of the version (1), the attachment id (16 bytes)
///   and the key (32 bytes), 66 characters. **Secret**: it goes in the chat message, sent and
///   stored like the message, never with the stored object, and never logged.
/// - `header`: the stored object's first `SCTAttachmentHeaderSize` (72) bytes, the key commitment
///   and Tink's header. Not secret. The sender keeps it, with the key, until the upload is
///   complete; the recipient reads it from the object.
///
/// `restoreWithAttachmentKey:header:` gives the same cipher again from both: to resume an upload,
/// or to download.
///
/// Encrypting **different** plaintext with one cipher reuses GCM nonces, which leaks the
/// plaintexts: encrypt one plaintext per cipher, and resume only with the same bytes
/// (`SCTPreparedUpload` checks that). Two ciphers are equal when their attachment keys and
/// headers are. Thread safe; calls block.
NS_SWIFT_NAME(AttachmentCipher)
@interface SCTAttachmentCipher : NSObject

/// The attachment key, for the message. Secret: never log it.
@property (nonatomic, readonly, copy) NSString *attachmentKey;

/// The stored object's first `SCTAttachmentHeaderSize` bytes. Not secret.
@property (nonatomic, readonly, copy) NSData *header;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// A new cipher: a random key, salt and nonce prefix, bound to `attachmentId`. Fails with
/// `SCTFileEncryptionErrorInvalidArgument` if `attachmentId` isn't `SCTAttachmentIdSize` bytes.
/// @param attachmentId The 16 bytes the slot service gives, or `SCTAeadFileEncryptionProvider newAttachmentId`.
+ (nullable instancetype)createWithAttachmentId:(NSData *)attachmentId error:(NSError **)error
NS_SWIFT_NAME(create(attachmentId:));

/// The cipher of `attachmentKey` and `header`: the sender's saved ones to resume an upload, or the
/// message's attachment key and the stored object's first `SCTAttachmentHeaderSize` bytes to
/// download. Fails with `SCTFileEncryptionErrorInvalidEncryption` for a malformed key or an
/// unknown version, `SCTFileEncryptionErrorInvalidArgument` for a header of another size, and
/// `SCTFileEncryptionErrorAuthentication` for a header that doesn't belong to this key and
/// attachment id (the key commitment).
+ (nullable instancetype)restoreWithAttachmentKey:(NSString *)attachmentKey
                                           header:(NSData *)header
                                            error:(NSError **)error
NS_SWIFT_NAME(restore(attachmentKey:header:));

/// Like Tink's encrypting stream (`SCTEncryptingStream`): the plaintext written from byte 0 gives
/// the whole stored object, header first. All of it, joined, is what
/// `newEncryptingRandomAccessStreamWithSource:` gives for the same plaintext; to resume an upload
/// after a restart, use that view instead: it makes any part again.
- (nullable SCTEncryptingStream *)newEncryptingStreamWithError:(NSError **)error NS_SWIFT_NAME(newEncryptingStream());

/// The stored object of `plaintextSource`, read by range: `pread` takes stored offsets and returns
/// exactly those bytes, reading only the plaintext of the segments they cover, so an upload can
/// make any part, in any order, again after a restart. Its `size` is the stored size. The view
/// owns the source and closes it; on failure the source stays the caller's.
- (nullable SCTRandomAccessView *)newEncryptingRandomAccessStreamWithSource:(id<SCTRandomAccessStream>)plaintextSource
                                                                        error:(NSError **)error
NS_SWIFT_NAME(newEncryptingRandomAccessStream(source:));

/// Like Tink's decrypting stream (`SCTDecryptingStream`): the stored object from byte 0, whose
/// header must be `header`.
- (nullable SCTDecryptingStream *)newDecryptingStreamWithError:(NSError **)error NS_SWIFT_NAME(newDecryptingStream());

/// The verified plaintext of the stored object `ciphertextSource`, read by range: `pread` takes
/// plaintext offsets, fetching and verifying only the segments it needs (in aligned 1 MiB windows,
/// keeping recent segments, so a player can seek). Its `size` is the plaintext size, from the
/// source's. Checks the source's size and that its header is `header` (and an empty file's only
/// segment) before returning: `SCTFileEncryptionErrorAuthentication` otherwise. The view owns the
/// source and closes it; on failure the source stays the caller's.
- (nullable SCTRandomAccessView *)newDecryptingRandomAccessStreamWithSource:(id<SCTRandomAccessStream>)ciphertextSource
                                                                        error:(NSError **)error
NS_SWIFT_NAME(newDecryptingRandomAccessStream(source:));

@end

/// Local state to restore an upload session (`restoreUpload`): the session's cipher and
/// SDK-defined data (the file's size and time, and a SHA-256 per range made). The UI kit saves the
/// cipher's `attachmentKey` and `header` and the data in private storage (Keychain), as securely
/// as the message, and gives them back unchanged; it is not message metadata. The data has no key.
NS_SWIFT_NAME(FileEncryptionCheckpoint)
@interface SCTFileEncryptionCheckpoint : NSObject <NSCopying>

/// The session's cipher.
@property (nonatomic, readonly, strong) SCTAttachmentCipher *cipher;

/// SDK-defined state of the session, without the key.
@property (nonatomic, readonly, copy) NSString *data;

/// Initialize a checkpoint, e.g. from storage.
/// @param cipher The session's cipher, e.g. from `restoreWithAttachmentKey:header:` with the ones saved before.
/// @param data The checkpoint data saved before.
- (instancetype)initWithCipher:(SCTAttachmentCipher *)cipher data:(NSString *)data
NS_SWIFT_NAME(init(cipher:data:));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// An encryption session of one prepared file: `readCiphertextRange` makes any range of the
/// encrypted file on demand, for a transport to upload, through its cipher's random-access view.
/// No encrypted copy is stored.
NS_SWIFT_NAME(PreparedUpload)
@protocol SCTPreparedUpload <NSObject>

/// The size of the encrypted file in bytes.
@property (nonatomic, readonly) uint64_t ciphertextSize;

/// The size of the original file in bytes.
@property (nonatomic, readonly) uint64_t plaintextSize;

/// The identity of this encrypted stream: the same after a valid restore, new per session.
@property (nonatomic, readonly, copy) NSString *sourceId;

/// The cipher of this upload: its `attachmentKey` is what the message carries so recipients can
/// decrypt the file.
@property (nonatomic, readonly, strong) SCTAttachmentCipher *cipher;

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

/// Encrypts files for upload. Downloads decrypt through `SCTAttachmentCipher`: the message's
/// attachment key and the stored object's header restore it.
NS_SWIFT_NAME(FileEncryptionProvider)
@protocol SCTFileEncryptionProvider <NSObject>

/// A new upload of the file (after any resizing or transcoding): a new cipher and session.
/// @param fileURL The local file to upload.
/// @param attachmentId The attachment id, unique to the upload: the 16 bytes the slot service
///                     gives, e.g. from `newAttachmentId`. The encryption is bound to it.
- (nullable id<SCTPreparedUpload>)prepareUploadWithFileURL:(NSURL *)fileURL
                                              attachmentId:(NSData *)attachmentId
                                                     error:(NSError **)error
NS_SWIFT_NAME(prepareUpload(fileURL:attachmentId:));

/// The upload saved in `checkpoint`: the same cipher and session, so the same encrypted bytes.
/// Fails with `SCTFileEncryptionErrorFileChanged` if the file's size or modification time differs.
/// @param fileURL The same local file.
/// @param checkpoint The checkpoint saved from the session.
- (nullable id<SCTPreparedUpload>)restoreUploadWithFileURL:(NSURL *)fileURL
                                                checkpoint:(SCTFileEncryptionCheckpoint *)checkpoint
                                                     error:(NSError **)error
NS_SWIFT_NAME(restoreUpload(fileURL:checkpoint:));

@end

/// Encrypts a stream given in pieces, like Tink's `StreamingAead.newEncryptingStream`: `write`
/// the plaintext in pieces of any size, e.g. 5 MB upload parts, then `close` once to seal the
/// last segment. Without `close` the output has no last segment and doesn't decrypt. Thread safe;
/// calls block.
///
/// The ciphertext of a plaintext part isn't the part's size: the held-back segment (up to 64 KiB)
/// makes it smaller, and the header and the 16-byte tag per segment make it larger. So 5 MiB of
/// plaintext can give less than 5 MiB of ciphertext, and S3 multipart uploads reject parts other
/// than the last below 5 MiB. Collect the ciphertext until it is at least the minimum part size
/// before uploading a part; what `close` returns, with any ciphertext not yet uploaded, is the
/// last part, of any size.
NS_SWIFT_NAME(EncryptingStream)
@interface SCTEncryptingStream : NSObject

/// The plaintext bytes written so far.
@property (nonatomic, readonly) uint64_t position;

/// The ciphertext bytes returned so far.
@property (nonatomic, readonly) uint64_t ciphertextPosition;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// The ciphertext `plaintext` completes, possibly empty: the header on the first call, then whole
/// 64 KiB segments. As in Tink, the last segment of the plaintext so far stays buffered until more
/// comes or `close`. Fails with `SCTFileEncryptionErrorClosed` once closed or failed.
- (nullable NSData *)write:(NSData *)plaintext error:(NSError **)error NS_SWIFT_NAME(write(_:));

/// The rest of the ciphertext, sealed as the last segment.
- (nullable NSData *)closeWithError:(NSError **)error NS_SWIFT_NAME(close());

@end

/// Decrypts a stream given in pieces, like Tink's `StreamingAead.newDecryptingStream`: `write` the
/// stored bytes in pieces of any size, then `close` once. Each segment's plaintext is returned
/// once it verifies; `close` verifies the last one. On an error
/// (`SCTFileEncryptionErrorAuthentication`: tampered, truncated, or another header), discard all
/// the plaintext returned before. Thread safe; calls block.
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
NS_SWIFT_NAME(AeadFileEncryptionProvider)
@interface SCTAeadFileEncryptionProvider : NSObject <SCTFileEncryptionProvider>

/// "tink-aes256-gcm-hkdf-64k+commit-v1".
@property (class, nonatomic, readonly, copy) NSString *format;

/// A random attachment id: `SCTAttachmentIdSize` random bytes.
+ (NSData *)newAttachmentId NS_SWIFT_NAME(newAttachmentId());

@end

NS_ASSUME_NONNULL_END
