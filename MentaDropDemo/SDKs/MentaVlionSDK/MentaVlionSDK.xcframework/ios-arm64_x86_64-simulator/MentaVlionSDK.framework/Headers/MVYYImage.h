//
//  MVYYImage.h
//  MVYYImage <https://github.com/ibireme/MVYYImage>
//
//  Created by ibireme on 14/10/20.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<MVYYImage/MVYYImage.h>)
FOUNDATION_EXPORT double MVYYImageVersionNumber;
FOUNDATION_EXPORT const unsigned char MVYYImageVersionString[];
#import <MVYYImage/MVYYFrameImage.h>
#import <MVYYImage/MVYYSpriteSheetImage.h>
#import <MVYYImage/MVYYImageCoder.h>
#import <MVYYImage/MVYYAnimatedImageView.h>
#elif __has_include(<MVYYWebImage/MVYYImage.h>)
#import <MVYYWebImage/MVYYFrameImage.h>
#import <MVYYWebImage/MVYYSpriteSheetImage.h>
#import <MVYYWebImage/MVYYImageCoder.h>
#import <MVYYWebImage/MVYYAnimatedImageView.h>
#else
#import "MVYYFrameImage.h"
#import "MVYYSpriteSheetImage.h"
#import "MVYYImageCoder.h"
#import "MVYYAnimatedImageView.h"
#endif

NS_ASSUME_NONNULL_BEGIN


/**
 A MVYYImage object is a high-level way to display animated image data.
 
 @discussion It is a fully compatible `UIImage` subclass. It extends the UIImage
 to support animated WebP, APNG and GIF format image data decoding. It also 
 support NSCoding protocol to archive and unarchive multi-frame image data.
 
 If the image is created from multi-frame image data, and you want to play the 
 animation, try replace UIImageView with `MVYYAnimatedImageView`.
 
 Sample Code:
 
     // animation@3x.webp
     MVYYImage *image = [MVYYImage imageNamed:@"animation.webp"];
     MVYYAnimatedImageView *imageView = [MVYYAnimatedImageView alloc] initWithImage:image];
     [view addSubView:imageView];
    
 */
@interface MVYYImage : UIImage <MVYYAnimatedImage>

+ (nullable MVYYImage *)imageNamed:(NSString *)name; // no cache!
+ (nullable MVYYImage *)imageWithContentsOfFile:(NSString *)path;
+ (nullable MVYYImage *)imageWithData:(NSData *)data;
+ (nullable MVYYImage *)imageWithData:(NSData *)data scale:(CGFloat)scale;

/**
 If the image is created from data or file, then the value indicates the data type.
 */
@property (nonatomic, readonly) MVYYImageType animatedImageType;

/**
 If the image is created from animated image data (multi-frame GIF/APNG/WebP),
 this property stores the original image data.
 */
@property (nullable, nonatomic, readonly) NSData *animatedImageData;

/**
 The total memory usage (in bytes) if all frame images was loaded into memory.
 The value is 0 if the image is not created from a multi-frame image data.
 */
@property (nonatomic, readonly) NSUInteger animatedImageMemorySize;

/**
 Preload all frame image to memory.
 
 @discussion Set this property to `YES` will block the calling thread to decode 
 all animation frame image to memory, set to `NO` will release the preloaded frames.
 If the image is shared by lots of image views (such as emoticon), preload all
 frames will reduce the CPU cost.
 
 See `animatedImageMemorySize` for memory cost.
 */
@property (nonatomic) BOOL preloadAllAnimatedImageFrames;

@end

NS_ASSUME_NONNULL_END
