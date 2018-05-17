//
//  main.cpp
//  IO流操作
//
//  Created by fangyukui on 2018/5/17.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

class Person{
private:
    int age;
    int id;
public:
    Person(){}
    Person(int age,int id):age(age),id(id){}
    void show(){
        cout << "age = " << this->age << ",id = " << this->id << endl;
    }
    
};

void binaryIO(){
    //对象序列化
    Person p1(12,1);
    
    Person p2(16,2);
    
    char *target_name = "/Users/fangyukui/Desktop/c.txt";
    
    ofstream osm(target_name,ios::out | ios::binary);
    
    osm.write((char *)&p1,sizeof(Person));
    
    osm.write((char *)&p2,sizeof(Person));
    
    osm.close();
    
    ifstream ism(target_name,ios::in|ios::binary);
    
    Person p3,p4;
    
    ism.read((char *)&p3,sizeof(Person));
    
    ism.read((char *)&p4,sizeof(Person));
    
    p3.show();
    
    p4.show();
    
   ism.close();
    
   
}

void fileIO(){
    
    char *source_name = "/Users/fangyukui/Desktop/a.txt";
    char *target_name = "/Users/fangyukui/Desktop/b.txt";
    //自读方式打开
    ifstream ism(source_name,ios::in);
    
    //没有该文件会自动创建      写入和追加模式
    ofstream osm(target_name,ios::out | ios::app);
    
    if (!ism) {
        cout << "打开文件失败" <<endl;
        return;
    }
    
    char ch;
    while (ism.get(ch)) {
        cout << ch;
        osm.put(ch);
        
    }
    ism.close();
    osm.close();
    
}

int main(int argc, const char * argv[]) {
    binaryIO();
    return 0;
}
