//
//  UIFont+Size.m
//  method_swizzling
//
//  Created by fangyukui on 2018/3/23.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "UIFont+Size.h"
#import <objc/message.h>

@implementation UIFont (Size)
+(void)load{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class class = [self class];
        
        SEL originSelector = @selector(systemFontOfSize:);
        
        SEL swizzledSelector = @selector(yk_systemFontOfSize:);

        
        Method originMethod =  class_getClassMethod(class, originSelector);
        
        Method swizzledMethod =  class_getClassMethod(class, swizzledSelector);
        
        //交换实现
        method_exchangeImplementations(originMethod, swizzledMethod);
        
    });
    
}

+(UIFont *)yk_systemFontOfSize:(CGFloat)size{
    //这个自己从本地json获取
    double rate = 2.0;
    
    NSLog(@"监听到systemFontOfSize被调用");
    
    return [UIFont yk_systemFontOfSize:size * rate];
}


@end
