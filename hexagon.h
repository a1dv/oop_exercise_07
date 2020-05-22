#pragma once

#include "figure.h"

struct hexagon : figure
{
    point a1, a2, a3, a4, a5, a6;
    point center() const override;
    void print(std::ostream& out) const override;
    void printFile(std::ofstream& out) const override;
    double area() const override;
    hexagon() = default;
    hexagon(std::istream& npt);
    hexagon(std::ifstream& npt);
};
