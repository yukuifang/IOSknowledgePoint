//
//  Car.m
//  RealmUse
//
//  Created by fangyukui on 2018/4/17.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "Car.h"

@implementation Car

//忽然属性，不存储
//+(NSArray<NSString *> *)ignoredProperties{
//
//}

//限制哪些属性必须有值
+(NSArray<NSString *> *)requiredProperties{
    return @[@"carName",@"identify"];
}
+(NSDictionary *)defaultPropertyValues{
    return @{
             @"carName":@"红旗",
             @"identify":@"粤A"
             
             };
}

@end
