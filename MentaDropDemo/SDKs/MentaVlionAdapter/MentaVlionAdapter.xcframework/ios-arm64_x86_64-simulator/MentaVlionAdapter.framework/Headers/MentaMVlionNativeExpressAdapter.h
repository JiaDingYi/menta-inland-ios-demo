//
//  MentaMVlionNativeExpressAdapter.h
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/22.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeExpressAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaMVlionNativeExpressAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedNativeExpressAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
