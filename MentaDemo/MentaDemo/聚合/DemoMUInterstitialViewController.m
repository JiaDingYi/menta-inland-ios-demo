//
//  DemoMUInterstitialViewController.m
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/17.
//

#import "DemoBaseViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK-umbrella.h>

@interface DemoMUInterstitialViewController : DemoBaseViewController <MentaUnifiedInterstitialAdDelegate>
@property (nonatomic, strong) MentaUnifiedInterstitialAd *interstitialAd;
@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnShow;
@property (nonatomic, strong) UIButton *btnBidSuccess;
@property (nonatomic, strong) UIButton *btnBidFail;
@property (nonatomic, assign) BOOL  isLoded;

@property (nonatomic, strong) UITextField *placementIDField;
@property (nonatomic, strong) UITextField *countdownField;

@end

@implementation DemoMUInterstitialViewController

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
    
    self.placementIDField = [[UITextField alloc] initWithFrame:CGRectMake(100, 180, 200, 30)];
    self.placementIDField.placeholder = @"P1845";
    self.placementIDField.borderStyle = UITextBorderStyleRoundedRect;
    self.placementIDField.keyboardType = UIKeyboardTypeNumberPad;
    [self.view addSubview:self.placementIDField];
    
    self.countdownField = [[UITextField alloc] initWithFrame:CGRectMake(100, 220, 200, 30)];
    self.countdownField.placeholder = @"enter count down here";
    self.countdownField.borderStyle = UITextBorderStyleRoundedRect;
    self.countdownField.keyboardType = UIKeyboardTypeNumberPad;
    [self.view addSubview:self.countdownField];
    
    self.btnBidSuccess = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnBidSuccess.frame = CGRectMake(100, 270, 100, 30);
    [self.btnBidSuccess setTitle:@"bid success" forState:UIControlStateNormal];
    self.btnBidSuccess.backgroundColor = [UIColor blackColor];
    [self.btnBidSuccess setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnBidSuccess.layer.cornerRadius = 10;
    self.btnBidSuccess.layer.masksToBounds = YES;
    [self.btnBidSuccess addTarget:self action:@selector(sendWinNotification) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnBidSuccess];
    
    self.btnBidFail = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnBidFail.frame = CGRectMake(100, 310, 100, 30);
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
    [self appendLog:@"开始加载插屏广告"];
    if (self.interstitialAd) {
        [self.interstitialAd destory];
        self.interstitialAd.delegate = nil;
        self.interstitialAd = nil;
    }
    
    MUInterstitialConfig *config = [[MUInterstitialConfig alloc] init];
    config.adSize = UIScreen.mainScreen.bounds.size;
    
    NSString *placementID = self.placementIDField.text;
    if (!placementID || placementID.length == 0) {
        placementID = @"P0290";
    }
    config.slotId = placementID;
    NSString *countdown = self.countdownField.text;
    config.countDown = countdown.intValue ? : 0;
    
    self.interstitialAd = [[MentaUnifiedInterstitialAd alloc] initWithConfig:config];
    self.interstitialAd.delegate = self;
    [self.interstitialAd loadAd];
}

- (void)showAd {
    if (!_isLoded) {
        [self appendLog:@"广告物料未加载成功"];
        return;
    }
    
    [self.interstitialAd showAdFromViewController:self];
}

- (void)sendWinNotification {
    [self.interstitialAd sendWinNotification];
}

- (void)sendLossNotification {
    // 如果MentaSDK 竞价失败, 则调用此方法将您胜出的价格传给我们
    [self.interstitialAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32/*请填写胜出价格*/)}];
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingInterstitialADPolicy:(MentaUnifiedInterstitialAd *)interstitialAd {
    [self appendLog:@"插屏广告策略加载成功"];
}

/// 插屏广告源数据拉取成功
- (void)menta_interstitialAdDidLoad:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    [self appendLog:@"插屏广告加载成功"];

}

/// 插屏广告视频下载成功
- (void)menta_interstitialAdMaterialDidLoad:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    [self appendLog:@"插屏广告物料加载成功"];
    _isLoded = YES;
}

/// 插屏广告加载失败
- (void)menta_interstitialAd:(MentaUnifiedInterstitialAd *)interstitialAd didFailWithError:(NSError *)error description:(NSDictionary *)description {
    [self appendLog:[NSString stringWithFormat:@"插屏广告加载失败：%@", error.localizedDescription]];
}

/// 插屏广告被点击了
- (void)menta_interstitialAdDidClick:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    [self appendLog:@"插屏广告被点击"];
}

/// 插屏广告关闭了
- (void)menta_interstitialAdDidClose:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;{
    [self appendLog:@"插屏广告关闭"];
}

/// 插屏将要展现
- (void)menta_interstitialAdWillVisible:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    [self appendLog:@"插屏广告即将展示"];
}

/// 插屏广告曝光
- (void)menta_interstitialAdDidExpose:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    [self appendLog:@"插屏广告曝光"];
}

/// 插屏广告 展现的广告信息 曝光之前会触发该回调
- (void)menta_interstitialAd:(MentaUnifiedInterstitialAd *)interstitialAd bestTargetSourcePlatformInfo:(NSDictionary *)info {
    [self appendLog:[NSString stringWithFormat:@"插屏广告信息：%@", info]];
}

- (void)reportAdExposureFailed:(MentaAdExposureFailureCode)failureCode reportParam:(MentaAdExposureReportParam *)reportParam {
    [self appendLog:[NSString stringWithFormat:@"快手竞价失败，code: %ld, winner: %ld, adnType: %ld, winEcpm: %ld", failureCode, reportParam.adnName, reportParam.adnType, reportParam.winEcpm]];
}

- (void)dealloc {
    NSLog(@"%s", __func__);
}
@end
