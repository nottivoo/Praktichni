#include <iostream>
#include <string>

void processIntArray(const int* arr, int size) {
    if (size <= 0) return;
    int evenSum = 0, oddSum = 0;
    int evenCount = 0, oddCount = 0;

    for (const int* ptr = arr; ptr < arr + size; ++ptr) {
        if (*ptr % 2 == 0) {
            evenSum += *ptr;
            evenCount++;
        } else {
            oddSum += *ptr;
            oddCount++;
        }
    }

    std::cout << "\n--- Результати для масиву цілих чисел ---" << std::endl;
    if (evenCount > 0) std::cout << "Середнє парних: " << static_cast<double>(evenSum) / evenCount << std::endl;
    else std::cout << "Парні елементи відсутні." << std::endl;

    if (oddCount > 0) std::cout << "Середнє непарних: " << static_cast<double>(oddSum) / oddCount << std::endl;
    else std::cout << "Непарні елементи відсутні." << std::endl;
}

void processStringArray(const std::string* arr, int size) {
    if (size <= 0) return;
    const std::string* longest = arr;
    const std::string* shortest = arr;

    for (const std::string* ptr = arr + 1; ptr < arr + size; ++ptr) {
        if (ptr->length() > longest->length()) longest = ptr;
        if (ptr->length() < shortest->length()) shortest = ptr;
    }

    std::cout << "\n--- Результати для масиву рядків ---" << std::endl;
    std::cout << "Найдовший рядок: \"" << *longest << "\" (розмір: " << longest->length() << ")" << std::endl;
    std::cout << "Найкоротший рядок: \"" << *shortest << "\" (розмір: " << shortest->length() << ")" << std::endl;
}

void processFloatArray(const double* arr, int size) {
    if (size <= 0) return;
    double sum = 0.0;

    for (const double* ptr = arr + size - 1; ptr >= arr; --ptr) {
        sum += *ptr;
    }

    std::cout << "\n--- Результати для масиву чисел із плаваючою крапкою ---" << std::endl;
    std::cout << "Сума елементів (реверсивно): " << sum << std::endl;
}

int main() {
    int choice;
    do {
        std::cout << "\n================ МЕНЮ ================" << std::endl;
        std::cout << "1. Обчислити середнє парних/непарних чисел" << std::endl;
        std::cout << "2. Знайти найдовший/найкоротший рядок" << std::endl;
        std::cout << "3. Обчислити суму дійсних чисел (реверсивно)" << std::endl;
        std::cout << "0. Вихід" << std::endl;
        std::cout << "Виберіть опцію: ";
        std::cin >> choice;

        if (choice == 1) {
            int size;
            std::cout << "Введіть розмір масиву: ";
            std::cin >> size;
            if (size > 0) {
                int* arr = new int[size];
                std::cout << "Введіть елементи масиву:\n";
                for (int i = 0; i < size; ++i) std::cin >> arr[i];
                processIntArray(arr, size);
                delete[] arr;
            }
        } 
        else if (choice == 2) {
            int size;
            std::cout << "Введіть кількість рядків: ";
            std::cin >> size;
            if (size > 0) {
                std::string* arr = new std::string[size];
                std::cout << "Введіть рядки:\n";
                std::cin.ignore();
                for (int i = 0; i < size; ++i) std::getline(std::cin, arr[i]);
                processStringArray(arr, size);
                delete[] arr;
            }
        } 
        else if (choice == 3) {
            int size;
            std::cout << "Введіть розмір масиву дійсних чисел: ";
            std::cin >> size;
            if (size > 0) {
                double* arr = new double[size];
                std::cout << "Введіть елементи масиву:\n";
                for (int i = 0; i < size; ++i) std::cin >> arr[i];
                processFloatArray(arr, size);
                delete[] arr;
            }
        }
    } while (choice != 0);

    return 0;
}
