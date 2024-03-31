//
//  MVlionSDKPramsManager.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//

#import <Foundation/Foundation.h>
@class MVlionUser, MULocation;
NS_ASSUME_NONNULL_BEGIN

extern NSString *const kMVlionDatabaseName;
extern NSString *const kMVlionTableName;
extern NSString *const kMVlionDatabaseVersionKey;


// 插屏模版参数
extern NSString *const kMAIN_PORTRAIT_BASE;
extern NSString *const kMAIN_PORTRAIT_LEFT_VIDEO_RIGHT_TEXT;

// 初始化相关的参数

@interface MVlionSDKPramsManager : NSObject
@property (nonatomic, copy, class) NSString *appId;
@property (nonatomic, assign, class) BOOL isInitialized;
@property (nonatomic, assign, class) BOOL isEnableLog;

@property (nonatomic, copy, class) NSString *ua;

@property (nonatomic, assign, class) BOOL isCanUseIDFA;
@property (nonatomic, copy, class) NSString *idfa;
@property (nonatomic, copy, class) NSString *polluxValue;
@property (nonatomic, copy, class) NSString *polluxVersion;

@property (nonatomic, assign, class) BOOL isCanUseLocation;
@property (nonatomic, assign, class) BOOL isAggregation;



@property (nonatomic, strong, class) MVlionUser *user;
@property (nonatomic, strong, class) MULocation *location;

@property (nonatomic, assign, class) BOOL isCanUseCarrier;
@property (nonatomic, copy, class) NSString *carrier;


@end

NS_ASSUME_NONNULL_END
