#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"
#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>

class Array {
private:
    std::vector<std::shared_ptr<Figure>> figures;
    
public:
    Array() = default;
    
    void addFigure(std::shared_ptr<Figure> figure);
    void removeFigure(size_t index);
    size_t size() const;
    std::shared_ptr<Figure> getFigure(size_t index) const;
    double totalArea() const;
    void printAll() const;
    void clear();
};

#endif