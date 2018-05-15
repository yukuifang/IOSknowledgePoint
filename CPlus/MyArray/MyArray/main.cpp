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
    for (int i=0; i<marray.getMSize(); i++) {
        cout << marray[i] << endl;
    }
    
    
    return 0;
}
