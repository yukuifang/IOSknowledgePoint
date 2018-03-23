//
//  Cube.hpp
//  day01
//
//  Created by fangyukui on 2018/3/23.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma once

class Cube{
public:
    void setABC(int a = 0,int b = 0,int c = 0);
    int getV();
    int getS();
    bool judgeCube(Cube &c);
    
private:
    int a;
    int b;
    int c;
    
    
};

