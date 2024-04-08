#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MentaMVlionAdapter.h"
#import "MentaMVlionBannerAdapter.h"
#import "MentaMVlionInterstitialAdapter.h"
#import "MentaMVlionNativeExpressAdapter.h"
#import "MentaMVlionRewardVideoAdapter.h"
#import "MentaMVlionSplashAdapter.h"
#import "MentaMVlionNativeAdapter.h"
#import "MentaMVlionNativeAdView.h"

FOUNDATION_EXPORT double MentaVlionAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char MentaVlionAdapterVersionString[];

