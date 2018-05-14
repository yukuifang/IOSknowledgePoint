//
//  VirtureDestruct.hpp
//  day01
//
//  Created by fangyukui on 2018/4/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

#include <iostream>

//虚析构函数

using namespace std;

class J{
private:
    char *p;
public:
    J(){
        p = new char[20];
        strcpy(p, "6666");
        cout << "J 构造"<<endl;
        
    }
    virtual ~J(){
//        if (p) {
//            delete [] p;
//            p = NULL;
//        }
        
        cout << "J 析构" << endl;
    }
    
};

class JA:public J {
private:
    char *p;
public:
    JA(){
        p = new char[20];
        strcpy(p, "6666");
        cout << "JA 构造"<<endl;
        
    }
    virtual ~JA(){
        delete [] p;
        cout << "JA 析构" << endl;
    }
    
};

class JB:public JA {
private:
    char *p;
public:
    JB(){
        p = new char[20];
        strcpy(p, "6666");
        cout << "JB构造"<<endl;
        
    }
    virtual ~JB(){
        delete [] p;
        cout << "JB 析构" << endl;
    }
    
};



