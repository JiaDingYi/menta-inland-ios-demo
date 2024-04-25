//
//  MentaNativeAdMediaViewProtocol.h
//  MentaUnifiedSDK
//
//  Created by jdy on 2024/4/22.
//

#import <Foundation/Foundation.h>
#import <MentaVlionBaseSDK/MVMediaView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MentaNativeAdMediaViewProtocol <NSObject>

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
