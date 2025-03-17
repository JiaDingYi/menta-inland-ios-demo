//
//  DemoMURewardViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2023/12/20.
//

#import "DemoBaseViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK-umbrella.h>

@interface DemoMURewardViewController : DemoBaseViewController <MentaUnifiedRewardVideoDelegate>
@property (nonatomic, strong) MentaUnifiedRewardVideoAd *rewardVideoAd;
@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnShow;
@property (nonatomic, strong) UIButton *btnBidSuccess;
@property (nonatomic, strong) UIButton *btnBidFail;
@property (nonatomic, assign) BOOL  isLoded;

@end

@implementation DemoMURewardViewController

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
    [self appendLog:@"开始加载激励视频广告"];
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
    [self.rewardVideoAd loadAd];
}

- (void)showAd {
    if (!_isLoded) {
        [self appendLog:@"广告物料未加载成功"];
        return;
    }
    
    if (self.rewardVideoAd.isAdValid) {
        [self.rewardVideoAd showAdFromRootViewController:self];
    }
}

- (void)sendWinNotification {
    [self.rewardVideoAd sendWinNotification];
}

- (void)sendLossNotification {
    // 如果MentaSDK 竞价失败, 则调用此方法将您胜出的价格传给我们
    [self.rewardVideoAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32/*请填写胜出价格*/)}];
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingRewardVideoADPolicy:(MentaUnifiedRewardVideoAd *)rewardVideoAd {
    [self appendLog:@"激励视频策略加载成功"];
}

/// 激励视频广告数据拉取成功
- (void)menta_rewardVideoAdDidLoad:(MentaUnifiedRewardVideoAd *)rewardVideoAd {
    [self appendLog:@"激励视频广告加载成功"];
}

/// 激励视频广告视频下载成功
- (void)menta_rewardVideoAdMaterialDidLoad:(MentaUnifiedRewardVideoAd *)rewardVideoAd {
    [self appendLog:@"激励视频物料加载成功"];
    _isLoded = YES;
}

/// 激励视频加载失败
- (void)menta_rewardVideoAd:(MentaUnifiedRewardVideoAd *)rewardVideoAd didFailWithError:(NSError *)error description:(NSDictionary *)description {
    [self appendLog:[NSString stringWithFormat:@"激励视频加载失败：%@", error.localizedDescription]];
}

/// 激励视频广告被点击了
- (void)menta_rewardVideoAdDidClick:(MentaUnifiedRewardVideoAd *)rewardVideoAd {
    [self appendLog:@"激励视频被点击"];
}

/// 激励视频广告关闭了
- (void)menta_rewardVideoAdDidClose:(MentaUnifiedRewardVideoAd *)rewardVideoAd closeMode:(MentaRewardVideoAdCloseMode)mode {
    [self appendLog:[NSString stringWithFormat:@"激励视频关闭，关闭模式：%lu", (unsigned long)mode]];
}

/// 激励视频将要展现
- (void)menta_rewardVideoAdWillVisible:(MentaUnifiedRewardVideoAd *)rewardVideoAd {
    [self appendLog:@"激励视频即将展示"];
}

/// 激励视频广告曝光
- (void)menta_rewardVideoAdDidExpose:(MentaUnifiedRewardVideoAd *)rewardVideoAd {
    [self appendLog:@"激励视频曝光"];
}

/// 激励视频广告播放达到激励条件回调
- (void)menta_rewardVideoAdDidRewardEffective:(MentaUnifiedRewardVideoAd *)rewardVideoAd {
    [self appendLog:@"激励视频达到激励条件"];
}

/// 激励视频广告播放完成回调
- (void)menta_rewardVideoAdDidPlayFinish:(MentaUnifiedRewardVideoAd *)rewardVideoAd {
    NSLog(@"%s", __func__);
    [self appendLog:@"激励视频播放完成"];
}

/// 激励视频广告 展现的广告信息 曝光之前会触发该回调
- (void)menta_rewardVideoAd:(MentaUnifiedRewardVideoAd *)rewardVideoAd bestTargetSourcePlatformInfo:(NSDictionary *)info {
    [self appendLog:[NSString stringWithFormat:@"激励视频广告信息：%@", info]];
}

- (void)reportAdExposureFailed:(MentaAdExposureFailureCode)failureCode reportParam:(MentaAdExposureReportParam *)reportParam {
    [self appendLog:[NSString stringWithFormat:@"快手竞价失败，code: %ld, winner: %ld, adnType: %ld, winEcpm: %ld", failureCode, reportParam.adnName, reportParam.adnType, reportParam.winEcpm]];
}

- (void)dealloc {
    NSLog(@"%s",__func__);
}

@end
