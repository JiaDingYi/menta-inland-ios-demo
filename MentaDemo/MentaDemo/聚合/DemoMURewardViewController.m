//
//  DemoMURewardViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2023/12/20.
//

#import "DemoMURewardViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>

@interface DemoMURewardViewController ()<MentaUnifiedRewardVideoDelegate>
@property (nonatomic, strong) MentaUnifiedRewardVideoAd *rewardVideoAd;
@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnShow;
@property (nonatomic, assign) BOOL  isLoded;

@end

@implementation DemoMURewardViewController

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
    if (self.rewardVideoAd) {
        [self.rewardVideoAd destory];
        self.rewardVideoAd.delegate = nil;
        self.rewardVideoAd = nil;
    }
    
    MURewardVideoConfig *config = [[MURewardVideoConfig alloc] init];
    config.adSize = UIScreen.mainScreen.bounds.size;
    config.slotId = @"P0147";
    config.videoGravity = MentaRewardVideoAdViewGravity_ResizeAspect;
//    MentaRewardVideoAdViewGravity_ResizeAspect,      // 等比例填充至屏幕内, 上下 或 左右 可能留黑, 但视频宽高比例不变, 不会裁剪视频  //默认
//    MentaRewardVideoAdViewGravity_ResizeAspectFill,  // 等比例填充纸屏幕内, 四周不会留黑, 视频宽高比保持不变, 但会裁剪视频
//    MentaRewardVideoAdViewGravity_Resize,            // 视频拉伸至屏幕边缘, 四周不会留黑, 视频宽高比会发生变化, 不会裁剪视频

    self.rewardVideoAd = [[MentaUnifiedRewardVideoAd alloc] initWithConfig:config];
    self.rewardVideoAd.delegate = self;
//    self.rewardVideoAd.orientation = MentaRewardVideoAdViewInterfaceOrientation_Portrait;
    [self.rewardVideoAd loadAd];

}

- (void)showAd {
    
    if (!_isLoded) {
        NSLog(@"广告物料未加载成功");
        return;
    }
    
    [self.rewardVideoAd showAdFromRootViewController:self];
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingRewardVideoADPolicy:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd {
    NSLog(@"%s", __func__);
}

/// 激励视频广告数据拉取成功
- (void)menta_rewardVideoAdDidLoad:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd {
    NSLog(@"%s", __func__);
}

/// 激励视频广告视频下载成功
- (void)menta_rewardVideoAdMaterialDidLoad:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd {
    NSLog(@"%s", __func__);
    _isLoded = YES;
    [self showAd];
}

/// 激励视频加载失败
- (void)menta_rewardVideoAd:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description {
    NSLog(@"%s\r\nerror: %@\r\ndescription: %@", __func__, error, description);
}

/// 激励视频广告被点击了
- (void)menta_rewardVideoAdDidClick:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd {
    NSLog(@"%s", __func__);
}

/// 激励视频广告关闭了
- (void)menta_rewardVideoAdDidClose:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd closeMode:(MentaRewardVideoAdCloseMode)mode {
    NSLog(@"%s %lu", __func__, mode);
}

/// 激励视频将要展现
- (void)menta_rewardVideoAdWillVisible:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd {
    NSLog(@"%s", __func__);
}

/// 激励视频广告曝光
- (void)menta_rewardVideoAdDidExpose:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd {
    NSLog(@"%s", __func__);
}

/// 激励视频广告播放达到激励条件回调
- (void)menta_rewardVideoAdDidRewardEffective:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd {
    NSLog(@"%s", __func__);
}

/// 激励视频广告播放完成回调
- (void)menta_rewardVideoAdDidPlayFinish:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd {
    NSLog(@"%s", __func__);
}

/// 激励视频广告 展现的广告信息 曝光之前会触发该回调
- (void)menta_rewardVideoAd:(MentaUnifiedRewardVideoAd *_Nonnull)rewardVideoAd bestTargetSourcePlatformInfo:(NSDictionary *_Nonnull)info {
    NSLog(@"%s info(info当中的BEST_SOURCE_PRICE字段为NSNumber类型)该回调会在menta_rewardVideoAdMaterialDidLoad前触发:%@", __func__, info);

    [self.rewardVideoAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32)}];
}

- (void)dealloc {
    NSLog(@"%s",__func__);
}


@end
