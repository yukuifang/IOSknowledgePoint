//
//  Downloador.m
//  shareInstance
//
//  Created by fangyukui on 2018/3/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "Downloador.h"
@implementation Downloador

+(instancetype)shareInstance{
    //提供静态变量
    static Downloador *_downLoador;
    //一次代码，线程安全的，里面包装有同步锁
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _downLoador = [[Downloador alloc]init];
        
    });
    return _downLoador;
}
@end
