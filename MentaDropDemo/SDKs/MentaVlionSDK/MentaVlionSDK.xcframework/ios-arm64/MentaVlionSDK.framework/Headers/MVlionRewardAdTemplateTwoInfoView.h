//
//  MVlionRewardAdTemplateTwoInfoView.h
//  MVlionSDK
//
//  Created by iMacMe on 2023/12/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionBid;
@interface MVlionRewardAdTemplateTwoInfoView : UIView
@property (nonatomic, strong) UILabel *labDownload;

- (instancetype)initWithBid:(MVlionBid *)bid;

@end

NS_ASSUME_NONNULL_END
