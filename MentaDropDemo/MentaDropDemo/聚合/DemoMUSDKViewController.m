//
//  DemoMUSDKViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2023/11/27.
//

#import "DemoMUSDKViewController.h"
#import <MentaUnifiedSDK/MentaUnifiedSDK.h>
@interface DemoMUSDKViewController ()<UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *demoArray;

@end

@implementation DemoMUSDKViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    
    
    self.demoArray = [@[
        @[@"瑞狮聚合SDK 开屏", @"DemoMUSplashViewController"],
        @[@"瑞狮聚合SDK 激励视频", @"DemoMURewardViewController"],
        @[@"瑞狮聚合SDK 插屏", @"DemoMUInterstitialViewController"],
        @[@"瑞狮聚合SDK 横幅(banner)", @"DemoMUBannerViewController"],
        @[@"瑞狮聚合SDK 信息流模版渲染", @"DemoMUNativeExpressViewController"],
        @[@"瑞狮聚合SDK 信息流自渲染", @"DemoMUNativeViewController"],
        
                        ] mutableCopy];

    [self.view addSubview:self.tableView];
    self.tableView.frame = self.view.bounds;

}


#pragma mark - UITableView
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.demoArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *SimpleTableIdentifier = @"SimpleTableIdentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:SimpleTableIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:SimpleTableIdentifier];
    }
    cell.textLabel.text = self.demoArray[indexPath.row][0];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    id item = self.demoArray[indexPath.row][1];
    if ([item isKindOfClass:[NSString class]]) {
        UIViewController *vc = [[NSClassFromString(item) alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
    }
}


- (UITableView *)tableView
{
    if (!_tableView) {
        _tableView = [[UITableView alloc] init];
        _tableView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.accessibilityIdentifier = @"tableView_id";
    }
    return _tableView;
}


@end

