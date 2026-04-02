#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));
    int task;

    std::cout << "Выберите номер задания (1, 2, 3, 5): ";
    std::cin >> task;

    if (task == 1) {
        // Завдання 1: Генерация массива
        int array[10];
        std::cout << "Your array: ";
        for (int i = 0; i < 10; i++) {
            array[i] = rand() % 100;
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

    } else if (task == 2) {
        // Завдання 2: Проверка многоугольника
        int n = 0;
        std::cout << "Put how many corners you want: ";
        std::cin >> n;

        if (n < 3) {
            std::cout << "A polygon must have at least 3 corners." << std::endl;
        } else {
            int x[20];
            int sum = 0;
            std::cout << "Write your corners: " << std::endl;
            for (int i = 0; i < n; i++) {
                std::cin >> x[i];
                sum += x[i];
            }
            std::cout << "Sum of your corners = " << sum << std::endl;

            if (sum == 180 * (n - 2)) {
                std::cout << "The polygon exists" << std::endl;
            } else {
                std::cout << "The polygon can't exist" << std::endl;
            }
        }

    } else if (task == 3) {
        // Завдання 3: Изменение элемента массива
        std::cout << "Write an array size: ";
        int size = 0;
        std::cin >> size;

        int array[100];
        std::cout << "Array: ";
        for (int i = 0; i < size; i++) {
            array[i] = rand() % 100;
            std::cout << array[i] << " ";
        }
        std::cout << "\nWrite index of element to change (0 to " << size-1 << "): ";
        int element;
        std::cin >> element;

        std::cout << "Enter the new value: ";
        int userNum;
        std::cin >> userNum;

        if (element >= 0 && element < size) {
            array[element] = userNum;
        }

        std::cout << "Your modified array: ";
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

    } else if (task == 5) {
        // Завдання 5: Проверка сортировки
        int array[100];
        std::cout << "Enter array size: ";
        int size = 0;
        std::cin >> size;

        std::cout << "Array: ";
        for (int i = 0; i < size; i++) {
            array[i] = rand() % 100;
            std::cout << array[i] << " ";
        }

        std::cout << "\nCheck order (1 - ascending, 2 - descending): ";
        int choice;
        std::cin >> choice;

        bool order = true;
        if (choice == 1) {
            for (int i = 0; i < size - 1; i++) {
                if (array[i] > array[i + 1]) {
                    order = false;
                    break;
                }
            }
            std::cout << (order ? "Array is in ascending order" : "Array is NOT in ascending order") << std::endl;
        } else if (choice == 2) {
            for (int i = 0; i < size - 1; i++) {
                if (array[i] < array[i + 1]) {
                    order = false;
                    break;
                }
            }
            std::cout << (order ? "Array is in descending order" : "Array is NOT in descending order") << std::endl;
        }
    } else {
        std::cout << "Неверный выбор или задание 'Pass'" << std::endl;
    }

    return 0;
}