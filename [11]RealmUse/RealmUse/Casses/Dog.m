//
//  Dog.m
//  RealmUse
//
//  Created by fangyukui on 2018/4/16.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "Dog.h"

@implementation Dog

+(NSDictionary<NSString *,RLMPropertyDescriptor *> *)linkingObjectsProperties{
    return @{
             @"master":[RLMPropertyDescriptor descriptorWithClass:NSClassFromString(@"Student") propertyName:@"pets"]
             
             };
}

@end
