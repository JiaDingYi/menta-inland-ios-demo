//
//  MULocation.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MULocation : NSObject
// 经度
@property (nonatomic, copy) NSString *longitude;

// 维度
@property (nonatomic, copy) NSString *latitude;
@end

NS_ASSUME_NONNULL_END
