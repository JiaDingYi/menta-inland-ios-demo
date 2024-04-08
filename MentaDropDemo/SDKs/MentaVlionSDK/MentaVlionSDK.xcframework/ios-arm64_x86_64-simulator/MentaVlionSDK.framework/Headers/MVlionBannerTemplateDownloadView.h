//
//  MVlionBannerTemplateDownloadView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/3/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBannerSlotConfig, MVlionBid;
@interface MVlionBannerTemplateDownloadView : UIView

@property (nonatomic, strong, readonly) UILabel *labDownload; // 查看按钮
@property (nonatomic, copy) NSString *templateName; // 模版名称

- (instancetype)initWithBid:(MVlionBid *)bid config:(MVlionBannerSlotConfig *)config;

@end

NS_ASSUME_NONNULL_END
