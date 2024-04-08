//
//  MVlionInterstitialTemplateAbstractFactory.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/28.
//
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
@class MVLionVideoPlayer, MVlionBid, MVlionInterstitialConfig;

@protocol MVlionInterstitialTemplateAbstractFactory <NSObject>

@property(nonatomic, strong)MVLionVideoPlayer *player;

// 关闭
@property(nonatomic, copy)void(^dismissBlock)(MVlionBid *bid, NSInteger mode);

// 到达奖励时间
@property(nonatomic, copy)void(^effectiveBlock)(MVlionBid *bid);

// 播放完毕
@property(nonatomic, copy)void(^playFinishedBlock)(MVlionBid *bid);

// 跳过
@property(nonatomic, copy)void(^skipBlock)(MVlionBid *bid);

@property(nonatomic, copy)void(^playFailBlock)(MVlionBid *bid,NSError *error);

@property(nonatomic, weak) UIViewController *viewController;

@property(nonatomic, assign) MentaAdTemplateViewState pageState;
/// 是否渲染成功  当渲染成功 为YES 失败 及渲染中为NO
@property(nonatomic,assign)BOOL isRender;


- (instancetype)initWithBid:(MVlionBid *)bid config:(MVlionInterstitialConfig *)config;
@end
