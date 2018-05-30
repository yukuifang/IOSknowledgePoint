//
//  main.cpp
//  LinkQueue
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "LinkQueue.hpp"
using namespace std;

typedef struct PERSON{
    LinkNode node;
    char name[50];
    int age;
}Person;

int main(int argc, const char * argv[]) {
    LinkQueue *queue = init_LinkQueue();
    
    Person p1,p2,p3,p4;
    
    //创建数据
    stpcpy(p1.name, "fangyukui");
    stpcpy(p2.name, "xianzige");
    stpcpy(p3.name, "xiaoMing");
    stpcpy(p4.name, "heheda");
    p1.age = 11;
    p2.age = 22;
    p3.age = 33;
    p4.age = 44;
    
    //入栈
    push_LinkQueue(queue, (LinkNode*)&p1);
    push_LinkQueue(queue, (LinkNode*)&p2);
    push_LinkQueue(queue, (LinkNode*)&p3);
    push_LinkQueue(queue, (LinkNode*)&p4);
    
    while (size_LinkQueue(queue) > 0) {
        Person *p = (Person *)front_LinkQueue(queue);
        cout << "name=" << p->name << ",age=" <<p->age <<endl;
        pop_LinkQueue(queue);
    }
    freeSpace_LinkQueue(queue);
    return 0;
}
