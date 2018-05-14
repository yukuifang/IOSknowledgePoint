//
//  Point.hpp
//  友元类
//
//  Created by fangyukui on 2018/5/14.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#pragma  once
#include <cmath>

class Point;

class PointManager{
public:
    double distancePoint(Point &a,Point &b);
};

class Point{
    friend double PointManager::distancePoint(Point &a,Point &b);
private:
    double x;
    double y;
public:
    Point(double x = 0,double y = 0)
    {
        this->x = x;
        this->y = y;
    }
};







