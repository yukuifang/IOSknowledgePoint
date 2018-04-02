//
//  Polymorphism.hpp
//  day01
//
//  Created by fangyukui on 2018/4/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

class KPatent{
private:
    int a;
public:
    KPatent(int a){
      this-> a = a;
        
    }
    virtual void descripsion(){
        cout << this->a << endl;
        cout << "父类函数" << endl;
    }
    void parentFun(){
        cout << "parentFun" <<endl;
    }
};

class KChrid:public KPatent{
private:
    int b;
public:
    KChrid(int b):KPatent(10) {
        this->b = b;
        
    }
    virtual void descripsion(){
        cout << this->b << endl;
         cout << "子类函数" << endl;
    }
    void chridFun(){
        cout << "chridFun" <<endl;
    }
};




