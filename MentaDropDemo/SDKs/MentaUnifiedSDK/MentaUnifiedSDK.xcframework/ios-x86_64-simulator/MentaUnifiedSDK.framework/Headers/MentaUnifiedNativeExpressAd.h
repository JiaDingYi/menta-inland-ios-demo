//
//  MentaUnifiedNativeExpressAd.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeExpressAdDelegate.h>
#import <MentaUnifiedSDK/MentaUnifiedAdSpotDefine.h>

NS_ASSUME_NONNULL_BEGIN
@class MUNativeExpressConfig, MentaUnifiedNativeExpressAdObject;
@interface MentaUnifiedNativeExpressAd : NSObject<MentaUnifiedAdSpotDefine, MUAdProtocol>
/// 初始化时传入的config
@property (nonatomic, strong, readonly) MUNativeExpressConfig *config;

/// 开屏广告代理
@property (nonatomic, weak) id <MentaUnifiedNativeExpressAdDelegate> delegate;



- (instancetype)initWithConfig:(MUNativeExpressConfig *)config;


- (void)loadAd;

- (void)destory;

@end

NS_ASSUME_NONNULL_END
