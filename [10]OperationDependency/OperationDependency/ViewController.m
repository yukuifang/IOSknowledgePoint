//
//  ViewController.m
//  OperationDependency
//
//  Created by fangyukui on 2018/3/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self demo3];
    
//    [self demo4];
    // Do any additional setup after loading the view, typically from a nib.
    
  
//    NSOperationQueue *queue = [[NSOperationQueue alloc]init];
//
//    NSBlockOperation *op1 = [NSBlockOperation blockOperationWithBlock:^{
//        NSLog(@"op1 %@",[NSThread currentThread]);
//
//    }];
//    [op1 addExecutionBlock:^{
//
//        NSLog(@"op1-11111");
//
//    }];
//
//
//
//    NSBlockOperation *op2 = [NSBlockOperation blockOperationWithBlock:^{
//        NSLog(@"op2 %@",[NSThread currentThread]);
//
//    }];
//    [op2 addExecutionBlock:^{
//
//        NSLog(@"op2-11111");
//
//    }];
//
//
//
//    [op1 addDependency:op2];
    
    
    
   
    
    //设置等待
    

    
   
    
    
    
    //线程间通信:在主线程里更新UI
    
//    NSBlockOperation *op3 = [NSBlockOperation blockOperationWithBlock:^{
//        
//        NSLog(@"更新UI......%@",[NSThread currentThread]);}];
//    
//    [[NSOperationQueue mainQueue] addOperation:op3];
//    
//    
//    
//    [op3 addDependency:op2]; //依赖关系，可以跨队列
//    
    
    
}

-(void)demo4{
    sleep(3);
    NSLog(@"888");
    
    
}

-(void)demo3{
    NSOperationQueue *queue = [[NSOperationQueue alloc]init];
    __block dispatch_semaphore_t sem = dispatch_semaphore_create(0);
    NSBlockOperation *operation1 = [NSBlockOperation blockOperationWithBlock:^{
        
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            
            NSLog(@"请求数据好了->operation1");
            dispatch_semaphore_signal(sem);
        });
         dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
        
    }];
    NSBlockOperation *operation2 = [NSBlockOperation blockOperationWithBlock:^{
        
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSLog(@"请求数据好了->operation2");
            dispatch_semaphore_signal(sem);
            
        });
         dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
        
    }];
    NSBlockOperation *operation3 = [NSBlockOperation blockOperationWithBlock:^{
        
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSLog(@"请求数据好了->operation3");
            dispatch_semaphore_signal(sem);
        });
        dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
        
    }];
    
    [operation3 addDependency:operation2];
    [operation2 addDependency:operation1];
    
    [queue addOperations:@[operation1,operation2,operation3] waitUntilFinished:NO];
    
    dispatch_semaphore_signal(sem);
    NSBlockOperation *notification = [NSBlockOperation blockOperationWithBlock:^{
        
       NSLog(@"我在等待你们哟");
        
    }];
    [queue addOperation:notification];
    
   

    
    
    
    
    
}

-(void)demo2{
   
    
    __block dispatch_semaphore_t sem = dispatch_semaphore_create(5);
    
    dispatch_group_t group = dispatch_group_create();
    
    for (int i =0 ; i< 5; i++) {
        dispatch_group_async(group, dispatch_get_main_queue(), ^{
            
            dispatch_async(dispatch_get_main_queue(), ^{
                sleep(1);
                dispatch_semaphore_signal(sem);
                NSLog(@"%d",i);
            });
            dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
         
        });
        
        
        
    }

    dispatch_group_notify(group, dispatch_get_main_queue(), ^{
        NSLog(@"我来回调日狗");
    });
    
    

//    for (int i =0 ; i< 5; i++) {
//
//        __block NSBlockOperation *operation = [NSBlockOperation blockOperationWithBlock:^{
//            dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
//            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//                 NSLog(@"operation:%d",i);
//                 dispatch_semaphore_signal(sem);
//
//
//            });
//
//        }];
//        [queque addOperation:operation];
//
//
//
//    }
//
//
//
//    __block NSBlockOperation *callOperation = [NSBlockOperation blockOperationWithBlock:^{
//        dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            NSLog(@"我来回调日狗");
//            dispatch_semaphore_signal(sem);
//        });
//
//
//
//
//    }];
//
//    [queque addOperation:callOperation];
 

    

    
    
}

-(void)demo1{
    
    NSOperationQueue *queque1 = [[NSOperationQueue alloc]init];
    __block NSBlockOperation *op4 = [NSBlockOperation blockOperationWithBlock:^{
        NSLog(@"op4");
    }];
    __block NSBlockOperation *op5 = [NSBlockOperation blockOperationWithBlock:^{
        NSLog(@"op5");
    }];
    __block NSBlockOperation *op6 = [NSBlockOperation blockOperationWithBlock:^{
        
        
        __block dispatch_semaphore_t sem = dispatch_semaphore_create(0);
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            NSBlockOperation *op7 = [NSBlockOperation blockOperationWithBlock:^{
                for (int i=0; i<1; i++) {
                    NSLog(@"111");
                }
                dispatch_semaphore_signal(sem);
                NSLog(@"op7");
            }];
            [queque1 addOperation:op7];
            
        });
        
        dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
        NSLog(@"op6");
    }];
    
    __block NSBlockOperation *op1 = [NSBlockOperation blockOperationWithBlock:^{
        
        NSOperationQueue *queque2 = [[NSOperationQueue alloc]init];
        [queque2 addOperation:op6];
        
        
        [op4 addDependency:op6];
        [op5 addDependency:op6];
        [queque1 addOperation:op4];
        [queque1 addOperation:op5];
        
        
        NSLog(@"op1");
        
        
    }];
    NSBlockOperation *op2 = [NSBlockOperation blockOperationWithBlock:^{
        NSLog(@"op2");
    }];
    NSBlockOperation *op3 = [NSBlockOperation blockOperationWithBlock:^{
        NSLog(@"op3");
    }];
    
    [op1 addDependency:op2];
    [op2 addDependency:op3];
    [queque1 addOperation:op1];
    [queque1 addOperation:op2];
    [queque1 addOperation:op3];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
