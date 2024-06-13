//
//  MentaUnifiedPriEnum.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/19.
//

#ifndef MentaUnifiedPriEnum_h
#define MentaUnifiedPriEnum_h

typedef NS_ENUM(NSInteger, MUTrackingEventType) {
    MUTrackingEventTypeReq,               // 广告请求
    MUTrackingEventTypeFillSuccess,       // 广告填充成功
    MUTrackingEventTypeFillFail,          // 广告填充失败
    MUTrackingEventTypeBidSuccess,        // 广告竞价成功
    MUTrackingEventTypeBidFail,           // 广告竞价失败
    MUTrackingEventTypeRenderSuccess,     // 广告渲染成功
    MUTrackingEventTypeRenderFail,        // 广告渲染失败
    MUTrackingEventTypeTrigger,           // 广告触发展示
    MUTrackingEventTypeShow,              // 广告触发展示或者被添加到父视图
    MUTrackingEventTypeImp,               // 广告展示
    MUTrackingEventTypeEnter,             // 信息流广告入屏1px时触发
    MUTrackingEventTypeDpcheck,           // dplink打点
    MUTrackingEventTypeSkip,              // 跳过
    MUTrackingEventTypeClose,             // 广告关闭
    MUTrackingEventTypeClick,             // 广告点击
    MUTrackingEventTypeNetResp,           // 网络响应打点
    MUTrackingEventTypeStart,             // 启动打点
    MUTrackingEventTypeReport,            // 设备信息上报
    MUTrackingEventTypeFrontBack,         // 后台打点
};


#endif /* MentaUnifiedPriEnum_h */
