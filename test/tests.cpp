#include <gtest/gtest.h>
#include <memory>
#include "Array.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Triangle.h"

TEST(TriangleTest, BasicArea) {
    std::array<std::pair<double, double>, 3> vertices = {{{0, 0}, {4, 0}, {0, 3}}};
    Triangle triangle(vertices);
    EXPECT_DOUBLE_EQ(triangle.area(), 6.0);
}

TEST(TriangleTest, BasicCenter) {
    std::array<std::pair<double, double>, 3> vertices = {{{0, 0}, {4, 0}, {0, 3}}};
    Triangle triangle(vertices);
    auto center = triangle.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 4.0/3.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
}

TEST(HexagonTest, BasicArea) {
    std::array<std::pair<double, double>, 6> vertices = {{
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    }};
    Hexagon hexagon(vertices);
    double area = hexagon.area();
    EXPECT_GT(area, 0);
}

TEST(HexagonTest, BasicCenter) {
    std::array<std::pair<double, double>, 6> vertices = {{
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    }};
    Hexagon hexagon(vertices);
    auto center = hexagon.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
}

TEST(OctagonTest, BasicArea) {
    std::array<std::pair<double, double>, 8> vertices = {{
        {0, 0}, {2, 0}, {3, 1}, {3, 3},
        {2, 4}, {0, 4}, {-1, 3}, {-1, 1}
    }};
    Octagon octagon(vertices);
    double area = octagon.area();
    EXPECT_GT(area, 0);
}

TEST(OctagonTest, BasicCenter) {
    std::array<std::pair<double, double>, 8> vertices = {{
        {0, 0}, {2, 0}, {3, 1}, {3, 3},
        {2, 4}, {0, 4}, {-1, 3}, {-1, 1}
    }};
    Octagon octagon(vertices);
    auto center = octagon.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(ArrayTest, AddFigures) {
    Array array;
    auto triangle = std::make_shared<Triangle>(std::array<std::pair<double, double>, 3>{{{0, 0}, {4, 0}, {0, 3}}});
    array.addFigure(triangle);
    EXPECT_EQ(array.size(), 1);
}

TEST(ArrayTest, TotalArea) {
    Array array;
    auto triangle = std::make_shared<Triangle>(std::array<std::pair<double, double>, 3>{{{0, 0}, {4, 0}, {0, 3}}});
    array.addFigure(triangle);
    EXPECT_DOUBLE_EQ(array.totalArea(), 6.0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
