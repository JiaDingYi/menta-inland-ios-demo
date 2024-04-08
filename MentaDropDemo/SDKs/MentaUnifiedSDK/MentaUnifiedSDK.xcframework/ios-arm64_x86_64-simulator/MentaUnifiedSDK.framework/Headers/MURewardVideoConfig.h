//
//  MURewardVideoConfig.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/12/19.
//

#import <Foundation/Foundation.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN

@interface MURewardVideoConfig : NSObject
@property (nonatomic, copy) NSString *slotId;// 广告位id

// 广告位尺寸 所有广告位必须要传
// 注: adSize 不意味着广告返回的真正宽高
@property (nonatomic) CGSize adSize;

/// 广告加载容忍时间
/// 建议3f~5f。如果设定的时间内没有竞价到广告，则判断竞价失败
@property (nonatomic, assign) NSInteger tolerateTime;

// 视频填充方式
@property (nonatomic, assign) MentaRewardVideoAdViewGravity videoGravity;

@end

NS_ASSUME_NONNULL_END
