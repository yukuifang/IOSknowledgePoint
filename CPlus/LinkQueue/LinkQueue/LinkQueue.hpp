//
//  LinkQueue.hpp
//  LinkQueue
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

typedef struct LINKNODE{
   struct LINKNODE *next;
}LinkNode;

typedef struct LINKQUEUE{
    LinkNode head;
    int size;
}LinkQueue;

//初始化
LinkQueue *init_LinkQueue();

//入队列
void push_LinkQueue(LinkQueue *queue,LinkNode *node);

//出队列
void pop_LinkQueue(LinkQueue *queue);

//取出对首第一个
LinkNode *front_LinkQueue(LinkQueue *queue);

//取出对尾第一个
LinkNode *back_LinkQueue(LinkQueue *queue);

//队列个数
int size_LinkQueue(LinkQueue *queue);

//清空队列
void clear_LinkQueue(LinkQueue *queue);

//释放内存
void freeSpace_LinkQueue(LinkQueue *queue);



