//
//  MentaSigmobInterstitialAdapter.h
//  Masonry
//
//  Created by jdy on 2024/4/17.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedInterstitialAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaSigmobInterstitialAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedInterstitialAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
