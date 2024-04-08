//
//  NSString+MVlion.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface NSString (MVlion)
+ (BOOL)mvl_isEmpty:(NSString *)string;

+ (NSString *)mvl_md5:(NSString *)str;

// dictionary ->json
+ (NSString *)mvl_jsonStringFromDictionary:(NSDictionary *)dictionary;

// 计算文字宽高 系统字体
+ (CGSize)mvl_sizeOfString:(NSString *)string withFont:(UIFont *)font;

+ (CGFloat)mvl_heightForText:(NSString *)text withFont:(UIFont *)font maxWidth:(CGFloat)maxWidth;

+ (CGFloat)mvl_heightForText:(NSString *)text withFont:(UIFont *)font maxWidth:(CGFloat)maxWidth numberOfLines:(NSInteger)numberOfLines;

@end

NS_ASSUME_NONNULL_END
