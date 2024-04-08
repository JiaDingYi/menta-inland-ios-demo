//
//  MVlionWebViewController.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionWebViewController : UIViewController

@property(nonatomic,copy)void(^closedBlock)(void);

// 默认NO
@property(nonatomic,assign)BOOL hideLeftItems;

- (instancetype)initWithURLString:(NSString *)urlString;

@end

NS_ASSUME_NONNULL_END
