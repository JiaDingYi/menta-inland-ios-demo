//
//  Header.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/3/18.
//

@class MUAdSource;
#import <MentaUnifiedSDK/MUBaseAbstractFactory.h>
@protocol MUBannerAbstractFactory <MUBaseAbstractFactory>

- (void)showInContainer:(UIView *)containerView;



@end
