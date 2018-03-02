//
//  Player.m
//  shareInstance
//
//  Created by fangyukui on 2018/3/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "Player.h"

//01 提供一个全局的静态变量(对外界隐藏)
static Player *_player;

@implementation Player


//02 重写alloc方法,保证永远只分配一次存储空间
// alloc - > allocWithZone(分配存储空间)
+(instancetype)allocWithZone:(struct _NSZone *)zone{
    
    /*@synchronized(self){
        if (!_player) {
           _player = [super allocWithZone:zone];
        }
    }*/
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _player = [super allocWithZone:zone];
    });
    return _player;
    
}

//03 提供类方法
+(instancetype)shareInstance{
    return [[self alloc]init];
}

//04 重写copy
-(id)copyWithZone:(NSZone *)zone{
    return _player;
}
-(id)mutableCopyWithZone:(NSZone *)zone
{
    return _player;
}





@end
