//
//  MVlionCommon.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//

#ifndef MVlionCommon_h
#define MVlionCommon_h


#if __has_include(<MentaVlionBaseSDK/MentaVlionBaseSDK.h>)
    #import <MentaVlionBaseSDK/MentaVlionBaseSDK.h>
#endif


#if __has_include(<MentaVlionSDK/MVlionAdModel.h>)
    #import <MentaVlionSDK/MVlionAdModel.h>
#endif

#if __has_include(<MentaVlionSDK/MVlionSDKPramsManager.h>)
    #import <MentaVlionSDK/MVlionSDKPramsManager.h>
#endif



#define USERAGENTKEY   @"MVlion_KEY_UserAgent"
#define IDFAKEY   @"MVlion_KEY_idfa"
#define SDKVERSION @"5.20.16"

#define kMVLION_SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define kMVLION_SCREENH_HEIGHT ([UIScreen mainScreen].bounds.size.height)

// 渐变色
#define kGradientColor(startColorHex,endColorHex,frame) [UIColor mvl_gradientColorFromColor:[UIColor mvl_colorWithHex:startColorHex] toColor:[UIColor mvl_colorWithHex:endColorHex] withFrame:frame]

static NSString * _Nullable kMVLAdViewWillClickNotification = @"kMVLAdViewWillClickNotification";
static NSString * _Nullable kMVLAdViewDidClickNotification = @"kMVLAdViewDidClickNotification";




#endif /* MVlionCommon_h */
