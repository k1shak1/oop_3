#include "../include/Array.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include "../include/Triangle.h"
#include <iostream>
#include <memory>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Array figures;
    int choice;
    
    do {
        std::cout << "\n=== Figure Manager ===" << std::endl;
        std::cout << "1. Add Triangle" << std::endl;
        std::cout << "2. Add Hexagon" << std::endl;
        std::cout << "3. Add Octagon" << std::endl;
        std::cout << "4. Remove figure" << std::endl;
        std::cout << "5. Show all figures" << std::endl;
        std::cout << "6. Total area" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;
        
        // Очищаем буфер после ввода числа
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                std::cout << "Enter triangle vertices (format: (x1,y1) (x2,y2) (x3,y3)):" << std::endl;
                std::cout << "Example: (0,0) (4,0) (0,3)" << std::endl;
                std::cout << "Your input: ";
                
                auto triangle = std::make_shared<Triangle>();
                std::cin >> *triangle;
                figures.addFigure(triangle);
                std::cout << "Triangle added!" << std::endl;
                
                // Очищаем буфер после ввода фигуры
                clearInputBuffer();
                break;
            }
            case 2: {
                std::cout << "Enter hexagon vertices (format: (x1,y1) (x2,y2) ... (x6,y6)):" << std::endl;
                std::cout << "Example: (0,0) (2,0) (3,1) (2,2) (0,2) (-1,1)" << std::endl;
                std::cout << "Your input: ";
                
                auto hexagon = std::make_shared<Hexagon>();
                std::cin >> *hexagon;
                figures.addFigure(hexagon);
                std::cout << "Hexagon added!" << std::endl;
                
                clearInputBuffer();
                break;
            }
            case 3: {
                std::cout << "Enter octagon vertices (format: (x1,y1) (x2,y2) ... (x8,y8)):" << std::endl;
                std::cout << "Example: (0,0) (2,0) (3,1) (3,3) (2,4) (0,4) (-1,3) (-1,1)" << std::endl;
                std::cout << "Your input: ";
                
                auto octagon = std::make_shared<Octagon>();
                std::cin >> *octagon;
                figures.addFigure(octagon);
                std::cout << "Octagon added!" << std::endl;
                
                clearInputBuffer();
                break;
            }
            case 4: {
                if (figures.size() == 0) {
                    std::cout << "No figures to remove!" << std::endl;
                    break;
                }
                std::cout << "Enter index (0-" << figures.size()-1 << "): ";
                int index;
                std::cin >> index;
                clearInputBuffer();
                
                if (index >= 0 && index < figures.size()) {
                    figures.removeFigure(index);
                    std::cout << "Figure removed!" << std::endl;
                } else {
                    std::cout << "Invalid index!" << std::endl;
                }
                break;
            }
            case 5:
                figures.printAll();
                break;
            case 6:
                std::cout << "Total area: " << figures.totalArea() << std::endl;
                break;
            case 0:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                clearInputBuffer();
        }
    } while (choice != 0);
    
    return 0;
}