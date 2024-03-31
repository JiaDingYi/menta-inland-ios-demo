//
//  MentaVlionCommonEnum.h
//  MentaVlionBaseSDK
//
//  Created by iMacMe on 2023/12/20.
//  0.0.7

/* * * * * * * * * * * * * * * * * * * * * 开屏广告 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// 开屏广告关闭方式
// 注意: 如果广告源不支持跳过的业务逻辑, 一律按照倒计时结束处理
typedef NS_ENUM(NSUInteger, MentaSplashAdCloseMode) {
    MentaSplashAdCloseMode_Unknown,          // 有些广告源无法支持该业务 统一回调 unknown
    MentaSplashAdCloseMode_ByClickAd,        // 点击广告关闭
    MentaSplashAdCloseMode_ByClickSkip,      // 点击跳过
    MentaSplashAdCloseMode_TimeOver,         // 倒计时结束时关闭
};

// 开屏广告点进模式
typedef NS_ENUM(NSUInteger, MentaSplashAdInterviewMode) {
    MentaSplashAdInterviewMode_BottomHotSpotClick = 1 << 0,      // 底部热区点击 // 默认
    MentaSplashAdInterviewMode_FullScreenClick    = 1 << 1,      // 全屏可点 (目前不支持)
    MentaSplashAdInterviewMode_Shake              = 1 << 2,      // 摇一摇
    MentaSplashAdInterviewMode_Swipe              = 1 << 3,      // 滑动

};

// 开屏广告物料填充模式
typedef NS_ENUM(NSUInteger, MentaSplashAdMaterialFillMode) {
    MentaSplashAdMaterialFillMode_ScaleAspectFill, // 默认
    MentaSplashAdMaterialFillMode_ScaleToFill,
    MentaSplashAdMaterialFillMode_ScaleAspectFit,
};


// 滑动方向
typedef NS_OPTIONS(NSUInteger, MVlionSwipeDirection) {
    MVlionSwipeDirection_None   = 0,
    MVlionSwipeDirection_Up     = 1 << 0,
    MVlionSwipeDirection_Down   = 1 << 1,
    MVlionSwipeDirection_Left   = 1 << 2,
    MVlionSwipeDirection_Right  = 1 << 3
};


/* * * * * * * * * * * * * * * * * * * * * 开屏广告 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */





/* * * * * * * * * * * * * * * * * * * * * 激励视频广告 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// 激励视频屏幕方向
typedef NS_ENUM(NSUInteger, MentaRewardVideoAdViewInterfaceOrientation) {
    MentaRewardVideoAdViewInterfaceOrientation_Portrait,      // 竖屏 默认
    MentaRewardVideoAdViewInterfaceOrientation_Landscape      // 横屏
};

// 激励视频视频填充方式
typedef NS_ENUM(NSUInteger, MentaRewardVideoAdViewGravity) {
    MentaRewardVideoAdViewGravity_ResizeAspect,      // 等比例填充至屏幕内, 上下 或 左右 可能留黑, 但视频宽高比例不变, 不会裁剪视频  //默认
    MentaRewardVideoAdViewGravity_ResizeAspectFill,  // 等比例填充纸屏幕内, 四周不会留黑, 视频宽高比保持不变, 但会裁剪视频
    MentaRewardVideoAdViewGravity_Resize,            // 视频拉伸至屏幕边缘, 四周不会留黑, 视频宽高比会发生变化, 不会裁剪视频
};

// 激励视频广告关闭模式
typedef NS_ENUM(NSUInteger, MentaRewardVideoAdCloseMode) {
    MentaRewardVideoAdCloseMode_Unknown,          // 有些渠道不支持跳过业务,则关闭时统一回调 unknown
    MentaRewardVideoAdCloseMode_ByClickSkip,      // 点击跳过
    MentaRewardVideoAdCloseMode_TimeOver,         // 倒计时结束时关闭
};

/* * * * * * * * * * * * * * * * * * * * * 激励视频广告 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */




/* * * * * * * * * * * * * * * * * * * * * 插屏广告 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// 插屏广告点击模式
typedef NS_ENUM(NSUInteger, MentaInterstitialAdInterviewMode) {
    MentaInterstitialAdInterviewMode_FullClick = 1 << 0,      // 点击(插屏广告默认可以显示广告范围内都可点击)
    MentaInterstitialAdInterviewMode_Shake     = 1 << 1,      // 摇动

};

/* * * * * * * * * * * * * * * * * * * * * 插屏广告 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* * * * * * * * * * * * * * * * * * * * * 信息流广告模版渲染 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// 开屏广告物料填充模式
typedef NS_ENUM(NSUInteger, MentaNativeExpressAdMaterialFillMode) {
    MentaNativeExpressAdMaterialFillMode_ScaleAspectFill, // 默认
    MentaNativeExpressAdMaterialFillMode_ScaleToFill,
    MentaNativeExpressAdMaterialFillMode_ScaleAspectFit,
};

/* * * * * * * * * * * * * * * * * * * * * 信息流广告模版渲染 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


// 点击广告之后的跳转类型
typedef NS_ENUM(NSUInteger, MentaJumpTargetMode) {
    MentaJumpTargetMode_Unknown,      // 默认
    MentaJumpTargetMode_StoreProduct, // APPLE STORE
    MentaJumpTargetMode_Deeplink,     // dplink
    MentaJumpTargetMode_Land,         // 落地页
};

// 触发点击广告时, 点击区域的分类 只有统计时 拼接参数使用
typedef NS_ENUM(NSUInteger, MentaClkAreaCategory) {
    MentaClkAreaCategory_None  =     20240202, // 没有,说明是摇一摇或其他非点击方式
    MentaClkAreaCategory_Hotsplot,             // 点击了热区
    MentaClkAreaCategory_Button,               // 按钮
    MentaClkAreaCategory_ShakeIcon,            // 点击了摇一摇的icon
    MentaClkAreaCategory_Admin,                // 点击了广告素材
};

// 广告模版的页面状态 目前用于点击统计时的打点
typedef NS_ENUM(NSUInteger, MentaAdTemplateViewState) {
    MentaAdTemplateViewState_Main ,            // main
    MentaAdTemplateViewState_Popup,            // 挽留页
    MentaAdTemplateViewState_EndCard,          // 结束页
};

/* * * * * * * * * * * * * * * * * * * * * banner广告 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// 开屏广告物料填充模式(视频或者图片素材的填充方式)
typedef NS_ENUM(NSUInteger, MentaBannerAdMaterialFillMode) {
    MentaBannerAdMaterialFillMode_ScaleAspectFit,// 默认
    MentaBannerAdMaterialFillMode_ScaleAspectFill,
    MentaBannerAdMaterialFillMode_ScaleToFill,
};

// 模版填充样式(整个广告ADview相对于Container的填充方式)
typedef NS_ENUM(NSUInteger, MentaBannerAdTemplateFillMode) {
    MentaBannerAdTemplateFillMode_AutomaticDetection, // 默认 (容器)
    MentaBannerAdTemplateFillMode_ScaleAspectFill,
    MentaBannerAdTemplateFillMode_ScaleToFill,
    MentaBannerAdTemplateFillMode_ScaleAspectFit,
};

/* * * * * * * * * * * * * * * * * * * * * banner广告 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
