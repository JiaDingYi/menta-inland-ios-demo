//
//  MentaMVlionSplashAdapter.h
//  MentaMVlionAdapter
//
//  Created by iMacMe on 2023/11/24.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedSplashAdDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaMVlionSplashAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedSplashAdDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
