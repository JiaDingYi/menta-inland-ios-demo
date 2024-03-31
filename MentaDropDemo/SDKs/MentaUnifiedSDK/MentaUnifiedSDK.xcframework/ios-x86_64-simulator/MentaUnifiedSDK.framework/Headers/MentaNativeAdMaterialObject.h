//
//  MentaNativeAdMaterialObject.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/3/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaNativeAdMaterialObject : NSObject
/**
 素材宽度, 如果广告平台返回 则有值
 */
@property (nonatomic, assign) NSInteger materialWidth;

/**
 素材高度 如果广告平台返回 则有值
 */
@property (nonatomic, assign) NSInteger materialHeight;

/**
 素材url
 */
@property (nonatomic, copy) NSString *materialUrl;

@end

NS_ASSUME_NONNULL_END
