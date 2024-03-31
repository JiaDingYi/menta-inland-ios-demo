//
//  MVlionNativeExpressTemplateAbstractFactory.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/18.
//

#import <UIKit/UIKit.h>
@class MVlionSlotConfig, MVlionBid, MVlionAdIconView, MVlionNativeExpressSlotConfig, MVlionNativeExpressTemplateDownloadView;
@protocol MVlionNativeExpressTemplateAbstractFactory <NSObject>
@property(nonatomic, strong) MVlionNativeExpressSlotConfig *config;   // 广告位配置信息
@property(nonatomic, strong) MVlionBid *bid;                          // 广告数据
@property(nonatomic, strong) UILabel *labDesc;               // 广告详情
@property(nonatomic, strong) UIImageView *imageMaterial;     // 物料展示区域
@property(nonatomic, strong) MVlionAdIconView *adLogoView;   // 广告logoView
@property(nonatomic, strong) MVlionNativeExpressTemplateDownloadView *downloadArea; // 点击查看按钮的区域
@property(nonatomic, strong) UIImageView *btnClose;          // 广告关闭按钮
@property(nonatomic, strong) UIImageView *imgClose;          // 广告关闭图片


- (instancetype)initWithBid:(MVlionBid *)bid config:(MVlionNativeExpressSlotConfig *)config;

- (BOOL)isValid;

- (NSString *)templateName;

- (CGFloat)getTemplateViewHeight;
@end
