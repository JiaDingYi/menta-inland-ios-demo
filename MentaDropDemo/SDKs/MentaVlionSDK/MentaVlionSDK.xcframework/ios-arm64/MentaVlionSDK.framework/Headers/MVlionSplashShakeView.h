//
//  MVlionSplashShakeView.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/25.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBid, MVlionSlotConfig, MVYYAnimatedImageView;
@interface MVlionSplashShakeView : UIView
@property (nonatomic, strong) MVYYAnimatedImageView *imgShake;
- (instancetype)initWithBid:(MVlionBid *)bid;
@end

NS_ASSUME_NONNULL_END
