//
//  MVlionLocationManager.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionLocationManager : NSObject
@property (nonatomic, assign, readonly) CGFloat latitude;
@property (nonatomic, assign, readonly) CGFloat longitude;
@property (nonatomic, assign) BOOL isCanUseLocation;

//@property (nonatomic, copy) void (^completionHandler)(double latitude, double longitude, NSError *error);

+ (instancetype)sharedManager;


- (void)startUpdatingLocation;
//- (void)getCurrentLocationWithCompletionHandler:(void (^)(double latitude, double longitude, NSError *error))completionHandler;
@end

NS_ASSUME_NONNULL_END
