//
//  MUExceptionHandler.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MUExceptionHandler : NSObject
+ (void)setDefaultHandler;
+ (NSUncaughtExceptionHandler*)getHandler;
+ (void)uploadCrashInfo;
+ (void)saveCrashInfo:(NSString *)crashInfo;
@end

NS_ASSUME_NONNULL_END
