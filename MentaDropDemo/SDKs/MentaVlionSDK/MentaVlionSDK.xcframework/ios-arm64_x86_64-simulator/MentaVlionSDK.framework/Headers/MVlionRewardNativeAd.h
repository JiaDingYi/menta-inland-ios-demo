//
//  MVlionRewardNativeAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/12.
//

#import <Foundation/Foundation.h>
@class MVlionSlotConfig, MVlionRewardNativeAd, MVlionBid;
NS_ASSUME_NONNULL_BEGIN
@protocol MVlionRewardNativeAdDelegate <NSObject>

/// 广告数据加载成功
/// @param nativeAd 广告
- (void)mvlion_nativeAdDidLoad:(MVlionRewardNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告加载失败
- (void)mvlion_nativeAd:(MVlionRewardNativeAd *)nativeAd didFailWithError:(NSError *)error;

///// 广告数据加载成功
///// @param nativeAd 广告
//- (void)mvlion_preloadNativeAdDidLoad:(MVlionRewardNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载成功
/// @param nativeAd 广告
- (void)mvlion_nativeAdDowaload:(MVlionRewardNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载失败
/// @param nativeAd 广告
- (void)mvlion_nativeAdDowaload:(MVlionRewardNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids didFailWithError:(NSError *)error;


@end
@interface MVlionRewardNativeAd : NSObject

@property(nonatomic,weak)id <MVlionRewardNativeAdDelegate> delegate;

- (instancetype)initWithConfig:(MVlionSlotConfig *)config;

- (void)loadAd;
@end

NS_ASSUME_NONNULL_END
