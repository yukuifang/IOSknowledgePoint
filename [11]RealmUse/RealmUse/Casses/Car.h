//
//  Car.h
//  RealmUse
//
//  Created by fangyukui on 2018/4/17.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Realm/Realm.h>
@interface Car : RLMObject

@property NSString *carName;

@property NSString *identify;

@end
RLM_ARRAY_TYPE(Car);
