//
//  Student.h
//  RealmUse
//
//  Created by fangyukui on 2018/4/12.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Realm/Realm.h>
#include "Dog.h"
@interface Student : RLMObject
@property int stuId;
@property int age;
@property NSString *name;
@property RLMArray<Dog*><Dog> *pets;

@end
RLM_ARRAY_TYPE(Student)
