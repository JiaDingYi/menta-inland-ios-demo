//
//  DemoMVNativeExpressShowInTableViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/19.
//

#import "DemoMUNativeExpressShowInTableViewController.h"
#import "DemoMVNativeTableViewCell.h"
#import "DemoNormalModel.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>

@interface DemoMUNativeExpressShowInTableViewController ()<UITableViewDelegate, UITableViewDataSource, MentaUnifiedNativeExpressAdDelegate>
@property (nonatomic, strong) MentaUnifiedNativeExpressAd *nativeExpressAd;
@property (nonatomic, strong) MentaUnifiedNativeExpressAdObject *object;
@property (nonatomic) CGSize adSize;

@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, assign) BOOL isLoded;

// tableView
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *demoArray;

@end

@implementation DemoMUNativeExpressShowInTableViewController

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
    if (self.nativeExpressAd) {
        [self.nativeExpressAd destory];
        self.nativeExpressAd.delegate = nil;
        self.nativeExpressAd = nil;
    }
    self.adSize = CGSizeMake(self.view.frame.size.width - 20, 300);
    MUNativeExpressConfig *config = [[MUNativeExpressConfig alloc] init];
    config.adSize = self.adSize;
    config.slotId = @"P0299";
    config.materialFillMode = MentaNativeExpressAdMaterialFillMode_ScaleAspectFill;

    self.nativeExpressAd = [[MentaUnifiedNativeExpressAd alloc] initWithConfig:config];
    self.nativeExpressAd.delegate = self;

    [self.nativeExpressAd loadAd];

}



- (void)showInTableView {
    if (!self.isLoded || !self.nativeExpressAd) {
        NSLog(@"请先加载广告");
        return;
    }
        

}


- (id)objectFromJSONStringWith:(NSString *)s {
    NSData *data = [s dataUsingEncoding:NSUTF8StringEncoding];
    return [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:nil];
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
        
    } else if ([obj isKindOfClass:[MentaUnifiedNativeExpressAdObject class]]) {
        resultHeight = self.object.expressView.bounds.size.height;
    }
    return resultHeight;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    NSObject *obj = self.demoArray[indexPath.row];
    
    if ([obj isKindOfClass:[DemoNormalModel class]]) {
        
        static NSString *SimpleTableIdentifier = @"SimpleTableIdentifier";
        DemoMVNativeTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:SimpleTableIdentifier];
        if (cell == nil) {
            cell = [[DemoMVNativeTableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:SimpleTableIdentifier];
        }
        cell.model = self.demoArray[indexPath.row];
        
        return cell;

    } else {
        static NSString *SimpleTableIdentifier = @"NativeAdCell";
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:SimpleTableIdentifier];
        if (cell == nil) {
            cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:SimpleTableIdentifier];
        }
        cell.frame = CGRectMake(0, 0, tableView.bounds.size.width, self.object.expressView.bounds.size.height);
        
        cell.contentView.backgroundColor = [UIColor blueColor];
        [[cell.contentView viewWithTag:1001] removeFromSuperview];
        [cell.contentView addSubview:self.object.expressView];
        
        // frame self.adSize =  CGSizeMake(self.view.frame.size.width - 20, 200);  所以x = 10 widith = size.width - 20
        self.object.expressView.frame = CGRectMake(10, 0, self.adSize.width, self.object.expressView.bounds.size.height);

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
/// 广告策略服务加载成功
- (void)menta_didFinishLoadingADPolicy:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd{
    NSLog(@"%s", __func__);
}

/**
 广告数据回调
 @param unifiedNativeAdDataObjects 广告数据数组
 */
- (void)menta_nativeExpressAdLoaded:(NSArray<MentaUnifiedNativeExpressAdObject *> * _Nullable)unifiedNativeAdDataObjects nativeExpressAd:(MentaUnifiedNativeExpressAd * _Nonnull)nativeExpressAd{
    
    NSLog(@"%s", __func__);
    NSLog(@"price字段为NSNumber类型 price:%@", unifiedNativeAdDataObjects.firstObject.price);
    
    
}


/**
信息流广告加载失败
@param nativeExpressAd MentaUnifiedNativeExpressAd 实例,
@param error 错误
*/
- (void)menta_nativeExpressAd:(MentaUnifiedNativeExpressAd *_Nonnull)nativeExpressAd didFailWithError:(NSError * _Nullable)error description:(NSDictionary *_Nonnull)description{
    NSLog(@"%s", __func__);
}

/**
 信息流渲染成功
 */
- (void)menta_nativeExpressAdViewRenderSuccess:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj {
    NSLog(@"%s", __func__);
    
    if (nativeExpressAdObj) {
        self.object = nativeExpressAdObj;
        self.object.expressView.tag = 1001;
        [self.demoArray addObject:self.object];
        [self.tableView reloadData];
    }
    

    [self.nativeExpressAd sendLossNotificationWithInfo:@{MU_M_L_WIN_PRICE : @(32)}];

}

/**
 信息流渲染失败
 */
- (void)nativeExpressAdViewRenderFail:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    NSLog(@"%s", __func__);
}

/**
 广告曝光回调
 */
- (void)menta_nativeExpressAdViewWillExpose:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    NSLog(@"%s", __func__);
}


/**
 广告点击回调,
 */
- (void)menta_nativeExpressAdViewDidClick:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    NSLog(@"%s", __func__);
}

/**
 广告点击关闭回调
 */
- (void)menta_nativeExpressAdDidClose:(MentaUnifiedNativeExpressAd *)nativeExpressAd nativeExpressAdObject:(MentaUnifiedNativeExpressAdObject *)nativeExpressAdObj{
    NSLog(@"%s", __func__);
    [self destroy];
}

- (void)destroy {
    [self.nativeExpressAd destory];
    self.nativeExpressAd.delegate = nil;
    self.nativeExpressAd = nil;
}

- (void)dealloc {
    NSLog(@"%s", __func__);
    [self destroy];
}

@end
