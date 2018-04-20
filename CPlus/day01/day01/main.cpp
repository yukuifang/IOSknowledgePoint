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
#include "Extend.hpp"
#include "Extend_1.hpp"
#include "Extend_2.hpp"
#include "VirtureExtend.hpp"
#include "Polymorphism.hpp"
#include "VirtureDestruct.hpp"
#include "Step.hpp"
#include "Figure.hpp"

typedef void(*MyFuncPtr)(int a,int b);
using namespace std;


int add(int a,int b){
    return a + b;
}


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
    
    
    
    
//    MyString s;
//    s.description();
//    MyString s2("666");
//    s2.description();
//    MyString s3 = s2;
//    s3.description();
  
    
//    MyString s1("888");
//    MyString s2("888");
//    cout << s1 << s2 <<  endl;
//    if (s1 == s2) {
//        cout<<"想等"<<endl;
//    }else{
//        cout << "不相等"<<endl;
//    }
    
  
//    Chird1 c1;
//    cout << c1.c << endl;
//
//    Chird2 c2;
//   // cout << c2.c << endl; //Cannot cast 'Chird2' to its protected base class 'Parent'
//
//    Chird3 c3;
//   // cout << c3.c << endl; //Cannot cast 'Chird3' to its private base class 'Parent'
    
    
//    AChrid c(1,2,3);
    
    
//    BChrid b(1,2);
    
    
//    K3 k3;
//
//    k3.b = 100;
//
//    k3.c = 200;
//
//    k3.d = 300;
//
//    k3.a = 400;
    
    
    
//    E3 e3;
//
//    e3.E1::a = 100;
//
//    e3.E2::a = 200;
    
 
//
//    KPatent *ptr = NULL;
//
//    KPatent p(200);
//
//    KChrid c(100);
//
//    ptr = &p;
//
//    ptr->descripsion();
//
//    ptr->parentFun();
//
//    ptr = &c;
//
//    ptr->descripsion();
//
//    ptr->parentFun();
    
//    ptr->chridFun() //访问不了的
    
    
//    J *j = new JB;
//
//    delete j;
    
    
//    Step_Parent *pP = NULL;
//
//    Step_Chird *pC = NULL;
//
//    Step_Chird c[] = {Step_Chird(1),Step_Chird(2),Step_Chird(3),Step_Chird(4)};
//
//    pP = c;
//    pC = c;
//    pP ->description();
//    pC->description();
//
//    pP++;
//    pC++;
//    pP ->description();
//    pC ->description();
//
//    pP++;
//    pC++;
//    pP ->description();
//    pC ->description();
    
    
    
//    Triangle t;
//    t.getArea();
//    Square s;
//    s.getArea();
    
    
//    FigureAbstract *f = NULL;
//    Triangle t;
//    f = &t;
//    f->getArea();
//    Square s;
//    f = &s;
//    f->getArea();
    
    
//    int a[10];
    // a 代表的是数组首元素的地址 &a代表整个数组的地址， 两个步长不一样:a+1的步长是 4 * 1 = 4字节;&a + 1的步长是 4 *10  * 1 = 40字节
//    {
//        typedef int (myTypeArray)[10];
//        myTypeArray array;
//        array[0] = 666;
//        printf("%d",array[0]);
//    }
//
//    {
//        int a[10];
//        //一个指向10个int元素的数组地址
//        typedef int (*PTypeArray) [10];
//        PTypeArray pTypeArray = NULL;
//        pTypeArray = &a;
//        (*pTypeArray)[0] = 888;
//        printf("%d",a[0]);
//
//
//    }
//    {
//        int a[10];
//        int (*myPointer)[10];
//        myPointer = &a;
//        (*myPointer)[0]= 111;
//        printf("%d",a[0]);
//
//    }
    
    
    
//    {
//
//        typedef int (MyFucType)(int a,int b);
//        MyFucType *myFucPointer = NULL;
//        myFucPointer = add;
//        printf("%d",myFucPointer(1,2));
//
//    }
//    {
//
//        typedef int (*MyFucType)(int a,int b);
//        MyFucType pointer = NULL;
//        pointer = add;
//        printf("%d",pointer(1,2));
//        
//    }
//    {
//        int (*myFucPoint)(int a,int b);
//        myFucPoint = add;
//        printf("%d",myFucPoint(1,2));
//
//    }
    
    
    return 0;
}








