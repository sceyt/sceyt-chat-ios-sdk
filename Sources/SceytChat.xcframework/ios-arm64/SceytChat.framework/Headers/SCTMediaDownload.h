//
//  SCTMediaDownload.h
//  SceytChat
//
//  Copyright © 2026 Sceyt LLC. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Downloads of media attachments that a player can read while they download, implemented by the
/// native SDK (shared with Android).
///
/// The bytes go to `<destinationPath>.part`, filled block by block, with a block map in
/// `<destinationPath>.part.json`; when every block is there, the file is renamed to
/// `destinationPath`. A pause, a network loss or an app restart keeps what is downloaded. An
/// encrypted attachment is decrypted and verified as it arrives, so only verified plaintext is
/// ever written.

/// The error domain of media download errors.
FOUNDATION_EXPORT NSErrorDomain const SCTMediaDownloadErrorDomain
NS_SWIFT_NAME(MediaDownloadErrorDomain);

/// The `userInfo` key of the HTTP status of an `SCTMediaDownloadErrorHTTPStatus` error (NSNumber).
FOUNDATION_EXPORT NSString *const SCTMediaDownloadHTTPStatusKey
NS_SWIFT_NAME(MediaDownloadHTTPStatusKey);

/// Media download error codes, the same as the native DownloadErrorCode.
typedef NS_ERROR_ENUM(SCTMediaDownloadErrorDomain, SCTMediaDownloadErrorCode) {
    /// No response or a broken one; retried before it is reported.
    SCTMediaDownloadErrorNetwork = 1,
    /// The server answered with an error status (`SCTMediaDownloadHTTPStatusKey`).
    SCTMediaDownloadErrorHTTPStatus = 2,
    /// The file changed on the server since the download started.
    SCTMediaDownloadErrorFileChanged = 3,
    /// A response that doesn't match the request.
    SCTMediaDownloadErrorInvalidResponse = 4,
    /// The destination couldn't be written.
    SCTMediaDownloadErrorIO = 5,
    /// The download was cancelled.
    SCTMediaDownloadErrorCancelled = 6,
    /// A read: the bytes didn't arrive in time; nothing failed, read again.
    SCTMediaDownloadErrorTimedOut = 7,
    /// The encrypted bytes didn't verify, even fetched again: tampered, or a wrong key.
    SCTMediaDownloadErrorIntegrity = 8,
    /// The cipher is malformed or unsupported: show the attachment as unavailable.
    SCTMediaDownloadErrorInvalidEncryption = 9,
} NS_SWIFT_NAME(MediaDownloadError);

/// The state of a download.
typedef NS_ENUM(NSInteger, SCTMediaDownloadState) {
    /// Opened, not started.
    SCTMediaDownloadStateIdle = 0,
    SCTMediaDownloadStateDownloading = 1,
    SCTMediaDownloadStatePaused = 2,
    /// Retries ran out; `resume` or `resumeAll` continues. Also done when the chat connects.
    SCTMediaDownloadStateWaitingForNetwork = 3,
    /// The file is at the destination path.
    SCTMediaDownloadStateCompleted = 4,
    /// See the status's error; `start` tries again.
    SCTMediaDownloadStateFailed = 5,
    /// Stopped, and the partial file removed.
    SCTMediaDownloadStateCancelled = 6,
} NS_SWIFT_NAME(MediaDownloadState);

/// What a download asks the server for: the file's URL and the headers that authorize it, e.g. a
/// presigned URL, or a URL and a token header. A header with a line break is never sent, nor one
/// the download sets itself (Range, If-Match and the like).
NS_SWIFT_NAME(DownloadRequest)
@interface SCTDownloadRequest : NSObject <NSCopying>

@property (nonatomic, readonly, copy) NSString *url;
@property (nonatomic, readonly, copy) NSDictionary<NSString *, NSString *> *headers;

/// A request for `url` with no headers.
- (instancetype)initWithURL:(NSString *)url
NS_SWIFT_NAME(init(url:));

/// A request for `url` with `headers`.
- (instancetype)initWithURL:(NSString *)url headers:(NSDictionary<NSString *, NSString *> *)headers
NS_SWIFT_NAME(init(url:headers:));

