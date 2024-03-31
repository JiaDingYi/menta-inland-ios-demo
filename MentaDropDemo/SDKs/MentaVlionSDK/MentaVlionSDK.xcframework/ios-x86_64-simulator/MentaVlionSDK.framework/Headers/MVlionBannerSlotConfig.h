//
//  MVlionBannerSlotConfig.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/3/12.
//

#import <MentaVlionSDK/MVlionSDK.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN

@interface MVlionBannerSlotConfig : MVlionSlotConfig
// 物料填充方式
@property (nonatomic, assign) MentaBannerAdMaterialFillMode materialFillMode;

//@property (nonatomic, assign) MentaBannerAdTemplaFillMode materialFillMode;
/// 当前控制器
@property(nonatomic,weak) UIViewController *viewController;
@end

NS_ASSUME_NONNULL_END
