//
//  MUBaseAbstractFactory.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/21.
//
@class MUAdSource;
@protocol MUBaseAbstractFactory <NSObject>

@required
/// 命中该adapter后，执行回调逻辑

- (instancetype)initWithSource:(MUAdSource *)source adspot:(id)adspot;
- (void)winnerAdapterToShowAd;
- (void)loadAd;
- (void)destory;

- (void)sendLossNoticeWithInfo:(NSDictionary *)lossInfo;

@optional
@property (nonatomic, assign) BOOL isWinnerAdapter;
@property (nonatomic, assign) BOOL isVideoCached;
- (void)renderNativeAdView;

@end
