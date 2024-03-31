//
//  NSDictionary+MVlion.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (MVlion)

@end

@interface NSMutableDictionary (MVlion)

- (void)mvlion_setObject:(NSObject *)obj forKey:(NSString *)key;



@end

NS_ASSUME_NONNULL_END
