//
//  MURewardVideoAbstractFactory.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/20.
//

#import <UIKit/UIKit.h>
#import <MentaUnifiedSDK/MUBaseAbstractFactory.h>

@class MUAdSource;

@protocol MURewardVideoAbstractFactory <MUBaseAbstractFactory>

@required


- (void)showAdFromRootViewController:(UIViewController *)viewController;

- (BOOL)isAdValid;
@end
