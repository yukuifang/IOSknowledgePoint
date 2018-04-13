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
    RLMRealm *RLM = [RLMRealm defaultRealm];
    [RLM beginWriteTransaction];
    [RLM addObject:s];
    [RLM commitWriteTransaction];
    NSLog(@"%d",s.age);
    
}

@end
