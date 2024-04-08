//
//  MVlionRewardDetainmentView.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/29.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBid;
@interface MVlionRewardDetainmentView : UIView
@property (nonatomic, strong) UILabel *labContinue;
@property (nonatomic, strong) UILabel *labQuit;

@property (nonatomic, assign) NSInteger currentTime;
- (instancetype)initWithBid:(MVlionBid *)bid;

@end

NS_ASSUME_NONNULL_END
