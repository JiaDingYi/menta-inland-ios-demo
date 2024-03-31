//
//  MVlionSplashSlotConfig.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/25.
//

#import <MentaVlionSDK/MVlionSDK.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN

@interface MVlionSplashSlotConfig : MVlionSlotConfig

// 其他属性见基类


/// 广告交互方式 默认 MentaSplashAdInterviewMode_BottomHotSpotClick
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic, assign) MentaSplashAdInterviewMode interviewMode;

/// 素材填充方式 默认 MentaSplashAdMaterialFillMode_ScaleAspectFill
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic, assign) MentaSplashAdMaterialFillMode materialFillMode;

/// 开屏广告持续秒数 默认5
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic,assign) NSInteger maxSec;

/// 开屏广告摇一摇模式下的灵敏度 默认500
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic,assign) NSInteger shakeRange;

/// 开屏广告摇一摇模式下扭动的灵敏度 默认500
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic,assign) NSInteger twistRange;

/// 开屏广告上滑模式下的触发滑动方法的滑动距离 默认 20
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic,assign) NSInteger swipeRange;


/// 底部logo
@property(nonatomic, strong) UIView *bottomView;

/// 当前控制器
@property(nonatomic,weak) UIViewController *viewController;



@end

NS_ASSUME_NONNULL_END
