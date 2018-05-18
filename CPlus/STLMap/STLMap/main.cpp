//
//  main.cpp
//  STLMap
//
//  Created by fangyukui on 2018/5/18.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

void test01(){
    
    map<int,int> myMap;
    myMap.insert(make_pair(10, 10));
    //insert 有该对应的键不做任何修改，没有的话添加
    pair<map<int,int>::iterator,bool> ret = myMap.insert(pair<int, int>(10,20));
    if (ret.second == true ) {
        cout << "写入成功" <<endl;
    }else{
        cout << "重复键" << endl;
    }
    myMap.insert(make_pair(20, 20));
    myMap.insert(map<int,int>::value_type(30,30));
    myMap[40] = 40;
    for (map<int,int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
       cout << it->first << ":" << it->second << endl;
    }
    //[]: 有该对应的键直接修改，没有的话添加；如果用[] 访问时，没有的话也添加
    myMap[10] = 20;
    
    cout << "-----------------------" << endl;
    for (map<int,int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
        cout << it->first << ":" << it->second << endl;
    }
    
    
    
}

int main(int argc, const char * argv[]) {
    test01();
    return 0;
}
