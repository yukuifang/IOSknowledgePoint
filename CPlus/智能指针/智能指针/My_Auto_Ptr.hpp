//
//  My_Auto_Ptr.hpp
//  智能指针
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
#include "A.hpp"
using namespace std;

template <typename E>
class My_Auto_Ptr{
private:
    E *ptr;
public:
    My_Auto_Ptr(E *ptr){
        this->ptr = ptr;
    }
    ~My_Auto_Ptr(){
        if (this->ptr != NULL) {
            delete this->ptr; //delete会自动调用析构函数，free不会自动调用析构函数；new会自动调用构造函数，malloc不会自动调用构造函数
            this->ptr = NULL;
            
        }
    }
    
};


