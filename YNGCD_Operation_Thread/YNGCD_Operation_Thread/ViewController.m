//
//  ViewController.m
//  YNGCD_Operation_Thread
//
//  Created by ZYN on 2018/3/13.
//  Copyright © 2018年 cn.yn.oc. All rights reserved.
//

#import "ViewController.h"
#import <AFNetworking.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    [self requestGroupQueue];
    [self requestOperationDependency];
    
}


#pragma mark - Private Method

#pragma mark - Queue Method
/// 组队列 - 模拟切割图片请求成功 合成一张图片
- (void)requestGroupQueue {
    dispatch_group_t group_t = dispatch_group_create();
    
    dispatch_group_async(group_t, dispatch_get_global_queue(0, 0), ^{
        [self requestWithType:1];
    });
    
    dispatch_group_async(group_t, dispatch_get_global_queue(0, 0), ^{
        [self requestWithType:2];
    });
    
    dispatch_group_async(group_t, dispatch_get_global_queue(0, 0), ^{
        [self requestWithType:3];
    });
    
    dispatch_group_notify(group_t, dispatch_get_main_queue(), ^{
        NSLog(@"-- 三个请求完成");
    });
    
}
/// 依赖队列
- (void)requestOperationDependency {
    
    //    //按照顺序
        NSBlockOperation *operation_1 = [NSBlockOperation blockOperationWithBlock:^{
            [self requestWithType:1];
        }];
        NSBlockOperation *operation_2 = [NSBlockOperation blockOperationWithBlock:^{
            [self requestWithType:2];
        }];
        NSBlockOperation *operation_3 = [NSBlockOperation blockOperationWithBlock:^{
            [self requestWithType:3];
        }];
        NSBlockOperation *operation_4 = [NSBlockOperation blockOperationWithBlock:^{
            NSLog(@"---完成");
        }];
        //设置依赖
        [operation_2 addDependency:operation_1];
        [operation_3 addDependency:operation_2];
    
        [operation_4 addDependency:operation_3];
    

        //创建队列并添加任务
        NSOperationQueue *queue = [[NSOperationQueue alloc]init];
        [queue addOperations:@[operation_3,operation_2,operation_1, operation_4] waitUntilFinished:NO];
    
    
//    NSBlockOperation *blockOperation_1 = [NSBlockOperation blockOperationWithBlock:^{
//        [self requestWithType:1];
//    }];
//    NSBlockOperation *blockOperation_2 = [NSBlockOperation blockOperationWithBlock:^{
//        [self requestWithType:2];
//    }];
//    NSBlockOperation *blockOperation_3 = [NSBlockOperation blockOperationWithBlock:^{
//        [self requestWithType:3];
//    }];
//    [blockOperation_2 addDependency:blockOperation_1];
//    [blockOperation_3 addDependency:blockOperation_2];
//    NSOperationQueue *operationQueue = [[NSOperationQueue alloc] init];
//    [operationQueue addOperations:@[blockOperation_3, blockOperation_2, blockOperation_1]
//                waitUntilFinished:YES];
    
}

- (void)requestWithType:(NSInteger)type {
    dispatch_semaphore_t semaphore_t = dispatch_semaphore_create(0);
    
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.responseSerializer = [AFJSONResponseSerializer serializer];
    NSString *url = [NSString stringWithFormat:@"%s","http://v3.wufazhuce.com:8000/api/channel/movie/more/0?platform=ios&version=v4.0.1"];
    [manager GET:url parameters:nil progress:^(NSProgress * _Nonnull uploadProgress) {
        
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        
        NSLog(@"请求%zd%zd%zd%zd%zd成功", type, type, type, type, type);
        //计数加1
        dispatch_semaphore_signal(semaphore_t);
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        NSLog(@"请求%zd%zd%zd%zd%zd失败", type, type, type, type, type);
        //计数加1
        dispatch_semaphore_signal(semaphore_t);
    }];
    /// 不等于 0 才会执行
    dispatch_semaphore_wait(semaphore_t, DISPATCH_TIME_FOREVER);
}


@end
