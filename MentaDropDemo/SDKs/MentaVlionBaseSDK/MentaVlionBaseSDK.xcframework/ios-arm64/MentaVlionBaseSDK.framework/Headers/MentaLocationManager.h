//
//  MentaLocationManager.h
//  MentaVlionBaseSDK
//
//  Created by iMacMe on 2023/12/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaLocationManager : NSObject 
@property (nonatomic, assign, readonly) double latitude;
@property (nonatomic, assign, readonly) double longitude;

@property (nonatomic, assign) BOOL isCanUseLocation;
+ (instancetype)sharedManager;

- (void)startUpdatingLocation;

@end

NS_ASSUME_NONNULL_END
