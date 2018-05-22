//
//  LinkList.hpp
//  LinkList
//
//  Created by fangyukui on 2018/5/22.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

typedef struct LINKNODE{
    void *data;
    struct LINKNODE *next;
}LinkNode;


typedef struct LINKLIST{
    LinkNode *head;
    int size;
}LinkList;

typedef void(*PRINTFLINKNODE)(void *);


LinkList *init_LinkList();

void insert_LinkList(LinkList *list,int pos,void *data);

void removeByPos_LinkList(LinkList *list,int pos);

int size_LinkList(LinkList *list);

int find_LinkList(LinkList *list,void *data);

void * front_LinkList(LinkList *list);

void printf_LinkList(LinkList *list,PRINTFLINKNODE myPrint);

void freeSpace_LinkList(LinkList *list);










