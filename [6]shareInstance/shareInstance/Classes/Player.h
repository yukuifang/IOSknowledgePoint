//
//  Player.h
//  shareInstance
//
//  Created by fangyukui on 2018/3/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Player : NSObject<NSCopying,NSMutableCopying>

+(instancetype)shareInstance;

@end
