//
//  main.cpp
//  异常处理
//
//  Created by fangyukui on 2018/5/16.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
using namespace std;

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


class MyException{
private:
    char *p;
public:
    MyException(){
        this->p = (char *)malloc(20);
        cout << "MyException() 无参构造" <<endl;
        
    }
    MyException(const MyException &myExcetion){
        cout << "MyException(const MyException &myExcetion) 赋值构造" <<endl;
        
    }
    ~MyException(){
        cout << "MyException 析构" <<endl;
    }
    
    void what(){
        cout << "这是MyException 自定义类异常"<<endl;
    }
};

// 基本数据类型int异常抛出
int divide(int x,int y){
    if (y == 0) {
        throw 666;
    }
    return x/y;
}

// 基本数据类型char异常抛出
bool letter(char c){
    if (c >= 'a' && c <= 'z') {
        return true;
    }else{
        throw c;
    }
}

// 基本数据类型指针异常抛出
void isNullPointer(char *ptr){
    if (ptr == nullptr) {
        ptr = new char[10];
        strcpy(ptr, "666");
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


#pragma 异常基本知识
void test(){
    try {
        divide(1, 0);
    } catch (int e) {
        cout << e <<endl;
    }
    
    try {
        letter('6');
    }catch (char e) {
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
//        如果出现异常,前面的代码的对象还没出作用域会提前被释放
        Person p1;
        throwMyException();
    } catch (MyException e) {
        e.what();
    }
    
    
}

void test2(){
    try {
        //该函数throw MyException()会调用无参构造并且抛出一个对象 用于catch (MyException e)的中e赋值,所以这里调用赋值构造，默认的赋值构造只是浅拷贝，只是简单复制指针引用，没有复制指针指向的内存，故当throw MyException这句话赋值给抛出异常的catch (MyException e)的e时候，它调用了析构，这里释放了内存，当catch (MyException e)的e也释放时候，也调用了一次析构，故会重复释放内存，坏内存访问，程序崩溃
        throwMyException();
    } catch (MyException e) {
        e.what();
    }
}



int main(int argc, const char * argv[]) {
    test2();
    return 0;
}
