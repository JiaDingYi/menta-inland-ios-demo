//
//  MentaJDYunNativeExpressAdapter.h
//  MentaJDYunAdapter
//
//  Created by stone on 2024/2/17.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeExpressAdDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaJDYunNativeExpressAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedNativeExpressAdDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
