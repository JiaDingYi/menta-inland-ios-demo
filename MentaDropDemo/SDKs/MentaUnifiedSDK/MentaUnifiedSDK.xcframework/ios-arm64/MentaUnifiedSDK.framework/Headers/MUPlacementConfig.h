//
//  MUPlacementConfig.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MUPlacementConfig : NSObject
@property (nonatomic, assign) BOOL isBiding;
@property (nonatomic, copy)   NSString *style;
@property (nonatomic, assign) NSInteger twistRange;
@property (nonatomic, assign) NSInteger screenType;
@property (nonatomic, assign) NSInteger videoVoice;
@property (nonatomic, copy)   NSString *showId;
@property (nonatomic, copy)   NSString *creativeType;
@property (nonatomic, copy)   NSString *interactiveType;
@property (nonatomic, assign) NSInteger price;
@property (nonatomic, assign) NSInteger adType;
@property (nonatomic, copy)   NSString *randerType;
@property (nonatomic, copy)   NSString *templateType;
@property (nonatomic, assign) NSInteger autoPlay;
@property (nonatomic, assign) NSInteger shakeRange;
@property (nonatomic, assign) NSInteger swipeRange;

@property (nonatomic, strong) NSMutableDictionary *adTemplate;

// 统计事件字典
@property (nonatomic, strong) NSDictionary *eventsDict;

// 统计使用
@property (nonatomic, copy)   NSString *stime; //服务端接口响应时间 current请求配置时间
@property (nonatomic, copy)   NSString *trace; // 服务端的uuid trace（客户端请求header头中的x-trace）


// 这个字段是从api层获取的, 为了统计
@property (nonatomic, strong) NSMutableDictionary *extra;


// 只有信息流模版渲染使用 , 信息流模渲染, 最后显示的模版 不能在聚合层确定, 需要在api层确定
@property (nonatomic, strong) NSArray *nativeExpressTemplateConfigWeights; // 信息流模版渲染的配置权重信息
@property (nonatomic, strong) NSArray *nativeExpressTemplates;             // 信息流模版渲染的模版信息

@end

NS_ASSUME_NONNULL_END
