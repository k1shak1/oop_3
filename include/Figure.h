#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <utility>

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual std::pair<double, double> geometricCenter() const = 0;
    
    virtual std::shared_ptr<Figure> clone() const = 0;
    
    virtual bool operator==(const Figure& other) const = 0;
    virtual bool operator!=(const Figure& other) const = 0;
    
    virtual void read(std::istream& is) = 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);

#endif