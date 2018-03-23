//
//  reload.cpp
//  day01
//
//  Created by fangyukui on 2018/3/22.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "reload.hpp"
#include <iostream>
using namespace std;
void caluate(double a, double b){
    cout << a-b << endl;
}

void caluate(int a, int b){
    cout << a+b << endl;
}

void caluate(int a){
    int result = a *a;
    cout << result << endl;
    
}

void caluate(double a){
    cout << a << endl;
}
