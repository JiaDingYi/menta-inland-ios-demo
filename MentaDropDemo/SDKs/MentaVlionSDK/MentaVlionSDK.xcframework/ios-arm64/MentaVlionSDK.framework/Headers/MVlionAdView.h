//
//  MVlionAdView.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/17.
//

#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
#import <MentaVlionSDK/MVlionEnum.h>
#import "UIView+MVlionClick.h"
@class MVlionAdView, MVlionBid;
NS_ASSUME_NONNULL_BEGIN
@protocol MVlionAdViewDelegate <NSObject>
@optional
/**
 广告曝光回调
 */
- (void)mvl_nativeAdViewExpose:(MVlionAdView *)nativeAdView;

/**
 广告点击回调
 */
- (void)mvl_nativeAdViewDidClick:(MVlionAdView *)nativeAdView extra:(NSMutableDictionary *)extra;

/**
 需要媒体处理的dp回调
 */
- (void)mvl_nativeAdView:(MVlionAdView *)nativeAdView jumpTargetMode:(MentaJumpTargetMode)mode link:(NSString *)link;

/**
 广告详情页关闭
 */
- (void)mvl_nativeAdViewDetailClosed:(MVlionAdView *)nativeAdView;

/**
 广告详情页弹出
 */
- (void)mvl_nativeAdViewDetailPresent:(MVlionAdView *)nativeAdView;

@end

@interface MVlionAdView : UIView
/// 代理
@property(nonatomic,weak)id<MVlionAdViewDelegate> delegate;

/// 当前控制器
@property(nonatomic,weak)UIViewController *currentViewController;
 
// 点击的view
- (void)registerAd:(MVlionBid *)bid
    clickableViews:(NSArray<UIView *> *)clickableViews;

// 可以响应滑动的view
- (void)registerAd:(MVlionBid *)bid swipeViews:(NSArray<UIView *> *)swipeViews distance:(CGFloat)distance direction:(MVlionSwipeDirection)direction;

// 开始摇一摇
- (void)shakeActionWithThreshold:(double)shakeThreshold twistThreshold:(double)twistThreshold priority:(NSInteger)priority slotType:(MVlionSlotType)slotType;

// 停止摇一摇
- (void)stopShakeDetection;
@end

NS_ASSUME_NONNULL_END
