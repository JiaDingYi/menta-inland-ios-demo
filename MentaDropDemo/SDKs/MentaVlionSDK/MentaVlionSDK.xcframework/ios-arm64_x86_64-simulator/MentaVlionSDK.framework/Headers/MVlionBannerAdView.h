//
//  MVlionBannerAdView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/3/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBannerSlotConfig, MVlionBid, MVlionBannerAd;
@interface MVlionBannerAdView : UIView



- (instancetype)initWithConfig:(MVlionBannerSlotConfig *)config bid:(MVlionBid *)bid bannerAd:(MVlionBannerAd *)bannerAd;
@end

NS_ASSUME_NONNULL_END
