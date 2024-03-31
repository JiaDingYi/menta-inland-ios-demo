//
//  MUBannerConfig.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/3/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN

@interface MUBannerConfig : NSObject
// 广告位id
@property (nonatomic, copy) NSString *slotId;

// 广告位尺寸 所有广告位必须要传
// 注: adSize 就是 广告view 的Size
@property (nonatomic) CGSize adSize;

// 广告加载容器视图
@property (nonatomic, weak) UIViewController *viewController;

/// 广告加载容忍时间 默认5s
/// 建议3f~5f。如果设定的时间内没有竞价到广告，则判断竞价失败
@property (nonatomic, assign) NSInteger tolerateTime;

// 物料填充方式
@property (nonatomic, assign) MentaBannerAdMaterialFillMode materialFillMode;

//// banner的容器view
//@property (nonatomic, strong) UIView *containerView;

@end

NS_ASSUME_NONNULL_END
