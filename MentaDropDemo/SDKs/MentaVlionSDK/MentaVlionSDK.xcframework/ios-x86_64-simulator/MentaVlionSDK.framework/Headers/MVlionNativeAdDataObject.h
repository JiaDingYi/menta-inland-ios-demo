//
//  MVlionNativeAdDataObject.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionNativeAdMaterialItemData : NSObject
/**
 素材宽度
 */
@property (nonatomic, readonly) NSInteger materialWidth;

/**
 素材高度
 */
@property (nonatomic, readonly) NSInteger materialHeight;

/**
 素材url
 */
@property (nonatomic, copy, readonly) NSString *materialUrl;

@end

@interface MVlionNativeAdDataObject : NSObject
/**
 广告标题
 */
@property (nonatomic, copy, readonly) NSString *title;

/**
 广告描述
 */
@property (nonatomic, copy, readonly) NSString *desc;


/**
 广告主App 图标Url
 */
@property (nonatomic, copy, readonly) NSString *iconUrl;

/**
 素材集合
 */
@property (nonatomic, copy, readonly) NSArray<MVlionNativeAdMaterialItemData *> *materialList;

/**
 广告价格 单位 分
 */
@property (nonatomic, assign, readonly) NSInteger price;

/**
 广告icon "icon + 广告 + 黑色背景 + 透明度0.3"
 如果您不满意该效果 可以从 文档中自行下载 广告icon 然后自定义布局
 */
@property (nonatomic, strong, readonly) UIImage *mvlionIcon;

// 是否视频素材
@property (nonatomic, assign, readonly) BOOL isVideo;

@end

NS_ASSUME_NONNULL_END
