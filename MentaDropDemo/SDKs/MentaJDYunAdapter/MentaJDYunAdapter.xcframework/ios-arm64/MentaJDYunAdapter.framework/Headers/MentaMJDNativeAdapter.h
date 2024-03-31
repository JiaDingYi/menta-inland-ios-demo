//
//  MentaMJDNativeAdapter.h
//  MentaJDYunAdapter
//
//  Created by iMacMe on 2024/3/7.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaMJDNativeAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedNativeAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
