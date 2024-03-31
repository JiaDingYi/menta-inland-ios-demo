//
//  DemoNormalModel.h
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DemoNormalModel : NSObject
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *source;
@property (nonatomic, strong) NSString *incon;
@property (nonatomic, copy) NSArray *imgs;
@property (nonatomic, assign) float cellHeight;
- (instancetype)initWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
