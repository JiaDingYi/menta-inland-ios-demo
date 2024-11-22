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

    /**
     appId: A0049
     appKey: 11c1a2fda74fc3243fc935368aae3e5d
     splashID: P0105

     */
    
    
    [MUAPI enableLog:YES];

    
    // IDFA
    [MUAPI canUseIDFA:YES];
    /*
     canUseIDFA = NO 需要外部传入 IDFA
    [MUAPI canUseIDFA:NO];
    [MUAPI setCustomIDFA:@"TEST MU IDFA"];
    */
    
    
    
    
    /** !!!!!!!!!
     iOS ua 为系统全局属性, 项目中任何一个三方库,只要更改了ua, 项目里所有获取的ua的地方, 得到的都是更改后的ua,为避免此情况, 开发者需根据自身情况获取原始ua 然后原始ua传入SDK
     iOS ua 为系统全局属性, 项目中任何一个三方库,只要更改了ua, 项目里所有获取的ua的地方, 得到的都是更改后的ua,为避免此情况, 开发者需根据自身情况获取原始ua 然后原始ua传入SDK
     iOS ua 为系统全局属性, 项目中任何一个三方库,只要更改了ua, 项目里所有获取的ua的地方, 得到的都是更改后的ua,为避免此情况, 开发者需根据自身情况获取原始ua 然后原始ua传入SDK
     iOS ua 为系统全局属性, 项目中任何一个三方库,只要更改了ua, 项目里所有获取的ua的地方, 得到的都是更改后的ua,为避免此情况, 开发者需根据自身情况获取原始ua 然后原始ua传入SDK
     iOS ua 为系统全局属性, 项目中任何一个三方库,只要更改了ua, 项目里所有获取的ua的地方, 得到的都是更改后的ua,为避免此情况, 开发者需根据自身情况获取原始ua 然后原始ua传入SDK
     iOS ua 为系统全局属性, 项目中任何一个三方库,只要更改了ua, 项目里所有获取的ua的地方, 得到的都是更改后的ua,为避免此情况, 开发者需根据自身情况获取原始ua 然后原始ua传入SDK
     iOS ua 为系统全局属性, 项目中任何一个三方库,只要更改了ua, 项目里所有获取的ua的地方, 得到的都是更改后的ua,为避免此情况, 开发者需根据自身情况获取原始ua 然后原始ua传入SDK
     */
    [MUAPI setCustomUA:@"强烈建议传入原始UA 不然非常影响填充率和收益, 注意是最原始的UA,不要拼接包名等任何东西, 客户端可以在程序启动的时候先获取原始ua 再缓存本地,然后传入 MUAPI中,"];

    [MUAPI setPolluxValues:@[@{ @"version": @"20230330", @"caid": @"75c7bc3754b3019c135b526cb8eb4420" }, @{ @"version": @"20220111", @"caid": @"8799abe1c76805fab06ee3f98a3f704e" }]];
    [MUAPI setUserInfoWith:@"12dsad" age:13 gender:MVUserGenderMale consumeLevel:MVUserConsumeLevelHigh];


    NSLog(@"MentaUnifiedSDK VERSION:%@", [MUAPI sdkVersion]);
    [MUAPI startWithAppID:@"A0049" appKey:@"11c1a2fda74fc3243fc935368aae3e5d" finishBlock:^(BOOL success, NSError * _Nullable error) {
        
    }];
}



@end
