//
//  MentaUnifiedSplashAdDelegate.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/22.
//
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
#import <MentaUnifiedSDK/MUAdProtocol.h>
@class MentaUnifiedSplashAd;

@protocol MentaUnifiedSplashAdDelegate <MUAdProtocol>

@optional

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedSplashAd *_Nonnull)splashAd;

/// 开屏广告数据拉取成功
- (void)menta_splashAdDidLoad:(MentaUnifiedSplashAd *_Nonnull)splashAd;

/// 开屏加载失败
- (void)menta_splashAd:(MentaUnifiedSplashAd *_Nonnull)splashAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description;

/// 开屏广告被点击了
- (void)menta_splashAdDidClick:(MentaUnifiedSplashAd *_Nonnull)splashAd;

/// 开屏广告关闭了
- (void)menta_splashAdDidClose:(MentaUnifiedSplashAd *_Nonnull)splashAd closeMode:(MentaSplashAdCloseMode)mode;

/// 开屏广告曝光
- (void)menta_splashAdDidExpose:(MentaUnifiedSplashAd *_Nonnull)splashAd;

/// 开屏广告 展现的广告信息 曝光之前会触发该回调
- (void)menta_splashAd:(MentaUnifiedSplashAd *_Nonnull)splashAd bestTargetSourcePlatformInfo:(NSDictionary *_Nonnull)info;

@end
