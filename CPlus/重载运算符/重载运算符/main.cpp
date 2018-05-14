//
//  main.cpp
//  重载运算符
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "Reload_1.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    {
//        Sqr a(10);
//
//        int result1 = a.operator()(20);
//        int result2  = a(20); //伪函数
//
//        cout << result1 << "  " << result2  << endl;
    }
    
    {
//        Sqr *s = new Sqr(10);
//        delete(s);
    }
    
    {
        Sqr *s = new Sqr[20];
        delete [] s;
        
    }
    
    
    
    
    return 0;
}
