//
//  MVlionNativeExpressAdView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionNativeExpressAdView : UIView
/*
*  viewControllerForPresentingModalView
*  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
*/
@property (nonatomic, weak) UIViewController *controller;

/**
 *  广告是否有效，以下情况会返回NO，建议在调用render之前判断，当为NO时render失败
 *  a.广告过期
 */
@property (nonatomic, readonly) BOOL isAdValid;

@property (nonatomic, assign, readonly) NSInteger price;


- (void)render;
@end

NS_ASSUME_NONNULL_END
