
//
//  SeqStack.cpp
//  SeqStack
//
//  Created by fangyukui on 2018/5/28.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "SeqStack.hpp"
#include <iostream>


//初始化栈
SeqStack *init_SeqStack(){
    SeqStack *seqStack = (SeqStack *)malloc(sizeof(SeqStack *));
    for (int i=0; i<MAX_SIZE; i++) {
        seqStack->data[i] = NULL;
    }
    seqStack->size = 0;
    return seqStack;
}

//入栈
void push_SeqStack(SeqStack *seqStack,void *data){
    if (seqStack == NULL) return;
    if (data == NULL) return;
    if (seqStack->size == MAX_SIZE) {
        return;
    }
    seqStack->data[seqStack->size] = data;
    seqStack->size++;
}

//返回栈顶元素
void *top_SeqStack(SeqStack *seqStack){
    if (seqStack == NULL) return NULL;
    if (seqStack->size == 0) return NULL;
    return seqStack->data[seqStack->size-1];
}

//出栈
void pop_SeqStack(SeqStack *seqStack){
    if (seqStack == NULL) return;
    if (seqStack->size == 0) return;
    seqStack->size--;
    
}

//判断是否为空
int isEmpty(SeqStack *seqStack){
    if (seqStack == NULL) return SEQSTACK_TRUE;
    if (seqStack->size==0) return SEQSTACK_TRUE;
    return SEQSTACK_FALSE;
}

//返回栈中元素个数
int size_SeqStack(SeqStack *seqStack){
    if (seqStack == NULL) return 0;
    return seqStack->size;
}

//清空
void clear_SeqStack(SeqStack *seqStack){
    if (seqStack == NULL) return;
    for (int i=0; i<seqStack->size; i++) {
        seqStack->data[i] = NULL;
    }
    seqStack->size = 0;
}

//销毁
void freeSpace_SeqStack(SeqStack *seqStack){
    if (seqStack == NULL) return;
    free(seqStack);
}
