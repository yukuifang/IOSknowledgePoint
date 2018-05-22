//
//  main.cpp
//  LinkList
//
//  Created by fangyukui on 2018/5/22.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "LinkList.hpp"
using namespace std;

typedef struct PERSON{
    char name[50];
    int age;
    double score;
}Person;


void myPrint(void *data){
    Person *p = (Person *)data;
    cout << "name= " << p->name << ",age =" << p-> age << ",score=" <<  p->score <<endl;
    
}

int main(int argc, const char * argv[]) {
    LinkList *list = init_LinkList();
    
    Person p1 = {"aaa",11,100};
    Person p2 = {"bbb",12,99};
    Person p3 = {"ccc",13,88};
    Person p4 = {"ddd",14,77};
    Person p5 = {"eee",15,66};
    
    insert_LinkList(list, 0, &p1);
    insert_LinkList(list, 0, &p2);
    insert_LinkList(list, 0, &p3);
    insert_LinkList(list, 0, &p4);
    insert_LinkList(list, 0, &p5);
    
    printf_LinkList(list, myPrint);
    
    removeByPos_LinkList(list, 2);
    
    cout << "------" << endl;
    
    printf_LinkList(list, myPrint);
    
    freeSpace_LinkList(list);
    
    
    
    
    
    
    
    
    
    
    return 0;
}
