//
//  main.cpp
//  STLList
//
//  Created by fangyukui on 2018/5/18.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//链表

void printfList(list<int> &mlist){
    for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    
    list<int> mlist1;
    list<int> mlist2(10,1);
    list<int> mlist3(mlist2);
    list<int> mlist4(mlist2.begin(),mlist2.end());
    mlist1 = mlist2;
    printfList(mlist1);
    printfList(mlist2);
    printfList(mlist3);
    printfList(mlist4);
    
    
}

void test02(){
    list<int> mlist;
    mlist.push_back(1);
    mlist.push_front(2);
    mlist.push_front(50);
    mlist.push_front(50);
    list<int>::iterator it =  mlist.begin();
    // 因为是链表，所以访问不可以随机访问，要一个结点沿着一个结点爬上去访问,所以it += 5;是错误的，it++是正确的
//    it += 5;
    it++;
    it++;
    mlist.insert(it,3);
    printfList(mlist);
    mlist.remove(50); //删除所有的50
    printfList(mlist);
    
    
}

void test03(){
    list<int> mlist1;
    mlist1.assign(10, 6);
    list<int> mlist2(10,8);
    
    cout << "mlist1" <<endl;
    printfList(mlist1);
    cout << "mlist2"<<endl;
    printfList(mlist2);
    
    mlist1.swap(mlist2);
    
    cout << "mlist1" <<endl;
    printfList(mlist1);
    cout << "mlist2"<<endl;
    printfList(mlist2);
    
}

void test04(){
    list<int> mlist;
    for (int i=0; i<10; i++) {
        mlist.push_back(i);
    }
    //返回第一个元素和最后一个元素
    cout << mlist.back() << endl;
    cout << mlist.front() << endl;
    
    //翻转
    mlist.reverse();
    printfList(mlist);
    
    

}
bool myCompare(int v1,int v2){
    return v1 > v2;
}

void test05(){
    list<int> mlist;
    mlist.push_back(10);
    mlist.push_back(2);
    mlist.push_back(8);
    mlist.push_back(4);
    mlist.push_back(20);
    //默认从小到大
//    mlist.sort();
    mlist.sort(myCompare);
    printfList(mlist);
    
    //因为链表不可以的随机访问，而algorithm下的sort针对可以随机访问的容器的算法，效率高。所以链表针对自身的数据结构自己提高高效的sort实例方法
    
}
int main(int argc, const char * argv[]) {
    test05();
    return 0;
}
