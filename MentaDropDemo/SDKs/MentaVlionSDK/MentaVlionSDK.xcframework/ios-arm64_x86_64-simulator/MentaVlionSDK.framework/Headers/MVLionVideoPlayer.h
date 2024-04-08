//
//  MVLionVideoPlayer.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/12.
//

#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionBaseSDK.h>
@class MVLionVideoPlayer, MVlionBid, MVlionAdVideo;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    MVlionPlayerStatusUnknown = 0,    // 未知状态 初始状态
    MVlionPlayerStatusFailed = 1,     // 播放失败
    MVlionPlayerStatusEnd = 2,        // 播放结束
} MVlionPlayerStatus;

@protocol MVLionVideoPlayerDelegate <NSObject>
@optional

- (void)player:(MVLionVideoPlayer *)player status:(MVlionPlayerStatus)status error:(NSError *)error video:(MVlionAdVideo *)video;

- (void)player:(MVLionVideoPlayer *)player currentTime:(NSInteger)currentTime video:(MVlionAdVideo *)video;

@end

@interface MVLionVideoPlayer : UIView


/// 代理对象
@property(nonatomic,weak) id<MVLionVideoPlayerDelegate> delegate;

///
@property(nonatomic,assign) MentaRewardVideoAdViewGravity gravity;

/// 是否静音 默认不静音
@property(nonatomic,assign)BOOL mute;

/// 激励视频时展现是否view
@property(nonatomic,assign)BOOL isShowDetentionView;

@property(nonatomic,strong) UIColor *layerBackgroundColor;

- (void)pause;

- (void)play;

- (void)registerBid:(MVlionBid *)bid;

@end

NS_ASSUME_NONNULL_END
