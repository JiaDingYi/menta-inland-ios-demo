//
//  DemoMUNativeShowInTableViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/10.
//

#import "DemoMUNativeShowInTableViewController.h"
#import "DemoMUNativeTableViewCell.h"
#import "DemoNormalModel.h"

#import <Masonry/Masonry.h>
#import <SDWebImage/SDWebImage.h>

#import <MentaUnifiedSDK/MentaUnifiedSDK-umbrella.h>

@interface DemoMUNativeShowInTableViewController ()<UITableViewDelegate, UITableViewDataSource,MentaUnifiedNativeAdDelegate>
@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, assign) BOOL isLoded;

@property (nonatomic, strong) MentaUnifiedNativeAd *nativeAd;

@property (nonatomic, strong) MentaNativeObject *nativeObject; // 总object: adData + adView
@property (nonatomic, strong) UIView<MentaNativeAdViewProtocol>   *nativeAdView; // adView
@property (nonatomic, strong) MentaNativeAdDataObject *nativeAdData; // adData


// tableView
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *demoArray;


// 自定义广告adview的控件
@property (nonatomic, strong) UIImageView *imageMaterial;
@property (nonatomic, strong) UIImageView *imageIcon;
@property (nonatomic, strong) UIImageView *imageMvlionIcon;
@property (nonatomic, strong) UILabel *labTitle;
@property (nonatomic, strong) UILabel *labDesc;
@property (nonatomic, strong) UILabel *labPrice;
@property (nonatomic, strong) UILabel *labClose;

@end

@implementation DemoMUNativeShowInTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    
    
    NSString *feedPath = [[NSBundle mainBundle] pathForResource:@"feedInfo" ofType:@"cactus"];
    NSString *s = [NSString stringWithContentsOfFile:feedPath encoding:NSUTF8StringEncoding error:nil];
    NSArray *datas = [self objectFromJSONStringWith:s];

    // 数据
    self.demoArray = [NSMutableArray new];
    for (NSDictionary *dict in datas) {
        DemoNormalModel *model = [[DemoNormalModel alloc]initWithDict:dict];
       [self.demoArray addObject:model];
    }

    [self.view addSubview:self.tableView];
    self.tableView.frame = self.view.bounds;


    
    
    
    
    
    
    
    self.btnLoad = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnLoad.frame = CGRectMake(100, 100, 100, 80);
    [self.btnLoad setTitle:@"加载广告" forState:UIControlStateNormal];
    [self.btnLoad addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.btnLoad];
    
    UIButton * btnShow = [UIButton buttonWithType:UIButtonTypeSystem];
    btnShow.frame = CGRectMake(100, 200, 200, 80);
    [btnShow setTitle:@"展现广告在TableView中" forState:UIControlStateNormal];
    [btnShow addTarget:self action:@selector(showInTableView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnShow];
    
    
    
    self.tableView = [[UITableView alloc] init];
    self.tableView.frame = CGRectMake(0, CGRectGetMaxY(btnShow.frame), self.view.frame.size.width, self.view.frame.size.height - CGRectGetMaxY(btnShow.frame));
    self.tableView.backgroundColor = [UIColor lightGrayColor];
    self.tableView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    
    [self.view addSubview:self.tableView];
    

}


- (void)loadAd {
    if (self.nativeAd || self.nativeObject) {
        self.nativeAd.delegate = nil;
        self.nativeAd = nil;
        

        [self.demoArray removeObject:self.nativeObject];
        [self.tableView reloadData];
        
    }

    MUNativeConfig *config = [MUNativeConfig new];
    config.slotId = @"P0250";
    config.viewController = self;
    config.tolerateTime = 30;
    
    _nativeAd = [[MentaUnifiedNativeAd alloc] initWithConfig:config];
    _nativeAd.delegate = self;
    
    [_nativeAd loadAd];

}


