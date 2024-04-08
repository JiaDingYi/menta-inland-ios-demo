//
//  UIViewController+MVlion.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (MVlion)



+ (UIViewController *)mvlion_currentViewController;

+ (UINavigationController *)mvlion_currentNavigationController;

+ (UIViewController *)mvlion_rootViewController;



@end

NS_ASSUME_NONNULL_END
