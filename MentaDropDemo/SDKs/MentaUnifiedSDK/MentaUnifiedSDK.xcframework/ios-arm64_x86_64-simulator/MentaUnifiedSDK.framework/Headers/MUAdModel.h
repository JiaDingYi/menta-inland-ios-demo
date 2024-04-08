//
//  MUAdModel.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/22.
//

#import <Foundation/Foundation.h>

@class MUAdModel;
@class MUAdData;
@class MUAdAd;
@class MUAdPlacement;
@class MUAdSource;
@class MUAdConfig;
@class MUAdAdmin;
@class MUAdEvents;
@class MUPlacementConfig;

@class MUAdTemplateConfig;


typedef NS_ENUM(NSUInteger, MentaSourceLoadAdState) {
    /// 准备就绪
    MentaSourceLoadAdReady = 0,
    /// 渠道请求广告素材成功
    MentaSourceLoadAdSuccess,
    /// 渠道请求广告素材失败
    MentaSourceLoadAdFailed,
    /// 渠道请求广告素材超时
    MentaSourceLoadAdTimeout,
};

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Object interfaces
@interface MUAdModel : NSObject<NSCopying,NSSecureCoding>
@property (nonatomic, copy)   NSString *message;
@property (nonatomic, strong) MUAdData *data;
@property (nonatomic, assign) NSInteger code;
@end

@interface MUAdData : NSObject<NSCopying, NSSecureCoding>
@property (nonatomic, copy)   NSString *report;
@property (nonatomic, copy)   NSString *reportv2;
@property (nonatomic, copy)   NSString *current;
@property (nonatomic, copy)   NSString *trace;
@property (nonatomic, strong) MUAdAd *ad;
@property (nonatomic, strong) MUAdEvents *events;
@property (nonatomic, strong) MUAdAdmin *admin;
@property (nonatomic, strong) NSDictionary *eventsDict;

//templates 按照字典的格式去解析
@property (nonatomic, strong)   NSArray<NSDictionary *> *templates;


@end

@interface MUAdAd : NSObject<NSCopying, NSSecureCoding>
@property (nonatomic, strong) NSArray<MUAdPlacement *> *placement;
@end

@interface MUAdPlacement : NSObject<NSCopying, NSSecureCoding>
@property (nonatomic, assign) BOOL isBiding;
@property (nonatomic, copy)   NSString *style;
@property (nonatomic, assign) NSInteger twistRange;
@property (nonatomic, assign) NSInteger screenType;
@property (nonatomic, copy)   NSString *showId;
@property (nonatomic, copy)   NSString *creativeType;
@property (nonatomic, strong)   NSMutableArray<MUAdSource *> *sources;
@property (nonatomic, copy)   NSString *interactiveType;
@property (nonatomic, assign) NSInteger price;
@property (nonatomic, assign) NSInteger adType;
@property (nonatomic, assign) NSInteger videoVoice;
@property (nonatomic, copy)   NSString *randerType;
@property (nonatomic, copy)   NSString *templateType;
@property (nonatomic, assign) NSInteger autoPlay;
@property (nonatomic, assign) NSInteger shakeRange;
@property (nonatomic, assign) NSInteger swipeRange;
@property (nonatomic, strong) NSArray<MUAdTemplateConfig *> *templateConfig;
@property (nonatomic, strong) NSArray<NSDictionary *> *templateConfigDicts;// 模版dict类型 仅仅信息流模版渲染时使用
@end

@interface MUAdSource : NSObject<NSCopying, NSSecureCoding>
@property (nonatomic, copy)   NSString *platformName;
@property (nonatomic, copy)   NSString *identifier;
@property (nonatomic, copy)   NSString *platformAccount;
@property (nonatomic, strong) MUAdConfig *config;
@property (nonatomic, assign) NSInteger bidfloor;
@property (nonatomic, assign) double shareRatio;
@property (nonatomic, copy)   NSString *sourceID;

@property (nonatomic, assign) MentaSourceLoadAdState loadAdState; // 广告加载状态
@property (nonatomic, assign) BOOL hited; // 是否已经命中过
/// 用于存储对应的Adapter，key必须唯一，会有同渠道配置多个的情况
// bidding时 最后填充的价格
@property (nonatomic, assign) double sdk_price; /// 这个广告源最后的 价格, 如果是bid广告位 则取SDK返回的价格, 如果是瀑布流广告位则取底价 最后再乘以shareRatio
@property (nonatomic, assign) double sdk_s_price; /// 这个广告源最后的 价格, 如果是bid广告位 则取SDK返回的价格, 如果是瀑布流广告位则取底价 打点使用
@property (nonatomic, assign) NSInteger result;  /// 用来标记事件是否成功 详见文档Menta打点汇总
@property (nonatomic, strong) NSError *error;  /// 错误

