//
//  Person.m
//  ObjKVO
//
//  Created by fangyukui on 2018/2/13.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "Person.h"

@implementation Person

-(instancetype)init{
    if (self = [super init]) {
        _dog = [[Dog alloc]init];
        _dog.name = @"66";
        _dog.age = 11;
        
    }
    return self;
}

//默认为YES，全自动模型;
//+(BOOL)automaticallyNotifiesObserversForKey:(NSString *)key{
//    return YES;
//}


//    [_p addObserver:self forKeyPath:@"dog" options:NSKeyValueObservingOptionNew context:nil];回调该方法

+(NSSet<NSString *> *)keyPathsForValuesAffectingValueForKey:(NSString *)key{
    NSSet *keyPathSets  =  [super keyPathsForValuesAffectingValueForKey:key];
    if ([key isEqualToString:@"dog"]) {
        keyPathSets  = [keyPathSets setByAddingObjectsFromArray:@[@"_dog.name",@"_dog.age"]];
        
    }
    return keyPathSets;
    
}
@end
