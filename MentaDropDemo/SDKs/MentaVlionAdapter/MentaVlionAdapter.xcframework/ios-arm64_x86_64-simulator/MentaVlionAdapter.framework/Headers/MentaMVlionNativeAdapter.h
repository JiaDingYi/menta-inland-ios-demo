//
//  MentaMVlionNativeAdapter.h
//  MentaMVlionAdapter
//
//  Created by iMacMe on 2024/1/9.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeAdDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaMVlionNativeAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedNativeAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
