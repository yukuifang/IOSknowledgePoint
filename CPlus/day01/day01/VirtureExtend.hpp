//
//  VirtureExtend.hpp
//  day01
//
//  Created by fangyukui on 2018/4/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

class K{
public:
    int a;
public:
    K(){
        cout << "K构造" << endl;
        
    }
};

class K1 :virtual public K{
public:
    int b;
public:
    K1(){
       cout << "K1构造" << endl;
    }
};

class K2 : virtual public K{
public:
    int c;
public:
    K2(){
        cout << "K2构造" << endl;
    }
};

class K3:public K1 , public K2{
public:
    int d;
public:
    K3(){
        cout << "K3构造" << endl;
    }
};



class E1{
public:
    int a;
    
};

class E2{
public:
    int a;
};

class E3 : public E1 ,public E2{
public:
    int b;
    
};





