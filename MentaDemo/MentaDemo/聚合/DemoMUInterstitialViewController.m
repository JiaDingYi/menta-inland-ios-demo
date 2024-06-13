//
//  DemoMUInterstitialViewController.m
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2024/1/17.
//

#import "DemoMUInterstitialViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>

@interface DemoMUInterstitialViewController ()<MentaUnifiedInterstitialAdDelegate>
@property (nonatomic, strong) MentaUnifiedInterstitialAd *interstitialAd;
@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnShow;
@property (nonatomic, assign) BOOL  isLoded;

@end

@implementation DemoMUInterstitialViewController

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
    if (self.interstitialAd) {
        [self.interstitialAd destory];
        self.interstitialAd.delegate = nil;
        self.interstitialAd = nil;
    }
    
    MUInterstitialConfig *config = [[MUInterstitialConfig alloc] init];
    config.adSize = UIScreen.mainScreen.bounds.size;
//    config.slotId = @"P0291";// 视频
    config.slotId = @"P0290";// 图片
    config.countDown = 10;

    self.interstitialAd = [[MentaUnifiedInterstitialAd alloc] initWithConfig:config];
    self.interstitialAd.delegate = self;
    [self.interstitialAd loadAd];

}

- (void)showAd {
    
    if (!_isLoded) {
        NSLog(@"广告物料未加载成功");
        return;
    }
    
    [self.interstitialAd showAdFromViewController:self];
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingInterstitialADPolicy:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    NSLog(@"%s",__func__);
}

/// 插屏广告源数据拉取成功
- (void)menta_interstitialAdDidLoad:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    NSLog(@"%s",__func__);

}

/// 插屏广告视频下载成功
- (void)menta_interstitialAdMaterialDidLoad:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    NSLog(@"%s",__func__);
    _isLoded = YES;

    [self showAd];
}

/// 插屏广告加载失败
- (void)menta_interstitialAd:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description {
    NSLog(@"%s",__func__);

}

/// 插屏广告被点击了
- (void)menta_interstitialAdDidClick:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    NSLog(@"%s",__func__);

}

/// 插屏广告关闭了
- (void)menta_interstitialAdDidClose:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd;{
    NSLog(@"%s",__func__);

}

/// 插屏将要展现
- (void)menta_interstitialAdWillVisible:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    NSLog(@"%s",__func__);

}

/// 插屏广告曝光
- (void)menta_interstitialAdDidExpose:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd {
    NSLog(@"%s",__func__);

}

/// 插屏广告 展现的广告信息 曝光之前会触发该回调
- (void)menta_interstitialAd:(MentaUnifiedInterstitialAd *_Nonnull)interstitialAd bestTargetSourcePlatformInfo:(NSDictionary *_Nonnull)info {
    NSLog(@"%s info(info当中的BEST_SOURCE_PRICE字段为NSNumber类型)该回调会在mvlion_interstitialMaterialDidLoad前触发:%@", __func__, info);
    
    [interstitialAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32)}];

}

- (void)dealloc {
    NSLog(@"%s", __func__);
}
@end
