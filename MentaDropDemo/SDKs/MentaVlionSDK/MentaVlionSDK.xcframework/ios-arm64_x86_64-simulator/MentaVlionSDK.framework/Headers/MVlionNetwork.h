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

+ (void)get:(NSString *)url
 parameters:(NSDictionary *)parameters
 completion:(void (^)(NSDictionary *, NSError *, NSHTTPURLResponse *))completion;

//+ (void)preloadAdMaterialFromCacheWithParameters:(NSDictionary *)parameters completion:(void (^)(MPPCacheBid *model, NSError *error))completion;

+ (void)uploadTrackEvent:(NSString *)url
              parameters:(id)parameters
              completion:(void (^)(BOOL succee))completion;

@end

NS_ASSUME_NONNULL_END
