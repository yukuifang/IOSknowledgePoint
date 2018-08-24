//
//  main.cpp
//  异常处理
//
//  Created by fangyukui on 2018/5/16.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
using namespace std;
#include "CustomException.hpp"


//用于测试异常抛出的时候,前面的代码的对象还没出作用域会提前被释放
class Person {
public:
    Person(){
        cout<< "Person 构造" << endl;
    }
    ~Person(){
        cout<< "Person 析构" << endl;
    }
    
};






// 基本数据类型int异常抛出
int divide(int x,int y){
    if (y == 0) {
        throw "除数不能为0";
    }
    return x/y;
}

// 基本数据类型char异常抛出
bool letter(char c){
    if (c >= 'a' && c <= 'z') {
        return true;
    }else{
        throw "不是字母";
    }
}

// 基本数据类型指针异常抛出
void isNullPointer(char *ptr){
    if (ptr == nullptr) {
        ptr = new char[10];
        strcpy(ptr, "是空指针哈");
        throw ptr;
    }
}

// 基本数据类型引用异常抛出
void throwReference(){
    int a = 888;
    int &b = a;
    throw b;
}

// 自定义类型异常抛出
void throwMyException(){
    throw MyException();
}

// 自定义类型异常抛出:对象
void throwMyMsgException_obj(){
    throw MyMsgException("error message is out of array capatity");
}
// 自定义类型异常抛出:引用
void throwMyMsgException_reference(){
    throw MyMsgException("error message is out of array capatity");
}
// 自定义类型异常抛出:指针
void throwMyMsgException_pointer(){
    // throw (&(MyMsgException("error message is out of array capatity")));是错误的，MyMsgException("error message is out of array capatity")在栈中,直接抛出其对应指针，马上出了这个{}作用域，MyMsgException("error message is out of array capatity")这块栈内存直接释放,在catch里面拿到异常指针去访问已经释放的内存，直接报错
//    throw (&(MyMsgException("error message is out of array capatity")));
    
    
    //new MyMsgException("error message is out of array capatity")放在堆里面，需要程序员手动释放，故抛出其对应指针。马上出了这个{}作用域，但是堆内存还在，在catch里面拿到异常指针去访问这块堆内存没毛病，但是需要注意：在catch里面收尾工作要释放这块内存 delete e;
    throw (new MyMsgException("error message is out of array capatity"));
}


#pragma 异常基本知识
void test(){
    try {
        divide(1, 0);
        
    } catch (char const*e) {
        cout << e <<endl;
    }
    
    try {
        letter('6');
    }catch (char const * e) {
        cout << e <<endl;
        
    }
    
    try {
        char *ptr = NULL;
        isNullPointer(ptr);
    }catch (char *e) {
        cout << e <<endl;
        
    }
    
    try {
        throwReference();
    } catch (int &e) {
        cout << e <<endl;
    }
    
    
    try {
//      如果出现异常,前面的代码的对象还没出作用域会提前被释放
        Person p1;
        throwMyException();
    } catch (MyException e) {
        e.what();
    }
    
    
}

void test2(){
    try {
        //该函数throw MyException()会调用无参构造并且抛出一个对象 用于catch (MyException e)的中e赋值,所以这里调用赋值构造，默认的赋值构造只是浅拷贝，只是简单复制指针引用，没有复制指针指向的内存，故当throw MyException这句话赋值给抛出异常的catch (MyException e)的e时候，它调用了析构，这里释放了内存，当catch (MyException e)的e也释放时候，也调用了一次析构，故会重复释放内存，坏内存访问，程序崩溃;一般一个类自觉写拷贝构造和重写=操作符
        throwMyMsgException_obj();
    } catch (MyMsgException e) {
        e.msg();
    }
}



void test3(){
    try {
        
        throwMyMsgException_reference();
    } catch (MyMsgException &e) {
        //引用的话，不会调用拷贝构造，异常对象catch之后才析构
        e.msg();
       
    }
}

void test4(){
    try {
        throwMyMsgException_pointer();
    } catch (MyMsgException *e) {
        //指针的话，不会调用拷贝构造，异常对象catch之后才析构
        e->msg();
        //注意:这里是delete e 对应：new MyMsgException("error message is out of array capatity")
        // 类内部 delete [] e->error,对应：delete [] this->error;
        //两者不要混淆
        delete e;
    }
}





int main(int argc, const char * argv[]) {
    test();
    return 0;
}
