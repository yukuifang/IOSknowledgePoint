//
//  Test.hpp
//  day01
//
//  Created by fangyukui on 2018/3/23.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

class Test{
private:
    int a;
    int b;
    char *p;
public:
    Test();
    Test(int a,int b);
    Test(int a);
    Test(const Test &t);
    ~Test();
    void printMessage();
};

