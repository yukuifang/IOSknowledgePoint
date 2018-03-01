//
//  NSObject+MyKVO.h
//  ObjKVO
//
//  Created by fangyukui on 2018/2/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (MyKVO)

-(void)XZG_addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context;

@end