- (void)showInTableView {
    if (!self.isLoded || !self.nativeObject) {
        NSLog(@"请先加载广告");
        return;
    }
        
    // 创建自定义信息流View
    [self addCustomViews];
    [self setAdData];
    [self createCustomNativeViewWithObj:self.nativeObject];

    if (![self.demoArray containsObject:self.nativeObject]) {
        // 插入数组 初始状态可见
        [self.demoArray insertObject:self.nativeObject atIndex:2];
        // 插入数组 初始状态不可见
//        [self.demoArray insertObject:self.nativeObject atIndex:9];
    }
    [self.tableView reloadData];


}

#pragma mark - UITableView
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.demoArray.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    // The ad cell provider knows the height of ad cells based on its configuration
    CGFloat resultHeight = 0;
    NSUInteger index = indexPath.row;
    NSObject *obj = self.demoArray[index];
    
    if ([obj isKindOfClass:[DemoNormalModel class]]){
        resultHeight = [(DemoNormalModel *)obj cellHeight];
        
    } else if ([obj isKindOfClass:[MentaNativeObject class]]) {
        resultHeight = 200;
    }
    return resultHeight;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    NSObject *obj = self.demoArray[indexPath.row];
    
    if ([obj isKindOfClass:[DemoNormalModel class]]) {
        
        static NSString *SimpleTableIdentifier = @"SimpleTableIdentifier";
        DemoMUNativeTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:SimpleTableIdentifier];
        if (cell == nil) {
            cell = [[DemoMUNativeTableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:SimpleTableIdentifier];
        }
        cell.model = self.demoArray[indexPath.row];
        
        return cell;

    } else {
        static NSString *SimpleTableIdentifier = @"NativeAdCell";
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:SimpleTableIdentifier];
        if (cell == nil) {
            cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:SimpleTableIdentifier];
        }
        cell.frame = CGRectMake(0, 0, tableView.bounds.size.width, 200);
        cell.contentView.backgroundColor = [UIColor blueColor];
        [[cell.contentView viewWithTag:1001] removeFromSuperview];
        [cell.contentView addSubview:self.nativeAdView];
        
        // frame
        self.nativeAdView.frame = cell.contentView.bounds;

        // masonry
//        [self.nativeAdView mas_makeConstraints:^(MASConstraintMaker *make) {
//            make.top.equalTo(@(0));
//            make.left.equalTo(@10);
//            make.right.equalTo(@(-10));
//            make.bottom.equalTo(@0);
//        }];


        return cell;
    }
    
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
}



#pragma mark - MentaUnifiedNativeAdDelegate
/// 广告策略服务加载成功
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedNativeAd *_Nonnull)nativeAd {
    NSLog(@"%s", __func__);
}

/// 广告数据回调
- (void)menta_nativeAdLoaded:(NSArray<MentaNativeObject *> *)unifiedNativeAdDataObjects nativeAd:(MentaUnifiedNativeAd *)nativeAd {
    NSLog(@"%s", __func__);
    MentaNativeObject *nativeObject = unifiedNativeAdDataObjects.firstObject;
    self.nativeObject = nativeObject;
    self.nativeAdView = nativeObject.nativeAdView;
    self.nativeAdData = nativeObject.dataObject;
    self.nativeAdView.tag = 1001;
    self.isLoded = YES;
    
    [self showInTableView];
}

/// 信息流自渲染加载失败
- (void)menta_nativeAd:(MentaUnifiedNativeAd *_Nonnull)nativeAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description {
    
}

/**
 广告曝光回调,
 @param nativeAd MentaUnifiedNativeAd 实例,
 @param adView 广告View
 */
- (void)menta_nativeAdViewWillExpose:(MentaUnifiedNativeAd *)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *)adView {
    NSLog(@"%s", __func__);
    [adView.mentaMediaView muteEnable:NO];
}


/**
 广告点击回调,

 @param nativeAd MentaUnifiedNativeAd 实例,
 */
- (void)menta_nativeAdViewDidClick:(MentaUnifiedNativeAd *_Nullable)nativeAd adView:(UIView *_Nullable)adView {
    NSLog(@"%s", __func__);
}

