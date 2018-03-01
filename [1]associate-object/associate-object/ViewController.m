//
//  ViewController.m
//  associate-object
//
//  Created by fangyukui on 2018/3/1.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"
#import "Person+Joy.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    Person *p =[[Person alloc]init];
    p.salary = @"10";
    NSLog(@"joy的工资是:%@",p.salary);
}





@end
