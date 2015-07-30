//
//  PageConst.h
//  PageController
//
//  Created by haibo on 15/7/30.
//  Copyright (c) 2015年 haibo. All rights reserved.
//

static NSString *const WMControllerDidFinishInitNotification = @"WMControllerDidFinishInitNotification";

//  当一个控制器完全被展示在用户面前时发送的通知
//  可用于判断当前控制器的序号，加载或者刷新当前数据.
//  传递的数据包含两个信息，当前序号 (index) 以及标题 title
static NSString *const WMControllerDidFullyDisplayedNotification = @"WMControllerDidFullyDisplayedNotification";




