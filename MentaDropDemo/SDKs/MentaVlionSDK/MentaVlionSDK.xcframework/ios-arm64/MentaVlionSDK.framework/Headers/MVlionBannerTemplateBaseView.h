//
//  MVlionBannerTemplateBaseView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/3/13.
//

#import <UIKit/UIKit.h>
#import "MVlionBannerTemplateAbstractFactory.h"
#import "MVlionBannerSlotConfig.h"
#import "MVYYAnimatedImageView.h"
#import "MVYYWebImage.h"

#import "MVlionBannerTemplateDownloadView.h"
#import "MVlionAdIconView.h"
#import "MVlionSlotConfig.h"
#import "MVlionAdModel.h"
#import "UIImage+MVlion.h"

NS_ASSUME_NONNULL_BEGIN

@interface MVlionBannerTemplateBaseView : UIView<MVlionBannerTemplateAbstractFactory>
@property (nonatomic, assign) CGFloat templateHeight; // 模版高度
@property (nonatomic, strong, readonly) MVMediaView *mediaView;

// 设置每个模版的属性 字号 字体等等 在每个模版里设置
- (void)setEspeciallyProperty;

- (void)initViews;

@end

NS_ASSUME_NONNULL_END
