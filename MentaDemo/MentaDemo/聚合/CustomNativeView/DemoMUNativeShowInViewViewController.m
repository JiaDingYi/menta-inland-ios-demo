//
//  DemoMUNativeShowInViewViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/10.
//

#import "DemoBaseViewController.h"
#import <Masonry/Masonry.h>
#import <SDWebImage/SDWebImage.h>
#import <MentaUnifiedSDK/MentaUnifiedSDK-umbrella.h>

@interface DemoMUNativeShowInViewViewController : DemoBaseViewController <MentaUnifiedNativeAdDelegate>
@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnBidSuccess;
@property (nonatomic, strong) UIButton *btnBidFail;
@property (nonatomic, strong) UIButton *btnShowNextVc;
@property (nonatomic, assign) BOOL isLoded;

@property (nonatomic, strong) MentaUnifiedNativeAd *nativeAd;

@property (nonatomic, strong) MentaNativeObject *nativeObject; // 总object: adData + adView
@property (nonatomic, strong) UIView<MentaNativeAdViewProtocol> *nativeAdView; // adView
@property (nonatomic, strong) MentaNativeAdDataObject *nativeAdData; // adData

// 自定义广告adview的控件
@property (nonatomic, strong) UIImageView *imageMaterial;
@property (nonatomic, strong) UIImageView *imageIcon;
@property (nonatomic, strong) UIImageView *imageMvlionIcon;
@property (nonatomic, strong) UILabel *labTitle;
@property (nonatomic, strong) UILabel *labDesc;
@property (nonatomic, strong) UILabel *labPrice;
@property (nonatomic, strong) UILabel *labClose;

@end

