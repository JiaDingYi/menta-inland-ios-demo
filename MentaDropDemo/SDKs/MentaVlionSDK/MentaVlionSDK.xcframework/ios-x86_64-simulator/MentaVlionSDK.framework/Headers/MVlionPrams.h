//
//  MVlionPrams.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/15.
//

#import <Foundation/Foundation.h>
#import "MVlionEnum.h"

NS_ASSUME_NONNULL_BEGIN
@class MVlionSlotConfig;
@interface MVlionPrams : NSObject
+ (NSDictionary *)requestParameterWithConfig:(MVlionSlotConfig *)config  slotType:(MVlionSlotType)slotType;

@end

NS_ASSUME_NONNULL_END
