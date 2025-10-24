#include "../include/Triangle.h"

Triangle::Triangle() : vertices{} {}

Triangle::Triangle(const std::array<std::pair<double, double>, 3>& vertices) 
    : vertices(vertices) {}

Triangle::Triangle(const Triangle& other) : vertices(other.vertices) {}

Triangle::Triangle(Triangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

double Triangle::area() const {
    double x1 = vertices[0].first;
    double y1 = vertices[0].second;
    double x2 = vertices[1].first;
    double y2 = vertices[1].second;
    double x3 = vertices[2].first;
    double y3 = vertices[2].second;
    
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle: ";
    for (size_t i = 0; i < 3; ++i) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i < 2) os << " ";
    }
}

std::pair<double, double> Triangle::geometricCenter() const {
    double centerX = 0.0, centerY = 0.0;
    for (const auto& vertex : vertices) {
        centerX += vertex.first;
        centerY += vertex.second;
    }
    return {centerX / 3.0, centerY / 3.0};
}

std::shared_ptr<Figure> Triangle::clone() const {
    return std::make_shared<Triangle>(*this);
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (!otherTriangle) return false;
    return vertices == otherTriangle->vertices;
}

bool Triangle::operator!=(const Figure& other) const {
    return !(*this == other);
}

void Triangle::read(std::istream& is) {
    std::string line;
    std::getline(is, line);
    std::istringstream iss(line);
    
    for (int i = 0; i < 3; ++i) {
        char dummy;
        iss >> dummy; // '('
        iss >> vertices[i].first;
        iss >> dummy; // ','
        iss >> vertices[i].second;
        iss >> dummy; // ')'
    }
}

const std::array<std::pair<double, double>, 3>& Triangle::getVertices() const {
    return vertices;
}