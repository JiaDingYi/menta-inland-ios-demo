#import <UIKit/UIKit.h>

@interface DemoBaseViewController : UIViewController

@property (nonatomic, strong) UITextView *logTextView;

- (void)setupLogTextView;
- (void)appendLog:(NSString *)log;
- (void)clearLog;

@end 