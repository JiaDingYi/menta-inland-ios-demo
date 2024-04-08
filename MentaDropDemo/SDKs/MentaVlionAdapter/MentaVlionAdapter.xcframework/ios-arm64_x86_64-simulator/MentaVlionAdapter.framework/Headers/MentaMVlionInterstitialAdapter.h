//
//  MentaMVlionInterstitialAdapter.h
//  MentaMVlionAdapter
//
//  Created by iMacMe on 2024/1/17.
//

#import <Foundation/Foundation.h>
#import <MentaUnifiedSDK/MentaUnifiedInterstitialAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MentaMVlionInterstitialAdapter : NSObject
@property (nonatomic, weak) id<MentaUnifiedInterstitialAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
