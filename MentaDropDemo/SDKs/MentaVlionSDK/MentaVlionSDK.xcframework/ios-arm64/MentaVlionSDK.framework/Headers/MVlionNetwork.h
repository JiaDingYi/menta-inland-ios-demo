//
//  MVlionNetwork.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/16.
//

#import <Foundation/Foundation.h>
@class MVlionAdModel;
NS_ASSUME_NONNULL_BEGIN

@interface MVlionNetwork : NSObject

+ (void)loadAdWithParameters:(NSDictionary *)parameters completion:(void(^)(MVlionAdModel *model,NSError *error))completion;

+ (void)get:(NSString *)url parameters:(NSDictionary *)parameters completion:(void(^)(NSDictionary *response,NSError *error))completion;

//+ (void)preloadAdMaterialFromCacheWithParameters:(NSDictionary *)parameters completion:(void (^)(MPPCacheBid *model, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
