//
//  ViewController.m
//  RealmUse
//
//  Created by fangyukui on 2018/4/12.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"

#import "Student.h"

#import "Dog.h"

#import <Realm/Realm.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    [self insertObj];
//    [self updateObj];
//    [self delObj];
    
    [self relative];
    
}

#pragma mark -增
-(void)insertObj{
    Student *s = [[Student alloc]initWithValue:@{@"stuId":@2,@"age":@0000,@"name":@"yu-vin"}];
    RLMRealm *realm = [RLMRealm defaultRealm];
    
//    //方法1
//    [realm beginWriteTransaction];
//    [realm addObject:s];
//    [realm commitWriteTransaction];
    
    
    //方法2
//    [realm transactionWithBlock:^{
//        [realm addObject:s];
//
//    }];
    
    //方法3
//    [realm transactionWithBlock:^{
//        [Student createInRealm:realm withValue:@{@"stuId":@2,@"age":@66666,@"name":@"箱子格"}];
//    }];
    
    //方法4
    [realm transactionWithBlock:^{
        //要配合主键才能做到,如果之前没有该主键，则增加，有的话的则更新
        [realm addOrUpdateObject:s];
    }];
    
    
}
#pragma mark -改
-(void)updateObj{
    RLMRealm *realm = [RLMRealm defaultRealm];
    //方法1
//    Student *s = [[Student alloc]initWithValue:@{@"age":@66666,@"name":@"yu-vin"}];
//    [realm transactionWithBlock:^{
//        [realm addObject:s];
//    }];
//    [realm transactionWithBlock:^{
//        s.name = @"小方";
//    }];
    
    //方法2
//    RLMResults * results =  [Student objectsWhere:@"name = '箱子格'"];
//    Student *s  = results.firstObject;
//    [realm transactionWithBlock:^{
//        if (s) {
//            s.name = @"箱子格2";
//        }
//
//    }];
    
    //方法3
   
//    [realm transactionWithBlock:^{
//        [Student createOrUpdateInRealm:realm withValue:@{@"stuId":@8,@"age":@7878,@"name":@"heheda"}];
//        
//    }];
 
}
-(void)delObj{
    //方法1
    RLMRealm *realm = [RLMRealm defaultRealm];
//    Student *s  = [[Student objectsWhere:@"name = 'yu-vin'"]firstObject];
//    [realm transactionWithBlock:^{
//        [realm deleteObject:s];
//    }];
    //方法2:删除所有模型
//    [realm transactionWithBlock:^{
//        [realm deleteAllObjects];
//    }];
    
//    方法3:
    [realm transactionWithBlock:^{
        //获取Student模型所有对象,不是一下子将所有数据加载到内存，只是加载了数据的引用，当访问修改的时候才
       RLMResults *resluts =  [Student allObjects];
    }];
}
-(void)relative{
    Dog *d1 = [[Dog alloc]initWithValue:@{@"nickName":@"dog1",@"hobby":@"sleep"}];
    Dog *d2 = [[Dog alloc]initWithValue:@{@"nickName":@"dog2",@"hobby":@"eat"}];
    Student *s  =[[Student alloc]init];
    s.name = @"fangfang";
    s.stuId = 7;
    s.age = 22;
    [s.pets addObject:d1];
    [s.pets addObject:d2];
    
    RLMRealm *realm = [RLMRealm defaultRealm];
    [realm transactionWithBlock:^{
        [realm addObject:s];
        
    }];
    
    Student *findS  = [[Student allObjects]firstObject];
    Dog *findD = findS.pets.firstObject;
    NSLog(@"%@",findD.master);
    
    
    
    
    
}
@end
