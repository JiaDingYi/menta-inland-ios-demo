//
//  MUUser.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/22.
//

#import <Foundation/Foundation.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface MUUser : NSObject

@property (nonatomic, copy) NSString *userID;// userId
// 性别
@property (nonatomic, assign) MVUserGender gender;
// 年龄
@property (nonatomic, assign) NSUInteger age;
// 消费水平（高：high、中：middle、低：low）
@property (nonatomic, assign) MVUserConsumeLevel consumeLevel;

@end

NS_ASSUME_NONNULL_END
