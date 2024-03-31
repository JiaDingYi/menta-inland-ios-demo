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

#import "MentaTanxAdapter.h"
#import "MentaTanxInterstitialAdapter.h"
#import "MentaTanxNativeExpressAdapter.h"
#import "MentaTanxRewardVideoAdapter.h"
#import "MentaTanxSplashAdapter.h"

FOUNDATION_EXPORT double MentaTanxAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char MentaTanxAdapterVersionString[];

