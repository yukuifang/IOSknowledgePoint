//
//  EqualOperation.hpp
//  day01
//
//  Created by fangyukui on 2018/3/28.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;
class Name{
private:
    long length;
    char *p;
public:
    Name(const char *p){
        this->length =  strlen(p);
        this->p = (char *)malloc(this->length + 1);
        strcpy(this->p, p);
    }
    //自定义深拷贝
    Name(const Name& obj){
        this->length =  strlen(obj.p);
        this->p = (char *)malloc(this->length + 1);
        strcpy(this->p, obj.p);
    }
    ~Name(){
        if (this->p != NULL) {
            free(this->p);
            this->p = NULL;
            this->length = 0;
        }
    }
    Name& operator=(const Name& obj){
        if (this->p != NULL) {
            free(this->p);
            this->p = NULL;
            this->length = 0;
        }
        this->length  = strlen(obj.p);
        this->p =  (char *)malloc(this->length+1);
        strcpy(this->p, obj.p);
        return *this;
    }
    void description(){
        cout<< this->p << endl;
    }
};





