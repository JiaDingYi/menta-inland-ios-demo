//
//  MentaUnifiedInterstitialAd.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/17.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedInterstitialAdDelegate.h>
#import <MentaUnifiedSDK/MentaUnifiedAdSpotDefine.h>
@class MUInterstitialConfig;
NS_ASSUME_NONNULL_BEGIN

@interface MentaUnifiedInterstitialAd : NSObject<MentaUnifiedAdSpotDefine, MUAdProtocol>
/// 初始化时传入的config
@property (nonatomic, strong, readonly) MUInterstitialConfig *config;

/// 开屏广告代理
@property (nonatomic, weak) id <MentaUnifiedInterstitialAdDelegate> delegate;


- (instancetype)initWithConfig:(MUInterstitialConfig *)config;

- (void)loadAd;


- (void)showAdFromViewController:(UIViewController *)viewController;


- (void)destory;
@end

NS_ASSUME_NONNULL_END
