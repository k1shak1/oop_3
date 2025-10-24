#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include <array>
#include <sstream>

class Triangle : public Figure {
private:
    std::array<std::pair<double, double>, 3> vertices;
    
public:
    Triangle();
    Triangle(const std::array<std::pair<double, double>, 3>& vertices);
    
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    
    double area() const override;
    void print(std::ostream& os) const override;
    std::pair<double, double> geometricCenter() const override;
    std::shared_ptr<Figure> clone() const override;
    
    bool operator==(const Figure& other) const override;
    bool operator!=(const Figure& other) const override;
    
    void read(std::istream& is) override;
    
    const std::array<std::pair<double, double>, 3>& getVertices() const;
};

#endif