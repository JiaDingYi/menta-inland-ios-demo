//
//  MUAdProtocol.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/7.
//



#define MU_M_L_WIN_PRICE @"winPrice"

@protocol MUAdProtocol <NSObject>

@optional
/*
 *  竞败之后或未参竞调用
 *
 *  @pararm lossInfo 竞败信息，字典类型，注：key是个宏，在MUAdProtocol.h中有定义，可以参考demo中的使用方法
 *  MU_M_L_WIN_PRICE ：竞胜价格 (单位: 分)，值类型为NSNumber *，选填
 */
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

