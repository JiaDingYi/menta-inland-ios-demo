//
//  MVlionNativeSlotConfig.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/4.
//

#import <MentaVlionSDK/MVlionSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionNativeSlotConfig : MVlionSlotConfig
// 其他属性见基类

// 请求广告条数 默认 1  推荐传入 1
// 该条数为最大返回条数, 具体返回多少条广告 以相关回调为准
@property(nonatomic, assign) NSInteger maxAdCount;

@end

NS_ASSUME_NONNULL_END
