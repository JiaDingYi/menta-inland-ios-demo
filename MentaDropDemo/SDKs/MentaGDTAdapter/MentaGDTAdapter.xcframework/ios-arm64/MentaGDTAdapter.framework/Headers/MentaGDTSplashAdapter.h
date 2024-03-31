//
//  MentaGDTSplashAdapter.h
//  MentaGDTAdatper
//
//  Created by iMacMe on 2024/2/29.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedSplashAdDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaGDTSplashAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedSplashAdDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
