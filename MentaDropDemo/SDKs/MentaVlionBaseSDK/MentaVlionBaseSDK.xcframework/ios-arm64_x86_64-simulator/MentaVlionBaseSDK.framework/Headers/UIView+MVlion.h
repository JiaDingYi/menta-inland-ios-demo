//
//  UIView+MVlion.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/17.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface UIView (MVlion_View_Tool)

- (UIWindow *)mvl_keyWindow;

- (UIViewController *)mvl_viewController;

- (BOOL)mvl_isDisplayedInScreen;

+ (UIViewController *)mvl_topViewController;

+ (BOOL)mvl_isIPhoneX;

+ (CGFloat)mvl_statusBarHeight;

+ (BOOL)mvl_isLandscape;

+ (UIInterfaceOrientation)mvl_statusBarOrientation;

+ (CGFloat)mvl_safeAreaBottomHeight;

- (void)addRoundedCornersWithRadius:(CGFloat)radius atCorners:(UIRectCorner)corners;

+ (UIScrollView *)mvl_findScrollViewInSuperviews:(UIView *)view;

- (BOOL)mvl_isDisplayedInScrollView:(UIScrollView *)scrollView;
@end

@interface UIView (MVlion)
@property (assign, nonatomic) CGFloat mvl_x;
@property (assign, nonatomic) CGFloat mvl_y;
@property (assign, nonatomic) CGFloat mvl_width;
@property (assign, nonatomic) CGFloat mvl_height;
@property (assign, nonatomic) CGSize mvl_size;
@property (assign, nonatomic) CGPoint mvl_origin;
@property (assign, nonatomic) CGFloat mvl_right;
@property (assign, nonatomic) CGFloat mvl_bottom;

@end

NS_ASSUME_NONNULL_END
