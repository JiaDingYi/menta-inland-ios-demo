//
//  MVlionRewardVideoTemplateAbstractFactory.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/22.
//

#import <UIKit/UIKit.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
@class MVLionVideoPlayer, MVlionBid, MVlionRewardSlotConfig;
@protocol MVlionRewardVideoTemplateAbstractFactory <NSObject>

@property(nonatomic, strong)MVLionVideoPlayer *player;

// 关闭
@property(nonatomic, copy)void(^dismissBlock)(MVlionBid *bid);

// 到达奖励时间
@property(nonatomic, copy)void(^effectiveBlock)(MVlionBid *bid);

// 播放完毕
@property(nonatomic, copy)void(^playFinishedBlock)(MVlionBid *bid);

// 跳过
@property(nonatomic, copy)void(^skipBlock)(MVlionBid *bid);

@property(nonatomic, copy)void(^playFailBlock)(MVlionBid *bid,NSError *error);

@property(nonatomic, weak) UIViewController *viewController;

@property(nonatomic, assign) MentaAdTemplateViewState pageState;

- (instancetype)initWithBid:(MVlionBid *)bid config:(MVlionRewardSlotConfig *)config;

@property(nonatomic, strong)UIView *topHotArea; // 上方热区
@property(nonatomic, strong)UIView *bottomHotArea;// 底部热区

@end

