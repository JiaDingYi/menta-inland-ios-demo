//
//  MVlionNativeExpressAdView+MVlion.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/18.
//

#import <MentaVlionSDK/MVlionSDK.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionNativeExpressSlotConfig, MVlionBid, MVlionNativeExpressAd;
@interface MVlionNativeExpressAdView (MVlion)

- (instancetype)initExpressAdViewWithConfig:(MVlionNativeExpressSlotConfig *)config bid:(MVlionBid *)bid nativeAd:(MVlionNativeExpressAd *)nativeAd;
@end

NS_ASSUME_NONNULL_END
