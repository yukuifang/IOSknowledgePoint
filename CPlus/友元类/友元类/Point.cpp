//
//  Point.cpp
//  友元类
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include "Point.hpp"

double PointManager::distancePoint(Point &a,Point &b){
    double daltX = a.x - b.x;
    double daltY = a.y - b.y;
    return sqrt(daltX * daltX  + daltY * daltY);
}


