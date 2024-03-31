//
//  MentaMJDNativeAdView.h
//  MentaJDYunAdapter
//
//  Created by iMacMe on 2024/3/8.
//

#import <UIKit/UIKit.h>

#if __has_include(<MentaUnifiedSDK/MentaUnifiedSDK.h>)

#import <MentaUnifiedSDK/MentaUnifiedNativeAdDelegate.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeAd.h>



#else

#import "MentaUnifiedNativeAdDelegate.h"
#import "MentaUnifiedNativeAd.h"

#endif

#if __has_include(<JADYunCore/JADYunUmbrella.h>)
#import <JADYunCore/JADYunUmbrella.h>
#else
#import <JADYun/JADYunUmbrella.h>
#endif

#if __has_include(<JADYun/JADNativeAd.h>)
#import <JADYun/JADNativeAd.h>
#else
#import "JADNativeAd.h"
#endif

#import <MentaVlionBaseSDK/MVMediaView.h>
#import <MentaUnifiedSDK/MentaNativeAdViewProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MentaJDVideoPlayerDelegate <NSObject>

/// 视频暂停时上报此事件，duration为视频暂停时视频已播放的时长
- (void)mentaJD_didPauseVideoWithCurrentDuration:(NSTimeInterval)duraiton;

/// 视频播放完成时上报此事件，duration为视频播放完成时视频已播放的时长
- (void)mentaJD_didFinishVideoWithCurrentDuration:(NSTimeInterval)duration;

/// 视频复播时上报此事件，duration为视频复播时视频已播放的时长
- (void)mentaJD_didResumeVideoWithCurrentDuration:(NSTimeInterval)duraiton;

/// 视频播放异常时上报此事件，duration为出现异常时视频已播放的时长
- (void)mentaJD_didFailVideoWithCurrentDuration:(NSTimeInterval)duration error:(NSError *__nullable)error;

@end

@class MUAdSource;
@interface MentaMJDNativeAdView : UIView <MentaNativeAdViewProtocol>

@property (nonatomic, weak) id<MentaJDVideoPlayerDelegate> delegate;

- (instancetype)initWithDataObject:(JADNativeAd *)dataObject
                          delegate:(id<MentaUnifiedNativeAdDelegate>)delegate
                            adSpot:(MentaUnifiedNativeAd *)adSpot
                            source:(MUAdSource *)source;

- (void)registerClickableViews:(nullable NSArray<UIView *> *)clickableViews
                closeableViews:(nullable NSArray<UIView *> *)closeableViews;

@property (nonatomic, strong, readonly) UIView *logoImageView;

@property (nonatomic, assign, readonly) CGSize logoSize;

// 视频播放控件
@property (nonatomic, strong, readonly) MVMediaView *mediaView;

// 视频宽
@property (nonatomic, assign, readonly) CGFloat videoWidth;

// 视频高
@property (nonatomic, assign, readonly) CGFloat videoHeight;

- (void)destoryNativeAdView;

@end

NS_ASSUME_NONNULL_END
