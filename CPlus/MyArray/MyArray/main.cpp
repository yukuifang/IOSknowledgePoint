//
//  main.cpp
//  MyArray
//
//  Created by fangyukui on 2018/5/15.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "MyArray.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    MyArray<int> marray(20);
    for (int i=0; i<10; i++) {
        marray.pushBack(i);
    }
    marray.pushBack(10);
    for (int i=0; i<marray.getMSize(); i++) {
        cout << marray[i] << endl;
    }
    
    
//    MyArray<int> marray2(20);
//
//    marray2 = marray;
//
//    for (int i=0; i<marray2.getMSize(); i++) {
//        cout << marray2[i] << endl;
//    }
    
    
    
    
    return 0;
}
