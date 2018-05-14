//
//  ViewController.m
//  testo
//
//  Created by fangyukui on 2018/5/11.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"

#define InterceptLoginShowAlertAutoInvokTheSelector \
UIAlertController *alertController =  \
[UIAlertController  alertControllerWithTitle:@"提示"message:@"拨打客服电话"preferredStyle:UIAlertControllerStyleAlert]; \
UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"  style:UIAlertActionStyleCancel handler:nil];  \
UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"好的"  style:UIAlertActionStyleDefault handler:nil]; \
[alertController addAction:cancelAction]; \
[alertController addAction:okAction]; \
[self presentViewController:alertController animated:YES   completion:nil]; \
//BOOL a  = [alertController respondsToSelector:@selector(viewWillDisappear:)]; \
//if (a) { \
//    NSLog(@"666");\
//}\




@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    InterceptLoginShowAlertAutoInvokTheSelector
    [self performSelector:@selector(hello) onThread:[NSThread mainThread] withObject:nil waitUntilDone:YES modes:@[NSRunLoopCommonModes]];
    
    
    [[NSRunLoop currentRunLoop]addPort:[NSPort port] forMode:NSRunLoopCommonModes];
    
    
    
//    BOOL a  = [self respondsToSelector:@selector(viewWillDisappear:)];
//    if (a) {
//        NSLog(@"666");
//    }
    
    
   
}
-(void)hello{
    NSLog(@"66");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
