//
//  MentaTanxSplashAdapter.h
//  MentaTanxAdapter
//
//  Created by stone on 2024/2/17.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedSplashAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaTanxSplashAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedSplashAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