@property (nonatomic, assign) NSInteger sendWinnerPrice; /// 瑞狮聚合广告位竞价失败时 开发者需手动调用上报价格的方法  此时用这个字段承接外部传入的价格 单位: 分
@property (nonatomic, copy)   NSString *ad_trace;// 统计生成, 每次load广告的时候都要生成新的

//MUAdPlacement 中广告位的配置
@property (nonatomic, strong) MUPlacementConfig *placementConfig;

@property (nonatomic, strong) MUAdEvents *events;

@end

@interface MUAdConfig : NSObject<NSCopying, NSSecureCoding>
@property (nonatomic, copy)           NSString *appId;
@property (nonatomic, copy)           NSString *tagId;
@property (nonatomic, assign)         BOOL isBid;
@property (nonatomic, copy)           NSString *type;
@property (nonatomic, copy)           NSString *appKey;
//@property (nonatomic, copy) NSString *uniqueid;

@end

@interface MUAdTemplateConfig : NSObject<NSCopying, NSSecureCoding>
@property (nonatomic, copy)   NSString *identifier;
@property (nonatomic, assign) NSInteger weight;
@end


@interface MUAdAdmin : NSObject<NSCopying, NSSecureCoding>
@property (nonatomic, assign) NSInteger collectInstalledPackage;
@property (nonatomic, assign) NSInteger deeplinkTimes;
@property (nonatomic, assign) NSInteger sampleRadio;
@property (nonatomic, assign) NSInteger backgroundTickTime;
@property (nonatomic, strong)   NSArray<NSString *> *checkInstalledPackageList;
@property (nonatomic, assign) NSInteger refreshConfigTime;
@end

@interface MUAdEvents : NSObject<NSCopying, NSSecureCoding>
@property (nonatomic, copy) NSString *ad_clk;
@property (nonatomic, copy) NSString *ad_show;
@property (nonatomic, copy) NSString *ad_enter;
@property (nonatomic, copy) NSString *report;
@property (nonatomic, copy) NSString *ad_fill;
@property (nonatomic, copy) NSString *ad_render;
@property (nonatomic, copy) NSString *ad_imp;
@property (nonatomic, copy) NSString *ad_skip;
@property (nonatomic, copy) NSString *ad_trigger;
@property (nonatomic, copy) NSString *ad_dpcheck;
@property (nonatomic, copy) NSString *ad_bid;
@property (nonatomic, copy) NSString *start;
@property (nonatomic, copy) NSString *ad_req;
@property (nonatomic, copy) NSString *ad_close;
@property (nonatomic, copy) NSString *net_resp;
@property (nonatomic, copy) NSString *frontback;

@end


NS_ASSUME_NONNULL_END






//@interface MUAdSource : NSObject
//@property (nonatomic, assign) NSInteger shakeRange;
//@property (nonatomic, copy)   NSString *style;
//@property (nonatomic, assign) BOOL isBiding;
//@property (nonatomic, copy)   NSString *req;
//@property (nonatomic, assign) NSInteger screenType;
//@property (nonatomic, copy)   NSString *fill;
//@property (nonatomic, copy)   NSString *platformAccount;
//@property (nonatomic, assign) NSInteger price; // 服务器返回的价格
//@property (nonatomic, strong) MUAdConfig *config;
//@property (nonatomic, assign) NSInteger bidfloor;
//@property (nonatomic, copy)   NSString *clk;
//@property (nonatomic, copy)   NSString *platformName;
//@property (nonatomic, copy)   NSString *imp;
//
//
///// 以下为自定义字段
//@property (nonatomic, assign) MentaSourceLoadAdState loadAdState; // 广告加载状态
//@property (nonatomic, assign) BOOL hited; // 是否已经命中过
///// 用于存储对应的Adapter，key必须唯一，会有同渠道配置多个的情况
//@property (nonatomic, copy) NSString *supplierKey;
//// bidding时 最后填充的价格
//@property (nonatomic, assign) NSInteger sdk_price; /// 单位: 分
//
//@end
