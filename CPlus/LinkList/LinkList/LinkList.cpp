//
//  LinkList.cpp
//  LinkList
//
//  Created by fangyukui on 2018/5/22.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "LinkList.hpp"
#include <iostream>
using namespace std;

LinkList *init_LinkList(){
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    list->size = 0;
    list->head = (LinkNode *)malloc(sizeof(LinkNode));
    //这里的第一个结点，也就是头结点，在本案例中不保存数据，故在下面各个方法中，几乎从第二个结点开始 LinkNode *pCurrentNode = list->head->next;注意这点
    list->head->data = NULL;
    list->head->next = NULL;
    return list;
}

void insert_LinkList(LinkList *list,int pos,void *data){
    if (list == NULL)return;
    if (data == NULL) return;
    if (pos < 0 || pos >= list->size) {
        pos = list->size;
    }
    
    //创建新的结点
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = data;
    newNode->next = NULL;
    
    //找pos位置上个结点
    LinkNode *pCurrentNode = list->head;
    for (int i=0; i < pos; i++) {
        pCurrentNode = pCurrentNode->next;
    }
    
    //新结点入链表
    newNode->next = pCurrentNode->next;
    pCurrentNode->next = newNode;
    
    list->size++;
    
}

void removeByPos_LinkList(LinkList *list,int pos){
    if (list == NULL)return;
    if (pos < 0 || pos >= list->size) return;
    
    //找pos位置前一个结点
    LinkNode *pCurrentNode = list->head;
    for (int i=0; i < pos; i++) {
        pCurrentNode = pCurrentNode->next;
    }
    
    //缓存要删除的结点
    LinkNode *pDelNode = pCurrentNode->next;
    
    pCurrentNode->next = pDelNode->next;
    
    
    //释放换成结点
    
    free(pDelNode);
    list->size--;
    
    
    
    
    
    
}

int size_LinkList(LinkList *list){
    return list->size;
}

int find_LinkList(LinkList *list,void *data){
    if (list == NULL)return -1;
    if (data == NULL) return -1;
    int pos = -1;
    LinkNode *pCurrentNode = list->head->next;
    int i = 0;
    while (pCurrentNode != NULL) {
        i++;
        if (data == pCurrentNode->data) {
            pos = i;
            break;
        }
        
    }
    return pos;
}

void * front_LinkList(LinkList *list){
    return list->head->next->data;
}

void printf_LinkList(LinkList *list,PRINTFLINKNODE myPrint){
    if (list == NULL)return;
    LinkNode *pCurrentNode = list->head->next;
    while (pCurrentNode != NULL) {
        myPrint(pCurrentNode->data);
        pCurrentNode = pCurrentNode->next;
    }
    
    
}

void freeSpace_LinkList(LinkList *list){
     if (list == NULL)return;
     LinkNode *pCurrentNode = list->head;
     while (pCurrentNode->next != NULL) {
        //缓存下一个结点
         LinkNode *pNext = pCurrentNode->next;
         
         //释放当前结点
         free(pCurrentNode);
         
         pCurrentNode = pNext;
         
    }
    //释放列表
    free(list);
    list->size = 0;
    
    
}
