//
//  MVlionInterstitialConfig.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/27.
//

#import <MentaVlionSDK/MVlionSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionInterstitialConfig : MVlionSlotConfig

// 其他属性见基类

// 交互方式
/// 广告交互方式 默认 MentaSplashAdInterviewMode_BottomHotSpotClick
/// 可传入多种 详情见demo
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic, assign) MentaInterstitialAdInterviewMode interviewMode;

/// 插屏广告摇一摇模式下的灵敏度 默认500
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic, assign) NSInteger shakeRange;

/// 插屏广告摇一摇模式下扭动的灵敏度 默认500
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic, assign) NSInteger twistRange;

/// 插屏广告 播放视频时 是否静音 默认NO
/// 当 MVlionSDKManager.isAggregation = NO 时 设置才生效 详情请看MVlionSDKManager类
@property(nonatomic, assign) BOOL mute;

// 插屏自动关闭倒计时
@property (nonatomic, assign) NSUInteger countDown;

@end

NS_ASSUME_NONNULL_END
