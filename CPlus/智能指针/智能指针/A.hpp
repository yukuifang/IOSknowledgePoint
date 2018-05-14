//
//  A.hpp
//  智能指针
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;


class A{
private:
    int a;
    
public:
    A(int a){
        this->a = a;
        cout << "A 构造" <<endl;
    }
    ~A(){
        cout << "A 析构" <<endl;
    }
    
};

