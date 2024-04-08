//
//  MVlionInterstitialEndCardView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/16.
//

#import <UIKit/UIKit.h>
#import "MVlionInterstitialClickBtnView.h"
NS_ASSUME_NONNULL_BEGIN

@class MVlionBid, MVlionInterstitialConfig;
@interface MVlionInterstitialEndCardView : UIView
@property (nonatomic, strong) MVlionInterstitialClickBtnView *labDownload;

- (instancetype)initWithBid:(MVlionBid *)bid config:(MVlionInterstitialConfig *)config;
@end

NS_ASSUME_NONNULL_END
