//
//  MVlionGCDTimer.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/17.
//

#import <Foundation/Foundation.h>
static  NSString * const _Nonnull MVLGCDTimerException = @"MVLGCDTimerException";
static  NSString * const _Nonnull MVLGCDTimerNameKey = @"MVLGCDTimerNameKey";

static const uint64_t MVL_TIMER_LEEWAY_NONE        = 0;
static const uint64_t MVL_TIMER_LEEWAY_LOW         = 1000 * 1000;
static const uint64_t MVL_TIMER_LEEWAY_MEDIUM      = 100 * 1000 * 1000;
static const uint64_t MVL_TIMER_LEEWAY_HIGH        = 1000 * 1000 * 1000;
static const uint64_t MVL_TIMER_LEEWAY_VERY_HIGH   = 30ULL * 1000 * 1000 * 1000;


NS_ASSUME_NONNULL_BEGIN

@interface MVlionGCDTimer : NSObject

- (instancetype)initWithDispatchQueue:(dispatch_queue_t)queue leeway:(uint64_t)leeway name:(NSString *)name;

+ (instancetype)timerOnQueue:(dispatch_queue_t)queue withLeeway:(uint64_t)leeway name:(NSString *)name;
+ (instancetype)timerOnQueue:(dispatch_queue_t)queue withName:(NSString *)name;
+ (instancetype)timerOnQueue:(dispatch_queue_t)queue;

/// 创建一个在主队列执行的timer
+ (instancetype)timerWithLeeway:(uint64_t)leeway name:(NSString *)name;
+ (instancetype)timerWithName:(NSString *)name;
+ (instancetype)timer;

/// 定时器无效
- (void)invalidate;


/// 定时器执行任务
/// @param block 任务block
/// @param interval 时间间隔 单位秒
- (void)scheduleBlock:(void (^)(void))block interval:(NSTimeInterval)interval;

/// 定时器执行任务
/// @param block 任务block
/// @param interval 时间间隔 单位秒
/// @param repeat 是否重复
- (void)scheduleBlock:(void (^)(void))block interval:(NSTimeInterval)interval repeat:(BOOL)repeat;


@end

NS_ASSUME_NONNULL_END
