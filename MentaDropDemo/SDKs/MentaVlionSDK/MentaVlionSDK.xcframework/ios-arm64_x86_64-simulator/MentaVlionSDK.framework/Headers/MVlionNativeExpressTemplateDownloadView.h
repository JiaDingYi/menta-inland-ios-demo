//
//  MVlionNativeExpressTemplateDownloadView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionNativeExpressSlotConfig, MVlionBid;
@interface MVlionNativeExpressTemplateDownloadView : UIView

@property (nonatomic, copy) NSString *templateName; // 不同的名字布局会不同

@property (nonatomic, strong, readonly) UILabel *labDownload; // 查看按钮

- (instancetype)initWithBid:(MVlionBid *)bid config:(MVlionNativeExpressSlotConfig *)config;

@end

NS_ASSUME_NONNULL_END
