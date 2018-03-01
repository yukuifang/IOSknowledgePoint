//
//  Person.h
//  ObjKVO
//
//  Created by fangyukui on 2018/2/13.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Dog.h"

@interface Person : NSObject

@property (nonatomic,copy)NSString *name;

@property (nonatomic,strong)Dog *dog;

@end
