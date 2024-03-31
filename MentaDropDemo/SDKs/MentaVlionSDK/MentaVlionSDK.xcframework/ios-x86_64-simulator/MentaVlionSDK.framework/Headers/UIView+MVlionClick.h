//
//  UIView+MVlionClick.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/20.
//

#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
@class MVlionBid;
NS_ASSUME_NONNULL_BEGIN

@interface UIView (MVlionClick)

@property(nonatomic,copy)void(^mvlion_detailClosed)(void);
@property(nonatomic,copy)void(^mvlion_detailPresent)(void);

- (void)mvlion_jumpTargeWithBid:(MVlionBid *)bid viewController:(UIViewController *)viewController completion:(void(^)(BOOL result, MentaJumpTargetMode mode))completion;

@end

NS_ASSUME_NONNULL_END
