//
//  Extend_1.hpp
//  day01
//
//  Created by fangyukui on 2018/3/30.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

#include <iostream>

using namespace std;
class AParent{
public:
    int a;
    int b;
public:
    AParent(int a,int b){
        this->a = a;
        this->b = b;
        cout << "父类构造函数" <<endl;
        
    }
    ~AParent(){
        cout << "父类析构函数" <<endl;
    }
    
    
};

class AChrid:public AParent{
public:
    int c;
public:
    AChrid(int a,int b,int c):AParent(a,b){
        this->c = c;
        cout << "子类构造函数" <<endl;
        
    }
    ~AChrid(){
        cout << "子类析构函数" <<endl;
    }
};



