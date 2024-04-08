//
//  NSError+MVlion.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (MVlion)
+ (NSError *)mvl_errorDefault;

+ (NSError *)mvl_errorNotFoundContainer;

+ (NSError *)mvl_errorWithStatus:(NSInteger)status;

@end

NS_ASSUME_NONNULL_END