/// This request with the header `name` added or replaced.
- (instancetype)requestWithHeader:(NSString *)name value:(NSString *)value
NS_SWIFT_NAME(withHeader(_:value:));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// A download's state and progress.
NS_SWIFT_NAME(MediaDownloadStatus)
@interface SCTMediaDownloadStatus : NSObject

@property (nonatomic, readonly) SCTMediaDownloadState state;
/// Bytes present.
@property (nonatomic, readonly) int64_t downloaded;
/// The file's size, or -1 until it is known.
@property (nonatomic, readonly) int64_t size;
/// Why it is Failed or WaitingForNetwork, in `SCTMediaDownloadErrorDomain`; nil otherwise.
@property (nonatomic, readonly, nullable) NSError *error;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// The format of a media file, for `SCTStreamableInfo`.
typedef NS_ENUM(NSInteger, SCTMediaFormat) {
    SCTMediaFormatUnknown = 0,
    /// MP4, MOV, M4A and other ISO/QuickTime files.
    SCTMediaFormatMp4 = 1,
    SCTMediaFormatMp3 = 2,
    /// ADTS.
    SCTMediaFormatAac = 3,
    /// Vorbis, Opus.
    SCTMediaFormatOgg = 4,
    SCTMediaFormatWav = 5,
    SCTMediaFormatFlac = 6,
    /// WebM, MKV.
    SCTMediaFormatMatroska = 7,
} NS_SWIFT_NAME(MediaFormat);

/// Whether a media file can play while it downloads: only when what the player needs first (the
/// header, or an MP4's index) is at the start. Anything else plays after the download.
NS_SWIFT_NAME(StreamableInfo)
@interface SCTStreamableInfo : NSObject

@property (nonatomic, readonly) SCTMediaFormat format;
/// MP4: its index (moov) comes before the media data. The other known formats: always.
@property (nonatomic, readonly, getter=isStreamable) BOOL streamable;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// The result of `SCTMediaFiles makeStreamable`.
typedef NS_ENUM(NSInteger, SCTMakeStreamableResult) {
    /// Nothing written: upload the original.
    SCTMakeStreamableResultAlreadyStreamable = 0,
    /// The streamable copy is at the out path: upload it.
    SCTMakeStreamableResultRewritten = 1,
    /// Not an MP4: upload the original.
    SCTMakeStreamableResultNotMp4 = 2,
} NS_SWIFT_NAME(MakeStreamableResult);

/// Media file checks for upload and playback.
NS_SWIFT_NAME(MediaFiles)
@interface SCTMediaFiles : NSObject

/// Whether the local file at `path` can play while it downloads.
+ (SCTStreamableInfo *)checkStreamableAtPath:(NSString *)path
NS_SWIFT_NAME(checkStreamable(path:));

/// For an MP4 whose index comes after its media data, writes a copy to `outPath` with the index
/// first, so it plays while it downloads. Never changes `path`. Fails if the copy can't be made:
/// then upload the original, which plays after download.
+ (SCTMakeStreamableResult)makeStreamableAtPath:(NSString *)path
                                        outPath:(NSString *)outPath
                                          error:(NSError **)error
NS_SWIFT_NAME(makeStreamable(path:outPath:)) __attribute__((swift_error(nonnull_error)));

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

/// Called on a download thread on each state change, and with progress a few times a second.
typedef void(^SCTMediaDownloadStatusHandler)(SCTMediaDownloadStatus *status)
NS_SWIFT_NAME(MediaDownloadStatusHandler);

/// When the server refuses the request (HTTP 400, 401 or 403: an expired URL or token), gets the
/// refused request and returns a fresh one (another URL, other headers or both), or nil, which
/// fails the download. Called on a download thread; may block while it asks the backend.
typedef SCTDownloadRequest * _Nullable (^SCTDownloadRequestProvider)(SCTDownloadRequest *refused)
NS_SWIFT_NAME(DownloadRequestProvider);

/// A download of one media attachment that a player can read while it downloads.
///
/// One download per destination path: downloading the same path again gives the one already
/// running. Releasing this object doesn't stop the download; `find` gives it again.
NS_SWIFT_NAME(MediaDownload)
@interface SCTMediaDownload : NSObject

