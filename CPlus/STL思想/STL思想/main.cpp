//
//  main.cpp
//  STL思想
//
//  Created by fangyukui on 2018/5/17.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countZero(int *beginPtr,int *endPtr,int val){
    int count = 0;
    while (beginPtr != endPtr) {
        if (*beginPtr == val) {
            count++;
        }
        beginPtr++;
        
    }
    return count;
}

void STL(){
    int nums[] = {1,0,6,8,12,0,5,9,5};
    
    int len = sizeof(nums) / sizeof(int);
    
    int *beginPtr = nums;
    
    int *endPtr =  &nums[len];
    
    cout << countZero(beginPtr, endPtr, 1) << endl;
}




void printVector(int i){
    cout << i <<endl;
}

void test01(){
    vector<int> v; //定义一个容器，并制定容器类型为int
    
    v.push_back(10);
    
    v.push_back(20);
    
    v.push_back(30);
    
    v.push_back(40);
    
    //容器提供迭代器
    vector<int>::iterator pBegin = v.begin();
    
    vector<int>::iterator pEnd = v.end();
    
    //通过algorithm提供算法
    //容器中有可能存放基本数据类型，有可能自定义数据类型
    for_each(pBegin, pEnd, printVector);
    
    
}


class Person{
private:
    int age;
    int id;
public:
    Person(int age,int id):age(age),id(id){};
    void show(){
        cout << "age=" << this->age << ",id = " << this->id <<endl;
        
    }
    
};

void callBack(Person p){
    p.show();
}

void test02(){
    vector<Person> v;
    Person p1(12,1),p2(13,2),p3(14,3),p4(16,4);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    
    
//    for (vector<Person>::iterator beginIt = v.begin();  beginIt != v.end(); beginIt++) {
//         //记得Person提供析构函数
//         Person p = *beginIt;
//         p.show();
//    }
    
    
    for_each(v.begin(), v.end(),callBack);
    
    
}

int main(int argc, const char * argv[]) {
    test02();
    return 0;
}



