//
//  main.cpp
//  day02
//
//  Created by fangyukui on 2018/4/27.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
using namespace std;

int myMax(int a,int b){
    cout << "myMax(int a,int b)" << endl;
    return a+b;
}

template <typename E>
int myMax(E a , E b) {
    cout << "myMax(E a , E b)" << endl;
    return a + b;
}

template <typename E>
int myMax(E a , E b , E d) {
    cout << "myMax(E a , E b , E d)" << endl;
    return a + b  + d ;
}

int main(int argc, const char * argv[]) {
    myMax(1, 2); //在符合情况下，默认优先调用普通函数
    myMax<>(1, 2); //如果想调用函数模版，需要<>示意
    myMax(13.0, 14.0);//如果函数模版是最优的调用，那么优先调用它
    myMax(1, 2, 3);
    
    return 0;
}
