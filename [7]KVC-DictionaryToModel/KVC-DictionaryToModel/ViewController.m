//
//  ViewController.m
//  KVC-DictionaryToModel
//
//  Created by fangyukui on 2018/3/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"
#import "NSDictionary+Property.h"
#import "StatusItem.h"
#import "NSObject+Model.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // 获取文件全路径
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"status.plist" ofType:nil];
    
    // 文件全路径
    NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:filePath];
    
    // 设计模型,创建属性代码 => dict
    //    [dict[@"user"] createPropertyCode];
    
    // 字典转模型:KVC,MJExtension
    StatusItem *item = [StatusItem modelWithDict:dict];
    
    NSLog(@"%@",item.user);
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
