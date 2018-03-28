//
//  Test2.hpp
//  day01
//
//  Created by fangyukui on 2018/3/26.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;


class Test2{
public:
    int a;
    int b;
public:
    Test2(int a=0,int b =0){
        this->a = a;
        this->b = b;
        cout << "构造函数" << endl;
    }
    Test2(const Test2 &t){
        
    }
    ~Test2(){
        cout << "析构函数" << endl;
    }
    
};


