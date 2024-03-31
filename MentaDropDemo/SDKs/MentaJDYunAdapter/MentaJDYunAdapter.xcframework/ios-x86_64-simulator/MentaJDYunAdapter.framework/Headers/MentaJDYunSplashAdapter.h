//
//  MentaJDYunSplashAdapter.h
//  MentaJDYunAdapter
//
//  Created by stone on 2024/2/11.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedSplashAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaJDYunSplashAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedSplashAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
