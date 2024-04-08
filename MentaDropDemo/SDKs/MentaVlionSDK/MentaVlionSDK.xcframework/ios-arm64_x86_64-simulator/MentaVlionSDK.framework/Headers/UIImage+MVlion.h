//
//  UIImage+MVlion.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/20.
//

#import <UIKit/UIKit.h>
@class MVYYImage;
NS_ASSUME_NONNULL_BEGIN

@interface UIImage (MVlion)
+ (UIImage *)mvlion_sdkBundleImageName:(NSString *)name;
//gif
+ (MVYYImage *)mvlion_sdkBundleGifImageName:(NSString *)name;
@end

NS_ASSUME_NONNULL_END
