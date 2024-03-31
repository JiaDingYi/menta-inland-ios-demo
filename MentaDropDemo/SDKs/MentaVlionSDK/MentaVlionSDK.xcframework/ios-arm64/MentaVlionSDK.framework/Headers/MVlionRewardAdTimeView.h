//
//  MVlionRewardAdTimeView.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBid;
@interface MVlionRewardAdTimeView : UIView
@property (nonatomic, assign) NSInteger currentTime;
- (instancetype)initWithBid:(MVlionBid *)bid;
- (void)playerFinish;
@end

NS_ASSUME_NONNULL_END
