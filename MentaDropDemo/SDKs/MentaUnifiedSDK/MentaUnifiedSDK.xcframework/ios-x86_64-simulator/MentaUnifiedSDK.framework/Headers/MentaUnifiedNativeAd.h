//
//  MentaUnifiedNativeAd.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/9.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedAdSpotDefine.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN
@class MUNativeConfig;
@interface MentaUnifiedNativeAd : NSObject<MentaUnifiedAdSpotDefine, MUAdProtocol>
/// 初始化时传入的config
@property (nonatomic, strong, readonly) MUNativeConfig *config;

/// 开屏广告代理
@property (nonatomic, weak) id <MentaUnifiedNativeAdDelegate> delegate;



- (instancetype)initWithConfig:(MUNativeConfig *)config;


- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
