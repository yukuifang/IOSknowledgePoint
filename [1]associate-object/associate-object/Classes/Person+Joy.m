//
//  Person+Joy.m
//  associate-object
//
//  Created by fangyukui on 2018/3/1.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "Person+Joy.h"
#import <objc/runtime.h>


static NSString *salaryKey;

@implementation Person (Joy)

-(void)setSalary:(NSString *)salary{
    objc_setAssociatedObject(self, &salaryKey, salary, OBJC_ASSOCIATION_COPY);
}
-(NSString *)salary{
    return  objc_getAssociatedObject(self, &salaryKey);
}
@end
