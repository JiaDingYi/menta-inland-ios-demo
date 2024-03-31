//
//  MentaTanxInterstitialAdapter.h
//  MentaTanxAdapter
//
//  Created by stone on 2024/2/18.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedInterstitialAdDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface MentaTanxInterstitialAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedInterstitialAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
