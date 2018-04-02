//
//  MyString.cpp
//  day01
//
//  Created by fangyukui on 2018/3/28.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "MyString.hpp"

ostream & operator<<(ostream &cout,MyString &obj) {
    cout << obj.p << endl;
    return cout;
}
