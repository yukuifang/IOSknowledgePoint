//
//  NSObject+MyKVO.m
//  ObjKVO
//
//  Created by fangyukui on 2018/2/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "NSObject+MyKVO.h"
#import <objc/runtime.h>

@implementation NSObject (MyKVO)

-(void)XZG_addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context{
    
    NSString *oldClassName =  NSStringFromClass([self class]);
    NSString *newClassName = [@"XZGKVONotification" stringByAppendingString:oldClassName];
    
    //创建一个类
    Class myClass = objc_allocateClassPair([self class], newClassName.UTF8String, 0);
    
    //注册
    objc_registerClassPair(myClass);
    
    //修改类型，isa
    object_setClass(self, myClass);
    
    //重写父类setName, 底层就是子类添加setName方法
    class_addMethod(myClass, @selector(setName:), (IMP)setNameIMP, "v@:@");
   
}
void setNameIMP(id self, SEL _cmd,NSString *name){
    [self willChangeValueForKey:name];
    
    [self didChangeValueForKey:name];
    NSLog(@"%@",name);
}

@end
