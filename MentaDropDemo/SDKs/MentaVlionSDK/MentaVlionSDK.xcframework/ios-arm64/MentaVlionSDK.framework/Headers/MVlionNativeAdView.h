//
//  MVlionNativeAdView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/4.
//

#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
#import <MentaVlionBaseSDK/MVMediaView.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionNativeAdView, MVlionNativeAdDataObject;
@protocol MVlionNativeAdViewDelegate <NSObject>

@optional


/**
 广告曝光回调,
 @param nativeAdView 可能多次触发
 */

- (void)mvlion_nativeAdViewWillVisible:(MVlionNativeAdView *)nativeAdView;

/**
 广告曝光回调(只触发一次)
 @param nativeAdView MVlionNativeAdView 实例,
 */
- (void)mvlion_nativeAdViewWillExpose:(MVlionNativeAdView *)nativeAdView;


/**
 广告点击回调,

 @param nativeAdView MVlionNativeAdView 实例,
 */
- (void)mvlion_nativeAdViewDidClick:(MVlionNativeAdView *)nativeAdView extra:(NSDictionary *)extra;

/**
 广告点击关闭回调 UI的移除和数据的解绑 需要在该回调中进行

 @param nativeAdView MVlionNativeAdView 实例,
 */
- (void)mvlion_nativeAdDidClose:(MVlionNativeAdView *)nativeAdView;


/**
 广告详情页面即将展示回调, 当广告位落地页广告时会触发

 @param nativeAdView MVlionNativeAdView 实例,
 */
- (void)mvlion_nativeAdDetailViewWillPresentScreen:(MVlionNativeAdView *)nativeAdView;


/**
 广告详情页关闭回调,即落地页关闭回调, 当关闭弹出的落地页时 触发

 @param nativeAdView MVlionNativeAdView 实例,
 */
- (void)mvlion_nativeAdDetailViewClosed:(MVlionNativeAdView *)nativeAdView;


// 插屏广告点击后的跳转模式
- (void)mvlion_nativeAd:(MVlionNativeAdView *)nativeAdView jumpTargetMode:(MentaJumpTargetMode)mode link:(NSString *)link;

// 信息流自渲染视频视频播放结束
- (void)mvlion_nativeAdDidPlayFinished:(MVlionNativeAdView *)nativeAdView;

@end

@interface MVlionNativeAdView : UIView
/**
 广告 View 事件回调对象
 */
@property (nonatomic, weak) id<MVlionNativeAdViewDelegate> delegate;

/**
 绑定的数据对象
 */
@property (nonatomic, strong, readonly) MVlionNativeAdDataObject *dataObject;

/**
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;

// 视频播放控件
@property (nonatomic, strong, readonly) MVMediaView *mentaMediaView;

// 视频宽
@property (nonatomic, assign, readonly) CGFloat videoWidth;

// 视频高
@property (nonatomic, assign, readonly) CGFloat videoHeight;

/**
 自渲染 视图注册方法
 
 @warning 需要注意的是 -[MVlionNativeAdView registerDataObject:clickableViews:closeableViews:]方法需要避免重复多次调用的情况
 @warning 当广告销毁的时候，需要调用 -[MVlionNativeAdView unregisterDataObject] 和 [MVlionNativeAdView destory] 方法
 @warning 当广告View 曝光后 或者已经绑定过数据后, 无法再进行绑定

 @param dataObject 数据对象，必传字段
 @param clickableViews 可触发点击回调的视图数组，此数组内的广告元素才可以响应广告对应的mvlion_nativeAdViewDidClick事件
 @param closeableViews 可触发关闭回调的视图数组，此数组内的广告元素才可以响应广告对应的mvlion_nativeAdDidClose事件
 */

- (void)registerDataObject:(MVlionNativeAdDataObject *_Nonnull)dataObject
            clickableViews:(NSArray<UIView *> *_Nonnull)clickableViews
            closeableViews:(NSArray<UIView *> *_Nonnull)closeableViews;


/**
 注销数据对象，解绑 clickableViews和closeableViews的手势 delegate置为nil等操作
 */
- (void)unregisterDataObject;

/**
 销毁 必须调用很重要
 注销数据对象 并将从父视图中移除
 */

- (void)destory;
@end

NS_ASSUME_NONNULL_END
