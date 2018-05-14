//
//  main.cpp
//  智能指针
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>
#include "A.hpp"
#include "My_Auto_Ptr.hpp"
#include <memory.h>

void test(){
#if 0
     auto_ptr<A> ptr(new A(10));
#endif
    My_Auto_Ptr<A> myPtr(new A(10));
    
    
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
