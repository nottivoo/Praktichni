#include <iostream>
#include <cstdlib>
#include <ctime>

void print3DArray(double*** arr, int depth, int rows, int cols) {
    for (int d = 0; d < depth; ++d) {
        std::cout << "--- Зріз (Глибина) " << d + 1 << " ---" << std::endl;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                std::cout << arr[d][r][c] << "\t";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int choice;

    do {
        std::cout << "\n======= ПРАКТИЧНА №16: МЕНЮ =======" << std::endl;
        std::cout << "1. Завдання 1 (Динамічні примітивні типи)" << std::endl;
        std::cout << "2. Завдання 2 (Посилання на double через вказівник)" << std::endl;
        std::cout << "3. Завдання 3 (Динамічний масив з індексами реверсом)" << std::endl;
        std::cout << "4. Завдання 4 (Тримірний динамічний масив)" << std::endl;
        std::cout << "0. Вихід" << std::endl;
        std::cout << "Виберіть завдання: ";
        std::cin >> choice;

        if (choice == 1) {
            int* pInt = new int;
            char* pChar = new char;
            double* pDouble = new double;

            std::cout << "Введіть ціле число (int): ";
            std::cin >> *pInt;
            std::cout << "Введіть символ (char): ";
            std::cin >> *pChar;
            std::cout << "Введіть дійсне число (double): ";
            std::cin >> *pDouble;

            std::cout << "\nВведені дані:" << std::endl;
            std::cout << "int: " << *pInt << ", char: " << *pChar << ", double: " << *pDouble << std::endl;

            delete pInt;
            delete pChar;
            delete pDouble;
        }
        else if (choice == 2) {
            double* pDouble = new double;
            double& refDouble = *pDouble;

            std::cout << "Введіть значення для double через посилання: ";
            std::cin >> refDouble;

            std::cout << "Значення виведене через вказівник: " << *pDouble << std::endl;

            delete pDouble;
        }
        else if (choice == 3) {
            int size;
            std::cout << "Введіть розмір масиву: ";
            std::cin >> size;

            if (size > 0) {
                int* arr = new int[size];

                for (int i = 0; i < size; ++i) {
                    arr[i] = size - 1 - i;
                }

                std::cout << "Елементи масиву в окремому циклі:" << std::endl;
                for (int i = 0; i < size; ++i) {
                    std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
                }

                delete[] arr;
            }
        }
        else if (choice == 4) {
            int depth, rows, cols;
            std::cout << "Введіть розміри 3D масиву (глибина, рядки, стовпці): ";
            std::cin >> depth >> rows >> cols;

            if (depth > 0 && rows > 0 && cols > 0) {
                double*** arr3d = new double**[depth];
                for (int d = 0; d < depth; ++d) {
                    arr3d[d] = new double*[rows];
                    for (int r = 0; r < rows; ++r) {
                        arr3d[d][r] = new double[cols];
                    }
                }

                for (int d = 0; d < depth; ++d) {
                    for (int r = 0; r < rows; ++r) {
                        for (int c = 0; c < cols; ++c) {
                            arr3d[d][r][c] = (std::rand() % 1000) / 10.0;
                        }
                    }
                }

                std::cout << "\nВиклик функції для виведення 3D масиву:" << std::endl;
                print3DArray(arr3d, depth, rows, cols);

                for (int d = 0; d < depth; ++d) {
                    for (int r = 0; r < rows; ++r) {
                        delete[] arr3d[d][r];
                    }
                    delete[] arr3d[d];
                }
                delete[] arr3d;
            }
        }
    } while (choice != 0);

    return 0;
}
