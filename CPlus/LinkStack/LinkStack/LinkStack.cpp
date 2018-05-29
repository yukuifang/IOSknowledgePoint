//
//  LinkStack.cpp
//  LinkStack
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "LinkStack.hpp"
#include <iostream>
using namespace std;

//初始化链式栈
LinkStack *init_LinkStack(){
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
    stack->head.next = NULL;
    stack->size = 0;
    return stack;
}

//入栈
void push_LinkStack(LinkStack *stack,LinkNode *node){
    if (stack == NULL) return;
    if (node  == NULL) return;
    node->next = stack->head.next;
    stack->head.next = node;
    stack->size++;
}

//出栈
void pop_LinkStack(LinkStack *stack){
    if (stack == NULL)return;
    LinkNode *delNode = stack->head.next;
    stack->head.next = delNode->next;
    stack->size--;
    
}

//栈顶元素
LinkNode * top_LinkStack(LinkStack *stack){
    if (stack == NULL)return NULL;
    if (stack->size==0) return NULL;
    LinkNode *topNode = stack->head.next;
    return topNode;
    
}

//返回栈个数
int size_LinkStack(LinkStack *stack){
    if (stack == NULL)return 0;
    return stack->size;
}

//清空栈
void clear_LinkStack(LinkStack *stack){
    if (stack == NULL)return;
    stack->head.next = NULL;
    stack->size = 0;
    
}

//释放内存
void freeSpace_LinkStack(LinkStack *stack){
    if (stack == NULL)return;
    free(stack);
}
