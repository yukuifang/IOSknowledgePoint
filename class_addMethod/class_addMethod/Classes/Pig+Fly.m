//
//  Pig+Fly.m
//  class_addMethod
//
//  Created by fangyukui on 2018/3/1.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "Pig+Fly.h"
#import <objc/runtime.h>

void flyMethod(id self,SEL _cmd){
    NSLog(@"begin to fly");
}

@implementation Pig (Fly)

+(BOOL)resolveInstanceMethod:(SEL)sel{
    if (sel == @selector(fly)) {
        class_addMethod([self class], sel, (IMP)flyMethod, "");
        return YES;
    }
    return [super resolveInstanceMethod:sel];
}
@end
