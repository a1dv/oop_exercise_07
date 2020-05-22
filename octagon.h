#pragma once

#include "figure.h"

struct octagon : figure
{
    point a1, a2, a3, a4, a5, a6, a7, a8;
    point center() const override;
    void print(std::ostream& out) const override;
    void printFile(std::ofstream& out) const;
    double area() const override;
    octagon() = default;
    octagon(std::istream& is);
    octagon(std::ifstream& is);
};
