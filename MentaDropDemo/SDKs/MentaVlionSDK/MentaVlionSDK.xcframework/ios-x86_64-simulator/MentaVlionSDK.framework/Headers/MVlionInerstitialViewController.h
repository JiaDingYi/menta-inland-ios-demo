//
//  MVlionInerstitialViewController.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionInerstitialViewController : UIViewController
@property(nonatomic,assign)UIInterfaceOrientation  defaultOrientation;

- (instancetype)initWithAdView:(UIView *)adView;

@end

NS_ASSUME_NONNULL_END
