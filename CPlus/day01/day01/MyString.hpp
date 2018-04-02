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
    friend ostream & operator<<(ostream &cout,MyString &obj) ;
private:
    long length;
    char *p;
public://构造和析构
    MyString(long length = 0){
        this->length = length;
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
public://操作符重载
    MyString& operator=(const char *p){
        if (this->p != NULL) {
            delete [] this->p;
            this->p = NULL;
            this->length = 0;
        }
        this->length = strlen(p);
        this->p = new char[this->length+1];
        strcpy(this->p, p);
        return *this;
        
    }
    MyString& operator=(const MyString& obj){
        if (this->p != NULL) {
            delete [] this->p;
            this->p = NULL;
            this->length = 0;
        }
        this->length = obj.length;
        this->p = new char[this->length+1];
        strcpy(this->p, obj.p);
        return *this;
        
    }
    //const 放在后面修饰函数参数，包括隐示参数this
    char& operator[](int index) const{
        return  this->p[index];
        
    }
    bool operator==(const char* p) const{
        return  !strcmp(this->p, p);
    }
    bool operator==(const MyString& s) const{
        return !strcmp(this->p, s.p);
        
        
    }

public:
    void description(){
        cout << this->p <<endl;
    }
    
};
ostream & operator<<(ostream &cout,MyString &obj);


