//
//  MentaNativeAdViewProtocol.h
//  MentaUnifiedSDK
//
//  Created by jdy on 2024/3/22.
//

#import <Foundation/Foundation.h>
#import <MentaVlionbaseSDK/MVMediaView.h>
#import "MentaNativeAdMediaViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MentaNativeAdViewProtocol <NSObject>

// 视频播放控件
@property (nonatomic, strong, readonly) UIView<MentaNativeAdMediaViewProtocol> *mentaMediaView;

// 视频宽
@property (nonatomic, assign, readonly) CGFloat videoWidth;

// 视频高
@property (nonatomic, assign, readonly) CGFloat videoHeight;

@optional

// only for sigmob
- (void)bindImageView:(UIImageView *)imageView;

@property (nonatomic, strong, readonly) UIView *logoView;

@property (nonatomic, strong, readonly) UIButton *dislikeButton;

@end

NS_ASSUME_NONNULL_END
