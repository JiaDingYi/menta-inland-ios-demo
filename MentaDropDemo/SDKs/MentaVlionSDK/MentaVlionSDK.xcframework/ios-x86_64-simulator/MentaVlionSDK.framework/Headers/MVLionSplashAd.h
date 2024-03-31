//
//  MVlionSplashAd.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//

#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
@class MVlionSplashAd;
@class MVlionSplashSlotConfig;
NS_ASSUME_NONNULL_BEGIN



@protocol MVlionSplashAdDelegate <NSObject>

@optional
/// 开屏广告数据拉取成功
- (void)mvlion_splashAdDidLoad:(MVlionSplashAd *)splashAd;

/// 开屏广告物料加载成功
- (void)mvlion_splashAdMaterialDidLoad:(MVlionSplashAd *)splashAd;

/// 开屏加载失败
- (void)mvlion_splashAd:(MVlionSplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏广告被点击了
- (void)mvlion_splashAdDidClick:(MVlionSplashAd *)splashAd extra:(NSDictionary *)extra;

/// 开屏广告关闭了
- (void)mvlion_splashAdDidClose:(MVlionSplashAd *)splashAd closeMode:(MentaSplashAdCloseMode)mode;

/// 开屏广告详情页面关闭的回调
- (void)mvlion_splashAdDetailDidClosed:(MVlionSplashAd *)splashAd;

///  开屏广告曝光
- (void)mvlion_splashAdDidExpose:(MVlionSplashAd *)splashAd;

///  开屏广告点击后的跳转模式
- (void)mvlion_splashAd:(MVlionSplashAd *)splashAd jumpTargetMode:(MentaJumpTargetMode)mode link:(NSString *)link;


@end

@interface MVlionSplashAd : NSObject

/// 开屏广告代理
@property(nonatomic,weak)id <MVlionSplashAdDelegate> delegate;

/// 广告id 只读，开发者不允许修改
@property (nonatomic, copy, readonly) NSString *slotId;

/// 当前广告的价格 在 -mvlion_splashAdDidLoad回调之后才能正确获取
@property (nonatomic, assign, readonly) NSInteger price;

/// 内部自用不必理会
@property (nonatomic, strong, readonly) NSMutableDictionary *extra;



/// 初始化方法
/// - Parameter config: 初始化配置
- (instancetype)initWithConfig:(MVlionSplashSlotConfig *)config;


/// 请求广告
- (void)loadAd;


/// 展现广告
/// - Parameters:
///   - window: 想要展现广告的window
///   - bottomView: 底部logo
///   展示规则: 屏幕高度 减去 bottomView的高度,  剩余部分为素材填充区域,  填充规则为 materialFillMode
- (void)showSplashAdInWindow:(UIWindow *)window;

- (void)destory;
@end

NS_ASSUME_NONNULL_END
