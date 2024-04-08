//
//  MUNativeExpressAbstractFactory.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/23.
//
#import <UIKit/UIKit.h>
#import <MentaUnifiedSDK/MUBaseAbstractFactory.h>
@class MUAdSource;
@protocol MUNativeExpressAbstractFactory <MUBaseAbstractFactory>

@required
- (instancetype)initWithSource:(MUAdSource *)source adspot:(id)adspot;

- (void)loadAd;


- (void)destory;
@end
