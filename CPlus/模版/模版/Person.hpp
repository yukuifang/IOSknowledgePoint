//
//  Person.hpp
//  模版
//
//  Created by fangyukui on 2018/5/15.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

template <class T>
class Person{
public:
    static int a;
};

template <class T> int Person<T>::a = 0;






