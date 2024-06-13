//
//  MentaVlionBaseMacro.h
//  MentaVlionBaseSDK
//
//  Created by jdy on 2024/4/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define kMentaReportUrlKey @"menta_report_url_key"
#define kMentaSdkCommonParameters @"menta_sdk_common_parameters"
#define kDeeplinkTimes @"mv_deeplinktimes"
#define kApplicationState @"mv_applicationState"

@interface MentaVlionBaseMacro : NSObject

extern NSString *const kNetRespUrlKey;
extern NSString *const kNetRespReqTimeKey;
extern NSString *const kNetRespBodySizeKey;
extern NSString *const kNetRespStatusKey;
extern NSString *const kNetRespLatencyKey;
extern NSString *const kNetRespErrMsgKey;
extern NSString *const kNetRespApiStatusKey;

@end

NS_ASSUME_NONNULL_END
