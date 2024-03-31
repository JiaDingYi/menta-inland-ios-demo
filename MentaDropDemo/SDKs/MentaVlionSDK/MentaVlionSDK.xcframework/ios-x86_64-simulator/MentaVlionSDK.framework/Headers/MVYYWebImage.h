//
//  MVYYWebImage.h
//  MVYYWebImage <https://github.com/ibireme/MVYYWebImage>
//
//  Created by ibireme on 15/2/23.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<MVYYWebImage/MVYYWebImage.h>)
FOUNDATION_EXPORT double MVYYWebImageVersionNumber;
FOUNDATION_EXPORT const unsigned char MVYYWebImageVersionString[];
#import <MVYYWebImage/MVYYImageCache.h>
#import <MVYYWebImage/MVYYWebImageOperation.h>
#import <MVYYWebImage/MVYYWebImageManager.h>
#import <MVYYWebImage/UIImage+MVYYWebImage.h>
#import <MVYYWebImage/UIImageView+MVYYWebImage.h>
#import <MVYYWebImage/UIButton+MVYYWebImage.h>
#import <MVYYWebImage/CALayer+MVYYWebImage.h>
#import <MVYYWebImage/MKAnnotationView+MVYYWebImage.h>
#else
#import "MVYYImageCache.h"
#import "MVYYWebImageOperation.h"
#import "MVYYWebImageManager.h"
#import "UIImage+MVYYWebImage.h"
#import "UIImageView+MVYYWebImage.h"
#import "UIButton+MVYYWebImage.h"
#import "CALayer+MVYYWebImage.h"
#import "MKAnnotationView+MVYYWebImage.h"
#endif

#if __has_include(<MVYYImage/MVYYImage.h>)
#import <MVYYImage/MVYYImage.h>
#elif __has_include(<MVYYWebImage/MVYYImage.h>)
#import <MVYYWebImage/MVYYImage.h>
#import <MVYYWebImage/MVYYFrameImage.h>
#import <MVYYWebImage/MVYYSpriteSheetImage.h>
#import <MVYYWebImage/MVYYImageCoder.h>
#import <MVYYWebImage/MVYYAnimatedImageView.h>
#else
#import "MVYYImage.h"
#import "MVYYFrameImage.h"
#import "MVYYSpriteSheetImage.h"
#import "MVYYImageCoder.h"
#import "MVYYAnimatedImageView.h"
#endif

#if __has_include(<MVYYCache/MVYYCache.h>)
#import <MVYYCache/MVYYCache.h>
#elif __has_include(<MVYYWebImage/MVYYCache.h>)
#import <MVYYWebImage/MVYYCache.h>
#import <MVYYWebImage/MVYYMemoryCache.h>
#import <MVYYWebImage/MVYYDiskCache.h>
#import <MVYYWebImage/MVYYKVStorage.h>
#else
#import "MVYYCache.h"
#import "MVYYMemoryCache.h"
#import "MVYYDiskCache.h"
#import "MVYYKVStorage.h"
#endif

