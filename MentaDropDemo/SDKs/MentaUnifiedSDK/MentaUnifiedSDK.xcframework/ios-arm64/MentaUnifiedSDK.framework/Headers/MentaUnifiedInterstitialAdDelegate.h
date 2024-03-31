//
//  MentaUnifiedInterstitialAdDelegate.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/17.
//

#import <UIKit/UIKit.h>
#import <MentaUnifiedSDK/MUAdProtocol.h>
@class MentaUnifiedInterstitialAd;

@protocol MentaUnifiedInterstitialAdDelegate <MUAdProtocol>
@optional

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingInterstitialADPolicy:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;

/// 插屏广告源数据拉取成功
- (void)menta_interstitialAdDidLoad:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;

/// 插屏广告视频下载成功
- (void)menta_interstitialAdMaterialDidLoad:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;

/// 插屏广告加载失败
- (void)menta_interstitialAd:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description;

/// 插屏广告被点击了
- (void)menta_interstitialAdDidClick:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;

/// 插屏广告关闭了
- (void)menta_interstitialAdDidClose:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;

/// 插屏将要展现
- (void)menta_interstitialAdWillVisible:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;

/// 插屏广告曝光
- (void)menta_interstitialAdDidExpose:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;

/// 插屏广告 展现的广告信息 曝光之前会触发该回调
- (void)menta_interstitialAd:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd bestTargetSourcePlatformInfo:(NSDictionary *_Nonnull)info;

@end
