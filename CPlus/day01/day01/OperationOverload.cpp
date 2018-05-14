//
//  OperationOverload.cpp
//  day01
//
//  Created by fangyukui on 2018/3/27.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "OperationOverload.hpp"

ostream& operator<<(ostream &cout, Complex &c){
    cout << "x=" <<  c.x << ",y=" << c.y << " ";
    return cout;
}
Complex::Complex(int x,int y){
    this->x = x;
    this->y = y;
}

Complex Complex::operator+(const Complex &c){
    return Complex(c.x + this->x,c.y + this->y);
}

Complex Complex::operator-(const Complex &c){
    return Complex(c.x - this->x,c.y - this->y);
}

Complex Complex::operator*(const Complex &c){
    return Complex(c.x * this->x,c.y * this->y);
}

Complex& Complex::operator++(){
    ++ this->x;
    ++ this->y;
    return *this;
}
Complex& Complex::operator++(int){
    this->x++;
    this->y++;
    return *this;
}
Complex& Complex::operator--(){
    -- this->x;
    -- this->y;
    return *this;
}
Complex Complex::operator--(int){
    this->x--;
    this->y--;
    return *this;
}

void Complex::description(){
    cout << "x=" << this->x << ",and,y=" << this->y <<endl;
}



