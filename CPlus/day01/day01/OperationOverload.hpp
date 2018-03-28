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
    Complex(int x,int y){
        this->x = x;
        this->y = y;
    }
public:
    Complex operator+(Complex &c){
        return Complex(c.x + this->x,c.y + this->y);
    }
    Complex operator-(Complex &c){
        return Complex(c.x - this->x,c.y - this->y);
    }
    Complex operator*(Complex &c){
        return Complex(c.x * this->x,c.y * this->y);
    }
    Complex& operator++(){
        ++ this->x;
        ++ this->y;
        return *this;
    }
    Complex operator++(int){
        Complex temp = *this;
        this->x++;
        this->y++;
        return temp;
    }
    Complex& operator--(){
        -- this->x;
        -- this->y;
        return *this;
    }
    Complex operator--(int){
        Complex temp = *this;
        this->x--;
        this->y--;
        return temp;
    }
    void operator=(Complex &c){
        
        
    }
    void description(){
        cout << "x=" << this->x << ",and,y=" << this->y <<endl;
        
    }
};
//友元类应用场景
ostream& operator<<(ostream &cout, Complex &c);














