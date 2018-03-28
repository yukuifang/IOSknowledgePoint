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
#include "friend.hpp"
#include "OperationOverload.hpp"
#include "EqualOperation.hpp"
#include "Array.hpp"
#include "MyString.hpp"

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
    
//    Test t1(1,2);
//    Test t2 = t1; // 拷贝时机，用一个对象初始化一个对象才会调用拷贝构造,如果是一个对象赋值一个对象是不会调用拷贝构造
//    t2.printMessage();
    
    
    
//    B b;
//    b.modifyA();
    
    
//    Complex a(1,2);
//    Complex b(1,2);
//    Complex c = a + b;
//    c.description();
//    Complex d = a - b;
//    d.description();
//    Complex e(1,2);
//    ++e;
//    --e;
//    e.description();
//    Complex f(1,2);
//    Complex temp =  f++;
//    temp.description();
//    f.description();
//
//    Complex g(1,1);
//    Complex temp2 =  g--;
//    temp2.description();
//    g.description();
    
    
//    Complex a(1,2);
//    Complex b(1,2);
//    cout<< a << "支持链式编程输出" << endl;
    
    
//    Name n1("fangyuykui");
//    Name n2("yu-vin");
//    n1.description();
//    n2.description();
//    n1 = n2;
//
//    n1.description();
//    n2.description();
//
//
//    Name n3 = n2;
//    n3.description();
//    n2.description();
    
    
//    Array a(10);
//    for (int i=0; i<10; i++) {
//        a[i] = 6;
//        cout << a[i] << endl;
//    }
//
//    Array b(5);
//    Array c(8);
//
//    if (a == b) {
//        cout<<"相等" << endl;
//    }else{
//        cout<<"不相等" << endl;
//    }
//    b = c = a;
//    if (a == b) {
//        cout<<"相等" << endl;
//    }else{
//        cout<<"不相等" << endl;
//    }
//    cout <<b.getLength() << c.getLength() << endl;
    
    
    
    
    MyString s;
    s.description();
    MyString s2("666");
    s2.description();
    MyString s3 = s2;
    s3.description();
    
    
    
    
    return 0;
}







