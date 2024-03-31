//
//  MVlionDownload.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/16.
//

#import <Foundation/Foundation.h>
@class MVlionBid;
NS_ASSUME_NONNULL_BEGIN

@interface MVlionDownload : NSObject
+ (void)downloadTemplateImages;

/// 用于广告素材下载 如果素材已经下载 立即回调 未下载执行下载任务
+ (void)downloadBidsMaterial:(NSArray<MVlionBid *> *)bids requestId:(NSString *)requestId completion:(void(^)(NSArray<MVlionBid *> *,NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
