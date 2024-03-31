//
//  MVlionRewardSlotConfig.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/21.
//

#import "MVlionSlotConfig.h"
#import <MentaVlionBaseSDK/MentaVlionBaseSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface MVlionRewardSlotConfig : MVlionSlotConfig

// 其他属性见基类

// 视频填充方式
@property (nonatomic, assign) MentaRewardVideoAdViewGravity videoGravity;

// 屏幕方向
@property (nonatomic, assign) MentaRewardVideoAdViewInterfaceOrientation orientation;

// 是否静音 默认NO
// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property (nonatomic, assign) BOOL mute;

// 是否使用热区点击(可以提高点击率) 默认YES
// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property (nonatomic, assign) BOOL isCanUseHotSpot;

@end

NS_ASSUME_NONNULL_END
