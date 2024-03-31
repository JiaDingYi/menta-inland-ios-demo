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

#import "MentaGDTAdatper.h"
#import "MentaGDTInterstitialAdapter.h"
#import "MentaGDTNativeExpressAdapter.h"
#import "MentaGDTRewardVideoAdapter.h"
#import "MentaGDTSplashAdapter.h"

FOUNDATION_EXPORT double MentaGDTAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char MentaGDTAdapterVersionString[];

