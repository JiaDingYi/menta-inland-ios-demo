//
//  MentaNativeAdViewProtocol.h
//  MentaUnifiedSDK
//
//  Created by jdy on 2024/3/22.
//

#import <Foundation/Foundation.h>
#import <MentaVlionbaseSDK/MVMediaView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MentaNativeAdViewProtocol <NSObject>

// 视频播放控件
@property (nonatomic, strong, readonly) MVMediaView *mediaView;

// 视频宽
@property (nonatomic, assign, readonly) CGFloat videoWidth;

// 视频高
@property (nonatomic, assign, readonly) CGFloat videoHeight;

@end

NS_ASSUME_NONNULL_END
