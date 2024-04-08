//
//  MVVideoPlayerView.h
//  MentaVlionBaseSDK
//
//  Created by jdy on 2024/3/20.
//

#import <UIKit/UIKit.h>
#import "MVMediaView.h"

NS_ASSUME_NONNULL_BEGIN

@class MVVideoPlayerView;
@protocol MVVideoPlayerViewDelegate <NSObject>
// 播放结束
- (void)mv_videoPlayerViewDidPlayFinished:(MVVideoPlayerView *)mediaView;
// 正在播放
- (void)mv_videoPlayerViewPlaying:(CGFloat)currentPlayTime;
// 播放失败
- (void)mv_videoPlayerViewFailedToPlay:(MVVideoPlayerView *)mediaView withError:(NSError *)error;
// 播放暂停
- (void)mv_videoPlayerViewPaused:(MVVideoPlayerView *)mediaView;
// 续播
- (void)mv_videoPlayerViewResume:(MVVideoPlayerView *)mediaView;

@end

@interface MVVideoPlayerView : UIView

@property (nonatomic, weak) id<MVVideoPlayerViewDelegate> delegate;

- (instancetype)initWithString:(NSString *)videoString;

- (instancetype)initWithURL:(NSURL *)videoUrl;

- (void)play;

- (void)pause;

- (void)stop;

// 视频广告时长，单位 ms
- (CGFloat)videoDuration;

// 视频广告已播放时长，单位 ms
- (CGFloat)videoPlayTime;

- (void)muteEnable:(BOOL)flag;

// 默认，AMVVideoFillModeAspectFit
- (void)setRenderMode:(MVVideoFillMode)fillMode;

@end

NS_ASSUME_NONNULL_END
