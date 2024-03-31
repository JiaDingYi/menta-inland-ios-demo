//
//  MVlionNativeExpressAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/18.
//

#import <Foundation/Foundation.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN
@class MVlionNativeExpressSlotConfig, MVlionNativeExpressAd, MVlionNativeExpressAdView;
@protocol MVlionNativeExpressAdDelegate <NSObject>

@optional
/**
 * 拉取原生模板广告成功
 */
- (void)mvlion_nativeExpressAdSuccessToLoad:(MVlionNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof MVlionNativeExpressAdView *> *)views;

/**
 * 拉取原生模板广告失败
 */
- (void)mvlion_nativeExpressAdFailToLoad:(MVlionNativeExpressAd *)nativeExpressAd error:(NSError *)error;

/**
 * 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 */
- (void)mvlion_nativeExpressAdViewRenderSuccess:(MVlionNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告渲染失败
 */
- (void)mvlion_nativeExpressAdViewRenderFail:(MVlionNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告将要展现回调 (可多次触发)
 */
- (void)mvlion_nativeExpressAdViewWillVisible:(MVlionNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告曝光回调 (只触发一次)
 */
- (void)mvlion_nativeExpressAdViewExposure:(MVlionNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告点击回调
 */
- (void)mvlion_nativeExpressAdViewClicked:(MVlionNativeExpressAdView *)nativeExpressAdView extra:(NSDictionary *)extra;

/**
 * 原生模板广告被关闭
 */
- (void)mvlion_nativeExpressAdViewClosed:(MVlionNativeExpressAdView *)nativeExpressAdView;

/**
 * 点击原生模板广告以后即将弹出详情页
 */
- (void)mvlion_nativeExpressAdDetailViewWillPresentScreen:(MVlionNativeExpressAdView *)nativeExpressAdView;

/**
 * 详情页被关闭
 */
- (void)mvlion_nativeExpressAdDetailViewDidDismissScreen:(MVlionNativeExpressAdView *)nativeExpressAdView;

// 原生模板点击后的跳转模式
- (void)mvlion_nativeExpressAd:(MVlionNativeExpressAdView *)nativeExpressAdView jumpTargetMode:(MentaJumpTargetMode)mode link:(NSString *)link;

@end

@interface MVlionNativeExpressAd : NSObject

/// 自渲染信息流广告代理
@property(nonatomic,weak)id <MVlionNativeExpressAdDelegate> delegate;

/// 广告id 只读，开发者不允许修改
@property(nonatomic, copy, readonly) NSString *slotId;

/// 内部自用不必理会
@property (nonatomic, strong) NSMutableDictionary *extra;

/// 初始化方法
/// - Parameter config: 初始化配置
- (instancetype)initWithConfig:(MVlionNativeExpressSlotConfig *)config;


/// 请求广告
- (void)loadAd;


- (void)destory;

@end

NS_ASSUME_NONNULL_END
