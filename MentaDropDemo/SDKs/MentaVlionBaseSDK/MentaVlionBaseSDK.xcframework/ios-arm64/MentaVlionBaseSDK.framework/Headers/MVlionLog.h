//
//  Custom_NSLog.m
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//


#import <Foundation/Foundation.h>

/**
*   自定义Log，可配置开关（用于替换NSLog）
*/
#define MentaLog(format,...) MVlionCustomLog(__FUNCTION__,__LINE__,format,##__VA_ARGS__)

/**
*   自定义Log
*   @warning 外部可直接调用 NSLog_Custom
*   @param   func            方法名
*   @param   lineNumber   行号
*   @param   format         Log内容
*   @param   ...               个数可变的Log参数
*/

void MVlionCustomLog(const char *func, int lineNumber, NSString *format, ...);

@interface MVlionLog : NSObject

/**
*   Log 输出开关 (默认关闭)
*   @param flag 是否开启 YES:显示；NO:不显示
*/
+ (void)setLogEnable:(BOOL)flag;

/**
*   是否开启了 Log 输出
*   @return Log 开关状态
*/
+ (BOOL)logEnable;

@end


