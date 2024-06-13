//
//  MentaSigmobNativeAdapter.h
//  MentaSigmobAdapter
//
//  Created by jdy on 2024/4/17.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedNativeAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaSigmobNativeAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedNativeAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
