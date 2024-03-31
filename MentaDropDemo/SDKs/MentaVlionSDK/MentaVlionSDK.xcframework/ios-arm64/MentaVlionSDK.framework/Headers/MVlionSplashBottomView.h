//
//  MVlionSplashBottomView.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/29.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBid, MVlionSplashSlotConfig, MVYYAnimatedImageView;
@interface MVlionSplashBottomView : UIView
// 半圆热区
@property (nonatomic, strong) UIView *viewHotArea;

// 摇一摇 icon
@property (nonatomic, strong) MVYYAnimatedImageView *imgShake;



- (instancetype)initWithBid:(MVlionBid *)bid config:(MVlionSplashSlotConfig *)config;


@end

NS_ASSUME_NONNULL_END