@implementation DemoMUNativeShowInViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];

    self.btnLoad = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnLoad.frame = CGRectMake(100, 100, 200, 30);
    [self.btnLoad setTitle:@"加载广告" forState:UIControlStateNormal];
    self.btnLoad.backgroundColor = [UIColor blackColor];
    [self.btnLoad setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnLoad.layer.cornerRadius = 10;
    self.btnLoad.layer.masksToBounds = YES;
    [self.btnLoad addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnLoad];
    
    UIButton * btnShowInView = [UIButton buttonWithType:UIButtonTypeSystem];
    btnShowInView.frame = CGRectMake(100, 150, 200, 30);
    [btnShowInView setTitle:@"展现广告在self.view中" forState:UIControlStateNormal];
    btnShowInView.backgroundColor = [UIColor blackColor];
    [btnShowInView setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    btnShowInView.layer.cornerRadius = 10;
    btnShowInView.layer.masksToBounds = YES;
    [btnShowInView addTarget:self action:@selector(showAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnShowInView];
    
    self.btnBidSuccess = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnBidSuccess.frame = CGRectMake(100, 200, 200, 30);
    [self.btnBidSuccess setTitle:@"bid success" forState:UIControlStateNormal];
    self.btnBidSuccess.backgroundColor = [UIColor blackColor];
    [self.btnBidSuccess setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnBidSuccess.layer.cornerRadius = 10;
    self.btnBidSuccess.layer.masksToBounds = YES;
    [self.btnBidSuccess addTarget:self action:@selector(sendWinNotification) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnBidSuccess];
    
    self.btnBidFail = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnBidFail.frame = CGRectMake(100, 250, 200, 30);
    [self.btnBidFail setTitle:@"bid fail" forState:UIControlStateNormal];
    self.btnBidFail.backgroundColor = [UIColor blackColor];
    [self.btnBidFail setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnBidFail.layer.cornerRadius = 10;
    self.btnBidFail.layer.masksToBounds = YES;
    [self.btnBidFail addTarget:self action:@selector(sendLossNotification) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnBidFail];
    
    self.btnShowNextVc = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnShowNextVc.frame = CGRectMake(100, 300, 200, 30);
    [self.btnShowNextVc setTitle:@"show next vc" forState:UIControlStateNormal];
    self.btnShowNextVc.backgroundColor = [UIColor blackColor];
    [self.btnShowNextVc setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnShowNextVc.layer.cornerRadius = 10;
    self.btnShowNextVc.layer.masksToBounds = YES;
    [self.btnShowNextVc addTarget:self action:@selector(showNextVc) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnShowNextVc];
    
    [self setupLogTextView];
}

- (void)loadAd {
    [self appendLog:@"开始加载自渲染广告"];
    if (self.nativeAd || self.nativeObject) {
        self.nativeAd.delegate = nil;
        self.nativeAd = nil;
        self.imageMaterial = nil;
    }
    
    if (self.nativeAdView.superview) {
        [self.nativeAdView removeFromSuperview];
        self.nativeAdView = nil;
    }

    [self appendLog:[NSString stringWithFormat:@"view: %@", self.view]];
    [self appendLog:[NSString stringWithFormat:@"window: %@", self.view.window]];
    [self appendLog:[NSString stringWithFormat:@"rootVC: %@", self.view.window.rootViewController]];

    if (!self.view.window.rootViewController) {
        [self appendLog:@"rootViewController is nil"];
        return;
    }
    MUNativeConfig *config = [MUNativeConfig new];
    config.slotId = @"P0250";
    config.viewController = self;
    config.tolerateTime = 30;
    
    _nativeAd = [[MentaUnifiedNativeAd alloc] initWithConfig:config];
    self.nativeAd.delegate = self;
    [_nativeAd loadAd];
}

- (void)showAd {
    if (!_isLoded) {
        [self appendLog:@"广告物料未加载成功"];
        return;
    }
    // 创建自定义信息流View
    [self createCustomNativeViewWithObj:self.nativeObject];
}

- (void)showNextVc {
    // Show next view controller using navigation controller
    UIViewController *nextViewController = [[UIViewController alloc] init];
    nextViewController.view.backgroundColor = [UIColor whiteColor];
    nextViewController.title = @"Next View Controller";
    
    [self.navigationController pushViewController:nextViewController animated:YES];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    if (self.nativeAdView.mentaMediaView) {
        if (self.nativeAdView.mentaMediaView.videoDuration <= self.nativeAdView.mentaMediaView.videoPlayTime) {
            [self.nativeAdView.mentaMediaView stop];
        } else {
            [self.nativeAdView.mentaMediaView pause];
        }
    }
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    if (self.nativeAdView.mentaMediaView) {
        if (self.nativeAdView.mentaMediaView.videoDuration <= self.nativeAdView.mentaMediaView.videoPlayTime) {
            [self.nativeAdView.mentaMediaView stop];
        }
        
        __weak typeof(self) weakSelf = self;
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            __strong typeof(weakSelf) strongSelf = weakSelf;
            [strongSelf.nativeAdView.mentaMediaView play];
        });
    }
}

- (void)sendWinNotification {
    [self.nativeAd sendWinNotification];
}

- (void)sendLossNotification {
    // 如果MentaSDK 竞价失败, 则调用此方法将您胜出的价格传给我们
    [self.nativeAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32/*请填写胜出价格*/)}];
}

/// 广告策略服务加载成功
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedNativeAd *)nativeAd {
    [self appendLog:@"广告策略加载成功"];
}

/// 广告数据回调
- (void)menta_nativeAdLoaded:(NSArray<MentaNativeObject *> *)unifiedNativeAdDataObjects nativeAd:(MentaUnifiedNativeAd *)nativeAd {
    [self appendLog:@"自渲染广告加载成功"];
    MentaNativeObject *nativeObject = unifiedNativeAdDataObjects.firstObject;
    self.nativeObject = nativeObject;
    self.nativeAdView = nativeObject.nativeAdView;
    self.nativeAdData = nativeObject.dataObject;
    self.isLoded = YES;
}

/// 信息流自渲染加载失败
- (void)menta_nativeAd:(MentaUnifiedNativeAd *)nativeAd didFailWithError:(NSError *)error description:(NSDictionary *)description {
    [self appendLog:[NSString stringWithFormat:@"自渲染广告加载失败：%@", error.localizedDescription]];
}

/**
 广告曝光回调
 */
- (void)menta_nativeAdViewWillExpose:(MentaUnifiedNativeAd *)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *)adView {
    [self appendLog:@"自渲染广告曝光"];
    [adView.mentaMediaView muteEnable:YES];
}

/**
 广告点击回调
 */
- (void)menta_nativeAdViewDidClick:(MentaUnifiedNativeAd *)nativeAd adView:(UIView *)adView {
    [self appendLog:@"自渲染广告被点击"];
}

/**
 广告点击关闭回调
 */
