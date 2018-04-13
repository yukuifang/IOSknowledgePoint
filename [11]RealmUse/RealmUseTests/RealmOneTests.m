//
//  RealmOneTests.m
//  RealmUseTests
//
//  Created by fangyukui on 2018/4/12.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Student.h"
#import <Realm/Realm.h>

@interface RealmOneTests : XCTestCase

@end

@implementation RealmOneTests

-(void)testRealm{
    Student *s = [[Student alloc]initWithValue:@{@"age":@66666,@"name":@"fangyukui"}];
    RLMRealm *realm = [RLMRealm defaultRealm];
    [realm beginWriteTransaction];
    [realm addObject:s];
    [realm commitWriteTransaction];
    NSLog(@"%@",s.name);
    
}

@end
