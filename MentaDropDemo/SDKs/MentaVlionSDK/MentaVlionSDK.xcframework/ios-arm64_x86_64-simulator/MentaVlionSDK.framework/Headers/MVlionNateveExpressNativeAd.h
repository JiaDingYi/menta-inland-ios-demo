//
//  MVlionNateveExpressNativeAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionSlotConfig, MVlionNateveExpressNativeAd, MVlionBid;
@protocol MVlionNateveExpressNativeAdDelegate <NSObject>

/// 广告数据加载成功
/// @param nativeAd 广告
- (void)mvlion_expressNativeAdDidLoad:(MVlionNateveExpressNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告加载失败
- (void)mvlion_expressNativeAd:(MVlionNateveExpressNativeAd *)nativeAd didFailWithError:(NSError *)error;

///// 广告数据加载成功
///// @param nativeAd 广告
//- (void)mvlion_preloadNativeAdDidLoad:(MVlionRewardNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载成功
/// @param nativeAd 广告
- (void)mvlion_expressNativeAdDowaload:(MVlionNateveExpressNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载失败
/// @param nativeAd 广告
- (void)mvlion_expressNativeAdDowaload:(MVlionNateveExpressNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids didFailWithError:(NSError *)error;


@end

@interface MVlionNateveExpressNativeAd : NSObject

/// delegate
@property(nonatomic, weak)id<MVlionNateveExpressNativeAdDelegate> delegate;

/// 初始化方法
- (instancetype)initWithConfig:(MVlionSlotConfig *)config;


/// 请求广告
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
