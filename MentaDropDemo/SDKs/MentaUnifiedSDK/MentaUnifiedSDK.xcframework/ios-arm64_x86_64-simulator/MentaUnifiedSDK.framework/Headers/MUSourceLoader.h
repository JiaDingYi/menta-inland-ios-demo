//
//  MUSourceLoader.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/23.
//

#import <Foundation/Foundation.h>
@class MUAdSource;
NS_ASSUME_NONNULL_BEGIN

@interface MUSourceLoader : NSObject

+ (void)loadSource:(MUAdSource *)source completion:(void (^)(void))completion;

@end

NS_ASSUME_NONNULL_END
