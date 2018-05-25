//
//  CircleLinkList.hpp
//  CircleLinkList
//
//  Created by fangyukui on 2018/5/25.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

//链表的小结点
typedef struct CIRCLELINKNODE{
    struct CIRCLELINKNODE *next;
}CircleLinkNode;

//链表结构体
typedef struct CIRCLELINKLIST{
    CircleLinkNode head;
    int size;
    
}CircleLinnList;


typedef int(*COMPARENODE)(CircleLinkNode *,CircleLinkNode *);

typedef void(PRINTNODE)(CircleLinkNode *);

#define CIRCLELINKLIST_TURE  1
#define CIRCLELINKLIST_FALSE 0


//API函数
CircleLinnList *init_CircleLinkList();

void insert_CircleLinkList(CircleLinnList *list,int pos,CircleLinkNode *node);

CircleLinkNode *front_CircleLinkList(CircleLinnList *list);

void removeByPos_CircleLinkList(CircleLinnList *list,int pos);

void removeByValue_CircleLinkList(CircleLinnList *list,CircleLinkNode *node,COMPARENODE compare);

int size_CircleLinkList(CircleLinnList *list);

int isEnpty_CircleLinkList(CircleLinnList *list);

int find_CircleLinkList(CircleLinnList *list,CircleLinkNode *node,COMPARENODE compare);

void print_CircleLinkList(CircleLinnList *list,PRINTNODE print);

void freeSpace_CirleLinkList(CircleLinnList *list);












