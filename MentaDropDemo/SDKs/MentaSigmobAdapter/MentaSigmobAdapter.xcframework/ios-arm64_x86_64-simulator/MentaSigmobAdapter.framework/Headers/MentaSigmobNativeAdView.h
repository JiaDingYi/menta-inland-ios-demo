//
//  MentaSigmobNativeAdView.h
//  MentaSigmobAdapter
//
//  Created by jdy on 2024/4/22.
//

#import <WindSDK/WindSDK.h>
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>
#import "MentaSigmobMediaView.h"

NS_ASSUME_NONNULL_BEGIN

@interface MentaSigmobNativeAdView : WindNativeAdView <MentaNativeAdViewProtocol>

@property (nonatomic, strong, readonly) MentaSigmobMediaView *mentaMediaView;

- (instancetype)initWithDataObject:(WindNativeAd *)dataObject
                          delegate:(id<MentaUnifiedNativeAdDelegate>)delegate
                            adSpot:(MentaUnifiedNativeAd *)adSpot
                            source:(MUAdSource *)source;

- (void)registerClickableViews:(nullable NSArray<UIView *> *)clickableViews
                closeableViews:(nullable NSArray<UIView *> *)closeableViews;

@end

NS_ASSUME_NONNULL_END
