//
//  MyArray.hpp
//  MyArray
//
//  Created by fangyukui on 2018/5/15.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray {
private:
    //一共可以容纳多少元素
    int mCapacity;
    //当前多少个数组
    int mSize;
    //数组首地址
    T *pAddr;
public:
    
    //构造
    MyArray(int capacity){
        this->mCapacity = capacity;
        this->mSize = 0;
        this->pAddr = new T[this->mCapacity];
        
    }
    
    //拷贝构造
    MyArray(const MyArray<T>& array){
        this->mSize = array.mSize;
        this->mCapacity = array.mCapacity;
        this->pAddr = new T[this->mCapacity];
        for (int i=0; i<array.mSize; i++) {
            this->pAddr[i] = array.pAddr[i];
        }
    }
    
    int getMSize(){
        return this->mSize;
    }
    
    //重载操作符
    T& operator[] (int index){
        return this->pAddr[index];
    }
    
    MyArray<T> operator=(const MyArray<T> & array){
        if (this->pAddr != NULL) {
            delete [] this->pAddr;
        }
        this->mSize = array.mSize;
        this->mCapacity = array.mCapacity;
        this->pAddr = new T[this->mCapacity];
        for (int i=0; i<array.mSize; i++) {
            this->pAddr[i] = array.pAddr[i];
        }
        return this;
    }
    
    void pushBack(const T& data){
        if (this->mSize >= this->mCapacity) {
            return;
        }
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
    
#if 0
    void pushBack(const T& data){
        if (this->mSize >= this->mCapacity) {
            return;
        }
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
#endif
    ~MyArray(){
        cout<<"析构函数"<<endl;
        if (this->pAddr != NULL) {
            delete [] this->pAddr;
            this->mCapacity = 0;
            this->mSize = 0;
        }
    }
    
    
    
};
