//
//  DemoMUSplashViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2023/12/20.
//

#import "DemoMUSplashViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>

@interface DemoMUSplashViewController ()<MentaUnifiedSplashAdDelegate>
@property (nonatomic, strong) MentaUnifiedSplashAd *splashAd;
@property (nonatomic, strong) UIButton *btn;
@property (nonatomic, assign) BOOL isLoded;
@property (nonatomic, strong) UIButton *btnShow;
@end

@implementation DemoMUSplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    
    
    self.btn = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btn.frame = CGRectMake(100, 100, 100, 80);
    [self.btn setTitle:@"加载广告" forState:UIControlStateNormal];
    [self.btn addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btn];
    
    self.btnShow = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnShow.frame = CGRectMake(100, 200, 100, 80);
    [self.btnShow setTitle:@"展现广告" forState:UIControlStateNormal];
    [self.btnShow addTarget:self action:@selector(showAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnShow];

    
}

- (void)loadAd {
    
    if (self.splashAd) {
        self.splashAd.delegate = nil;
        self.splashAd = nil;
    }
    
    MUSplashConfig *config = [MUSplashConfig new];
    config.slotId = @"P0105";
    config.viewController = self;
    config.tolerateTime = 5;
    config.bottomView = [self returnBottomView];
//    config.materialFillMode = MentaSplashAdMaterialFillMode_ScaleAspectFit;
    
    _splashAd = [[MentaUnifiedSplashAd alloc] initWithConfig:config];
    _splashAd.delegate = self;
    
    [_splashAd loadAd];

}

- (void)showAd {
    if (!_isLoded) {
        NSLog(@"广告物料未加载成功");
        return;
    }
    [self.splashAd showInWindow:self.view.window];
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
    NSLog(@"%s %@", __func__, splashAd.config.slotId);
}

/// 该回调会在 menta_splashAdDidLoad 之前被触发
- (void)menta_splashAd:(MentaUnifiedSplashAd *_Nonnull)splashAd bestTargetSourcePlatformInfo:(NSDictionary * _Nonnull)info {
    NSLog(@"%s info(info当中的BEST_SOURCE_PRICE字段为NSNumber类型)该回调会在menta_splashAdDidLoad前触发:%@", __func__, info);
    
    [self.splashAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32)}];
}

/// 开屏广告数据拉取成功
- (void)menta_splashAdDidLoad:(MentaUnifiedSplashAd *_Nonnull)splashAd {
    NSLog(@"%s", __func__);
    self.isLoded = YES;
    [self showAd];
}

/// 开屏广告数据拉取失败
- (void)menta_splashAd:(MentaUnifiedSplashAd *)splashAd didFailWithError:(NSError *)error description:(NSDictionary * _Nonnull)description {
    NSLog(@"%s %@ %@", __func__, error, description);
    
}

/// 开屏广告被点击了
- (void)menta_splashAdDidClick:(MentaUnifiedSplashAd *_Nonnull)splashAd {
    NSLog(@"%s", __func__);
}

/// 开屏广告关闭了
- (void)menta_splashAdDidClose:(MentaUnifiedSplashAd *_Nonnull)splashAd closeMode:(MentaSplashAdCloseMode)mode {
    NSLog(@"%s %lu", __func__, (unsigned long)mode);
    
}

///  开屏广告曝光
- (void)menta_splashAdDidExpose:(MentaUnifiedSplashAd *_Nonnull)splashAd {
    NSLog(@"%s", __func__);
}


- (void)dealloc {
    NSLog(@"%s", __func__);
}
@end
