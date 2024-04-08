//
//  MVlionSplashNativeAd.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//

#import <Foundation/Foundation.h>
#import "MVlionEnum.h"
@class MVlionSplashNativeAd;
@class MVlionBid;
@class MVlionSplashSlotConfig;

NS_ASSUME_NONNULL_BEGIN
@protocol MVlionSplashNativeAdDelegate <NSObject>
@optional
/// 广告数据加载成功
/// @param nativeAd 广告
- (void)mvlion_nativeAdDidLoad:(MVlionSplashNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告加载失败
- (void)mvlion_nativeAd:(MVlionSplashNativeAd *)nativeAd didFailWithError:(NSError *)error;

/// 广告数据加载成功
/// @param nativeAd 广告
- (void)mvlion_preloadNativeAdDidLoad:(MVlionSplashNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载成功
/// @param nativeAd 广告
- (void)mvlion_nativeAdDowaload:(MVlionSplashNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids;

/// 广告素材下载失败
/// @param nativeAd 广告
- (void)mvlion_nativeAdDowaload:(MVlionSplashNativeAd *)nativeAd bids:(NSArray<MVlionBid *> *)bids didFailWithError:(NSError *)error;

@end

@interface MVlionSplashNativeAd : NSObject
@property(nonatomic, assign)MVlionSlotType slotType;
/// delegate
@property(nonatomic, weak)id<MVlionSplashNativeAdDelegate> delegate;

/// 初始化方法
- (instancetype)initWithConfig:(MVlionSplashSlotConfig *)config;


/// 请求广告
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
