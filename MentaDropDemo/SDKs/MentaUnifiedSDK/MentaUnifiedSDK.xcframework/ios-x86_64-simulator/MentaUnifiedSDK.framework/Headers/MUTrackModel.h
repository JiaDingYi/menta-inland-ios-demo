//
//  MUTrackModel.h
//  Test
//
//  Created by iMacMe on 2023/12/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MUTrackModel : NSObject
@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, copy) NSString *sid;
@property (nonatomic, copy) NSString *act;
@property (nonatomic, copy) NSString *app;

// 以下字段为 可能为某个或者某几个事件特有
@property (nonatomic, assign) NSInteger price; // 广告填充价格
@property (nonatomic, assign) NSInteger result; // 结果
@end

NS_ASSUME_NONNULL_END
