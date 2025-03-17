//
//  DemoMUSplashViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2023/12/20.
//

#import "DemoBaseViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK-umbrella.h>

@interface DemoMUSplashViewController : DemoBaseViewController <MentaUnifiedSplashAdDelegate>
@property (nonatomic, strong) MentaUnifiedSplashAd *splashAd;
@property (nonatomic, assign) BOOL isLoded;
@property (nonatomic, strong) UIButton *btn;
@property (nonatomic, strong) UIButton *btnShow;
@property (nonatomic, strong) UIButton *btnBidSuccess;
@property (nonatomic, strong) UIButton *btnBidFail;
@end

@implementation DemoMUSplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.btn = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btn.frame = CGRectMake(100, 100, 100, 30);
    [self.btn setTitle:@"加载广告" forState:UIControlStateNormal];
    self.btn.backgroundColor = [UIColor blackColor];
    [self.btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btn.layer.cornerRadius = 10;
    self.btn.layer.masksToBounds = YES;
    [self.btn addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btn];
    
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
    [self appendLog:@"开始加载开屏广告"];
    if (self.splashAd) {
        self.splashAd.delegate = nil;
        self.splashAd = nil;
    }
    
    MUSplashConfig *config = [MUSplashConfig new];
    config.slotId = @"P0105";
    config.viewController = self;
    config.tolerateTime = 5;
    UIView *bottomView = [self returnBottomView];
    config.bottomView = bottomView;
    config.adSize = CGSizeMake(UIScreen.mainScreen.bounds.size.width, UIScreen.mainScreen.bounds.size.height - bottomView.bounds.size.height);
//    config.materialFillMode = MentaSplashAdMaterialFillMode_ScaleAspectFit;
    
    _splashAd = [[MentaUnifiedSplashAd alloc] initWithConfig:config];
    _splashAd.delegate = self;
    [_splashAd loadAd];
}

- (void)showAd {
    if (!_isLoded) {
        [self appendLog:@"广告物料未加载成功"];
        return;
    }
    [self.splashAd showInWindow:self.view.window];
}

- (void)sendWinNotification {
    [self.splashAd sendWinNotification];
}

- (void)sendLossNotification {
    // 如果MentaSDK 竞价失败, 则调用此方法将您胜出的价格传给我们
    [self.splashAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32/*请填写胜出价格*/)}];
}

- (UIView *)returnBottomView {
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 120)];
    view.backgroundColor = [UIColor blueColor];

    UILabel *lab = [[UILabel alloc] init];
    lab.frame = CGRectMake(0, 0, 200, 50);
    lab.textAlignment = NSTextAlignmentCenter;
    lab.text = @"底部logo自定义区域";
    lab.center = CGPointMake(CGRectGetWidth(view.frame) / 2.f, CGRectGetHeight(view.frame) / 2.f);
    lab.textColor = [UIColor whiteColor];
    [view addSubview:lab];

    return view;
}

/// MentaUnifiedSplashAdDelegate
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedSplashAd *)splashAd {
    [self appendLog:@"开屏广告策略加载成功"];
}

/// 该回调会在 menta_splashAdDidLoad 之前被触发
- (void)menta_splashAd:(MentaUnifiedSplashAd *_Nonnull)splashAd bestTargetSourcePlatformInfo:(NSDictionary * _Nonnull)info {
    [self appendLog:[NSString stringWithFormat:@"开屏广告信息：%@", info]];
}

/// 开屏广告数据拉取成功
- (void)menta_splashAdDidLoad:(MentaUnifiedSplashAd *_Nonnull)splashAd {
    [self appendLog:@"开屏广告加载成功"];
    self.isLoded = YES;
}

/// 开屏广告数据拉取失败
- (void)menta_splashAd:(MentaUnifiedSplashAd *)splashAd didFailWithError:(NSError *)error description:(NSDictionary * _Nonnull)description {
    [self appendLog:[NSString stringWithFormat:@"开屏广告加载失败：%@", error.localizedDescription]];
}

/// 开屏广告被点击了
- (void)menta_splashAdDidClick:(MentaUnifiedSplashAd *_Nonnull)splashAd {
    [self appendLog:@"开屏广告被点击"];
}

/// 开屏广告关闭了
- (void)menta_splashAdDidClose:(MentaUnifiedSplashAd *_Nonnull)splashAd closeMode:(MentaSplashAdCloseMode)mode {
    [self appendLog:[NSString stringWithFormat:@"开屏广告关闭，关闭模式：%lu", (unsigned long)mode]];
}

///  开屏广告曝光
- (void)menta_splashAdDidExpose:(MentaUnifiedSplashAd *_Nonnull)splashAd {
    [self appendLog:@"开屏广告曝光"];
}

- (void)reportAdExposureFailed:(MentaAdExposureFailureCode)failureCode reportParam:(MentaAdExposureReportParam *)reportParam {
    [self appendLog:[NSString stringWithFormat:@"快手竞价失败，code: %ld, winner: %ld, adnType: %ld, winEcpm: %ld", failureCode, reportParam.adnName, reportParam.adnType, reportParam.winEcpm]];
}

- (void)dealloc {
    NSLog(@"%s", __func__);
}
@end
