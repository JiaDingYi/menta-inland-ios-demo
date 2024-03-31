//
//  MUPolicyService.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/23.
//

#import <Foundation/Foundation.h>
#import "MentaUnifiedEnum.h"
#import "MentaUnifiedPriEnum.h"
#import "MUAdModel.h"
NS_ASSUME_NONNULL_BEGIN


@protocol MUPolicyServiceDelegate <NSObject>

@optional

/// 策略服务加载成功
- (void)muPolicyServiceLoadSuccessWithModel:(nonnull MUAdModel *)model;

/// 策略服务加载失败
- (void)muPolicyServiceLoadFailedWithError:(nullable NSError *)error;

/// 加载某一个渠道对象
/// @param source 被加载的渠道
- (void)muPolicyServiceLoadAnySource:(nullable MUAdSource *)source;

/// 开始Bidding
/// @param source 参加Bidding的渠道
- (void)muPolicyServiceStartBiddingWithSources:(NSArray <MUAdSource *> *_Nullable)source;

/// 结束Bidding
/// @param source 竞胜渠道
- (void)muPolicyServiceFinishBiddingWithWinSource:(MUAdSource *_Nonnull)source;

/// Bidding失败 (超时时间内，所有Bidding渠道返回广告都失败)
/// @param error 聚合SDK的策略错误信息
/// @param description 每个渠道的错误描述，部分情况下为nil
- (void)muPolicyServiceFailedBiddingWithError:(NSError *_Nullable)error description:(NSDictionary *_Nullable)description;


@end

@interface MUPolicyService : NSObject

@property (nonatomic, weak) id<MUPolicyServiceDelegate> delegate;

/// 各渠道的错误回调信息
@property (nonatomic, strong) NSMutableDictionary *errorInfo;

/// 数据管理对象
+ (instancetype)manager;

/// 实时加载策略数据
/// @param placementID   广告位id
/// @param tolerateTime 竞价容忍时长
/// @param type        广告位类型
- (void)loadDataWithPlacementID:(NSString *)placementID
                   tolerateTime:(NSInteger)tolerateTime
                       slotType:(MUSlotType)type;


/// 设置渠道返回的竞价
/// @param eCPM 竞价金额
/// @param source 当前渠道
- (void)setECPMIfNeeded:(NSInteger)eCPM source:(MUAdSource *)source;


/// 检测是否命中用于展示的渠道
/// 由每个渠道SDK Callback返回结果时调用 或者 超时后调用
/// - Parameters:
///   - source: loadAd后返回结果的某个渠道
///   - state: loadAd后返回结果状态
- (void)checkTargetWithResultfulSource:(MUAdSource *)source loadAdState:(MentaSourceLoadAdState)state;

/// 上报
- (void)reportEventWithType:(MUTrackingEventType)repoType source:(nullable MUAdSource *)source error:(nullable NSError *)error extra:(nullable NSMutableDictionary *)extra;

- (void)cancheTimer;
@end

NS_ASSUME_NONNULL_END
