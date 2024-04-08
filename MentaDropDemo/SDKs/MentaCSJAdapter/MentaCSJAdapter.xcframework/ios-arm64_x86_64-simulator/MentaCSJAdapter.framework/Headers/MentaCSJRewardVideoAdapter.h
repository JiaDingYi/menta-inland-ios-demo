//
//  MentaCSJRewardVideoAdapter.h
//  Pods
//
//  Created by iMacMe on 2024/3/28.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedRewardVideoDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaCSJRewardVideoAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedRewardVideoDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
