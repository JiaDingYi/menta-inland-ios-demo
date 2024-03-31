//
//  MVlionVideoViewController.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionVideoViewController : UIViewController

@property(nonatomic,assign)UIInterfaceOrientation  defaultOrientation;

- (instancetype)initWithAdView:(UIView *)adView;

@end

NS_ASSUME_NONNULL_END
