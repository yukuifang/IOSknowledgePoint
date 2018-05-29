//
//  SeqStack.hpp
//  SeqStack
//
//  Created by fangyukui on 2018/5/28.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#define MAX_SIZE 1024
#define SEQSTACK_TRUE   1
#define SEQSTACK_FALSE  0


typedef struct SEQSTACK{
    void *data[MAX_SIZE];
    int size;
}SeqStack;


//初始化栈
SeqStack *init_SeqStack();

//入栈
void push_SeqStack(SeqStack *seqStack,void *data);

//返回栈顶元素
void *top_SeqStack(SeqStack *seqStack);

//出栈
void pop_SeqStack(SeqStack *seqStack);

//判断是否为空
int isEmpty(SeqStack *seqStack);

//返回栈中元素个数
int size_SeqStack(SeqStack *seqStack);

//清空
void clear_SeqStack(SeqStack *seqStack);

//销毁
void freeSpace_SeqStack(SeqStack *seqStack);

