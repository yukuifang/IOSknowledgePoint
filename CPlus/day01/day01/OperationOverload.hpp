//
//  OperationOverload.hpp
//  day01
//
//  Created by fangyukui on 2018/3/27.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

class Complex{
    friend ostream& operator<<(ostream &cout, Complex &c);
private:
    int x;
    int y;
public:
    Complex(int x,int y);
    Complex(const Complex&c);
    void operator=(const Complex &c);
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex& operator++();
    Complex& operator++(int);
    Complex& operator--();
    Complex operator--(int);
    void description();
    
};
//友元类应用场景
ostream& operator<<(ostream &cout,const Complex &c);














