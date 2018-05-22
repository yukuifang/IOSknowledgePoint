//
//  main.cpp
//  DynamicArray
//
//  Created by fangyukui on 2018/5/22.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "DynamicArray.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    Dynamic_Array *marry = init_Array();
    
    cout << "capacity:" << capacity_Array(marry) << ",size:" << size_Array(marry)<<endl;
    
    for (int i=0; i<22; i++) {
        pushBack_Array(marry, i);
        
    }
    cout << "capacity:" << capacity_Array(marry) << ",size:" << size_Array(marry)<<endl;
    printf_Array(marry);
    
    removeByPos_Array(marry, 2);
    
    printf_Array(marry);
    
    freeSpace_Array(marry);
    
    
    return 0;
}
