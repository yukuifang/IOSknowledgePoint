//
//  LinkQueue.cpp
//  LinkQueue
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "LinkQueue.hpp"
#include <iostream>
using namespace std;

//初始化
LinkQueue *init_LinkQueue(){
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    queue->head.next = NULL;
    queue->size = 0;
    return queue;
}

//入队列
void push_LinkQueue(LinkQueue *queue,LinkNode *node){
    if (queue == NULL) return;
    if (node  ==  NULL) return;
    queue->head.next = node;
    node->next =  NULL;
    queue->size++;
    
    
}

//出队列
void pop_LinkQueue(LinkQueue *queue){
    if (queue == NULL) return;
    LinkNode *delQueue = queue->head.next;
    queue->head.next = delQueue->next;
    queue->size--;
    
}

//取出对首第一个,数组左边为对首
LinkNode * front_LinkQueue(LinkQueue *queue){
    if (queue == NULL) return NULL;
    return queue->head.next;
}

//取出对尾第一个
LinkNode *back_LinkQueue(LinkQueue *queue){
    if (queue == NULL) return NULL;
    LinkNode *currentNode = queue->head.next;
    while (currentNode->next!=NULL) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

//队列个数
int size_LinkQueue(LinkQueue *queue){
    if (queue == NULL) return 0;
    return queue->size;
    
}

//清空队列
void clear_LinkQueue(LinkQueue *queue){
    if (queue == NULL) return;
    queue->head.next = NULL;
    
}

//释放内存
void freeSpace_LinkQueue(LinkQueue *queue){
    if (queue == NULL) return;
    free(queue);
}
