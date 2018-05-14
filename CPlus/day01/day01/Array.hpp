//
//  Array.hpp
//  day01
//
//  Created by fangyukui on 2018/3/28.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

class Array{
private:
    int length;
    int *space;
public:
    Array(int length){
        if (length<0) {
            length=0;
        }
        this->length = length;
        this->space = new int(this->length);
    }
    Array(const Array& obj){
        this->length = obj.length;
        this->space = new int(this->length);
        for (int i=0; i<this->length; i++) {
            this->space[i] = obj.space[i];
        }
    }
    ~Array(){
        if (this->space != NULL) {
            free(this->space);
            this->space = NULL;
            this->length = 0;
            
        }
    }
    
public:
    void setData(int index,int value){
        if (index>=0 && index < this->length) {
            this->space[index] = value;
        }
    }
    int getData(int index){
        if (index>=0 && index < this->length) {
            return this->space[index];
        }
        return -1;
    }
    int getLength(){
        return this->length;
    }
    int& operator[](int index){
        return this->space[index];
        
    }
    Array& operator=(Array &obj){
        if(&obj ==  this)return *this;
        if (this->space != NULL) {
            free(this->space);
            this->space = NULL;
            this->length = 0;
        }
        this->length = obj.length;
        this->space = new int[this->length];
        for (int i=0; i<this->length; i++) {
            this->space[i] = obj[i];
            
        }
        return *this;
    }
    bool operator==(Array &obj){
        if (this->length == obj.length) {
            for (int i=0; i<this->length; i++) {
                if (this->space[i] != obj[i]) {
                    return false;
                }
            }
            return true;
            
        }
        return false;
    }
    
    
    
};
