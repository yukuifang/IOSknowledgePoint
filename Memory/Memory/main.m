//
//  main.m
//  Memory
//
//  Created by fangyukui on 2018/3/19.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
@interface Student:NSObject
{
@public
    int _age;
    NSString * _name;
    
}
@end

@implementation Student
@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        Student *s  = [[Student alloc]init];
        s->_name = @"箱子格";
        s->_age = 12;
        NSLog(@"%@",s);
        NSLog(@"%zd字节", class_getInstanceSize([NSObject class]));
        NSLog(@"%zd字节", class_getInstanceSize([Student class]));
        
        NSObject *obj1 = [[NSObject alloc]init];
        NSObject *obj2 = [[NSObject alloc]init];
        
        Class objectClass1 = [obj1 class];
        Class objectClass2 = [obj2 class];
        Class objectClass3 = [NSObject class];
        Class objectClass4 = [[[NSObject class]class]class];
        Class objectClass5 = object_getClass(obj1);
        Class objectClass6 = object_getClass(obj2);
        
        
        Class objectMetaClass = object_getClass([NSObject class]);

        

        
        
      
       
        
    }
    return 0;
}
