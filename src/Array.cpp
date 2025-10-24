#include "../include/Array.h"

void Array::addFigure(std::shared_ptr<Figure> figure) {
    figures.push_back(figure);
}

void Array::removeFigure(size_t index) {
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

size_t Array::size() const {
    return figures.size();
}

std::shared_ptr<Figure> Array::getFigure(size_t index) const {
    if (index < figures.size()) {
        return figures[index];
    }
    return nullptr;
}

double Array::totalArea() const {
    double total = 0.0;
    for (const auto& figure : figures) {
        total += figure->area();
    }
    return total;
}

void Array::printAll() const {
    std::cout << "\n=== Information about all figures ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":\n";
        std::cout << "  Type: " << *figures[i] << "\n";
        
        auto center = figures[i]->geometricCenter();
        std::cout << "  Geometric Center: (" << center.first << ", " << center.second << ")\n";
        std::cout << "  Area: " << figures[i]->area() << "\n\n";
    }
    std::cout << "Total area of all figures: " << totalArea() << "\n";
}

void Array::clear() {
    figures.clear();
}