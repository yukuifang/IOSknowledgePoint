//
//  Dog.h
//  RealmUse
//
//  Created by fangyukui on 2018/4/16.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Realm/Realm.h>

@interface Dog : RLMObject

@property NSString *nickName;

@property NSString * hobby;

@property (readonly) RLMLinkingObjects *master;


@end
RLM_ARRAY_TYPE(Dog);
