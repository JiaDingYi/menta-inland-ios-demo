//
//  MentaGDTRewardVideoAdapter.h
//  MentaGDTAdatper
//
//  Created by iMacMe on 2024/2/29.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedRewardVideoDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaGDTRewardVideoAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedRewardVideoDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
