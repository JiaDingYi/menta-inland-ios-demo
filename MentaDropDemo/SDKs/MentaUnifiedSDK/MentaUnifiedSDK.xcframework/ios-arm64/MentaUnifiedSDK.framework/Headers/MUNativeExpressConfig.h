//
//  MUNativeExpressConfig.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface MUNativeExpressConfig : NSObject
// 广告位id
@property (nonatomic, copy) NSString *slotId;

// 广告位尺寸 所有广告位必须要传 默认 (UIScreen.mainScreen.bounds.size.width - 20, 300)
// 注: adSize中的高度 不意味着广告返回的真正高度 计算规则:根据传入adSize中的width 会计算出整个广告模版View的高度
@property (nonatomic) CGSize adSize;

// 广告加载容器视图
@property (nonatomic, weak) UIViewController *viewController;

/// 广告加载容忍时间 默认5s
/// 建议3f~5f。如果设定的时间内没有竞价到广告，则判断竞价失败
@property (nonatomic, assign) NSInteger tolerateTime;

@property(nonatomic, assign) MentaNativeExpressAdMaterialFillMode materialFillMode;

@end

NS_ASSUME_NONNULL_END
