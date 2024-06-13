//
//  MVlionDevice.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionDevice : NSObject
+ (NSString *)getIDFA;

+ (NSString *)getUUID;

+ (NSString *)getIDFV;

+ (NSString *)getIPAddress;

+ (BOOL)getIsIphone;

+ (NSString *)getDeviceModelName;

+ (NSString *)getDeviceModel;

+ (NSString *)getOsv;

+ (NSNumber *)getScreenHeight;

+ (NSNumber *)getScreenWidth;

+ (NSInteger)getNetconnType;

+ (NSString *)getCarrier;

+ (NSString *)getBootTime;

+ (NSString *)getUpdateTime;

+ (NSString *)md5:(NSString *)str;

+ (NSString *)getLanguage;

+ (NSString *)getTimeZoneName;

+ (NSString *)getSystemInitTime;

+ (NSString *)getBootTimeInSec;

// 获取系统硬盘容量
+ (NSString *)getDiskCapacityAsString;
// 获取系统内存
+ (NSString *)getTotalPhysicalMemoryAsString;
// 获取设备名称
+ (NSString *)getDeviceName;
// 以下方法由pdd提供
// 设备初始化时间
+ (NSString *)getFileTime;
// 系统更新时间
+ (NSString *)getSysU;
// 系统启动时间
+ (NSString *)bootTimeInSec;

@end

NS_ASSUME_NONNULL_END
