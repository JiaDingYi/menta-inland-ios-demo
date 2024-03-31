//
//  MVlionShakeModel.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MentaVlionSDK/MVlionEnum.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, ShakeSensitivity) {
    ShakeSensitivityNone = 0,
    ShakeSensitivityThreeDimensional = 1 << 0,
    ShakeSensitivityTwoDimensional = 1 << 1
};

@interface MVlionShakeModel : NSObject
@property (nonatomic, weak) UIView *view;
@property (nonatomic, assign) double shakeThreshold;
@property (nonatomic, assign) double twistThreshold;
@property (nonatomic, assign) ShakeSensitivity sensitivity;
@property (nonatomic, copy) void (^shakeHandler)(void);
@property (nonatomic, assign) NSInteger priority; // 响应优先级属性
@property (nonatomic, assign) MVlionSlotType slotType;

@end

NS_ASSUME_NONNULL_END
