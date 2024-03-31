

#import "ViewController.h"

@interface ViewController ()<UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *demoArray;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.demoArray = [@[
                        @[@"聚合SDK(MentaUnifiedSDK)", @"DemoMUSDKViewController"],
                        ] mutableCopy];

    [self.view addSubview:self.tableView];
    self.tableView.frame = self.view.bounds;

    
    
}

#pragma mark - UITableView
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.demoArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *SimpleTableIdentifier = @"SimpleTableIdentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:SimpleTableIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:SimpleTableIdentifier];
    }
    cell.textLabel.text = self.demoArray[indexPath.row][0];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    id item = self.demoArray[indexPath.row][1];
    if ([item isKindOfClass:[NSString class]]) {
        UIViewController *vc = [[NSClassFromString(item) alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
    }
}


- (UITableView *)tableView
{
    if (!_tableView) {
        _tableView = [[UITableView alloc] init];
        _tableView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.accessibilityIdentifier = @"tableView_id";
    }
    return _tableView;
}


@end
