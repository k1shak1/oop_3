#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"
#include <array>
#include <sstream>

class Hexagon : public Figure {
private:
    std::array<std::pair<double, double>, 6> vertices;
    
public:
    Hexagon();
    Hexagon(const std::array<std::pair<double, double>, 6>& vertices);
    
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    
    double area() const override;
    void print(std::ostream& os) const override;
    std::pair<double, double> geometricCenter() const override;
    std::shared_ptr<Figure> clone() const override;
    
    bool operator==(const Figure& other) const override;
    bool operator!=(const Figure& other) const override;
    
    void read(std::istream& is) override;
    
    const std::array<std::pair<double, double>, 6>& getVertices() const;
};

#endif