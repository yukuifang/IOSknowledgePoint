//
//  OperationOverload.cpp
//  day01
//
//  Created by fangyukui on 2018/3/27.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "OperationOverload.hpp"

ostream& operator<<(ostream &cout, Complex &c){
    cout<< "生活如此艰难"<<endl;
    cout << c.x << c.y << endl;
    return cout;
}

