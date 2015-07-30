//
//  WMMainTableViewController.m
//  PageController
//
//  Created by haibo on 15/7/29.
//  Copyright (c) 2015年 haibo. All rights reserved.
//

#import "WMMainTableViewController.h"
#import "PageController.h"
#import "MyTableViewController.h"

@interface WMMainTableViewController ()
@property (nonatomic, strong) NSArray *styles;

@end

@implementation WMMainTableViewController

- (NSArray *)styles{
    if (_styles == nil) {
        _styles = @[@"WMMenuViewStyleDefault",
                    @"WMMenuViewStyleLine",
                    @"WMMenuViewStyleFlood",
                    @"WMMenuViewStyleFloodHollow"];
    }
    return _styles;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.styles.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *const cellIdentifier = @"WMMainCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                      reuseIdentifier:cellIdentifier];
    }
    cell.textLabel.text = self.styles[indexPath.row];
    return cell;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    PageController *pageController = [self getDefaultController];
    if ([self.styles[indexPath.row] isEqualToString:@"WMMenuViewStyleDefault"]) {
       
    }else if ([self.styles[indexPath.row] isEqualToString:@"WMMenuViewStyleLine"]){
        
    }else if ([self.styles[indexPath.row] isEqualToString:@"WMMenuViewStyleFlood"]){
        
    }else if ([self.styles[indexPath.row] isEqualToString:@"WMMenuViewStyleFloodHollow"]){
    }
    // 等待新样式
    // ...
    [self.navigationController pushViewController:pageController animated:YES];
}

-(PageController *)getDefaultController{
    NSMutableArray *viewControllers = [[NSMutableArray alloc] init];
    NSMutableArray *titles = [[NSMutableArray alloc] init];
//    for (int i = 0; i < 10; i++) {
//    int i = 0;
    Class vcClass;
    NSString *title;
//    switch (i%3) {
//        case 0:
//            vcClass = [MyTableViewController class];
//            title = @"Greetings";
//            break;
//        case 1:
////                vcClass = [WMViewController class];
////                title = @"Hit Me";
//            break;
//        default:
////                vcClass = [WMCollectionViewController class];
////                title = @"Fluency";
//            break;
//        }
    vcClass = [MyTableViewController class];
    title = @"Greetings";
    [viewControllers addObject:vcClass];
    [titles addObject:title];
//    }
    PageController *pageVC = [[PageController alloc] initWithViewControllerClasses:viewControllers andTheirTitles:titles];
    pageVC.pageAnimatable = YES;
    pageVC.menuItemWidth = 85;
    return pageVC;
}
               
               
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
