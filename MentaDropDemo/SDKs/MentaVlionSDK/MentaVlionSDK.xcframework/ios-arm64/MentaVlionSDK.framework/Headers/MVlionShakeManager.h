//
//  MVlionShakeManager.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/25.
//

#import <Foundation/Foundation.h>
#import "MVlionShakeModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface MVlionShakeManager : NSObject

+ (instancetype)sharedManager;

- (void)startShakeDetectionWithConfiguration:(MVlionShakeModel *)config;
- (void)stopShakeDetectionForView:(UIView *)view;
- (void)stopShakeDetection;
- (void)setPriorityConfiguration:(MVlionShakeModel *)config;

@end

NS_ASSUME_NONNULL_END
