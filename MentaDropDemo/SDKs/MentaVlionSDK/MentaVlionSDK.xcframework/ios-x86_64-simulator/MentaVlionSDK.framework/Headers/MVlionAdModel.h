//
//  MVlionAdModel.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/16.
//

#import <Foundation/Foundation.h>

@class MVlionImage;
@class MVlionBid;
@class MVlionAdVMPTracking;
@class MVlionAdVideo;
@class MVlionAdVMPTracking;
@class MVlionSeatbid;

NS_ASSUME_NONNULL_BEGIN

@interface MVlionImage : NSObject
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, copy) NSString *url;
@end

@interface MVlionBid : NSObject

@property (nonatomic, copy)NSString *requestId;
@property (nonatomic, copy)NSString *slotId;



@property (nonatomic, copy) NSString *crid;
@property (nonatomic, copy) NSString *dspid;
@property (nonatomic, assign) NSInteger is_download;
@property (nonatomic, assign) NSInteger price;
@property (nonatomic, strong) NSArray<MVlionImage *> *image;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) NSArray<NSString *> *clicktrackers;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, strong) NSArray<NSString *> *imptrackers;
@property (nonatomic, copy) NSString *impid;
@property (nonatomic, copy) NSString *deeplink;
@property (nonatomic, copy) NSString *ldp;


@property (nonatomic, copy) NSString *brand_name;
@property (nonatomic, copy) NSString *brand_logo;

@property (nonatomic, strong) MVlionAdVideo *video;

// 传参使用
@property (nonatomic, copy) NSString *ad_type;

@end

@interface MVlionAdVideo : NSObject
@property (nonatomic, strong)   NSArray<NSString *> *vm_p_start;
@property (nonatomic, assign) NSInteger vsize;
@property (nonatomic, copy)   NSString *vurl;
@property (nonatomic, strong)   NSArray<MVlionAdVMPTracking *> *vm_p_tracking;
@property (nonatomic, strong)   NSArray<NSString *> *vm_p_succ;
@property (nonatomic, assign) NSInteger duration;
@property (nonatomic, assign) NSInteger vw;
@property (nonatomic, assign) NSInteger vh;
@property (nonatomic, assign) NSInteger rewardTime;

// 自定义字段
@property (nonatomic, copy)   NSURL *fileURL;/// 文件URL 已经下载过的有值

@end

@interface MVlionAdVMPTracking : NSObject
@property (nonatomic, assign) NSInteger play_sec;
@property (nonatomic, strong)   NSArray<NSString *> *list;
@end


@interface MVlionSeatbid : NSObject
@property (nonatomic, strong) NSArray<NSArray<MVlionBid *> *> *bid;  // 需仔细查看服务器返回的json结构 有一层是 [[]] 的结构
@end


@interface MVlionAdModel : NSObject


@property (nonatomic, strong) NSArray<MVlionSeatbid *> *seatbid;
@property (nonatomic, copy)NSString *requestId;
@property (nonatomic, assign) NSInteger code;
@property (nonatomic, copy) NSString *bidId;

@end

NS_ASSUME_NONNULL_END
