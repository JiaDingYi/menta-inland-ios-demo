//
//  MentaUnifiedRewardVideoAd.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MentaUnifiedSDK/MentaUnifiedRewardVideoDelegate.h>
#import <MentaUnifiedSDK/MentaUnifiedAdSpotDefine.h>

NS_ASSUME_NONNULL_BEGIN
@class MURewardVideoConfig;
@interface MentaUnifiedRewardVideoAd : NSObject<MentaUnifiedAdSpotDefine, MUAdProtocol>

/// 初始化时传入的config
@property (nonatomic, strong, readonly) MURewardVideoConfig *config;

/// 开屏广告代理
@property (nonatomic, weak) id <MentaUnifiedRewardVideoDelegate> delegate;

/// 广告是否有效，建议在展示广告之前判断，否则会影响计费或展示失败
@property (nonatomic, readonly) BOOL isAdValid;


- (instancetype)initWithConfig:(MURewardVideoConfig *)config;


- (void)loadAd;


- (void)showAdFromRootViewController:(UIViewController *)viewController;

- (void)destory;
@end

NS_ASSUME_NONNULL_END
