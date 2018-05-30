//
//  main.cpp
//  SeqQuque
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "SeqQueue.hpp"
using namespace std;

typedef struct PERSON{
    char name[20];
    int age;
}Person;

int main(int argc, const char * argv[]) {
    
    SeqQueue *queue = init_SeqQueue();
    
    //创建数据
    Person p1 = {"fangyukui",23};
    Person p2 = {"xianzige",22};
    Person p3 = {"xiaoMing",28};
    Person p4 = {"heheda",19};
    
    push_SeqQueue(queue, &p1);
    push_SeqQueue(queue, &p2);
    push_SeqQueue(queue, &p3);
    push_SeqQueue(queue, &p4);
    
    Person *p  = (Person *)back_SeqQueue(queue);
    cout << "name=" << p->name << ",age=" <<p->age <<endl;
    
    
    while (size_SeqQueue(queue) > 0) {
        Person *p  = (Person *)front_SeqQueue(queue);
        cout << "name=" << p->name << ",age=" <<p->age <<endl;
        //出栈
        pop_SeqQueue(queue);
    }
    
    
    
    
    
    freeSpace_SeqQueue(queue);
    
    
    
    return 0;
}
