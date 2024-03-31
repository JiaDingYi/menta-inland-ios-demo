//
//  MentaUnifiedNativeExpressAdObject.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaUnifiedNativeExpressAdObject : NSObject
// 信息流view
@property (nonatomic, strong) UIView *expressView;

// 渠道标识
/**
 PDD: 拼多多
 VL : 瑞狮
 JM : 京东
 VS : SIGMOB
 VB : 百度
 */
@property (nonatomic, copy) NSString *identifier;

@property (nonatomic, strong) NSNumber *price;

@end

NS_ASSUME_NONNULL_END
