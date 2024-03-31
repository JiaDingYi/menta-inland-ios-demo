//
//  MVlionSlotConfig.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionSlotConfig : NSObject

@property (nonatomic) CGSize adSize;// 广告位尺寸 所有广告位必须要传 包括开屏
@property (nonatomic, copy) NSString *slotId;// 广告位id
@property (nonatomic, assign) NSInteger bidFloor;// 底价 默认 0


@property (nonatomic, copy) NSString *adx_tagid;// 聚合广告位id 用于统计时的填充的参数
@property (nonatomic, copy) NSString *trace_id;// 聚合广告位每次请求生成的trace_id 用于统计时的填充的参数
@property (nonatomic, copy) NSString *menta_app_id;// 聚合广告位的  appid 用于appobject的传值

#pragma mark 开发者不必理会该字段, 勿传
@property (nonatomic, strong) NSDictionary *adTemplate __deprecated_msg("adTemplate 已过期废弃"); // 模版信息

@end

NS_ASSUME_NONNULL_END
