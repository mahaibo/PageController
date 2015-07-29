//
//  PageController.h
//  PageController
//
//  Created by haibo on 15/7/29.
//  Copyright (c) 2015年 haibo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MenuView.h"

@interface PageController : UIViewController

// 各个控制器的 class, 例如:[UITableViewController class]
// Each controller's class, example:[UITableViewController class]
@property (nonatomic, strong) NSArray *viewControllerClasses;

// 各个控制器标题, NSString
// Titles of view controllers in page controller. Use NSString.
@property (nonatomic, strong) NSArray *titles;
@property (nonatomic, strong) UIViewController *currentViewController;

// 设置选中几号 item
// To select item at index
@property (nonatomic, assign) int selectIndex;

// 点击相邻的 MenuItem 是否触发翻页动画(当当前选中与点击Item相差大于1是不触发)
// Whether to animate when press the MenuItem
// When distant between the selected and the pressed is larger than 1,never animate.
@property (nonatomic, assign) BOOL pageAnimatable;

// 标题尺寸
// The title size
@property (nonatomic, assign) CGFloat titleSizeSelected;
@property (nonatomic, assign) CGFloat titleSizeNormal;

// 标题颜色, 颜色是可动画的.
// The title color,the color is animatable.
@property (nonatomic, strong) UIColor *titleColorSelected;
@property (nonatomic, strong) UIColor *titleColorNormal;

// 标题的字体名字
// The name of title's font
@property (nonatomic, copy) NSString *titleFontName;

// 导航栏高度
// The menu view height
@property (nonatomic, assign) CGFloat menuHeight;

// 当所有item的宽度加起来小于屏幕宽时，PageController会自动帮助排版，添加每个item之间的间隙以填充整个宽度
// When the sum of all the item's width is smaller than the screen's width, pageController will add gap to each item automatically, in order to fill the width.
// 每个 MenuItem 的宽度
// The item width,when all are same,use this property
@property (nonatomic, assign) CGFloat menuItemWidth;
// 各个 MenuItem 的宽度，可不等，数组内为 NSNumber
// Each item's width, when they are not all the same, use this property, Put `NSNumber` in this array.
@property (nonatomic, strong) NSArray *itemsWidths;

// 导航栏背景色
// The background color of menu view
@property (nonatomic, strong) UIColor *menuBGColor;

// 默认为无下划线
// Menu view's style, now has two different styles, 'Line','default'
@property (nonatomic, assign) WMMenuViewStyle menuViewStyle;

// 进度条的颜色，默认和选中颜色一致(如果不是 style 为 Default，则该属性无用)
// The progress's color,the default color is same with `titleColorSelected`.
// If you want to have a different color, set this property.
@property (nonatomic, strong) UIColor *progressColor;

// 是否发送在创建控制器或者视图完全展现在用户眼前时通知观察者，默认为不开启，如需利用通知请开启
// Whether notify observer when finish init or fully displayed to user, the default is NO.
@property (nonatomic, assign) BOOL postNotification;

// 是否记录Controller的位置，并在下次回来的时候回到相应位置,默认为NO
// 比如`UITabelViewController`,当然你也可以在自己的控制器中自行设置
// 如果将Controller.view替换为scrollView或者在Controller.view上添加了一个和自身bounds一样的scrollView也是OK的
// NOTE：在viewDidLoad中controller.view.bounds等于屏幕的bounds
// Whether to remember controller's positon if it's a kind of scrollView controller,like UITableViewController
// The default value is NO.
@property (nonatomic, assign) BOOL rememberLocation;

/**
 *  构造方法，请使用该方法创建控制器 (此方法不重用控制器).
 *  Init method，recommend to use this instead of `-init` (not reusable).
 *
 *  @param classes 子控制器的 class，确保数量与 titles 的数量相等
 *  @param titles  各个子控制器的标题，用 NSString 描述
 *
 *  @return instancetype
 */
- (instancetype)initWithViewControllerClasses:(NSArray *)classes andTheirTitles:(NSArray *)titles;
@end
