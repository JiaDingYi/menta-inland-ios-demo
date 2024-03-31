//
//  MVlionNativeExpressTemplateSelector.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBid, MVlionNativeExpressSlotConfig;
@interface MVlionNativeExpressTemplateSelector : NSObject
+ (NSString *)returnTemplateNameForBid:(MVlionBid *)bid config:(MVlionNativeExpressSlotConfig *)config;
@end

NS_ASSUME_NONNULL_END
