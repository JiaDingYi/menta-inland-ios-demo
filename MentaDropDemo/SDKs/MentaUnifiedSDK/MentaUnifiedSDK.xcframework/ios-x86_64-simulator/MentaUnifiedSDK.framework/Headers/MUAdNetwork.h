//
//  MUAdNetwork.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/22.
//

#import <Foundation/Foundation.h>
@class MUAdModel;
NS_ASSUME_NONNULL_BEGIN

@interface MUAdNetwork : NSObject

+ (void)loadAdWithParameters:(NSDictionary *)parameters completion:(void(^)(id jsonObj,NSError *error))completion;

+ (void)uploadCrashInfoWithParameters:(NSDictionary *)parameters completion:(void(^)(BOOL succee))completion;

//+ (void)get:(NSString *)url parameters:(NSDictionary *)parameters completion:(void (^)(NSDictionary *, NSError *))completion;


// 上报事件接口
+ (void)uploadTrackEvent:(NSString *)url parameters:(id)parameters completion:(void (^)(BOOL succee))completion;

@end

NS_ASSUME_NONNULL_END
