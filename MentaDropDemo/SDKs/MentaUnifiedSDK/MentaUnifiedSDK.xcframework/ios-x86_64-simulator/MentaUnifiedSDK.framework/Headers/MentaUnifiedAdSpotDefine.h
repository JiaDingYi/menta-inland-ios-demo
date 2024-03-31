//
//  MentaUnifiedAdSpotDefine.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class MUPolicyService;

#pragma 注意:该文件中的属性或方法 不可更改,   开发者可以忽略
#pragma 注意:该文件中的属性或方法 不可更改,   开发者可以忽略
#pragma 注意:该文件中的属性或方法 不可更改,   开发者可以忽略
@protocol MentaUnifiedAdSpotDefine <NSObject>

/// 并行渠道adpater存储器
@property (nonatomic, strong) NSMutableDictionary *adapterMap;

/// 被命中展示的Adapter
@property (nonatomic, strong) id targetAdapter;

/// 策略管理对象
@property (nonatomic, strong) MUPolicyService *manager;

@end
