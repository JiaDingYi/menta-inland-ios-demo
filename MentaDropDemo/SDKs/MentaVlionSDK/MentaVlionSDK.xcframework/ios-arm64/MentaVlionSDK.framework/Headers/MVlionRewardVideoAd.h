//
//  MVlionRewardVideoAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/12.
//


#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN
@class MVlionRewardVideoAd, MVlionRewardSlotConfig;


@protocol MVlionRewardVideoAdDelegate <NSObject>
@optional
// 激励视频广告加载广告数据成功回调
- (void)mvlion_rewardVideoAdDidLoad:(MVlionRewardVideoAd *)rewardedVideoAd;

// 激励视频数据下载成功回调，已经下载过的视频会直接回调
- (void)mvlion_rewardVideoAdMaterielDidLoad:(MVlionRewardVideoAd *)rewardedVideoAd;

// 激励视频播放页即将展示回调
- (void)mvlion_rewardVideoAdWillVisible:(MVlionRewardVideoAd *)rewardedVideoAd;

// 激励视频广告曝光回调
- (void)mvlion_rewardVideoAdDidExposed:(MVlionRewardVideoAd *)rewardedVideoAd;

// 激励视频广告播放页关闭回调
- (void)mvlion_rewardVideoAdDidClose:(MVlionRewardVideoAd *)rewardedVideoAd;

// 激励视频广告跳过回调
- (void)mvlion_rewardVideoAdDidSkipped:(MVlionRewardVideoAd *)rewardedVideoAd;

// 激励视频广告信息点击回调
- (void)mvlion_rewardVideoAdDidClicked:(MVlionRewardVideoAd *)rewardedVideoAd extra:(NSDictionary *)extra;

// 激励视频广告各种错误信息回调
- (void)mvlion_rewardVideoAd:(MVlionRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;

// 激励视频广告播放达到激励条件回调，以此回调作为奖励依据
- (void)mvlion_rewardVideoAdDidRewardEffective:(MVlionRewardVideoAd *)rewardedVideoAd info:(NSDictionary *)info;

// 激励视频广告播放完成回调
- (void)mvlion_rewardVideoAdDidPlayFinish:(MVlionRewardVideoAd *)rewardedVideoAd;

// 激励视频广告点击后的跳转模式
- (void)mvlion_rewardVideoAd:(MVlionRewardVideoAd *)rewardedVideoAd jumpTargetMode:(MentaJumpTargetMode)mode link:(NSString *)link;

@end

@interface MVlionRewardVideoAd : NSObject

/// 开屏广告代理
@property(nonatomic,weak)id <MVlionRewardVideoAdDelegate> delegate;

/// 广告id 只读，开发者不允许修改
@property(nonatomic, copy, readonly) NSString *slotId;

/// 当前广告的价格 在 -mvlion_rewardVideoAdDidLoad回调之后才能正确获取
@property (nonatomic, assign, readonly) NSInteger price;

/// 内部自用不必理会
@property (nonatomic, strong, readonly) NSMutableDictionary *extra;

/// 初始化方法
/// - Parameter config: 初始化配置
/// 请详细查看 MVlionRewardSlotConfig
- (instancetype)initWithConfig:(MVlionRewardSlotConfig *)config;

/// 加载广告
- (void)loadAd;

/// 展示激励广告
- (void)showAdFromRootViewController:(UIViewController *)viewController;
@end

NS_ASSUME_NONNULL_END
