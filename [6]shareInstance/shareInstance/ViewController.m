//
//  ViewController.m
//  shareInstance
//
//  Created by fangyukui on 2018/3/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"

#import "Downloador.h"

#import "Player.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    Downloador *downLoader1 = [Downloador shareInstance];
//    Downloador *downLoader2 = [Downloador shareInstance];
//
//    NSLog(@"%@",downLoader1);
//    NSLog(@"%@",downLoader2);
    
    
    Player *player1 = [Player shareInstance];
    Player *player2 = [Player shareInstance];
    
    NSLog(@"%@",player1);
    NSLog(@"%@",player2);
    
    
    
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
