//
//  DemoMUNativeViewController.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/9.
//

#import "DemoMUNativeViewController.h"
#import "DemoMUNativeShowInViewViewController.h"
#import "DemoMUNativeShowInScrollViewController.h"
#import "DemoMUNativeShowInTableViewController.h"

#import <Masonry/Masonry.h>
#import <SDWebImage/SDWebImage.h>

#import <MentaUnifiedSDK/MentaUnifiedSDK-umbrella.h>

@interface DemoMUNativeViewController ()

@end
@implementation DemoMUNativeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton * btnShowInView = [UIButton buttonWithType:UIButtonTypeSystem];
    btnShowInView.frame = CGRectMake(100, 200, 200, 80);
    [btnShowInView setTitle:@"展现广告在self.view中" forState:UIControlStateNormal];
    [btnShowInView addTarget:self action:@selector(showAdInSelf_view) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnShowInView];
    
    
    UIButton * btnShowInScrollView = [UIButton buttonWithType:UIButtonTypeSystem];
    btnShowInScrollView.frame = CGRectMake(100, 300, 200, 80);
    [btnShowInScrollView setTitle:@"展现广告在ScrollView中" forState:UIControlStateNormal];
    [btnShowInScrollView addTarget:self action:@selector(showInScrollView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnShowInScrollView];
    
    UIButton * btnShowInTableView = [UIButton buttonWithType:UIButtonTypeSystem];
    btnShowInTableView.frame = CGRectMake(100, 400, 200, 80);
    [btnShowInTableView setTitle:@"展现广告在TableView中" forState:UIControlStateNormal];
    [btnShowInTableView addTarget:self action:@selector(showInTableView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnShowInTableView];
}


- (void)showAdInSelf_view {
    
    DemoMUNativeShowInViewViewController *vc = [[DemoMUNativeShowInViewViewController alloc]init];
    [self.navigationController pushViewController:vc animated:YES];
    
}

- (void)showInScrollView {
    
    DemoMUNativeShowInScrollViewController *vc = [[DemoMUNativeShowInScrollViewController alloc]init];
    [self.navigationController pushViewController:vc animated:YES];

}

- (void)showInTableView {
    DemoMUNativeShowInTableViewController *vc = [[DemoMUNativeShowInTableViewController alloc]init];
    [self.navigationController pushViewController:vc animated:YES];

}

@end
