//
//  LinkStack.hpp
//  LinkStack
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

typedef struct LINKNODE{
    struct LINKNODE *next;
}LinkNode;

typedef struct LINKSTACK{
    LinkNode head;
    int size;
}LinkStack;

//初始化链式栈
LinkStack *init_LinkStack();

//入栈
void push_LinkStack(LinkStack *stack,LinkNode *node);

//出栈
void pop_LinkStack(LinkStack *stack);

//栈顶元素
LinkNode * top_LinkStack(LinkStack *stack);

//返回栈个数
int size_LinkStack(LinkStack *stack);

//清空栈
void clear_LinkStack(LinkStack *stack);

//释放内存
void freeSpace_LinkStack(LinkStack *stack);







