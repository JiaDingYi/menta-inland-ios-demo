//
//  MVlionInterstitialNativeAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/27.
//

#import <Foundation/Foundation.h>
@class MVlionSlotConfig, MVlionInterstitialNativeAd, MVlionBid;
NS_ASSUME_NONNULL_BEGIN
@protocol MVlionInterstitialNativeAdDelegate <NSObject>

/// 广告数据加载成功
/// @param nativeAd 广告
- (void)mvlion_nativeAdDidLoad:(MVlionInterstitialNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告加载失败
- (void)mvlion_nativeAd:(MVlionInterstitialNativeAd *)nativeAd didFailWithError:(NSError *)error;

///// 广告数据加载成功
///// @param nativeAd 广告
//- (void)mvlion_preloadNativeAdDidLoad:(MVlionRewardNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载成功
/// @param nativeAd 广告
- (void)mvlion_nativeAdDowaload:(MVlionInterstitialNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载失败
/// @param nativeAd 广告
- (void)mvlion_nativeAdDowaload:(MVlionInterstitialNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids didFailWithError:(NSError *)error;


@end

@interface MVlionInterstitialNativeAd : NSObject

@property(nonatomic,weak)id <MVlionInterstitialNativeAdDelegate> delegate;

- (instancetype)initWithConfig:(MVlionSlotConfig *)config;

- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
