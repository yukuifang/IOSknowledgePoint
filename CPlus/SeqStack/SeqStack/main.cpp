//
//  main.cpp
//  SeqStack
//
//  Created by fangyukui on 2018/5/28.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "SeqStack.hpp"
using namespace std;


typedef struct PERSON{
    char name[50];
    int age;
}Person;

int main(int argc, const char * argv[]) {
    SeqStack *stack = init_SeqStack();
    
    //创建数据
    Person p1 = {"fangyukui",23};
    Person p2 = {"xianzige",22};
    Person p3 = {"xiaoMing",28};
    Person p4 = {"heheda",19};
    
    //入栈
    push_SeqStack(stack, &p1);
    push_SeqStack(stack, &p2);
    push_SeqStack(stack, &p3);
    push_SeqStack(stack, &p4);
    
    
    while (size_SeqStack(stack) > 0) {
        //访问元素
        Person *p =  (Person *)top_SeqStack(stack);
        cout << "name=" << p->name << ",age=" <<p->age <<endl;
        //出栈
        pop_SeqStack(stack);
    }
    
    freeSpace_SeqStack(stack);
    
    return 0;
}
