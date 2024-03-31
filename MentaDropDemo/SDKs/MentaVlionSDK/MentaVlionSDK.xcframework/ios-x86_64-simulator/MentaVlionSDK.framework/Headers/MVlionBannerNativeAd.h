//
//  MVlionBannerNativeAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/3/12.
//

#import <Foundation/Foundation.h>
@class MVlionSlotConfig, MVlionBannerNativeAd, MVlionBid;
NS_ASSUME_NONNULL_BEGIN
@protocol MVlionBannerNativeAdDelegate <NSObject>

@optional
/// 广告数据加载成功
/// @param nativeAd 广告
- (void)mvlion_bannerNativeAdDidLoad:(MVlionBannerNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告加载失败
- (void)mvlion_bannerNativeAd:(MVlionBannerNativeAd *)nativeAd didFailWithError:(NSError *)error;

///// 广告数据加载成功
///// @param nativeAd 广告
//- (void)mvlion_preloadNativeAdDidLoad:(MVlionRewardNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载成功
/// @param nativeAd 广告
- (void)mvlion_bannerNativeAdDowaload:(MVlionBannerNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载失败
/// @param nativeAd 广告
- (void)mvlion_bannerNativeAdDowaload:(MVlionBannerNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids didFailWithError:(NSError *)error;


@end

@interface MVlionBannerNativeAd : NSObject
/// delegate
@property(nonatomic, weak)id<MVlionBannerNativeAdDelegate> delegate;

/// 初始化方法
- (instancetype)initWithConfig:(MVlionSlotConfig *)config;


/// 请求广告
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
