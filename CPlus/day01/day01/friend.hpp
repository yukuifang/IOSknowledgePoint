//
//  friend.hpp
//  day01
//
//  Created by fangyukui on 2018/3/27.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;
class A{
    friend class B;
private:
    int a;
    int b;
public:
    A(int a=0,int b=0){
        this->a = a;
        this->b =b;
        cout << "构造函数"<<endl;
        
    }
    ~A(){
        cout << "析构函数"<<endl;
    }
};

class B{
private:
    int a;
    int b;
    A aObject;
public:
    B(int a=0,int b=0){
        this->a = a;
        this->b =b;
        cout << "构造函数"<<endl;
        
    }
    ~B(){
        cout << "析构函数"<<endl;
    }
public:
    void modifyA(){
        this->aObject.a = 100;
        this->aObject.b = 200;
        cout << this->aObject.a << endl;
        cout << this->aObject.b << endl;
        
        
    }
};
