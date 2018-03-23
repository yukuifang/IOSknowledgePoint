//
//  Cube.cpp
//  day01
//
//  Created by fangyukui on 2018/3/23.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "Cube.hpp"

void Cube::setABC(int a,int b,int c){
    this->a = a;
    this->b = b;
    this->c = c;
    
}

int Cube::getS(){
    return 2 * (this->a * this->b + this->a * this->c + this->b * this->c);
    
}

int Cube::getV(){
    return this->a * this->b * this->c;
}

bool Cube::judgeCube(Cube &c){
    if (this->a == c.a && this->b == c.b&& this->c == c.c) {
        return true;
    }
    return false;
}
