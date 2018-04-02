//
//  Extend_2.hpp
//  day01
//
//  Created by fangyukui on 2018/3/30.
//  Copyright © 2018年 fangyukui. All rights reserved.
//


#pragma once

#include <iostream>

using namespace std;

class BObject{
public:
    BObject(){
        cout << "BObject构造函数" << endl;
    }
    ~BObject(){
        cout << "BObject析构函数" << endl;
        
    }
    
};


class BParent:public BObject{
protected:
    int a;
    int b;
public:
    BParent(int a,int b){
        this->a = a;
        this->b = b;
        cout << "父类构造函数" <<endl;
        
    }
    ~BParent(){
        cout << "父类析构函数" <<endl;
    }
    
    
};

class BChrid:public BParent{
protected:
    BObject obj1;
    BObject obj2;
    
public:
    BChrid(int a,int b):obj1(),obj2(),BParent(a,b){
        
        cout << "子类构造函数" <<endl;
        
    }
    ~BChrid(){
        cout << "子类析构函数" <<endl;
    }
};




