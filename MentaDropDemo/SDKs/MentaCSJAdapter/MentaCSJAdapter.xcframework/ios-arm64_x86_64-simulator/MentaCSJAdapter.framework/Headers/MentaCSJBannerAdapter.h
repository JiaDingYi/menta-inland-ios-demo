//
//  MentaCSJBannerAdapter.h
//  Pods
//
//  Created by iMacMe on 2024/3/28.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedBannerAdDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaCSJBannerAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedBannerAdDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
