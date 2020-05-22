#include "point.h"

std::istream& operator >> (std::istream& npt,point& p ) {
    return  npt >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& out,const point& p) {
    return out << p.x << ' ' << p.y << '\n';
}
