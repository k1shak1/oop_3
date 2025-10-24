#include "../include/Octagon.h"

Octagon::Octagon() : vertices{} {}

Octagon::Octagon(const std::array<std::pair<double, double>, 8>& vertices) 
    : vertices(vertices) {}

Octagon::Octagon(const Octagon& other) : vertices(other.vertices) {}

Octagon::Octagon(Octagon&& other) noexcept : vertices(std::move(other.vertices)) {}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

double Octagon::area() const {
    double area = 0.0;
    for (size_t i = 0; i < 8; ++i) {
        size_t next = (i + 1) % 8;
        area += vertices[i].first * vertices[next].second - vertices[next].first * vertices[i].second;
    }
    return std::abs(area) / 2.0;
}

void Octagon::print(std::ostream& os) const {
    os << "Octagon: ";
    for (size_t i = 0; i < 8; ++i) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i < 7) os << " ";
    }
}

std::pair<double, double> Octagon::geometricCenter() const {
    double centerX = 0.0, centerY = 0.0;
    for (const auto& vertex : vertices) {
        centerX += vertex.first;
        centerY += vertex.second;
    }
    return {centerX / 8.0, centerY / 8.0};
}

std::shared_ptr<Figure> Octagon::clone() const {
    return std::make_shared<Octagon>(*this);
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
    if (!otherOctagon) return false;
    return vertices == otherOctagon->vertices;
}

bool Octagon::operator!=(const Figure& other) const {
    return !(*this == other);
}

void Octagon::read(std::istream& is) {
    std::string line;
    std::getline(is, line);
    std::istringstream iss(line);
    
    for (int i = 0; i < 8; ++i) {
        char dummy;
        iss >> dummy;
        iss >> vertices[i].first;
        iss >> dummy;
        iss >> vertices[i].second;
        iss >> dummy;
    }
}

const std::array<std::pair<double, double>, 8>& Octagon::getVertices() const {
    return vertices;
}