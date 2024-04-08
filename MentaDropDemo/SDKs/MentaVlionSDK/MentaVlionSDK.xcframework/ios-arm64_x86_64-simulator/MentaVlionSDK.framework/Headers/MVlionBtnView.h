//
//  MVlionBtnView.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, MVlionBtnViewType) {
    MVlionBtnViewType_Close,      // 关闭按钮
    MVlionBtnViewType_Mute,       // 静音
};

@interface MVlionBtnView : UIView
@property (nonatomic, strong) UIImageView *btn;

- (instancetype)initWithImageName:(NSString *)imageName type:(MVlionBtnViewType)type;
@end

NS_ASSUME_NONNULL_END
