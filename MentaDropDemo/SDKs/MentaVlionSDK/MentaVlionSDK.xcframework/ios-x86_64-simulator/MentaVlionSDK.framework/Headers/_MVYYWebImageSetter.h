//
//  _MVYYWebImageSetter.h
//  MVYYWebImage <https://github.com/ibireme/MVYYWebImage>
//
//  Created by ibireme on 15/7/15.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//
#import <UIKit/UIKit.h>
#import <pthread.h>

#if __has_include(<MVYYWebImage/MVYYWebImage.h>)
#import <MVYYWebImage/MVYYWebImageManager.h>
#else
#import "MVYYWebImageManager.h"
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 Submits a block for execution on a main queue and waits until the block completes.
 */
static inline void _mvyy_dispatch_sync_on_main_queue(void (^block)()) {
    if (pthread_main_np()) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
}

extern NSString *const _MVYYWebImageFadeAnimationKey;
extern const NSTimeInterval _MVYYWebImageFadeTime;
extern const NSTimeInterval _MVYYWebImageProgressiveFadeTime;

/**
 Private class used by web image categories.
 Typically, you should not use this class directly.
 */
@interface _MVYYWebImageSetter : NSObject
/// Current image url.
@property (nullable, nonatomic, readonly) NSURL *imageURL;
/// Current sentinel.
@property (nonatomic, readonly) int32_t sentinel;

/// Create new operation for web image and return a sentinel value.
- (int32_t)setOperationWithSentinel:(int32_t)sentinel
                                url:(nullable NSURL *)imageURL
                            options:(MVYYWebImageOptions)options
                            manager:(MVYYWebImageManager *)manager
                           progress:(nullable MVYYWebImageProgressBlock)progress
                          transform:(nullable MVYYWebImageTransformBlock)transform
                         completion:(nullable MVYYWebImageCompletionBlock)completion;

/// Cancel and return a sentinel value. The imageURL will be set to nil.
- (int32_t)cancel;

/// Cancel and return a sentinel value. The imageURL will be set to new value.
- (int32_t)cancelWithNewURL:(nullable NSURL *)imageURL;

/// A queue to set operation.
+ (dispatch_queue_t)setterQueue;

@end

NS_ASSUME_NONNULL_END
