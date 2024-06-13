//
//  MVDpDetector.h
//  MentaVlionBaseSDK
//
//  Created by jdy on 2024/4/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^CompletionBlock)(NSInteger times, BOOL appIsInForeground);

@interface MVDpDetector : NSObject

+ (instancetype)sharedDpDetector;

- (void)startDetectorWith:(NSInteger)deepLinkTimes completion:(CompletionBlock)completion;

- (void)cancleTimer;

@end

NS_ASSUME_NONNULL_END
