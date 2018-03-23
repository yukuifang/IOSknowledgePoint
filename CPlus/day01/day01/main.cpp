//
//  main.cpp
//  day01
//
//  Created by fangyukui on 2018/3/13.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "reload.hpp"
#include "MyTeacher.hpp"
#include "Cube.hpp"
#include "Test.hpp"

typedef void(*MyFuncPtr)(int a,int b);
using namespace std;


void swapTwoInt1(int a, int b){
    int c;
    c = a;
    a = b;
    b = c;
    return;
}
//引用
void swapTwoInt2(int &a, int &b){
    int c;
    c = a;
    a = b;
    b = c;
    return;
}
//指针
void swapTwoInt3(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
    return;
}



void reload(){
    
    MyFuncPtr p = NULL;
    p = caluate;
    
    p(1,2);
    
    p(1.0,2.0);
    
    p('1','2');
    
}




int main(int argc, const char * argv[]) {
//    int a = 10;
//    int b = 20;
//    swapTwoInt3(&a, &b);
//    cout << "a=" <<  a << endl;
//    cout << "b=" <<  b << endl;
    
    
//    Cube c1,c2;
//    c1.setABC(1,1,1);
//    c2.setABC(1,1,1);
//    cout << "面积" << c1.getS()<< "体积" << c1.getV() << endl;
//    cout << c1.judgeCube(c2) << endl;
    
    
    
//    Test t;
//    Test t(1,2);
//    Test t = (1,2);
//    Test t = Test(1,2);
    
    Test t1(1,2);
    Test t2 = t1; // 拷贝时机，用一个对象初始化一个对象才会调用拷贝构造,如果是一个对象赋值一个对象是不会调用拷贝构造
    t2.printMessage();
    
    
    
    
   
    
   
    
    
    
    
    
    

    
    
    return 0;
}






