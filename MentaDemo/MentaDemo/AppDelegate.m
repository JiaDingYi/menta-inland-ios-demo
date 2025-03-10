//
//  AppDelegate.m
//  MentaDemo
//
//  Created by iMacMe on 2023/11/28.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <AdSupport/AdSupport.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>

#import <MentaUnifiedSDK/MentaUnifiedSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    ViewController *vc = [[ViewController alloc] init];
    UINavigationController *navc = [[UINavigationController alloc] initWithRootViewController:vc];
    self.window.rootViewController = navc;
    [self.window makeKeyAndVisible];

    [self setUpMentaSDK];
    return YES;
}

- (void)setUpMentaSDK {
    [MUAPI enableLog:YES];
    // IDFA
    [MUAPI canUseIDFA:YES];
    /*
     canUseIDFA = NO 需要外部传入 IDFA
    [MUAPI canUseIDFA:NO];
    [MUAPI setCustomIDFA:@"TEST MU IDFA"];
    */
    
    [MUAPI setPolluxValues:@[@"20230330_75c7bc3754b3019c135b526cb8eb4420", @"20220111_8799abe1c76805fab06ee3f98a3f704e"]];
    [MUAPI setUserInfoWith:@"12dsad" age:13 gender:MVUserGenderMale consumeLevel:MVUserConsumeLevelHigh];
    NSLog(@"MentaUnifiedSDK VERSION:%@", [MUAPI sdkVersion]);
    [MUAPI startWithAppID:@"A0049" appKey:@"11c1a2fda74fc3243fc935368aae3e5d" finishBlock:^(BOOL success, NSError * _Nullable error) {
        
    }];
}

@end
