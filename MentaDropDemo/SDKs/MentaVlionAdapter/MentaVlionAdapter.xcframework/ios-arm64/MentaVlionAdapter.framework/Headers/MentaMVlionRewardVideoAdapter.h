//
//  MentaMVlionRewardVideoAdapter.h
//  MentaMVlionAdapter
//
//  Created by iMacMe on 2023/12/20.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedRewardVideoDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaMVlionRewardVideoAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedRewardVideoDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
