//
//  MentaBdNativeExpressAdapter.h
//  MentaBdAdapter
//
//  Created by iMacMe on 2024/3/1.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeExpressAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaBdNativeExpressAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedNativeExpressAdDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
