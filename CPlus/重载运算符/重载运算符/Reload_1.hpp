//
//  Reload_1.hpp
//  重载运算符
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

class Sqr{
private:
    int value;
public:
    Sqr(){
        
    }
    Sqr(int value){
        cout << "构造函数" << "  the  value is : " << value  << endl;
        this->value = value;
    }
    ~Sqr(){
        cout << "析构函数" << endl;
    }
    void * operator new(size_t size){
        cout << "重载了new操作符" << "  the size is : " << size << endl;
        return malloc(size);
    }
    void operator delete(void *p){
        cout << "重载了delete操作符" << endl;
        if(p != NULL){
            free(p);
            p = NULL;
        }
    }
    void *operator new[](size_t size){
        cout << "重载了new[]操作符" << "  the size is : " << size << endl;
        return malloc(size);
    }
    void operator delete[](void *p){
        cout << "重载了delete[]操作符" << endl;
        if(p != NULL){
            free(p);
            p = NULL;
        }
        
    }
        
    
    
    int operator()(int value){
        return value * value;
    }
};


