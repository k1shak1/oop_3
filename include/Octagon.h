#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"
#include <array>
#include <sstream>

class Octagon : public Figure {
private:
    std::array<std::pair<double, double>, 8> vertices;
    
public:
    Octagon();
    Octagon(const std::array<std::pair<double, double>, 8>& vertices);
    
    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept;
    
    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;
    
    double area() const override;
    void print(std::ostream& os) const override;
    std::pair<double, double> geometricCenter() const override;
    std::shared_ptr<Figure> clone() const override;
    
    bool operator==(const Figure& other) const override;
    bool operator!=(const Figure& other) const override;
    
    void read(std::istream& is) override;
    
    const std::array<std::pair<double, double>, 8>& getVertices() const;
};

#endif