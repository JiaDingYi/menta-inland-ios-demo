//
//  MentaTanxRewardVideoAdapter.h
//  MentaTanxAdapter
//
//  Created by stone on 2024/2/20.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedRewardVideoDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaTanxRewardVideoAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedRewardVideoDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
