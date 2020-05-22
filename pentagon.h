#pragma once
#include "figure.h"
#include <fstream>

struct pentagon : figure{
    point a1,a2,a3,a4,a5;
    point center() const override;
    void print(std::ostream& out) const override;
    void printFile(std::ofstream& out) const;
    double area() const override;
    pentagon() = default;
    pentagon(std::istream& is);
    pentagon(std::ifstream& is);
};
