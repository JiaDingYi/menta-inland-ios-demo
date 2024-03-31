//
//  MVlionBannerAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/3/12.
//

#import <Foundation/Foundation.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
@class MVlionBannerAdView, MVlionBannerAd, MVlionBannerSlotConfig;
NS_ASSUME_NONNULL_BEGIN
@protocol MVlionBannerAdDelegate <NSObject>

/**
 * 拉取横幅(banner)拉取数据广告成功
 */
- (void)mvlion_bannerAdSuccessToLoad:(MVlionBannerAd *)bannerAd;

/**
 * 拉取横幅(banner)拉取数据广告成功
 */
- (void)mvlion_bannerAdMaterialDidLoad:(MVlionBannerAd *)bannerAd bannerAdView:(MVlionBannerAdView *)bannerAdView;

/**
 * 拉取横幅(banner)广告失败
 */
- (void)mvlion_bannerAdFailToLoad:(MVlionBannerAd *)bannerAd error:(NSError *)error;

/**
 * 横幅(banner)广告将要展现回调
 */
- (void)mvlion_bannerAdViewWillVisible:(MVlionBannerAd *)bannerAd bannerAdView:(MVlionBannerAdView *)bannerAdView;

/**
 * 横幅(banner)广告曝光回调 (只触发一次)
 */
- (void)mvlion_bannerAdViewExposure:(MVlionBannerAd *)bannerAd bannerAdView:(MVlionBannerAdView *)bannerAdView;

/**
 * 横幅(banner)广告点击回调
 */
- (void)mvlion_bannerAdViewClicked:(MVlionBannerAd *)bannerAd bannerAdView:(MVlionBannerAdView *)bannerAdView extra:(NSDictionary *)extra;

/**
 * 横幅(banner)广告被关闭
 */
- (void)mvlion_bannerAdViewClosed:(MVlionBannerAd *)bannerAd bannerAdView:(MVlionBannerAdView *)bannerAdView;

// 横幅(banner)点击后的跳转模式
- (void)mvlion_bannerAd:(MVlionBannerAdView *)bannerAdView jumpTargetMode:(MentaJumpTargetMode)mode link:(NSString *)link;

@end

@interface MVlionBannerAd : NSObject

- (instancetype)initWithConfig:(MVlionBannerSlotConfig *)config ;

/// 自渲染信息流广告代理
@property(nonatomic,weak)id <MVlionBannerAdDelegate> delegate;

/// 广告id 只读，开发者不允许修改
@property(nonatomic, copy, readonly) NSString *slotId;

/// 内部自用不必理会
@property (nonatomic, strong) NSMutableDictionary *extra;

/// 当前广告的价格
@property (nonatomic, assign, readonly) NSInteger price;


/// 请求广告
- (void)loadAd;


- (void)destory;

@end

NS_ASSUME_NONNULL_END
