//
//  DemoMVNativeExpressShowInScrollViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/19.
//

#import "DemoMUNativeExpressShowInScrollViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>

@interface DemoMUNativeExpressShowInScrollViewController ()<MentaUnifiedNativeExpressAdDelegate>
@property (nonatomic, strong) MentaUnifiedNativeExpressAd *nativeExpressAd;
@property (nonatomic, strong) MentaUnifiedNativeExpressAdObject *object;

@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, assign) BOOL isLoded;
// scrollview
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic) CGSize adSize;

@end

@implementation DemoMUNativeExpressShowInScrollViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.btnLoad = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnLoad.frame = CGRectMake(100, 100, 100, 80);
    [self.btnLoad setTitle:@"加载广告" forState:UIControlStateNormal];
    [self.btnLoad addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnLoad];
    
    UIButton * btnShow = [UIButton buttonWithType:UIButtonTypeSystem];
    btnShow.frame = CGRectMake(100, 200, 200, 80);
    [btnShow setTitle:@"展现广告在ScrollView中" forState:UIControlStateNormal];
//    [btnShow addTarget:self action:@selector(showInScrollView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnShow];
    
    
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(btnShow.frame), self.view.frame.size.width, self.view.frame.size.height - CGRectGetMaxY(btnShow.frame))];
    self.scrollView.backgroundColor = [UIColor lightGrayColor];
    self.scrollView.contentSize = CGSizeMake(0, 1900);
    
    [self.view addSubview:self.scrollView];
}

- (void)loadAd {
    if (self.nativeExpressAd) {
        [self.nativeExpressAd destory];
        self.nativeExpressAd.delegate = nil;
        self.nativeExpressAd = nil;
    }
    self.adSize = CGSizeMake(self.view.frame.size.width - 20, 300);
    MUNativeExpressConfig *config = [[MUNativeExpressConfig alloc] init];
    config.adSize = self.adSize;
    config.slotId = @"P0299";
    config.materialFillMode = MentaNativeExpressAdMaterialFillMode_ScaleAspectFill;

    self.nativeExpressAd = [[MentaUnifiedNativeExpressAd alloc] initWithConfig:config];
    self.nativeExpressAd.delegate = self;

    [self.nativeExpressAd loadAd];

}


- (void)showAd {
    if (!_isLoded) {
        NSLog(@"广告物料未加载成功");
        return;
    }
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd{
    NSLog(@"%s", __func__);
}

/**
 广告数据回调
 @param unifiedNativeAdDataObjects 广告数据数组
 */
- (void)menta_nativeExpressAdLoaded:(NSArray<MentaUnifiedNativeExpressAdObject *> * _Nullable)unifiedNativeAdDataObjects nativeExpressAd:(MentaUnifiedNativeExpressAd * _Nonnull)nativeExpressAd{
    
    NSLog(@"%s", __func__);
    NSLog(@"price字段为NSNumber类型 price:%@", unifiedNativeAdDataObjects.firstObject.price);
    
    
}


/**
信息流广告加载失败
@param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
@param error 错误
*/
- (void)menta_nativeExpressAd:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description{
    NSLog(@"%s", __func__);
}

/**
 信息流渲染成功
 */
- (void)menta_nativeExpressAdViewRenderSuccess:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj {
    NSLog(@"%s", __func__);
    
    [self.scrollView addSubview:nativeExpressAdObj.expressView];
    nativeExpressAdObj.expressView.frame = CGRectMake(10, 200, self.adSize.width, nativeExpressAdObj.expressView.bounds.size.height);

    [self.nativeExpressAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32)}];

}

/**
 信息流渲染失败
 */
- (void)nativeExpressAdViewRenderFail:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    NSLog(@"%s", __func__);
}

/**
 广告曝光回调
 */
- (void)menta_nativeExpressAdViewWillExpose:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    NSLog(@"%s", __func__);
}


/**
 广告点击回调,
 */
- (void)menta_nativeExpressAdViewDidClick:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    NSLog(@"%s", __func__);
}

/**
 广告点击关闭回调
 */
- (void)menta_nativeExpressAdDidClose:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    NSLog(@"%s", __func__);
    [self destroy];
}

- (void)destroy {
    [self.nativeExpressAd destory];
    self.nativeExpressAd.delegate = nil;
    self.nativeExpressAd = nil;
}

- (void)dealloc {
    NSLog(@"%s", __func__);
    [self destroy];
}


@end
