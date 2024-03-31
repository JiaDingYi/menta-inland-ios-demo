//
//  MentaUnifiedNativeAdDelegate.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/9.
//
#import <UIKit/UIKit.h>
#import "MUAdProtocol.h"
#import "MentaNativeAdViewProtocol.h"

@class MentaUnifiedNativeAd,  MentaNativeObject;
@protocol MentaUnifiedNativeAdDelegate <MUAdProtocol>
@optional
/// 广告策略服务加载成功
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedNativeAd *_Nonnull)nativeAd;

/**
 广告数据回调

 @param unifiedNativeAdDataObjects 广告数据数组
 */
- (void)menta_nativeAdLoaded:(NSArray<MentaNativeObject *> * _Nullable)unifiedNativeAdDataObjects nativeAd:(MentaUnifiedNativeAd *_Nullable)nativeAd;

/**
 广告数据回调

 @param unifiedNativeAdDataObjects 广告数据数组
 */
- (void)menta_nativeAdLoaded:(NSArray<MentaNativeObject *> * _Nullable)unifiedNativeAdDataObjects;__attribute__((deprecated("该回调已废弃")));


/// 信息流自渲染加载失败
- (void)menta_nativeAd:(MentaUnifiedNativeAd *_Nonnull)nativeAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description;


/**
 广告曝光回调,
 @param nativeAd MentaUnifiedNativeAd 实例,
 @param adView 广告View
 */
- (void)menta_nativeAdViewWillExpose:(MentaUnifiedNativeAd *_Nullable)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *_Nonnull)adView;


/**
 广告点击回调,

 @param nativeAd MentaUnifiedNativeAd 实例,
 */
- (void)menta_nativeAdViewDidClick:(MentaUnifiedNativeAd *_Nullable)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *_Nullable)adView;

/**
 广告点击关闭回调 UI的移除和数据的解绑 需要在该回调中进行

 @param nativeAd MentaUnifiedNativeAd 实例,
 */
- (void)menta_nativeAdDidClose:(MentaUnifiedNativeAd *_Nonnull)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *_Nullable)adView;


/**
 广告详情页面即将展示回调, 当广告位落地页广告时会触发

 @param nativeAd MentaUnifiedNativeAd 实例,
 */
- (void)menta_nativeAdDetailViewWillPresentScreen:(MentaUnifiedNativeAd *_Nullable)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *_Nonnull)adView;


/**
 广告详情页关闭回调,即落地页关闭回调, 当关闭弹出的落地页时 触发

 @param nativeAd MentaUnifiedNativeAd 实例,
 */
- (void)menta_nativeAdDetailViewClosed:(MentaUnifiedNativeAd *_Nullable)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *_Nonnull)adView;


@end
