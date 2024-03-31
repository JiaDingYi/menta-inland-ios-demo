//
//  MUNativeAbstractFactory.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/9.
//
@class MUAdSource;
@protocol MUNativeAbstractFactory <NSObject>
@required
- (instancetype)initWithSource:(MUAdSource *)source adspot:(id)adspot;

- (void)loadAd;

- (void)destory;
@end
