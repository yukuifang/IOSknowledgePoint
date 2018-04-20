//
//  Step.hpp
//  day01
//
//  Created by fangyukui on 2018/4/19.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

#include <iostream>

using namespace std;

class Step_Parent{
protected:
    int a;
public:
    Step_Parent(int a){
        this->a = a;

    }
    
    virtual void description(){
        cout << "父类描述" << endl;
        
    }
    virtual ~Step_Parent(){

    }
    
};

class Step_Chird:public Step_Parent{
private:
    int b;
    int c;
public:
    Step_Chird(int a,int b):Step_Parent(a){
        this->b = b;
        this->a = a;
        
        
    }
    Step_Chird(int a):Step_Parent(a){
        
    }
    
    virtual void description(){
        cout << "子类描述" << endl;
        
    }
    virtual ~Step_Chird(){
        
    }
};


