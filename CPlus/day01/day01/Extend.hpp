//
//  Extend.hpp
//  day01
//
//  Created by fangyukui on 2018/3/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

class Parent{
private:
    int a;
protected:
    int b;
public:
    int c;
};

//Chird1继承public Parent,存在父类属性a,b,c,只能访问b,c
class Chird1:public Parent{
public:
    void description(){
        cout  << this->b << this->c << endl;
    }
};
//Chird2继承protected Parent,存在父类属性a,b,c,此时public c 降级为protected ,只能访问b,c
class Chird2:protected Parent{
public:
    void description(){
        cout  << this->b << this->c << endl;
    }
};
//Chird3继承protected Parent,存在父类属性a,b,c,此时protected b , public c皆降级为private ,只能访问b,c
class Chird3:private Parent{
public:
    void description(){
        cout  << this->b << this->c << endl;
    }
};



