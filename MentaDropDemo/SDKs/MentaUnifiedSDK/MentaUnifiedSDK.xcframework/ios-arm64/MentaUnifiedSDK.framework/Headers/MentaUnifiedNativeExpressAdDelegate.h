//
//  Header.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/23.
//
#import "MUAdProtocol.h"
@class MentaUnifiedNativeExpressAd, MentaUnifiedNativeExpressAdObject;
@protocol MentaUnifiedNativeExpressAdDelegate <MUAdProtocol>
@optional
/// 广告策略服务加载成功
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd;

/**
 广告数据回调
 @param unifiedNativeAdDataObjects 广告数据数组
 */
- (void)menta_nativeExpressAdLoaded:(NSArray<MentaUnifiedNativeExpressAdObject *> * _Nullable)unifiedNativeAdDataObjects nativeExpressAd:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd;


/**
信息流广告加载失败
@param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
@param error 错误
*/
- (void)menta_nativeExpressAd:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description;

/**
 信息流渲染成功
 @param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
 */
- (void)menta_nativeExpressAdViewRenderSuccess:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *_Nonnull)nativeExpressAdObj;

/**
 信息流渲染失败
 @param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
 */
- (void)nativeExpressAdViewRenderFail:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *_Nonnull)nativeExpressAdObj;

/**
 广告曝光回调
 @param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
 @param adView 广告View
 */
- (void)menta_nativeExpressAdViewWillExpose:(MentaUnifiedNativeExpressAd *_Nullable)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *_Nonnull)nativeExpressAdObj;


/**
 广告点击回调,
 @param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
 */
- (void)menta_nativeExpressAdViewDidClick:(MentaUnifiedNativeExpressAd *_Nullable)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *_Nonnull)nativeExpressAdObj;

/**
 广告点击关闭回调 UI的移除和数据的解绑 需要在该回调中进行
 @param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
 */
- (void)menta_nativeExpressAdDidClose:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *_Nonnull)nativeExpressAdObj;


/**
 广告详情页面即将展示回调, 当广告位落地页广告时会触发
 @param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
 */
//- (void)menta_nativeExpressAdDetailViewWillPresentScreen:(MentaUnifiedNativeExpressAd *_Nullable)nativeExpressAd adView:(UIView *_Nonnull)adView;


/**
 广告详情页关闭回调,即落地页关闭回调, 当关闭弹出的落地页时 触发
 @param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
 */
//- (void)menta_nativeExpressAdDetailViewClosed:(MentaUnifiedNativeExpressAd *_Nullable)nativeExpressAd adView:(UIView *_Nonnull)adView;


@end
