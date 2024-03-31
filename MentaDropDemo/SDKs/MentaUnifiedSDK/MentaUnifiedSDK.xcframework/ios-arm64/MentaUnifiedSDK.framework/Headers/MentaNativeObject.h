//
//  MentaNativeObject.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MentaNativeAdViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN
@class MentaNativeAdDataObject;
@interface MentaNativeObject : NSObject
/// 自渲染信息流广告素材
@property (nonatomic, strong) MentaNativeAdDataObject *dataObject;

/// 自渲染信息流展示容器
@property (nonatomic, strong) UIView<MentaNativeAdViewProtocol> *nativeAdView;

/// 初始化方法 开发者不必理会
- (instancetype)initWithNativeAdView:(UIView<MentaNativeAdViewProtocol> *)nativeAdView
                          dataObject:(MentaNativeAdDataObject *)dataObject;

/// 绑定可点击、可关闭的视图
- (void)registerClickableViews:(nullable NSArray<UIView *> *)clickableViews
                closeableViews:(nullable NSArray<UIView *> *)closeableViews;

- (void)destoryNativeAdView;

@end

NS_ASSUME_NONNULL_END
