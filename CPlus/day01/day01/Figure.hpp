//
//  Figure.hpp
//  day01
//
//  Created by fangyukui on 2018/4/19.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

//含有纯虚函数的类叫抽象类abstract  ,抽象类不可以建立对象FigureAbstract t,这是错的；但是可以定义抽象类指针:FigureAbstract  *t;抽象类不可以作为参数或者返回值，但是其引用可以

class FigureAbstract{
public:
   //纯虚函数
   virtual void getArea() = 0;
};



class Triangle:public FigureAbstract{
public:
    virtual void getArea(){
        cout << "getArea from Triangle" <<endl;
    }
};

class Square:public FigureAbstract{
public:
    virtual void getArea(){
        cout << "getArea from Square" <<endl;
    }
};

