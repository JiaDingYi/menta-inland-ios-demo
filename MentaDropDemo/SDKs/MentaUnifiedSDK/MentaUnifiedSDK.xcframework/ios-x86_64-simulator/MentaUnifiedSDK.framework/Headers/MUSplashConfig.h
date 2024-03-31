//
//  MUSplashConfig.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN

@interface MUSplashConfig : NSObject
// 广告位id
@property (nonatomic, copy) NSString *slotId;
// 广告位尺寸 默认 屏幕宽高
// 注: adSize 不意味着广告返回的真正宽高

@property (nonatomic) CGSize adSize;
// 广告加载容器视图
@property (nonatomic, weak) UIViewController *viewController;
// 底部logo展示区域
@property (nonatomic, strong) UIView *bottomView;

/// 广告加载容忍时间 默认5s
/// 建议3f~5f。如果设定的时间内没有竞价到广告，则判断竞价失败
@property (nonatomic, assign) NSInteger tolerateTime;

/// 素材填充方式 默认 MentaSplashAdMaterialFillMode_ScaleAspectFill
@property(nonatomic, assign) MentaSplashAdMaterialFillMode materialFillMode;

@end

NS_ASSUME_NONNULL_END
