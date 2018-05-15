//
//  Animal.hpp
//  模版
//
//  Created by fangyukui on 2018/5/15.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;
template <class T>
class Animal {
public:
    T myAge;
public:
    void sound(){
        cout << myAge << "岁的动物在叫" << endl;
    }
    
};

template <class T>
class Cat:public Animal<T>{
    
};
