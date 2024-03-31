//
//  MVlionBannerTemplateAbstractFactory.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/3/13.
//

@class MVlionBid,MVlionBannerSlotConfig, MVlionAdIconView, MVlionBannerTemplateDownloadView, MVMediaView;

@protocol MVlionBannerTemplateAbstractFactory <NSObject>
@property(nonatomic, strong) MVlionBannerSlotConfig *config;   // 广告位配置信息
@property(nonatomic, strong) MVlionBid *bid;                          // 广告数据

@property(nonatomic, strong) UILabel *labDesc;               // 广告详情
@property(nonatomic, strong) UIImageView *imageMaterial;     // 物料展示区域
@property(nonatomic, strong) MVlionAdIconView *adLogoView;   // 广告logoView
@property(nonatomic, strong) MVlionBannerTemplateDownloadView *downloadArea; // 点击查看按钮的区域
@property(nonatomic, strong) UIImageView *btnClose;          // 广告关闭按钮
@property(nonatomic, strong) UIImageView *imgClose;          // 广告关闭图片

// 视频播放器
@property (nonatomic, strong, readonly) MVMediaView *mediaView;
@property (nonatomic, strong, readonly) UIImageView *muteIcon;

- (instancetype)initWithBid:(MVlionBid *)bid config:(MVlionBannerSlotConfig *)config;
@end
