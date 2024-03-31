//
//  MVlionBaseToolBox.h
//  MentaVlionBaseSDK
//
//  Created by iMacMe on 2023/11/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionBaseToolBox : NSObject

// 字典转get url 参数
+ (NSString *)mvlion_urlWithBaseURL:(NSString *)baseURL parameters:(NSDictionary *)parameters;

@end

NS_ASSUME_NONNULL_END
