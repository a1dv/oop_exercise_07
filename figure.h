#pragma once
#include <iostream>
#include "point.h"

struct figure {
    virtual point center() const = 0;
    virtual void print(std::ostream&) const = 0 ;
    virtual double area() const = 0;
    virtual void printFile(std::ofstream&) const = 0 ;
    virtual ~figure() = default;
};
