//
//  MentaUnifiedPrams.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class  MUAdSource;
// souruce 中没有的信息 要通过extra传进来
//extern NSString *const kActKey; // act
//extern NSString *const kStimeKey; // json 中的current

@interface MentaUnifiedPrams : NSObject

// 所有参数
+ (NSDictionary *)requestSDKTrackPramsWithSource:(MUAdSource *)source  extra:(NSDictionary *)extra;


//SDK公共参数
+ (NSMutableDictionary *)requestSDKCommonPramsWithSource:(MUAdSource *)source extra:(NSDictionary *)extra;

// 设备信息参数
+ (NSMutableDictionary *)requestDevicePramsWithSource:(MUAdSource *)source extra:(NSDictionary *)extra;

//广告模块公共参数
+ (NSMutableDictionary *)requestAdModuleCommentPramsWithSource:(MUAdSource *)source extra:(NSDictionary *)extra;

// 广告策略请求参数
+ (NSMutableDictionary *)requesetApiV1ConfigWithAppID:(NSString *)appID appKey:(NSString *)appKey;
@end

NS_ASSUME_NONNULL_END
