//
//  main.cpp
//  类型转换
//
//  Created by fangyukui on 2018/5/15.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
using namespace std;

class Building{};
class Animal{};
class Cat:public Animal{};

int main(int argc, const char * argv[]) {
    
    //static_cast 用于内置的数据结构，还有具有继承关系的指针或者引用
    
    
    {
        int a =65;
        
        //1.基本类型转换
        char c = static_cast<char>(a);
        
        cout << c << endl;
    }
    
    
    
    {
        //2.不可基本类型指针转换
        
//        int *intPtr = NULL;
//
//        char *p =  static_cast<char *>(intPtr);
    }
    
    {
        //3.不可无继承关系类型指针转换
//        Building *buildPtr = NULL;
//        Animal *p = static_cast<Animal *>(buildPtr);
        
    }
    {
        //4.继承关系类型指针转换
        Cat *cPtr = NULL;
        Animal *p = static_cast<Animal *>(cPtr);
    }
    {
        //4.继承关系类型指针转换
        Animal *animalPtr = NULL;
        Cat *p = static_cast<Cat *>(animalPtr);
    }
    
    //dynamic_cast转换具有继承关系的指针或者引用，在转换前会进行对象类型安全检查
    
    {
        //1.基本类型无法转换
        
//        int a = 10;
//        char c = dynamic_cast<char *>(a);
    }
    
    {
        //2.无继承关系类型指针无法转换
//        Building *buildPtr = NULL;
//        Animal *p = dynamic_cast<Animal *>(buildPtr);
    }
    
    {
        //3.继承关系类型指针可以转换 ,且只能子类转换为父类
        Cat *cPtr = NULL;
        Animal *p = dynamic_cast<Animal *>(cPtr);
        
    }
    {
        //4.继承关系类型指针可以转换,但是父类无法转换为子类进行对象类型安全检查
//        Animal *animalPtr = NULL;
//        Cat *p = dynamic_cast<Cat *>(animalPtr);
    }
    
    
    return 0;
}
