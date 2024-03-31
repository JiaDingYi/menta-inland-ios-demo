//
//  MVlionSaveDataManager.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kMVlionDatabaseEventKey;


@interface MVlionSaveDataManager : NSObject

// 数据库
+ (BOOL)setupDatabaseWithVersion:(NSString *)version;
+ (BOOL)migrateToVersion:(NSString *)version;
+ (BOOL)insertEventWithUUID:(NSString *)uuid eventData:(NSDictionary *)eventData;
+ (BOOL)deleteEventWithUUID:(NSString *)uuid;
+ (NSArray<NSDictionary *> *)getAllEvents;

@end

NS_ASSUME_NONNULL_END
