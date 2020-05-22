#pragma once
#include <iostream>
#include <fstream>

struct point {
    double x, y;
    point (double  a,double b) { x = a, y = b;};
    point() = default;
};

std::istream& operator >> (std::istream& npt,point& p );
std::ostream& operator << (std::ostream& out,const point& p);
