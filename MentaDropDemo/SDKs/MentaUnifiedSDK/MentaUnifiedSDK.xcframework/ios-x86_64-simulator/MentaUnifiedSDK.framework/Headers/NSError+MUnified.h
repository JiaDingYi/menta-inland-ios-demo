//
//  NSError+MUnified.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (MUnified)
+ (NSError *)mu_errorDefault;

+ (NSError *)mu_errorNotFoundContainer;

+ (NSError *)mu_errorWithStatus:(NSInteger)status;
@end

NS_ASSUME_NONNULL_END
