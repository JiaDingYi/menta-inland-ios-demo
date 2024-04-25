//
//  MVlionReport.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class MVlionBid;

NS_ASSUME_NONNULL_BEGIN

@interface MVlionReport : NSObject

+ (void)impTracking:(MVlionBid *)bid;

+ (void)clickTracking:(MVlionBid *)bid dxPoint:(CGPoint)dxPoint uxPoint:(CGPoint)uxPoint;

+ (void)trackEventWithResponse:(id)responseObject
                     urlString:(NSString *)urlString
                     startTime:(NSDate *)startTime
                    statusCode:(NSInteger)code
                        errMsg:(NSString *)errMsg
                       apiType:(NSString *)apiType;

// 激励视频开始播放
+ (void)rewardPlayStartTracking:(MVlionBid *)bid;
// 激励视频播放进度
+ (void)rewardPlayProcessTracking:(MVlionBid *)bid second:(NSInteger)second;
// 激励视频播放完成
+ (void)rewardPlayFinishedTracking:(MVlionBid *)bid;

@end

NS_ASSUME_NONNULL_END
