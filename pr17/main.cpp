#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Point {
    double x;
    double y;
};

double calculateDistance(Point p1, Point p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double calculateRectangleArea(const Point* vertices, int size) {
    if (size < 4) return 0.0;
    
    double side1 = calculateDistance(vertices[0], vertices[1]);
    double side2 = calculateDistance(vertices[1], vertices[2]);
    
    return side1 * side2;
}

bool validateRectangle(const Point* vertices, int size) {
    if (size != 4) return false;

    double d02 = std::pow(vertices[0].x - vertices[2].x, 2) + std::pow(vertices[0].y - vertices[2].y, 2);
    double d13 = std::pow(vertices[1].x - vertices[3].x, 2) + std::pow(vertices[1].y - vertices[3].y, 2);

    return std::abs(d02 - d13) < 1e-4;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int choice;

    do {
        std::cout << "\n======= ПРАКТИЧНА №17: МЕНЮ =======" << std::endl;
        std::cout << "1. Розрахунок площі прямокутника" << std::endl;
        std::cout << "0. Вихід" << std::endl;
        std::cout << "Виберіть опцію: ";
        std::cin >> choice;

        if (choice == 1) {
            int mode;
            std::cout << "\nВиберіть джерело значень координат:\n";
            std::cout << "1. Ввести самостійно\n";
            std::cout << "2. Згенерувати випадковим чином\n";
            std::cout << "Вибір: ";
            std::cin >> mode;

            int numVertices = 4;
            Point* rectangle = new Point[numVertices];
            bool isValid = false;

            if (mode == 1) {
                std::cout << "Введіть координати 4 вершин прямокутника по черзі (x та y через пробіл):\n";
                for (int i = 0; i < numVertices; ++i) {
                    std::cout << "Вершина " << i + 1 << ": ";
                    std::cin >> rectangle[i].x >> rectangle[i].y;
                }
                isValid = validateRectangle(rectangle, numVertices);
            } 
            else if (mode == 2) {
                double startX = (std::rand() % 100) / 2.0;
                double startY = (std::rand() % 100) / 2.0;
                double width = ((std::rand() % 50) + 2) / 2.0;
                double height = ((std::rand() % 50) + 2) / 2.0;

                rectangle[0] = {startX, startY};
                rectangle[1] = {startX + width, startY};
                rectangle[2] = {startX + width, startY + height};
                rectangle[3] = {startX, startY + height};

                std::cout << "\nЗгенеровані координати вершин прямокутника:\n";
                for (int i = 0; i < numVertices; ++i) {
                    std::cout << "Вершина " << i + 1 << ": (" << rectangle[i].x << ", " << rectangle[i].y << ")\n";
                }
                isValid = validateRectangle(rectangle, numVertices);
            }

            if (isValid) {
                double area = calculateRectangleArea(rectangle, numVertices);
                std::cout << "\nПеревірка успішна: Дані коректні (це прямокутник)." << std::endl;
                std::cout << "Розрахована площа прямокутника: " << area << std::endl;
            } else {
                std::cout << "\nПомилка: Введені або згенеровані координати не утворюють прямокутник!" << std::endl;
            }

            delete[] rectangle;
        }
    } while (choice != 0);

    return 0;
}
