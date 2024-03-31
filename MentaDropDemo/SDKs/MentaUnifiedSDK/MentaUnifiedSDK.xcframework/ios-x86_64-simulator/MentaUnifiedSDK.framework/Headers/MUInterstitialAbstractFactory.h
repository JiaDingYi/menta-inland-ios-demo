//
//  MUInterstitialAbstractFactory.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/17.
//

#ifndef MUInterstitialAbstractFactory_h
#define MUInterstitialAbstractFactory_h
#import <UIKit/UIKit.h>
#import <MentaUnifiedSDK/MUBaseAbstractFactory.h>
@class MUAdSource;

@protocol MUInterstitialAbstractFactory <MUBaseAbstractFactory>

@required


- (void)showAdFromViewController:(UIViewController *)viewController;

- (BOOL)isAdValid;
@end


#endif /* MUInterstitialAbstractFactory_h */