/// Starts downloading the file `request` asks for to `destinationPath`, or gives the download of
/// that path already running, which then uses `request`. If the file is already there, the
/// download is Completed and reads come from it.
/// @param statusHandler Replaces the download's handler; nil keeps it.
/// @param requestProvider Replaces the download's request provider before it starts; nil keeps
///                        it. Needed for URLs or tokens that expire.
+ (instancetype)downloadRequest:(SCTDownloadRequest *)request
                destinationPath:(NSString *)destinationPath
                  statusHandler:(nullable SCTMediaDownloadStatusHandler)statusHandler
                requestProvider:(nullable SCTDownloadRequestProvider)requestProvider
NS_SWIFT_NAME(download(_:destinationPath:statusHandler:requestProvider:));

/// The same for an encrypted attachment: `destinationPath` gets the decrypted file, and every
/// part is verified before it is written. The download fetches the stored object's header and
/// restores the cipher from it and `attachmentKey` (`SCTAttachmentCipher restoreWithAttachmentKey:header:`);
/// the size comes from the stored object with it, so until then the status's size is -1. Fails
/// with `SCTMediaDownloadErrorInvalidEncryption` if `attachmentKey` is malformed or of an unknown
/// version, and with an integrity error if the header isn't this key's.
/// @param attachmentKey The message's `SCTAttachmentCipher attachmentKey`.
+ (instancetype)downloadEncryptedRequest:(SCTDownloadRequest *)request
                         destinationPath:(NSString *)destinationPath
                           attachmentKey:(NSString *)attachmentKey
                           statusHandler:(nullable SCTMediaDownloadStatusHandler)statusHandler
                         requestProvider:(nullable SCTDownloadRequestProvider)requestProvider
NS_SWIFT_NAME(downloadEncrypted(_:destinationPath:attachmentKey:statusHandler:requestProvider:));

/// The download of `destinationPath` that is running, paused or waiting, or nil.
+ (nullable instancetype)findWithDestinationPath:(NSString *)destinationPath
NS_SWIFT_NAME(find(destinationPath:));

/// Cancels the download of `destinationPath`, if there is one, and removes its partial file.
+ (void)cancelDownloadWithDestinationPath:(NSString *)destinationPath
NS_SWIFT_NAME(cancelDownload(destinationPath:));

/// Continues every download that waits for the network. The SDK does it when the chat connects;
/// call it when the app sees the network come back.
+ (void)resumeAll;

/// The file's final path.
@property (nonatomic, readonly, copy) NSString *destinationPath;

/// The current state and progress.
@property (nonatomic, readonly) SCTMediaDownloadStatus *status;

/// Starts or continues the download: from Idle, Paused, WaitingForNetwork or Failed.
- (void)start;

/// The same as `start`.
- (void)resume;

/// Stops downloading and keeps what is downloaded.
- (void)pause;

/// Stops downloading and removes the partial file. The download can't be used afterwards.
- (void)cancel;

/// Replaces the status handler; nil removes it.
- (void)setStatusHandler:(nullable SCTMediaDownloadStatusHandler)statusHandler;

/// Replaces the request provider; nil removes it.
- (void)setRequestProvider:(nullable SCTDownloadRequestProvider)requestProvider;

/// Up to `length` bytes at `offset`: the present bytes from there, waiting up to `timeout`
/// seconds for the first of them; a missing part is fetched first. Empty data: the end of the
/// file. `SCTMediaDownloadErrorTimedOut`: nothing arrived in time, read again (show buffering).
/// Starts an Idle download. Blocks: not on the main thread.
- (nullable NSData *)readAtOffset:(uint64_t)offset
                           length:(NSUInteger)length
                          timeout:(NSTimeInterval)timeout
                            error:(NSError **)error
NS_SWIFT_NAME(read(offset:length:timeout:));

/// Whether the file can play while it downloads, from its first bytes, waiting up to `timeout`
/// seconds for them. `SCTMediaDownloadErrorTimedOut`: ask again. Blocks: not on the main thread.
- (nullable SCTStreamableInfo *)checkStreamableWithTimeout:(NSTimeInterval)timeout
                                                     error:(NSError **)error
NS_SWIFT_NAME(checkStreamable(timeout:));

/// The present parts of the file, in order, as ranges (location = start, length).
@property (nonatomic, readonly) NSArray<NSValue *> *bufferedRanges;

/// init is unavailable.
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