- (void)menta_nativeAdDidClose:(MentaUnifiedNativeAd *)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *)adView {
    [self appendLog:@"自渲染广告关闭"];
    self.imageMaterial = nil;
    [adView.mentaMediaView stop];
    [adView removeFromSuperview];
}

/**
 广告详情页面即将展示回调
 */
- (void)menta_nativeAdDetailViewWillPresentScreen:(MentaUnifiedNativeAd *)nativeAd adView:(UIView *)adView {
    [self appendLog:@"自渲染广告详情页即将展示"];
}

/**
 广告详情页关闭回调
 */
- (void)menta_nativeAdDetailViewClosed:(MentaUnifiedNativeAd *)nativeAd adView:(UIView *)adView {
    [self appendLog:@"自渲染广告详情页关闭"];
}

/**
 信息流自渲染视频播放结束
 */
- (void)menta_nativeAdDidPlayFinished:(MentaUnifiedNativeAd *)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *)adView {
    [self appendLog:@"自渲染广告视频播放完成"];
}

/**
 信息流自渲染视频播放失败
 */
- (void)menta_nativeAdDidPlayFailed:(MentaUnifiedNativeAd *)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *)adView error:(NSError *)error {
    [self appendLog:[NSString stringWithFormat:@"自渲染广告视频播放失败：%@", error.localizedDescription]];
}

- (void)reportAdExposureFailed:(MentaAdExposureFailureCode)failureCode reportParam:(MentaAdExposureReportParam *)reportParam {
    [self appendLog:[NSString stringWithFormat:@"快手竞价失败，code: %ld, winner: %ld, adnType: %ld, winEcpm: %ld", failureCode, reportParam.adnName, reportParam.adnType, reportParam.winEcpm]];
}

- (void)createCustomNativeViewWithObj:(MentaNativeObject *)object {
    self.nativeAdView.frame = CGRectMake(10, self.view.frame.size.height - 500, self.view.frame.size.width - 20, 200);
    self.nativeAdView.backgroundColor = [UIColor grayColor];
    [self.view addSubview:self.nativeAdView];
    
    if (object.dataObject.platform == MentaNativeAdPlatform_MS) {
        // 添加手势
        self.labClose.userInteractionEnabled = YES;
        UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTap:)];
        [self.labClose addGestureRecognizer:tapGesture];
    }
    // 必须调用
    if (self.nativeAdData.isVideo) {
        [self.nativeObject registerClickableViews:@[self.nativeAdView.mentaMediaView, self.labTitle, self.labDesc, self.imageIcon] closeableViews:@[self.labClose]];
    } else {
        [self.nativeObject registerClickableViews:@[self.imageMaterial, self.labTitle, self.labDesc, self.imageIcon] closeableViews:@[self.labClose]];
    }
    
    [self addCustomViews];
    [self setAdData];
}

- (void)handleTap:(UITapGestureRecognizer *)gesture {
    [self appendLog:@"自渲染广告关闭"];
    [self.nativeAdView.mentaMediaView stop];
    [self.nativeAdView removeFromSuperview];
}

- (void)setAdData {
    self.labClose.text = @"点我触发关闭回调";
    self.labTitle.text = [NSString stringWithFormat:@"title: %@", self.nativeAdData.title];
    self.labDesc.text = [NSString stringWithFormat:@"desc: %@", self.nativeAdData.desc];
    self.labPrice.text = [NSString stringWithFormat:@"price: %@", self.nativeAdData.price];
    
    [self.imageIcon sd_setImageWithURL:[NSURL URLWithString:self.nativeAdData.iconUrl]
                 placeholderImage:nil];
    
    if (self.nativeAdData.platform == MentaNativeAdPlatform_SigMob) {
        [self.nativeAdView bindImageView:self.imageMaterial];
    } else {
        MentaNativeAdMaterialObject *material = self.nativeAdData.materialList.firstObject;
        [self.imageMaterial sd_setImageWithURL:[NSURL URLWithString:material.materialUrl]];
    }
    
    self.imageMvlionIcon.image = self.nativeAdData.adIcon;
}

