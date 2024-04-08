//
//  MVlionNativeExpressSlotConfig.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/18.
//

#import <MentaVlionSDK/MVlionSDK.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN

@interface MVlionNativeExpressSlotConfig : MVlionSlotConfig

// 其他属性见基类

// 请求广告条数 默认 1  推荐传入 1
// 该条数为最大返回条数, 具体返回多少条广告 以相关回调为准
@property(nonatomic, assign) NSInteger maxAdCount;

/// 素材填充方式 默认 MentaSplashAdMaterialFillMode_ScaleAspectFill
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic, assign) MentaNativeExpressAdMaterialFillMode materialFillMode;






#pragma mark 开发者不必理会该字段, 勿传
// 信息流模版渲染的配置权重信息
@property (nonatomic, strong) NSArray *nativeExpressTemplateConfigWeights;__deprecated_msg("nativeExpressTemplateConfigWeights 已过期废弃");
// 信息流模版渲染的模版信息
@property (nonatomic, strong) NSArray *nativeExpressTemplates;__deprecated_msg("nativeExpressTemplates 已过期废弃");

@end

NS_ASSUME_NONNULL_END
