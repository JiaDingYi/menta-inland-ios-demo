//
//  MVMediaView.h
//  MentaVlionBaseSDK
//
//  Created by jdy on 2024/3/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MVVideoFillMode) {
    // 保持比例，可能有黑边，默认值
    AMVVideoFillModeAspectFit = 1,
    // 保持比例，裁剪，无黑边
    MVVideoFillModeAspectFill,
    // 拉伸，填充满屏幕
    MVVideoFillModeResize,
};

@class MVMediaView;
@protocol MVMediaViewDelegate <NSObject>

@optional

// 播放完成回调
- (void)mv_mediaViewDidPlayFinished:(MVMediaView *)mediaView;

// 播放过程每秒回调一次
- (void)mv_mediaViewPlaying:(CGFloat)currentPlayTime;

// 播放失败
- (void)mv_mediaViewFailedToPlay:(MVMediaView *)mediaView withError:(NSError *)error;

// 播放暂停
- (void)mv_mediaViewPaused:(MVMediaView *)mediaView;

// 续播
- (void)mv_mediaViewResume:(MVMediaView *)mediaView;

@end

@interface MVMediaView : UIView

@property (nonatomic, weak) id <MVMediaViewDelegate> delegate;

/**
 * 视频广告时长，单位 ms
 */
- (CGFloat)videoDuration;

/**
 * 视频广告已播放时长，单位 ms
 */
- (CGFloat)videoPlayTime;

/**
 播放视频
 */
- (void)play;

/**
 暂停视频，调用 pause 后，需要被暂停的视频广告对象，不会再自动播放，需要调用 play 才能恢复播放。
 */
- (void)pause;

/**
 停止播放，并展示第一帧
 */
- (void)stop;

/**
 播放静音开关
 @param flag 是否静音
 */
- (void)muteEnable:(BOOL)flag;

// 默认，AMVVideoFillModeAspectFit
- (void)setRenderMode:(MVVideoFillMode)fillMode;

@end

NS_ASSUME_NONNULL_END