/**
 广告点击关闭回调 UI的移除和数据的解绑 需要在该回调中进行

 @param nativeAd MentaUnifiedNativeAd 实例,
 */
- (void)menta_nativeAdDidClose:(MentaUnifiedNativeAd *)nativeAd adView:(UIView<MentaNativeAdViewProtocol> *)adView {
    NSLog(@"%s", __func__);
    [adView.mentaMediaView stop];
    [self.demoArray removeObject:self.nativeObject];
    [self.tableView reloadData];
}


/**
 广告详情页面即将展示回调, 当广告位落地页广告时会触发

 @param nativeAd MentaUnifiedNativeAd 实例,
 */
- (void)menta_nativeAdDetailViewWillPresentScreen:(MentaUnifiedNativeAd *_Nullable)nativeAd adView:(UIView *_Nonnull)adView {
    NSLog(@"%s", __func__);
}


/**
 广告详情页关闭回调,即落地页关闭回调, 当关闭弹出的落地页时 触发

 @param nativeAd MentaUnifiedNativeAd 实例,
 */
- (void)menta_nativeAdDetailViewClosed:(MentaUnifiedNativeAd *_Nullable)nativeAd adView:(UIView *_Nonnull)adView {
    NSLog(@"%s", __func__);
}

#pragma 很重要
- (void)dealloc {
    NSLog(@"%s",__func__);
}


// 创建自定义view
- (void)createCustomNativeViewWithObj:(MentaNativeObject *)object {

    // 初始状态可见
    self.nativeAdView.frame = CGRectMake(10, 50, self.view.frame.size.width - 20, 200);
    self.nativeAdView.backgroundColor = [UIColor grayColor];
    self.nativeAdView.tag = 1001;

    // 必须调用
    if (self.nativeAdData.isVideo) {
        [self.nativeObject registerClickableViews:@[self.nativeAdView.mentaMediaView] closeableViews:@[self.labClose]];
    } else {
        [self.nativeObject registerClickableViews:@[self.imageMaterial] closeableViews:@[self.labClose]];
    }
    
    [self addCustomViews];
    [self setAdData];
    
}

- (void)setAdData {
    self.labClose.text = @"点我触发关闭回调";
    self.labTitle.text = [NSString stringWithFormat:@"title: %@", self.nativeAdData.title];
    self.labDesc.text = [NSString stringWithFormat:@"desc: %@", self.nativeAdData.desc];
    self.labPrice.text = [NSString stringWithFormat:@"price: %@", self.nativeAdData.price];
    
    [self.imageIcon sd_setImageWithURL:[NSURL URLWithString:self.nativeAdData.iconUrl]
                 placeholderImage:nil];
    
    MentaNativeAdMaterialObject *material = self.nativeAdData.materialList.firstObject;
    [self.imageMaterial sd_setImageWithURL:[NSURL URLWithString:material.materialUrl]];
    
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
    // frame
    /*
    self.imageMaterial.frame = CGRectMake(0, 0, 100, 200);
    self.imageIcon.frame = CGRectMake(110, 0, 50, 50);
    self.imageMvlionIcon.frame = CGRectMake(self.nativeAdView.bounds.size.width - self.nativeAdData.adIcon.size.width, 0, self.nativeAdData.adIcon.size.width, self.nativeAdData.adIcon.size.height);
    self.labTitle.frame = CGRectMake(110, 60, 250, 30);
    self.labDesc.frame = CGRectMake(110, 100, 250, 30);
    self.labPrice.frame = CGRectMake(110, 140, 250, 30);
    self.labClose.frame = CGRectMake(self.nativeAdView.bounds.size.width - 100, self.nativeAdView.bounds.size.height - 50, 100, 50);
    */
    // masonry
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

    [self.labClose mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(self.nativeAdView);
        make.width.equalTo(@100);
        make.height.equalTo(@50);
        make.right.equalTo(self.nativeAdView);
    }];

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


- (id)objectFromJSONStringWith:(NSString *)s {
    NSData *data = [s dataUsingEncoding:NSUTF8StringEncoding];
    return [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:nil];
}

@end
