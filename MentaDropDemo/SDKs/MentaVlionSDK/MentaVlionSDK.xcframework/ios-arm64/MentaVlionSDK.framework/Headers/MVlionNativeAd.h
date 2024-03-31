//
//  MVlionNativeAd.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionNativeAdDataObject, MVlionNativeSlotConfig;
@protocol MVlionNativeAdDelegate <NSObject>

/**
 广告数据回调

 @param unifiedNativeAdDataObjects 广告数据数组
 @param error 错误信息
 */
- (void)mvlion_nativeAdLoaded:(NSArray<MVlionNativeAdDataObject *> * _Nullable)unifiedNativeAdDataObjects error:(NSError * _Nullable)error;
@end

@interface MVlionNativeAd : NSObject
/// 自渲染信息流广告代理
@property(nonatomic,weak)id <MVlionNativeAdDelegate> delegate;

/// 广告id 只读，开发者不允许修改
@property(nonatomic, copy, readonly) NSString *slotId;

/// 内部自用不必理会
@property (nonatomic, strong, readonly) NSMutableDictionary *extra;

/// 初始化方法
/// - Parameter config: 初始化配置
- (instancetype)initWithConfig:(MVlionNativeSlotConfig *)config;


/// 请求广告
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
