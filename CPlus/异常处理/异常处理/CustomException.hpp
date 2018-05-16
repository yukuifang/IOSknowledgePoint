//
//  CustomException.hpp
//  异常处理
//
//  Created by fangyukui on 2018/5/16.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once
#include <iostream>

using namespace std;


class MyException{
public:
    void what(){
        cout << "这是MyException 自定义类异常"<<endl;
    }
};



class MyMsgException{
private:
    char *error;
public:
    MyMsgException(char *msg){
        this->error = new char[strlen(msg) + 1];
        strcpy(this->error, msg);
        cout << "MyMsgException(char *msg) 构造" <<endl;
        
    }
    MyMsgException(const MyMsgException &myExcetion){
        cout << "MyMsgException(const MyMsgException &myExcetion) 赋值构造" <<endl;
        this->error = new char[strlen(myExcetion.error) + 1];
        strcpy(this->error, myExcetion.error);
        
    }
    MyMsgException& operator=(const MyMsgException &myExcetion){
        if (this->error!=nullptr) {
            delete [] this->error;
            this->error = nullptr;
        }
        this->error = new char[strlen(myExcetion.error) + 1];
        strcpy(this->error, myExcetion.error);
        return *this;
    }
    ~MyMsgException(){
        cout << "MyMsgException 析构" <<endl;
        if (this->error!=nullptr) {
            delete [] this->error;
            this->error = nullptr;
        }
    }
    
    void msg(){
        cout << this->error <<endl;
    }
    
};


//class extendSysException:exception{
//    const char* what() const{
//        return "extendSysException";
//    }
//    
//};





