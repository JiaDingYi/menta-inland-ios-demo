//
//  MVlionRewardInfoView.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBid;
@interface MVlionRewardInfoView : UIView
@property (nonatomic, strong) UILabel *labDownload;

- (instancetype)initWithBid:(MVlionBid *)bid;
@end

NS_ASSUME_NONNULL_END
