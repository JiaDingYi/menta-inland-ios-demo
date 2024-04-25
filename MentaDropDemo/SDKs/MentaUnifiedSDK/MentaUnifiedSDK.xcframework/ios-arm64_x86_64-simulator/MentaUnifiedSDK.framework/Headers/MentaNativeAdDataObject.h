//
//  MentaNativeAdDataObject.h
//  MentaMVlionAdapter
//
//  Created by iMacMe on 2024/1/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class MentaNativeAdMaterialObject;
typedef NS_ENUM(NSUInteger, MentaNativeAdPlatform) {
    MentaNativeAdPlatform_Unknown, // 未知
    MentaNativeAdPlatform_MVlion,  // 瑞狮
    MentaNativeAdPlatform_GDT,     // 广点通
    MentaNativeAdPlatform_CSJ,     // 穿山甲
    MentaNativeAdPlatform_JD,      // 京东
    MentaNativeAdPlatform_SigMob,  // Sigmob

};

NS_ASSUME_NONNULL_BEGIN
@interface MentaNativeAdDataObject : NSObject
// 广告标题
@property (nonatomic, copy) NSString *title;

// 广告描述
@property (nonatomic, copy) NSString *desc;

// 广告图标Url
@property (nonatomic, copy) NSString *iconUrl;

// 广告物料集合（单图、多图, 视频） // 目前只有图片 暂不考虑视频
@property (nonatomic, strong) NSArray <MentaNativeAdMaterialObject *>* materialList;

/**
 广告价格 单位 分 如果广告平台返回则有值  否则为 -1
 */
@property (nonatomic, strong) NSNumber *price;

/**
 各个广告平台的adIcon 瑞狮 广点通 穿山甲 京东 等等
 如果这些广告平台返回adIcon 则有值 否则则没有
 特别的当platform = MentaNativeAdPlatform_MVlion时 如果对Menta广告平台的广告不满意 可以从 文档中自行下载 瑞狮icon 然后自定义布局
 */
@property (nonatomic, strong) UIImage *adIcon;

// 平台名称
@property (nonatomic, assign) MentaNativeAdPlatform platform;

@property (nonatomic, assign) BOOL isVideo;

@end

NS_ASSUME_NONNULL_END
