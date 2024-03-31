//
//  MUSaveDataManager.h
//  Test
//
//  Created by iMacMe on 2023/12/6.
//

#import <Foundation/Foundation.h>
@class MUTrackModel, MUAdModel;
NS_ASSUME_NONNULL_BEGIN

@interface MUSaveDataManager : NSObject
// 数据库
+ (BOOL)setupDatabaseWithVersion:(NSString *)version;
+ (BOOL)migrateToVersion:(NSString *)version;
+ (BOOL)insertEventWithUUID:(NSString *)uuid eventData:(NSDictionary *)eventData;
+ (BOOL)deleteEventWithUUID:(NSString *)uuid;
+ (NSArray<NSDictionary *> *)getAllEvents;


// 数据模型
+ (void)saveModel:(MUAdModel *)model;
+ (MUAdModel *)loadModel;

@end

NS_ASSUME_NONNULL_END
