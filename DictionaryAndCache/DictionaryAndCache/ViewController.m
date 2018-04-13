//
//  ViewController.m
//  DictionaryAndCache
//
//  Created by fangyukui on 2018/4/11.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"
#import "FYKArchiverTool.h"
#import <YYCache.h>
@interface ViewController ()

@property (nonatomic, strong) NSMutableDictionary *responseObject; //想要存储的数据

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _responseObject = [NSMutableDictionary dictionary];
    for (NSInteger i = 0; i < 100000; i++) {
        [_responseObject setObject:[NSString stringWithFormat:@"test %ld",i] forKey:[NSString stringWithFormat:@"test %ld",i] ];
    }
    
    // 是路径也是存储的键
    NSString *filePath = @"responseObject";
    // 1.存储时间
    NSDate *tempStartDate = [NSDate date];
    [FYKArchiverTool archiverObject:_responseObject key:filePath filePath:filePath];
    [self endTimeLogStarDate:tempStartDate];
    
    
    NSDate *temp2 = [NSDate date];
    YYCache *yyCache = [YYCache cacheWithName:filePath];
    [yyCache setObject:_responseObject forKey:filePath];
    [self endTimeLogStarDate:temp2];
    
//    // 2.读取时间
    NSDate *temp3 = [NSDate date];
    id object = [FYKArchiverTool unarchiverPath:filePath key:filePath];
    [self endTimeLogStarDate:temp3];
    
    NSDate *temp4 = [NSDate date];
    YYCache *yyCache1 = [YYCache cacheWithName:filePath];
    id value = [yyCache1 objectForKey:filePath];
    [self endTimeLogStarDate:temp4];
//
//
    // 3.删除时间
    NSDate *temp5 = [NSDate date];
    [FYKArchiverTool removeArchiverObjectFilePath:filePath];
    [self endTimeLogStarDate:temp5];
    
    
    NSDate *temp6 = [NSDate date];
    YYCache *yyCache2 = [YYCache cacheWithName:filePath];
    [yyCache2 removeObjectForKey:filePath];
    [self endTimeLogStarDate:temp6];
//
//    // 在此可以断点是否删除失败 不用使用原来的对象去打印
//    id object1 = [FYKArchiverTool unarchiverPath:@"responseObject" key:@"responseObject"];
//    id value1 = [yyCache objectForKey:@"responseObject"];
}

- (void)endTimeLogStarDate:(NSDate *)startDete {
    double dealTime = [[NSDate date] timeIntervalSinceDate:startDete];
    // 使用毫秒测试 1s = 1000ms
    NSLog(@"endTime === %f ms", dealTime * 1000);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
