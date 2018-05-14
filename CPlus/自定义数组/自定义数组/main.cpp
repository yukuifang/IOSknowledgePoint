//
//  main.cpp
//  自定义数组
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "Array.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    Array a(10);
    a[0] = 1;
    a[1] = 2;
    
    Array b(20);
    b = a;
    
    cout << b.getData(1) << endl;
    
    
    
    bool result = (a==b);
    
    cout << result << endl;
    
    return 0;
}
