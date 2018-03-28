//
//  OperationOverload.cpp
//  day01
//
//  Created by fangyukui on 2018/3/27.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "OperationOverload.hpp"


Complex operator-(Complex &a,Complex &b){
    Complex c(a.x - b.x, a.y - b.y);
    return c;
}

Complex& operator++(Complex &a){
    ++a.x;
    ++a.y;
    return a;
}

Complex operator++(Complex &a,int){
    Complex temp = a;
    a.x++;
    a.y++;
    return temp;
}
