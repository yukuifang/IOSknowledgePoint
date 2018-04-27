//
//  MethodTemplate.hpp
//  day01
//
//  Created by fangyukui on 2018/4/27.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

template <typename T>
double addTemplate(T num1, T num2) {
    return num1 + num2;
}

template <typename T1,typename T2>
int mySort(T1 *array,int size){
    return 888;
}

//普通函数可以进行隐世的类型转换
bool myChange(char &c1, int  &c2);

//以下两个构成函数重载，同一作用域下产生的是重载
//函数模版的含义就是类型参数化，将严格按照类型进行匹配，不会进行自动类型转换
template <typename T1>
bool myChange(T1 &c1,T1 &c2) {
    T1 temp = c1;
    c1 = c2;
    c2 = temp;
    cout << "函数模版" << endl;
    return true;
}





