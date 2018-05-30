//
//  SeqQueue.hpp
//  SeqQuque
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

#define MAX_SIZE 100

typedef struct SEQQUEUE{
    void *data[MAX_SIZE];
    int size;
}SeqQueue;

//初始化
SeqQueue *init_SeqQueue();

//入队列
void push_SeqQueue(SeqQueue *queue,void *data);

//出队列
void pop_SeqQueue(SeqQueue *queue);

//取出对首第一个
void *front_SeqQueue(SeqQueue *queue);

//取出对尾第一个
void *back_SeqQueue(SeqQueue *queue);

//队列个数
int size_SeqQueue(SeqQueue *queue);

//清空队列
void clear_SeqQueue(SeqQueue *queue);

//释放内存
void freeSpace_SeqQueue(SeqQueue *queue);




