//
//  main.cpp
//  LinkStack
//
//  Created by fangyukui on 2018/5/29.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "LinkStack.hpp"
using namespace std;


typedef struct PERSON{
    LinkNode node;
    char name[50];
    int age;
}Person;

int main(int argc, const char * argv[]) {
    LinkStack *stack = init_LinkStack();
    
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
    push_LinkStack(stack, (LinkNode *)&p1);
    push_LinkStack(stack, (LinkNode *)&p2);
    push_LinkStack(stack, (LinkNode *)&p3);
    push_LinkStack(stack, (LinkNode *)&p4);
    
    
    while (size_LinkStack(stack) > 0) {
        //访问元素
        Person *p =  (Person *)top_LinkStack(stack);
        cout << "name=" << p->name << ",age=" <<p->age <<endl;
        //出栈
        pop_LinkStack(stack);
    }
    
    freeSpace_LinkStack(stack);
    
    return 0;
}
