//
//  MenuView.h
//  PageController
//
//  Created by haibo on 15/7/30.
//  Copyright (c) 2015年 haibo. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef enum{
    WMMenuViewStyleDefault,     // 默认
    WMMenuViewStyleLine,        // 带下划线 (若要选中字体大小不变，设置选中和非选中大小一样即可)
    WMMenuViewStyleFoold,       // 涌入效果 (填充)
    WMMenuViewStyleFooldHollow, // 涌入效果 (空心的)
    
} WMMenuViewStyle;

@interface MenuView : UIView

@end
