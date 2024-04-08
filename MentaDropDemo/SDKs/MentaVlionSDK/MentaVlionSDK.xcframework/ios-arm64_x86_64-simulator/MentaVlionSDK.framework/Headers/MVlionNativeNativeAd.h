//
//  MVlionNativeNativeAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/4.
//

#import <Foundation/Foundation.h>
@class MVlionNativeNativeAd;
@class MVlionBid;
@class MVlionNativeSlotConfig;

NS_ASSUME_NONNULL_BEGIN
@protocol MVlionNativeNativeAdDelegate <NSObject>
@optional
/// 广告数据加载成功
/// @param nativeAd 广告
- (void)mvlion_nativeNativeAdDidLoad:(MVlionNativeNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告加载失败
- (void)mvlion_nativeNativeAd:(MVlionNativeNativeAd *)nativeAd didFailWithError:(NSError *)error;

/// 广告数据加载成功
/// @param nativeAd 广告
- (void)mvlion_preloadNativeNativeAdDidLoad:(MVlionNativeNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

///// 广告素材下载成功
///// @param nativeAd 广告
//- (void)mvlion_nativeNativeAdDowaload:(MVlionNativeNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;
//
///// 广告素材下载失败
///// @param nativeAd 广告
//- (void)mvlion_nativeNativeAdDowaload:(MVlionNativeNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids didFailWithError:(NSError *)error;

@end

@interface MVlionNativeNativeAd : NSObject

/// delegate
@property(nonatomic, weak)id<MVlionNativeNativeAdDelegate> delegate;

/// 初始化方法
- (instancetype)initWithConfig:(MVlionNativeSlotConfig *)config;


/// 请求广告
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
