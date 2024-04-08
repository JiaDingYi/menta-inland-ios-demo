//
//  MentaTanxNativeExpressAdapter.h
//  MentaTanxAdapter
//
//  Created by iMacMe on 2024/2/26.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeExpressAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaTanxNativeExpressAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedNativeExpressAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
