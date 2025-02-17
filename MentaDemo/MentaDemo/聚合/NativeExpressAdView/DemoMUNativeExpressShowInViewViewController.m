//
//  DemoMVNativeExpressShowInViewViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/19.
//

#import "DemoBaseViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>
#import "DemoNormalModel.h"

@interface DemoMUNativeExpressShowInViewViewController : DemoBaseViewController <MentaUnifiedNativeExpressAdDelegate>
@property (nonatomic, strong) MentaUnifiedNativeExpressAd *nativeExpressAd;
@property (nonatomic, strong) MentaUnifiedNativeExpressAdObject *object;

@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnShow;
@property (nonatomic, strong) UIButton *btnBidSuccess;
@property (nonatomic, strong) UIButton *btnBidFail;
@property (nonatomic, assign) BOOL  isLoded;
@property (nonatomic) CGSize adSize;

@end

@implementation DemoMUNativeExpressShowInViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];

    self.btnLoad = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnLoad.frame = CGRectMake(100, 100, 100, 30);
    [self.btnLoad setTitle:@"加载广告" forState:UIControlStateNormal];
    self.btnLoad.backgroundColor = [UIColor blackColor];
    [self.btnLoad setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnLoad.layer.cornerRadius = 10;
    self.btnLoad.layer.masksToBounds = YES;
    [self.btnLoad addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnLoad];
    
    self.btnShow = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnShow.frame = CGRectMake(100, 140, 100, 30);
    [self.btnShow setTitle:@"展现广告" forState:UIControlStateNormal];
    self.btnShow.backgroundColor = [UIColor blackColor];
    [self.btnShow setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnShow.layer.cornerRadius = 10;
    self.btnShow.layer.masksToBounds = YES;
    [self.btnShow addTarget:self action:@selector(showAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnShow];
      
    self.btnBidSuccess = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnBidSuccess.frame = CGRectMake(100, 180, 100, 30);
    [self.btnBidSuccess setTitle:@"bid success" forState:UIControlStateNormal];
    self.btnBidSuccess.backgroundColor = [UIColor blackColor];
    [self.btnBidSuccess setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnBidSuccess.layer.cornerRadius = 10;
    self.btnBidSuccess.layer.masksToBounds = YES;
    [self.btnBidSuccess addTarget:self action:@selector(sendWinNotification) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnBidSuccess];
    
    self.btnBidFail = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnBidFail.frame = CGRectMake(100, 220, 100, 30);
    [self.btnBidFail setTitle:@"bid fail" forState:UIControlStateNormal];
    self.btnBidFail.backgroundColor = [UIColor blackColor];
    [self.btnBidFail setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnBidFail.layer.cornerRadius = 10;
    self.btnBidFail.layer.masksToBounds = YES;
    [self.btnBidFail addTarget:self action:@selector(sendLossNotification) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnBidFail];

    [self setupLogTextView];
}

- (void)loadAd {
    [self appendLog:@"开始加载模板广告"];
    if (self.nativeExpressAd) {
        [self.nativeExpressAd destory];
        self.nativeExpressAd.delegate = nil;
        self.nativeExpressAd = nil;
        self.isLoded = NO;
    }
    self.adSize = CGSizeMake(self.view.frame.size.width - 20, 250);
    MUNativeExpressConfig *config = [[MUNativeExpressConfig alloc] init];
    config.adSize = self.adSize;
    config.slotId = @"P0299";
    config.materialFillMode = MentaNativeExpressAdMaterialFillMode_ScaleAspectFill;
    config.viewController = self;// 必须设置, 用于内部presentvc

    self.nativeExpressAd = [[MentaUnifiedNativeExpressAd alloc] initWithConfig:config];
    self.nativeExpressAd.delegate = self;

    [self.nativeExpressAd loadAd];
}

- (void)showAd {
    if (!_isLoded) {
        [self appendLog:@"广告物料未加载成功"];
        return;
    }
    [self.view addSubview:self.object.expressView];
    self.object.expressView.frame = CGRectMake(10, 300, self.adSize.width, self.object.expressView.bounds.size.height);
}

- (void)sendWinNotification {
    [self.nativeExpressAd sendWinNotification];
}

- (void)sendLossNotification {
    // 如果MentaSDK 竞价失败, 则调用此方法将您胜出的价格传给我们
    [self.nativeExpressAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32/*请填写胜出价格*/)}];
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedNativeExpressAd *)nativeExpressAd{
    [self appendLog:@"模板广告策略加载成功"];
}

/**
 广告数据回调
 @param unifiedNativeAdDataObjects 广告数据数组
 */
- (void)menta_nativeExpressAdLoaded:(NSArray<MentaUnifiedNativeExpressAdObject *> *)unifiedNativeAdDataObjects nativeExpressAd:(MentaUnifiedNativeExpressAd *)nativeExpressAd{
    [self appendLog:@"模板广告加载成功"];
    [self appendLog:[NSString stringWithFormat:@"广告价格：%@", unifiedNativeAdDataObjects.firstObject.price]];
}

/**
信息流广告加载失败
@param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
@param error 错误
*/
- (void)menta_nativeExpressAd:(MentaUnifiedNativeExpressAd *)nativeExpressAd didFailWithError:(NSError *)error description:(NSDictionary *)description{
    [self appendLog:[NSString stringWithFormat:@"模板广告加载失败：%@", error.localizedDescription]];
}

/**
 信息流渲染成功
 */
- (void)menta_nativeExpressAdViewRenderSuccess:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj {
    [self appendLog:@"模板广告渲染成功"];
    self.isLoded = YES;
    self.object = nativeExpressAdObj;
}

/**
 信息流渲染失败
 */
- (void)nativeExpressAdViewRenderFail:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    [self appendLog:@"模板广告渲染失败"];
}

/**
 广告曝光回调
 */
- (void)menta_nativeExpressAdViewWillExpose:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    [self appendLog:@"模板广告即将曝光"];
}

/**
 广告点击回调,
 */
- (void)menta_nativeExpressAdViewDidClick:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    [self appendLog:@"模板广告被点击"];
}

/**
 广告点击关闭回调
 */
- (void)menta_nativeExpressAdDidClose:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    [self appendLog:@"模板广告关闭"];
    [nativeExpressAdObj.expressView removeFromSuperview];
}

- (void)reportAdExposureFailed:(MentaAdExposureFailureCode)failureCode reportParam:(MentaAdExposureReportParam *)reportParam {
    [self appendLog:[NSString stringWithFormat:@"快手竞价失败，code: %ld, winner: %ld, adnType: %ld, winEcpm: %ld", failureCode, reportParam.adnName, reportParam.adnType, reportParam.winEcpm]];
}

- (void)destroy {
    [self.nativeExpressAd destory];
    self.nativeExpressAd.delegate = nil;
    self.nativeExpressAd = nil;
}

- (void)dealloc {
    [self destroy];
}

@end
