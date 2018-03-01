//
//  ViewController.m
//  ObjKVO
//
//  Created by fangyukui on 2018/2/13.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"
#import "Dog.h"
#import "NSObject+MyKVO.h"
#import <objc/message.h>

@interface ViewController ()

@property (nonatomic,strong)Person *p;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _p = [[Person alloc]init];
//    [_p addObserver:self forKeyPath:@"dog" options:NSKeyValueObservingOptionNew context:nil];
    
    [_p XZG_addObserver:self forKeyPath:@"name" options:NSKeyValueObservingOptionNew context:nil];
    
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    NSLog(@"%@",change);
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    static int num = 0;
    //在工程build settings输入msg取消严格模式。导入#import <objc/message.h>
    //以下的代码底层实现原理：
//    objc_msgSend(_p, @selector(setName:),[NSString stringWithFormat:@"%d",num++]);
    // oc函数发送消息隐式有两个参数，id self, SEL _cmd
    _p.name = [NSString stringWithFormat:@"%d",num++];
    
}


@end
