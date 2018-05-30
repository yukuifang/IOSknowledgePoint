//
//  SeqQueue.cpp
//  SeqQuque
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "SeqQueue.hpp"
#include <iostream>
//初始化
SeqQueue *init_SeqQueue(){
    SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
    for (int i=0; i<MAX_SIZE; i++) {
        queue->data[i] = NULL;
    }
    queue->size = 0;
    return queue;
}

//入队列
void push_SeqQueue(SeqQueue *queue,void *data){
    if (queue==NULL) return;
    if (data==NULL) return;
    if (queue->size == MAX_SIZE)return;
    queue->data[queue->size] = data;
    queue->size++;
}
//取出对首第一个,数组左边为对首
void *front_SeqQueue(SeqQueue *queue){
    if (queue==NULL) return NULL;
    if (queue->size==0)return NULL;
    return queue->data[0];
    
}

//出队列
void pop_SeqQueue(SeqQueue *queue){
    if (queue==NULL) return;
    for (int i=0; i<queue->size-1; i++) {
        queue->data[i] = queue->data[i+1];
    }
    queue->size--;
    
}
//取出对尾第一个,数组右边为对尾
void *back_SeqQueue(SeqQueue *queue){
    if (queue==NULL) return NULL;
    if (queue->size==0)return NULL;
    return queue->data[queue->size-1];
    
}

//队列个数
int size_SeqQueue(SeqQueue *queue){
    if (queue==NULL) return 0;
    return queue->size;
}

//清空队列
void clear_SeqQueue(SeqQueue *queue){
    if (queue==NULL) return;
    queue->size = 0;
}

//释放内存
void freeSpace_SeqQueue(SeqQueue *queue){
    if (queue==NULL) return;
    free(queue);
    return;
}
