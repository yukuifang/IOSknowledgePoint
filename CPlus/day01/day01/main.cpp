//
//  main.cpp
//  day01
//
//  Created by fangyukui on 2018/3/13.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>

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

int main(int argc, const char * argv[]) {
    int a = 10;
    int b = 20;
    swapTwoInt3(&a, &b);
    cout << "a=" <<  a << endl;
    cout << "b=" <<  b << endl;
    return 0;
}




