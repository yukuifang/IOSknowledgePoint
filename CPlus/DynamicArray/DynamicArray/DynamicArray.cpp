//
//  DynamicArray.cpp
//  DynamicArray
//
//  Created by fangyukui on 2018/5/22.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "DynamicArray.hpp"
#include <iostream>
using namespace std;

Dynamic_Array *init_Array(){
    //申请内存
    Dynamic_Array *marray = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
    //初始化
    marray->size = 0;
    marray->capacity = 20;
    marray->pAddr = (int *)malloc(sizeof(int) * marray->capacity);
    return marray;
}

//插入
void pushBack_Array(Dynamic_Array *array,int value){
    if (array == NULL)return;
    //判断空间是否足够
    if (array->size == array->capacity) {
        //第一步:申请一块更大的空间，策略:新空间是旧空间的两倍
        int *newSpace =  (int *)malloc(sizeof(int) * array->capacity *2);
        //第二步:拷贝旧数据
        memcpy(newSpace, array->pAddr,sizeof(int) * array->capacity);
        //第三步:释放旧空间内存
        free(array->pAddr);
        //第四步:更新内存
        array->capacity = array->capacity * 2;
        array->pAddr = newSpace;
        
    }
    array->pAddr[array->size] = value;
    array->size++;
}

void removeByPos_Array(Dynamic_Array *array,int pos){
    if (array == NULL)return;
    if (pos < 0 ||  pos >= array->size)return;
    for (int i = pos; i < array->size; i++) {
        array->pAddr[i] = array->pAddr[i+1];
        
    }
    array->size--;
}

int find_Array(Dynamic_Array *array,int value){
    if (array == NULL)return -1;
    int pos = -1;
    for (int i=0; i<array->size; i++) {
        if (array->pAddr[i] == value) {
            pos = i;
            break;
        }
    }
    return pos;
}

void removeByValue_Array(Dynamic_Array *array,int value){
    if (array == NULL)return;
    int pos = find_Array(array, value);
    removeByPos_Array(array, pos);
}


//打印
void printf_Array(Dynamic_Array *array){
    if (array == NULL)return;
    for (int i=0; i<array->size; i++) {
        cout << array->pAddr[i]<< endl;
    }
}
//释放动态数组内存
void freeSpace_Array(Dynamic_Array *array){
    if (array == NULL)return;
    if (array->pAddr != NULL) {
        free(array->pAddr);
    }
    free(array);
    
}
//清空数组
void clear_Array(Dynamic_Array *array){
    if (array == NULL)return;
    array->size = 0;
}

//容量大小
int capacity_Array(Dynamic_Array *array){
    if (array == NULL)return 0;
    return array->capacity;
}

//使用的个数
int size_Array(Dynamic_Array *array){
    if (array == NULL)return 0;
    return array->size;
}
//
int at_Array(Dynamic_Array *array,int pos){
    if (array == NULL)return NULL;
    return array->pAddr[pos];
}


