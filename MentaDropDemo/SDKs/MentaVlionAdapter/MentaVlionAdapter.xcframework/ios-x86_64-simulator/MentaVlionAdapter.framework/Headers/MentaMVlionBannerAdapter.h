//
//  MentaMVlionBannerAdapter.h
//  MentaMVlionAdapter
//
//  Created by iMacMe on 2024/3/18.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedBannerAdDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaMVlionBannerAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedBannerAdDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
