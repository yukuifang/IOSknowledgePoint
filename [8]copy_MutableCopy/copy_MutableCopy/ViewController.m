//
//  ViewController.m
//  copy_MutableCopy
//
//  Created by fangyukui on 2018/3/5.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import "ViewController.h"


@interface ViewController ()
@property (nonatomic, copy) NSMutableArray *mutableArray;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    NSMutableArray *array = [NSMutableArray arrayWithObjects:@1,@2,nil];
//    self.mutableArray = array;
//    [self.mutableArray removeObjectAtIndex:0];
    
    
    int k[]={1,2,3,4,5,6};
    int *p=k;
    printf("%d\n",*p++);
    printf("%d\n",(*p)++);
    printf("%d\n",*++p);
    printf("%d\n",++*p);
    
    

    
   
    



    
    
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
