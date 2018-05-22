//
//  DynamicArray.hpp
//  DynamicArray
//
//  Created by fangyukui on 2018/5/22.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

typedef struct DYNAMICARRAY{
    int *pAddr;
    int size;
    int capacity;
}Dynamic_Array;

Dynamic_Array *init_Array();

void pushBack_Array(Dynamic_Array *array,int value);

void removeByPos_Array(Dynamic_Array *array,int pos);

void removeByValue_Array(Dynamic_Array *array,int value);

int find_Array(Dynamic_Array *array,int value);

void printf_Array(Dynamic_Array *array);

void freeSpace_Array(Dynamic_Array *array);

void clear_Array(Dynamic_Array *array);

int capacity_Array(Dynamic_Array *array);

int size_Array(Dynamic_Array *array);

int at_Array(Dynamic_Array *array,int pos);





