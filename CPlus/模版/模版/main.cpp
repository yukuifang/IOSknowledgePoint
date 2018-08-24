//
//  main.cpp
//  模版
//
//  Created by fangyukui on 2018/5/15.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "Animal.hpp"
#include "Person.hpp"
using namespace std;

//类型参数化
/**
 1.可以普通函数构成重载
 2.严格类型转换，char 和 int 无法隐世互相转换
 3.如果调用同时匹配 模版函数和普通函数，优先执行普通函数,如果一定要调用模版函数，则加上<>示意
 4.如果函数模版可以产生很好的匹配，选择模版函数
 **/
template <typename E>
void MySwap(E &a,E &b) {
    E temp = a;
    a = b;
    b  = temp;
}

//模版函数
template <typename E>
int MyAdd(E &a,E &b) {
    cout << "调用了 int MyAdd(E &a,E &b)" << endl;
    return a + b;
}

//普通函数，和上面构成重载
int MyAdd(int &a,char &b) {
    cout << "调用了 int MyAdd(int &a,char &b)" << endl;
    return a + b;
}

//普通函数，和上面构成重载
int MyAdd(int &a,int &b){
    cout << "调用了 MyAdd(int &a,int &b)" << endl;
    return a + b;
}





int main(int argc, const char * argv[]) {
    {
        int a = 10;
        int b = 20;
        //自动类型推导  MySwap<int>(a, b);
        MySwap(a,b);
        cout << "a=" << a << ",b=" << b <<endl;
    }
    
    {
        double a = 10.1;
        double b = 20.2;
        MySwap(a,b);
        cout << "a=" << a << ",b=" << b <<endl;
        
    }
    {
        int a = 10;
        int b = 20;
        double d = 1.1;
        double e = 2.2;
        char c = 'a';
        
        
        MyAdd(a, c);
        MyAdd(a, b);
        MyAdd(d, e);
//        MyAdd(c, a);
        
       
        
        
    }
    {
        Cat<int> c;
        c.myAge = 12;
        c.sound();
        
    }
    {
        Person<int>  i1,i2,i3;
        Person<char> c1,c2,c3;
        i1.a = 10;
        c1.a = 20;
        cout << i1.a << i2.a  << i3.a  << endl;
        cout << c1.a << c2.a  << c3.a  << endl;
        
        
        
    }
    
    
    return 0;
}
// index.cpp => 预编译器（宏展开，#include包含文件进来）=> index.i  => 编译器（编译成汇编语言）=> index.s(汇编文件) =>
//汇编器（把汇编文件编译成二进制文件） => index.o文件（二进制文件）=> 连接器（连接目标文件调用系统库的二进制包等） => .exe(可执行文件)


