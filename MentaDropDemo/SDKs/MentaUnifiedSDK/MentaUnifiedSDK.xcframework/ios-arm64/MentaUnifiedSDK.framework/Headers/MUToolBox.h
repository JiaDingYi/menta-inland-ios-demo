//
//  MUToolBox.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MUToolBox : NSObject
+ (NSString *)getIDFA;

+ (NSString *)md5:(NSString *)str;
@end

NS_ASSUME_NONNULL_END
