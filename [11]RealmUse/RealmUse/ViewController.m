//
//  ViewController.m
//  RealmUse
//
//  Created by fangyukui on 2018/4/12.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"

#import "Student.h"

#import <Realm/Realm.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    [self insertObj];
    [self updateObj];
    
}

#pragma mark -增
-(void)insertObj{
    Student *s = [[Student alloc]initWithValue:@{@"stuId":@1,@"age":@0000,@"name":@"yu-vin"}];
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
@end
