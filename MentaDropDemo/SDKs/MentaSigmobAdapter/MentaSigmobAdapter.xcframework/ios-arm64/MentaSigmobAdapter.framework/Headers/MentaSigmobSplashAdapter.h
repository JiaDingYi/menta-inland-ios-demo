//
//  MentaSigmobSplashAdapter.h
//  Masonry
//
//  Created by jdy on 2024/4/17.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedSplashAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaSigmobSplashAdapter : NSObject

@property (nonatomic, weak) id<MentaUnifiedSplashAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
