//
//  main.cpp
//  STLSet
//
//  Created by fangyukui on 2018/5/18.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

void printfSet(set<int> &s){
    for (set<int>::iterator it = s.begin(); it != s.end() ; it++) {
        cout << *it << " ";
        
    }
    cout << endl;
}

void test0(){
    set<int> s1;   //自动继续排序,从小到大
    
    s1.insert(7);
    s1.insert(2);
    s1.insert(4);
    s1.insert(5);
    s1.insert(1);
    
//    printfSet(s1);
//
//    s1.erase(s1.begin());
//
//    printfSet(s1);
//
//    s1.erase(4);
//
//    printfSet(s1);
    
    
    //二叉树遍历方式：中序排序，先序排序，后序排序
    
    
//    set<int>::iterator it =  s1.find(10);
//
//    if (it == s1.end()) {
//        cout << "找不到" <<  *it <<endl;
//
//    }else{
//        cout << "找到了" <<  *it  <<endl;
//    }
    
    
    
//    set<int>::iterator it1  = s1.lower_bound(3);
//    cout << *it1 << endl;
//
//    set<int>::iterator it2  = s1.upper_bound(2);
//    cout << *it2 << endl;
    
    
    
//    pair<set<int>::iterator , set<int>::iterator> rangePair =  s1.equal_range(3);
//    set<int>::iterator it1 = rangePair.first;
//    set<int>::iterator it2 = rangePair.second;
//    cout << *it1 << endl;
//    cout << *it2 << endl;
    

    
}

class MyCompare{
public:
    bool operator()(int a,int b){
        return a > b;
    }
};

void test02(){
    set<int,MyCompare> s1;
    s1.insert(7);
    s1.insert(2);
    s1.insert(4);
    s1.insert(5);
    s1.insert(1);
    for (set<int>::iterator it = s1.begin(); it != s1.end() ; it++) {
        cout << *it << " ";
        
    }
    cout << endl;
}

class Person{
public:
    int age;
    int id;
public:
    Person(int age,int id):age(age),id(id){};
    
};

class PersonCompare{
public:
    bool operator()(Person p1,Person p2){
        return p1.age > p2.age;
    }
    
};

void test03(){
    
    set<Person,PersonCompare> sp;
    Person p1(12,1), p2(23,2) , p3(6,5),p4(5,10);
    sp.insert(p1);
    sp.insert(p2);
    sp.insert(p3);
    sp.insert(p4);
    for (set<Person,PersonCompare>::iterator it = sp.begin(); it != sp.end() ; it++) {
       cout << "age=" <<  it->age << ",id=" << it->id << endl;
        
    }
    
    Person p5(12,4);
    //注意，当set存放自定义对象， 以 PersonCompare中比较的属性为key，所以p5虽然不在set容器里面，但是因为以此刻以age为key = 12 去找，找到p1
    set<Person,PersonCompare>::iterator it = sp.find(p5);
    if (it == sp.end()) {
        cout << "找不到" <<endl;
        
    }else{
         cout << "age=" <<  it->age << ",id=" << it->id << endl;
    }
    
    
}



int main(int argc, const char * argv[]) {
    test03();
    return 0;
}
