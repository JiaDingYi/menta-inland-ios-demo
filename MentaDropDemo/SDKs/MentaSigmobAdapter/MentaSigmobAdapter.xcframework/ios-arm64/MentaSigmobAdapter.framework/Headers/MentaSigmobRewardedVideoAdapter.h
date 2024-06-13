//
//  MentaSigmobRewardedVideoAdapter.h
//  Masonry
//
//  Created by jdy on 2024/4/17.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaSigmobRewardedVideoAdapter : NSObject

@property (nonatomic, weak) id<MentaUnifiedRewardVideoDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
