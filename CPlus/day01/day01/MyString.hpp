//
//  MyString.hpp
//  day01
//
//  Created by fangyukui on 2018/3/28.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;


class MyString{
private:
    long length;
    char *p;
public:
    MyString(){
        this->length = 0;
        this->p = new char[this->length+1];
        strcpy(this->p, "");
        
    }
    MyString(const char *p){
        if (p == NULL) {
            this->length = 0;
            this->p = new char[this->length+1];
            strcpy(this->p, "");
        }else{
            this->length = strlen(p);
            this->p = new char[this->length+1];
            strcpy(this->p, p);
            
        }
    }
    MyString(const MyString& obj){
        this->length = obj.length;
        this->p = new char[this->length+1];
        strcpy(this->p, obj.p);
    }
    ~MyString(){
        if (this->p != NULL) {
            delete [] this->p;
            this->p = NULL;
            this->length = 0;
        }
    }
    void description(){
        cout << this->p <<endl;
    }
    
};