- (void)addCustomViews {
    [self.nativeAdView addSubview:self.imageMaterial];
    if (self.nativeAdData.isVideo) {
        [self.nativeAdView addSubview:self.nativeAdView.mentaMediaView];
        self.imageMaterial.hidden = YES;
        
        [self.nativeAdView.mentaMediaView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.left.bottom.equalTo(self.nativeAdView);
            make.width.equalTo(@(100));
        }];
    } else {
        self.imageMaterial.hidden = NO;
    }
    [self.nativeAdView addSubview:self.imageIcon];
    [self.nativeAdView addSubview:self.imageMvlionIcon];
    [self.nativeAdView addSubview:self.labTitle];
    [self.nativeAdView addSubview:self.labDesc];
    [self.nativeAdView addSubview:self.labPrice];
    [self.nativeAdView addSubview:self.labClose];

    self.labTitle.textColor = [UIColor blackColor];
    self.labDesc.textColor = [UIColor redColor];
    self.labPrice.textColor = [UIColor orangeColor];
    
    self.labClose.backgroundColor = [UIColor blackColor];
    self.labClose.textColor = [UIColor whiteColor];
    self.labClose.numberOfLines = 0;
    
    [self.imageMaterial mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.bottom.equalTo(self.nativeAdView);
        make.width.equalTo(@(100));
    }];
    
    [self.imageIcon mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.imageMaterial.mas_right).offset(10);
        make.top.equalTo(self.nativeAdView);
        make.width.equalTo(@50);
        make.height.equalTo(@50);
    }];

    [self.imageMvlionIcon mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.nativeAdView);
        make.top.equalTo(self.nativeAdView);
        make.width.equalTo(@(self.nativeAdData.adIcon.size.width));
        make.height.equalTo(@(self.nativeAdData.adIcon.size.height));
    }];

    [self.labTitle mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.imageIcon.mas_bottom).offset(10);
        make.width.equalTo(@250);
        make.height.equalTo(@30);
        make.left.equalTo(self.imageIcon);
    }];
    
    [self.labDesc mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.labTitle.mas_bottom).offset(10);
        make.width.equalTo(@250);
        make.height.equalTo(@30);
        make.left.equalTo(self.imageIcon);
    }];
    
    [self.labPrice mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.labDesc.mas_bottom).offset(10);
        make.width.equalTo(@250);
        make.height.equalTo(@30);
        make.left.equalTo(self.imageIcon);
    }];
    
    if (self.nativeAdData.platform == MentaNativeAdPlatform_SigMob) {
        UIView *logogView = (UIView *)self.nativeAdView.logoView;
        [self.nativeAdView addSubview:logogView];
        [logogView mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.top.equalTo(logogView.superview).offset(10);
            make.right.equalTo(logogView.superview).offset(-10);
            make.width.equalTo(@(70));
            make.height.equalTo(@(20));
        }];
        
        [self.nativeAdView addSubview:self.nativeAdView.dislikeButton];
        [self.nativeAdView.dislikeButton bringSubviewToFront:logogView];
        [self.nativeAdView.dislikeButton mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.bottom.equalTo(self.nativeAdView).offset(-10);
            make.right.equalTo(self.nativeAdView).offset(-10);
            make.width.mas_equalTo(15);
            make.height.mas_equalTo(15);
        }];
        
    } else {
        [self.labClose mas_makeConstraints:^(MASConstraintMaker *make) {
            make.bottom.equalTo(self.nativeAdView);
            make.width.equalTo(@100);
            make.height.equalTo(@50);
            make.right.equalTo(self.nativeAdView);
        }];
    }
}

- (UIImageView *)imageMaterial {
    if (!_imageMaterial) {
        _imageMaterial = [UIImageView new];
    }
    return _imageMaterial;
}

- (UIImageView *)imageIcon {
    if (!_imageIcon) {
        _imageIcon = [UIImageView new];
    }
    return _imageIcon;
}

- (UIImageView *)imageMvlionIcon {
    if (!_imageMvlionIcon) {
        _imageMvlionIcon = [UIImageView new];
    }
    return _imageMvlionIcon;
}

- (UILabel *)labClose {
    if (!_labClose) {
        _labClose = [UILabel new];
    }
    return _labClose;
}

- (UILabel *)labTitle {
    if (!_labTitle) {
        _labTitle = [UILabel new];
    }
    return _labTitle;
}

- (UILabel *)labDesc {
    if (!_labDesc) {
        _labDesc = [UILabel new];
    }
    return _labDesc;
}

- (UILabel *)labPrice {
    if (!_labPrice) {
        _labPrice = [UILabel new];
    }
    return _labPrice;
}


#pragma 很重要
- (void)dealloc {
    [self.nativeObject destoryNativeAdView];
}

@end
