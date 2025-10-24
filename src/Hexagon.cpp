#include "../include/Hexagon.h"

Hexagon::Hexagon() : vertices{} {}

Hexagon::Hexagon(const std::array<std::pair<double, double>, 6>& vertices) 
    : vertices(vertices) {}

Hexagon::Hexagon(const Hexagon& other) : vertices(other.vertices) {}

Hexagon::Hexagon(Hexagon&& other) noexcept : vertices(std::move(other.vertices)) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

double Hexagon::area() const {
    double area = 0.0;
    for (size_t i = 0; i < 6; ++i) {
        size_t next = (i + 1) % 6;
        area += vertices[i].first * vertices[next].second - vertices[next].first * vertices[i].second;
    }
    return std::abs(area) / 2.0;
}

void Hexagon::print(std::ostream& os) const {
    os << "Hexagon: ";
    for (size_t i = 0; i < 6; ++i) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i < 5) os << " ";
    }
}

std::pair<double, double> Hexagon::geometricCenter() const {
    double centerX = 0.0, centerY = 0.0;
    for (const auto& vertex : vertices) {
        centerX += vertex.first;
        centerY += vertex.second;
    }
    return {centerX / 6.0, centerY / 6.0};
}

std::shared_ptr<Figure> Hexagon::clone() const {
    return std::make_shared<Hexagon>(*this);
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    if (!otherHexagon) return false;
    return vertices == otherHexagon->vertices;
}

bool Hexagon::operator!=(const Figure& other) const {
    return !(*this == other);
}

void Hexagon::read(std::istream& is) {
    std::string line;
    std::getline(is, line);
    std::istringstream iss(line);
    
    for (int i = 0; i < 6; ++i) {
        char dummy;
        iss >> dummy;
        iss >> vertices[i].first;
        iss >> dummy;
        iss >> vertices[i].second;
        iss >> dummy;
    }
}

const std::array<std::pair<double, double>, 6>& Hexagon::getVertices() const {
    return vertices;
}