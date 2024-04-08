//
//  UIColor+MVlion.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/17.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (MVlion)
+ (UIColor *)mvl_red:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(CGFloat)alpha;
+ (NSArray *)mvl_convertColorToRGB:(UIColor *)color;
+ (UIColor *)mvl_colorWithHex:(NSInteger)hex;
+ (UIColor *)mvl_colorWithHex:(NSInteger)hex alpha:(CGFloat)alpha;
+ (UIColor *)mvl_colorWithHexString:(NSString *)hexString;

+ (UIColor *)mvl_gradientColorFromColor:(UIColor *)startColor toColor:(UIColor *)endColor withFrame:(CGRect)frame;
@end

NS_ASSUME_NONNULL_END
