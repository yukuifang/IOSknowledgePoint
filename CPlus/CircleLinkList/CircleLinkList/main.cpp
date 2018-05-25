//
//  main.cpp
//  CircleLinkList
//
//  Created by fangyukui on 2018/5/25.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "CircleLinkList.hpp"
#include <iostream>
using namespace std;

typedef struct PERSON{
    CircleLinkNode node;
    char name[50];
    int age;
    double score;
}Person;

void print(CircleLinkNode *node){
    Person *p = (Person*)node;
    cout << "name=" << p->name << ",age=" <<p->age << ",score= " << p->score << endl;
    
}

int compare(CircleLinkNode *node1,CircleLinkNode *node2){
    Person *p1 = (Person*)node1;
    Person *p2 = (Person*)node2;
    if (!strcmp(p1->name, p2->name) && p1->age == p2->age && p2->score == p2->score) {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    CircleLinnList *list = init_CircleLinkList();
    
    Person p1,p2,p3,p4,p5;
    
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");
    
    p1.age = 10;
    p2.age = 10;
    p3.age = 10;
    p4.age = 10;
    p5.age = 10;
    
    p1.score = 50;
    p2.score = 60;
    p3.score = 70;
    p4.score = 80;
    p5.score = 90;
    
    
    insert_CircleLinkList(list, 0, (CircleLinkNode*)&p1);
    insert_CircleLinkList(list, 0, (CircleLinkNode*)&p2);
    insert_CircleLinkList(list, 0, (CircleLinkNode*)&p3);
    insert_CircleLinkList(list, 0, (CircleLinkNode*)&p4);
    insert_CircleLinkList(list, 0, (CircleLinkNode*)&p5);
    
    print_CircleLinkList(list, print);
    
    Person pDel;
    strcpy(pDel.name, "ccc");
    pDel.age = 10;
    pDel.score = 70;
    
    removeByValue_CircleLinkList(list, (CircleLinkNode*)&pDel, compare);
    
    
    print_CircleLinkList(list, print);
    
    freeSpace_CirleLinkList(list);
    
    
    
    return 0;
}
