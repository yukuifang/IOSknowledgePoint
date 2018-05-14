//
//  main.cpp
//  友元类
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "friend.hpp"
#include "OperationOverload.hpp"
#include "Point.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    {
//        B b;
//        b.modifyA();
    }
    
    {
//        Complex a(1,2);
//        Complex b(1,2);
//        Complex c = a + b;
//        c.description();
//
//        Complex e(1,2);
//        ++e;
//        e++;
//        e.description();
//
//
//        cout<< a << "支持链式编程输出" << endl;
        
        
    }
    {
        Point a(1,1);
        Point b(2,1);
        PointManager pm;
        double r =  pm.distancePoint(a, b);
        cout << r << endl;
        
    }
    
    
  
    
    
    
    return 0;
    
}
