//
//  CircleLinkList.cpp
//  CircleLinkList
//
//  Created by fangyukui on 2018/5/25.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "CircleLinkList.hpp"
#include <iostream>
using namespace std;

CircleLinnList *init_CircleLinkList(){
    CircleLinnList *list = (CircleLinnList*)malloc(sizeof(CircleLinnList*));
    list->head.next = &(list->head);
    list->size = 0;
    return list;
}

void insert_CircleLinkList(CircleLinnList *list,int pos,CircleLinkNode *node){
    if (list == NULL) return;
    if (node==NULL)return;
    if (pos< 0  || pos>list->size) {
        pos = list->size;
    }
    CircleLinkNode *currentNode = &(list->head);
    for (int i=0; i < pos; i++) {
        currentNode = currentNode->next;
    }
    node->next = currentNode->next;
    currentNode->next = node;
    list->size++;
}

CircleLinkNode *front_CircleLinkList(CircleLinnList *list){
    return list->head.next;
}

void removeByPos_CircleLinkList(CircleLinnList *list,int pos){
    if (list == NULL) return;
    if (pos < 0 || pos >= list->size) return;
    CircleLinkNode *currentNode = &list->head;
    for (int i=0; i< pos; i++) {
        currentNode = currentNode->next;
    }
    CircleLinkNode *nextNode = currentNode->next;
    currentNode->next = nextNode->next;
    list->size--;
    
}

void removeByValue_CircleLinkList(CircleLinnList *list,CircleLinkNode *node,COMPARENODE compare){
    if (list==NULL) return;
    if (node==NULL) return;
    CircleLinkNode *previousNode = &list->head;
    CircleLinkNode *currentNode = previousNode->next;
    for (int i=0; i< list->size; i++) {
        if (compare(node,currentNode)) {
            previousNode->next = currentNode->next;
            list->size--;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
}

int size_CircleLinkList(CircleLinnList *list){
    return list->size;
}

int isEnpty_CircleLinkList(CircleLinnList *list){
    if (list == NULL)return CIRCLELINKLIST_TURE;
    return !!list->size;
}

int find_CircleLinkList(CircleLinnList *list,CircleLinkNode *node,COMPARENODE compare){
    if (list==NULL) return -1;
    if (node==NULL) return -1;
    CircleLinkNode *currentNode = &list->head;
    for (int i=0; i< list->size; i++) {
        if (compare(node,currentNode)) {
            return i;
        }
        currentNode = currentNode->next;
        
    }
    return -1;
}

void print_CircleLinkList(CircleLinnList *list,PRINTNODE print){
    if (list==NULL) return;
    CircleLinkNode *currentNode = &list->head;
    for (int i=0; i<list->size; i++) {
        if (currentNode == &(list->head)) {
            currentNode = currentNode->next;
        }
        print(currentNode);
        currentNode = currentNode->next;
    }
    printf("-----------------\n");
}

void freeSpace_CirleLinkList(CircleLinnList *list){
    if (list==NULL) return;
    free(list);
    
}
