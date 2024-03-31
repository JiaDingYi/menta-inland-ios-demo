//
//  NSArray+MVlion.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (MVlion)
- (NSArray *)mvlion_map:(id(^)(id))handle;
- (NSArray *)mvlion_filter:(BOOL(^)(id))handle;
- (id)mvlion_reduce:(id(^)(id, id))handle initial:(id)initial;

@end

@interface NSMutableArray (MVlion)

- (void)mvlion_addObject:(id)anObject;

@end
NS_ASSUME_NONNULL_END
