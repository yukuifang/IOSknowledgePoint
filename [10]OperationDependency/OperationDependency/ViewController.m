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
    // Do any additional setup after loading the view, typically from a nib.
    
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
                for (int i=0; i<1000; i++) {
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
