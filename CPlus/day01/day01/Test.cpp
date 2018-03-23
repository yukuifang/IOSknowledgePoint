//
//  Test.cpp
//  day01
//
//  Created by fangyukui on 2018/3/23.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "Test.hpp"
#include <iostream>
using namespace std;




Test::Test(){
    this->a = 1;
    this->b = 2;
    this->p = (char *)malloc(100);
    strcpy(this->p, "abcdefg");
    cout <<"无参构造" << "初始化工作" <<endl;
    
}
Test::Test(int a,int b){
    this->a = a;
    this->b = b;
    this->p = (char *)malloc(100);
    strcpy(this->p, "abcdefg");
    cout <<"2个有参构造" << "初始化工作" <<endl;
    
}
Test::Test(int a){
    this->a = a;
    this->b = 2;
    this->p = (char *)malloc(100);
    strcpy(this->p, "abcdefg");
    cout <<"1个有参构造" << "初始化工作" <<endl;
    
}
Test::Test(const Test &t){
    this->a = t.a;
    this->b = t.b;
    this->p = (char *)malloc(100);
    strcpy(this->p, "abcdefg");
    
    
    cout <<"copy构造" << "初始化工作" <<endl;
}
void Test::printMessage(){
    cout << "a=" << this->a << ",b=" << this->b << endl;
    
}

Test::~Test(){
    this->a = 0;
    this->b = 0;
    if (this->p != NULL) {
        free(this->p);
        this->p = NULL;
    }
    
    
    cout << "析构工作" <<endl;
}
