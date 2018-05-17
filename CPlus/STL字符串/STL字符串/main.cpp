//
//  main.cpp
//  STL字符串
//
//  Created by fangyukui on 2018/5/17.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// 初始化
void test01(){
    string s1;
    s1 = "hello";
    string s2("hello");
    string s3 = s2;
    string s4(s2);
    cout << s1 << s2 << s3 << s4 << endl;
    
}
//操作
void test02(){
    string s = "abcdefghijk";
    cout << s.size() << endl;
    cout <<  s.at(0) <<s[1] <<endl;
    // [] 和 at 的区别：[]越界直接挂了，不抛出异常；at越界抛出异常
    try {
        s.at(12);
    } catch (exception e) {
        cout << "异常" << endl;
    }
    
    string s2 = "1";
    string s3 = "2";
    s2 += "a";
    s2.append(s3);
    string s4 = s2 + s3;
    cout << s4 << endl;
    
    string s5 = "abcdefgde";
    //查找de第一个出现的位置
    cout << s5.find("de") << endl;
    //查找de第一个出现的位置
    cout << s5.rfind("de") << endl;
    
    
    string s6 = "abcdefg";
    s6.replace(0, 2, "12");
    cout << s6 << endl;
    
    string s7 = "abc";
    string s8 = "abc";
    if (s7.compare(s8) == 0) {
        cout << "字符串相等" <<endl;
    }else{
        cout << "字符串不相等" <<endl;
    }
    
    string s9 = "abcdefg";
    
    cout << s9.substr(0,2) <<endl;
    
    s9.insert(7, "123");
    
    s9.erase(0,3);
    
    cout << s9 <<endl;
    
}


int main(int argc, const char * argv[]) {
    test02();
    return 0;
}
