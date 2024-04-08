//
//  MVlionNativeExpressTemplateBaseView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/19.
//

#import <UIKit/UIKit.h>
#import "MVlionNativeExpressTemplateAbstractFactory.h"
NS_ASSUME_NONNULL_BEGIN

@interface MVlionNativeExpressTemplateBaseView : UIView<MVlionNativeExpressTemplateAbstractFactory>

@property (nonatomic, assign) CGFloat templateHeight; // 模版高度

// 计算模版高度
- (void)computedAltitude;

- (void)initViews;
@end

NS_ASSUME_NONNULL_END
