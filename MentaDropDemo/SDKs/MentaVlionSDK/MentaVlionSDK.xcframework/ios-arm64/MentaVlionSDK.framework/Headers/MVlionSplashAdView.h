//
//  MVlionSplashAdView.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/17.
//

#import "MVlionAdView.h"
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBid, MVlionSplashSlotConfig;


@interface MVlionSplashAdView : MVlionAdView

@property (nonatomic, strong, readonly) MVlionBid *bid;

@property(nonatomic,copy)void(^dismissBlock)(MentaSplashAdCloseMode mode);

- (instancetype)initWithConfig:(MVlionSplashSlotConfig *)config bid:(MVlionBid *)bid;


@end

NS_ASSUME_NONNULL_END
