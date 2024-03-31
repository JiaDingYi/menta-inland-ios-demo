//
//  MVlionInterstitialClickBtnView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionInterstitialConfig;
@interface MVlionInterstitialClickBtnView : UIView
- (instancetype)initWithConfig:(MVlionInterstitialConfig *)config templateName:(NSString *)name;
@end

NS_ASSUME_NONNULL_END
