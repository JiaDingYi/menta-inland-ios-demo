//
//  MUAdReport.h
//  MentaUnifiedSDK
//
//  Created by iMacMe on 2023/11/27.
//

#import <Foundation/Foundation.h>
#import "MentaUnifiedEnum.h"
#import "MentaUnifiedPriEnum.h"
NS_ASSUME_NONNULL_BEGIN
@class MUAdSource;


@interface MUAdReport : NSObject
@property (class, nonatomic, copy) NSString *reportUrl; // 上传事件的url 从接口获取

+ (void)trackEvent:(MUTrackingEventType)eventType forAdSource:(MUAdSource *)source extra:(NSMutableDictionary *)extra;

@end

NS_ASSUME_NONNULL_END
