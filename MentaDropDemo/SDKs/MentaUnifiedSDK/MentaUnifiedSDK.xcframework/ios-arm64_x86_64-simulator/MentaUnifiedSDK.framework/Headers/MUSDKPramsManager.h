//
//  MUSDKPramsManager.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/22.
//

#import <Foundation/Foundation.h>
@class  MUUser, MULocation, MUSDKConfig;
NS_ASSUME_NONNULL_BEGIN

/// 平台name
extern NSString *const SDK_ID_PDD; // 拼多多
extern NSString *const SDK_ID_VLION; // 瑞狮
extern NSString *const SDK_ID_JD;    // 京东
extern NSString *const SDK_ID_SIGMOB;// sigmob
extern NSString *const SDK_ID_BAIDU; // 百度
extern NSString *const SDK_ID_TANX; //  Tanx
extern NSString *const SDK_ID_GDT;  //  广点通
extern NSString *const SDK_ID_CSJ;  //  穿山甲

/// 曝光广告的信息 相关的key
extern NSString *const BEST_SOURCE_PRICE;


extern NSString *const kMainUrl;
extern NSString *const kUploadErrorUrl;

extern NSString *const kDatabaseName;
extern NSString *const kTableName;
extern NSString *const kDatabaseVersionKey;
extern NSString *const kUniqueIdKey;
extern NSString *const kSaveConfigDataKey;

// 统计事件的key
extern NSString *const kActStartKey;
extern NSString *const kActFrontbackKey;
extern NSString *const kActReportKey;
extern NSString *const kActAdReqKey;
extern NSString *const kActAdFillKey;
extern NSString *const kActAdBidKey;
extern NSString *const kActAdRenderKey;
extern NSString *const kActAdTriggerKey;
extern NSString *const kActAdImpKey;
extern NSString *const kActAdClkKey;
extern NSString *const kActAdDpcheckKey;
extern NSString *const kActAdShowKey;
extern NSString *const kActAdSkipKey;
extern NSString *const kActAdEnterKey;
extern NSString *const kActAdCloseKey;
extern NSString *const kActNetRespKey;

extern NSString *const kNetRespUrlKey;
extern NSString *const kNetRespReqTimeKey;
extern NSString *const kNetRespBodySizeKey;
extern NSString *const kNetRespStatusKey;
extern NSString *const kNetRespLatencyKey;

extern NSString *const kSaveAdModelKey;


@interface MUSDKPramsManager : NSObject
@property (nonatomic, copy, class) NSString *appID;
@property (nonatomic, copy, class) NSString *appKey;


@property (nonatomic, assign, class) BOOL isInitialized;
@property (nonatomic, assign, class) BOOL isEnableLog;

@property (nonatomic, copy, class) NSString *ua;

@property (nonatomic, assign, class) BOOL isCanUseIDFA;
@property (nonatomic, copy, class) NSString *idfa;

@property (nonatomic, assign, class) BOOL isCanUseLocation;
@property (nonatomic, strong, class) MULocation *location;

@property (nonatomic, copy, class) NSString *polluxValue;
@property (nonatomic, copy, class) NSString *polluxVersion;

@property (nonatomic, copy, class) NSString *UniqueId;

@property (nonatomic, strong, class) MUUser *user;
@property (nonatomic, strong, class) MUSDKConfig *config;


@property (nonatomic, assign, class) BOOL isCanUseCarrier;
@property (nonatomic, copy, class) NSString *carrier;

@end

NS_ASSUME_NONNULL_END
