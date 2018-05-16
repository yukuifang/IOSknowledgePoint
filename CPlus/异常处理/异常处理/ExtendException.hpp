//
//  ExtendException.hpp
//  异常处理
//
//  Created by fangyukui on 2018/5/16.
//  Copyright © 2018年 fangyukui. All rights reserved.
//


#pragma once
#include <iostream>
using namespace std;

class BaseException{
public:
    virtual void what() = 0;
    virtual ~BaseException() {};
};

class TargetSpaceNullException:public BaseException{
public:
    virtual void what() {
        cout << "目标文件为空" <<endl;
        
    }
    virtual ~TargetSpaceNullException(){}
};

class SourceSpaceNullException:public BaseException{
public:
    virtual void what() {
        cout << "源文件为空" <<endl;
        
    }
    virtual ~SourceSpaceNullException(){}
};


