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

#import "MentaBdAdapter.h"
#import "MentaBdInterstitialAdapter.h"
#import "MentaBdNativeExpressAdapter.h"
#import "MentaBdRewardVideoAdapter.h"
#import "MentaBdSplashAdapter.h"

FOUNDATION_EXPORT double MentaBaiduAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char MentaBaiduAdapterVersionString[];

