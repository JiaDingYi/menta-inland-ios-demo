//
//  DemoMUBannerViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/3/18.
//

#import "DemoMUBannerViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>
@interface DemoMUBannerViewController ()<MentaUnifiedBannerAdDelegate>
@property (nonatomic, strong) MentaUnifiedBannerAd *bannerAd;

@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnShow;
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
    self.btnLoad.frame = CGRectMake(100, 100, 100, 80);
    [self.btnLoad setTitle:@"加载广告" forState:UIControlStateNormal];
    [self.btnLoad addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnLoad];
    
    self.btnShow = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnShow.frame = CGRectMake(100, 200, 100, 80);
    [self.btnShow setTitle:@"展现广告" forState:UIControlStateNormal];
    [self.btnShow addTarget:self action:@selector(showAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnShow];

}

- (void)loadAd {
    if (self.bannerAd) {
        [self.bannerAd destory];
        self.bannerAd.delegate = nil;
        self.bannerAd = nil;
    }
    
    // 模版比例
    // 先确定app展示banner广告位区域的 宽高比, 然后再在menta后台设置 相应或相近比例的模版
    CGFloat scale = 300.f / 150.f;
    
    CGFloat containerW = self.view.frame.size.width - 100;
    CGFloat containerH = containerW / scale;
    
    self.adSize = CGSizeMake(self.view.frame.size.width - 100, containerH);
    
    self.containerView = [[UIView alloc] initWithFrame:CGRectMake(50, 300, self.adSize.width, self.adSize.height)];
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

- (void)showAd {
    
    if (!_isLoded) {
        NSLog(@"广告物料未加载成功");
        return;
    }
    [self.view addSubview:self.containerView];
    [self.bannerAd showInContainer:self.containerView];
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingBannerADPolicy:(MentaUnifiedBannerAd *_Nonnull)bannerAd {
    NSLog(@"%s", __func__);
}

/// 横幅(banner)广告源数据拉取成功
- (void)menta_bannerAdDidLoad:(MentaUnifiedBannerAd *_Nonnull)bannerAd {
    NSLog(@"%s", __func__);
}

/// 横幅(banner)广告物料下载成功
- (void)menta_bannerAdMaterialDidLoad:(MentaUnifiedBannerAd *_Nonnull)bannerAd {
    NSLog(@"%s", __func__);
    _isLoded = YES;
//    [self showAd];
}

/// 横幅(banner)广告加载失败
- (void)menta_bannerAd:(MentaUnifiedBannerAd *_Nonnull)bannerAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description {
    NSLog(@"%s", __func__);
}

/// 横幅(banner)广告被点击了
- (void)menta_bannerAdDidClick:(MentaUnifiedBannerAd *_Nonnull)bannerAd adView:(UIView *_Nullable)adView {
    NSLog(@"%s", __func__);
}

/// 横幅(banner)广告关闭了
- (void)menta_bannerAdDidClose:(MentaUnifiedBannerAd *_Nonnull)bannerAd adView:(UIView *_Nullable)adView {
    NSLog(@"%s", __func__);
    [self.containerView removeFromSuperview];
}

/// 横幅(banner)将要展现
- (void)menta_bannerAdWillVisible:(MentaUnifiedBannerAd *_Nonnull)bannerAd adView:(UIView *_Nullable)adView {
    NSLog(@"%s", __func__);
}


/// 横幅(banner)广告曝光
- (void)menta_bannerAdDidExpose:(MentaUnifiedBannerAd *_Nonnull)bannerAd adView:(UIView *_Nullable)adView {
    NSLog(@"%s", __func__);
}

/// 横幅(banner)广告 展现的广告信息 曝光之前会触发该回调
- (void)menta_bannerAd:(MentaUnifiedBannerAd *_Nonnull)bannerAd bestTargetSourcePlatformInfo:(NSDictionary *_Nonnull)info {
    NSLog(@"%s %@", __func__, info);
}

@end
