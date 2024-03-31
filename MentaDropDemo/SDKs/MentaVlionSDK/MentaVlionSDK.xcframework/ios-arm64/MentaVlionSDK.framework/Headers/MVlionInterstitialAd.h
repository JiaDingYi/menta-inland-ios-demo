//
//  MVlionInterstitialAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
@class MVlionInterstitialAd, MVlionInterstitialConfig;
NS_ASSUME_NONNULL_BEGIN

@protocol MVlionInterstitialAdDelegate <NSObject>

@optional

/// 开屏广告数据拉取成功
- (void)mvlion_interstitialAdDidLoad:(MVlionInterstitialAd *)interstitial;

/// 开屏广告物料加载成功
- (void)mvlion_interstitialMaterialDidLoad:(MVlionInterstitialAd *)interstitial;

/// 开屏广告加载失败
- (void)mvlion_interstitialFailToLoadAd:(MVlionInterstitialAd *)interstitial error:(NSError *)error;

/// 插屏广告将要展示回调
- (void)mvlion_interstitialAdWillVisible:(MVlionInterstitialAd *)interstitial;

/// 插屏广告曝光回调
- (void)mvlion_interstitialAdDidExposed:(MVlionInterstitialAd *)interstitial;

/// 插屏广告关闭回调
- (void)mvlion_interstitialAdDidClose:(MVlionInterstitialAd *)interstitial;

/// 插屏广告点击
- (void)mvlion_interstitialClicked:(MVlionInterstitialAd *)interstitial extra:(NSDictionary *)extra;

/// 详情页关闭
- (void)mvlion_interstitialDetailDidClosed:(MVlionInterstitialAd *)interstitial;

// 插屏广告点击后的跳转模式
- (void)mvlion_interstitial:(MVlionInterstitialAd *)interstitial jumpTargetMode:(MentaJumpTargetMode)mode link:(NSString *)link;


@end

@interface MVlionInterstitialAd : NSObject

/// 开屏广告代理
@property(nonatomic,weak)id <MVlionInterstitialAdDelegate> delegate;

/// 广告id 只读，开发者不允许修改
@property(nonatomic, copy, readonly) NSString *slotId;

/// 当前广告的价格 在 -mvlion_rewardVideoAdDidLoad回调之后才能正确获取
@property (nonatomic, assign, readonly) NSInteger price;

/// 内部自用不必理会
@property (nonatomic, strong, readonly) NSMutableDictionary *extra;


/// 初始化方法
/// - Parameter config: 初始化配置
- (instancetype)initWithConfig:(MVlionInterstitialConfig *)config;


/// 加载广告
- (void)loadAd;

/// 展示激励广告
- (void)showAdFromViewController:(UIViewController *)viewController;

/// 移除插屏广告
- (void)destory;
@end

NS_ASSUME_NONNULL_END
