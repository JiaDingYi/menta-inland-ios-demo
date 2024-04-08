//
//  MentaUnifiedBannerAd.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/3/18.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedBannerAdDelegate.h>
#import <MentaUnifiedSDK/MentaUnifiedAdSpotDefine.h>

NS_ASSUME_NONNULL_BEGIN
@class MUBannerConfig;
@interface MentaUnifiedBannerAd : NSObject<MentaUnifiedAdSpotDefine, MUAdProtocol>
/// 初始化时传入的config
@property (nonatomic, strong, readonly) MUBannerConfig *config;

/// 开屏广告代理
@property (nonatomic, weak) id <MentaUnifiedBannerAdDelegate> delegate;


- (instancetype)initWithConfig:(MUBannerConfig *)config;

- (void)loadAd;

- (void)showInContainer:(UIView *)containerView;

- (void)destory;

@end

NS_ASSUME_NONNULL_END
