//
//  DemoMUBannerViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/3/18.
//

#import "DemoBaseViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>

@interface DemoMUBannerViewController : DemoBaseViewController <MentaUnifiedBannerAdDelegate>
@property (nonatomic, strong) MentaUnifiedBannerAd *bannerAd;

@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnShow;
@property (nonatomic, strong) UIButton *btnBidSuccess;
@property (nonatomic, strong) UIButton *btnBidFail;
@property (nonatomic, assign) BOOL  isLoded;
@property (nonatomic) CGSize  adSize;
@property (nonatomic, strong) UIView *containerView;

@end

@implementation DemoMUBannerViewController

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
    
    // 添加日志输出控件
    [self setupLogTextView];
}

- (void)loadAd {
    [self appendLog:@"开始加载广告"];
    if (self.bannerAd) {
        [self.containerView removeFromSuperview];
        [self.bannerAd destory];
        self.bannerAd.delegate = nil;
        self.bannerAd = nil;
    }
    // 模版比例
    // 先确定app展示banner广告位区域的 宽高比, 然后再在menta后台设置 相应或相近比例的模版
    CGFloat scale = 320.f / 50.f;
    CGFloat containerW = self.view.frame.size.width;
    CGFloat containerH = containerW / scale;
    self.adSize = CGSizeMake(containerW, containerH);
    self.containerView = [[UIView alloc] initWithFrame:CGRectMake(0, 300, self.adSize.width, self.adSize.height)];
    self.containerView.backgroundColor = [UIColor blueColor];
    MUBannerConfig *config = [[MUBannerConfig alloc] init];
    config.adSize = self.adSize; // adSize 设置多少 最后的banner显示区域就是多少 同时containerView的size 要与adsize保持一致
    config.slotId = @"P0406";// 图片
    config.materialFillMode = MentaBannerAdMaterialFillMode_ScaleAspectFill;
    config.viewController = self;

    self.bannerAd = [[MentaUnifiedBannerAd alloc] initWithConfig:config];
    self.bannerAd.delegate = self;
    [self.bannerAd loadAd];
}

- (void)sendWinNotification {
    [self appendLog:@"发送竞价成功通知"];
    [self.bannerAd sendWinNotification];
}

- (void)sendLossNotification {
    [self appendLog:@"发送竞价失败通知"];
    // 如果MentaSDK 竞价失败, 则调用此方法将您胜出的价格传给我们
    [self.bannerAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32/*请填写胜出价格*/)}];
}

- (void)showAd {
    if (!_isLoded) {
        [self appendLog:@"广告物料未加载成功"];
        return;
    }
    [self appendLog:@"展示广告"];
    [self.view addSubview:self.containerView];
    [self.bannerAd showInContainer:self.containerView];
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingBannerADPolicy:(MentaUnifiedBannerAd *)bannerAd {
    [self appendLog:@"广告策略加载成功"];
}

/// 横幅(banner)广告源数据拉取成功
- (void)menta_bannerAdDidLoad:(MentaUnifiedBannerAd *)bannerAd {
    [self appendLog:@"广告数据加载成功"];
}

/// 横幅(banner)广告物料下载成功
- (void)menta_bannerAdMaterialDidLoad:(MentaUnifiedBannerAd *)bannerAd {
    [self appendLog:@"广告物料加载成功"];
    _isLoded = YES;
//    [self showAd];
}

/// 横幅(banner)广告加载失败
- (void)menta_bannerAd:(MentaUnifiedBannerAd *)bannerAd didFailWithError:(NSError *)error description:(NSDictionary *)description {
    [self appendLog:[NSString stringWithFormat:@"广告加载失败：%@", error.localizedDescription]];
}

/// 横幅(banner)广告被点击了
- (void)menta_bannerAdDidClick:(MentaUnifiedBannerAd *)bannerAd adView:(UIView *)adView {
    [self appendLog:@"广告被点击"];
}

/// 横幅(banner)广告关闭了
- (void)menta_bannerAdDidClose:(MentaUnifiedBannerAd *)bannerAd adView:(UIView *)adView {
    [self appendLog:@"广告被关闭"];
    [self.containerView removeFromSuperview];
}

/// 横幅(banner)将要展现
- (void)menta_bannerAdWillVisible:(MentaUnifiedBannerAd *)bannerAd adView:(UIView *)adView {
    [self appendLog:@"广告即将展示"];
}


/// 横幅(banner)广告曝光
- (void)menta_bannerAdDidExpose:(MentaUnifiedBannerAd *)bannerAd adView:(UIView *)adView {
    [self appendLog:@"广告曝光"];
}

/// 横幅(banner)广告 展现的广告信息 曝光之前会触发该回调
- (void)menta_bannerAd:(MentaUnifiedBannerAd *)bannerAd bestTargetSourcePlatformInfo:(NSDictionary *)info {
    [self appendLog:[NSString stringWithFormat:@"广告信息：%@", info]];
}

@end
