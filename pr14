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
    if (evenCount > 0) {
        std::cout << "Середнє значення парних елементів: " << static_cast<double>(evenSum) / evenCount << std::endl;
    } else {
        std::cout << "Парні елементи відсутні." << std::endl;
    }

    if (oddCount > 0) {
        std::cout << "Середнє значення непарних елементів: " << static_cast<double>(oddSum) / oddCount << std::endl;
    } else {
        std::cout << "Непарні елементи відсутні." << std::endl;
    }
}

void processStringArray(const std::string* arr, int size) {
    if (size <= 0) return;

    const std::string* longest = arr;
    const std::string* shortest = arr;

    for (const std::string* ptr = arr + 1; ptr < arr + size; ++ptr) {
        if (ptr->length() > longest->length()) {
            longest = ptr;
        }
        if (ptr->length() < shortest->length()) {
            shortest = ptr;
        }
    }

    std::cout << "\n--- Результати для масиву рядків ---" << std::endl;
    std::cout << "Найдовший рядок: \"" << *longest << "\" (розмір: " << longest->length() << " символів)" << std::endl;
    std::cout << "Найкоротший рядок: \"" << *shortest << "\" (розмір: " << shortest->length() << " символів)" << std::endl;
}

void processFloatArray(const double* arr, int size) {
    if (size <= 0) return;

    double sum = 0.0;

    for (const double* ptr = arr + size - 1; ptr >= arr; --ptr) {
        sum += *ptr;
    }

    std::cout << "\n--- Результати для масиву чисел із плаваючою крапкою ---" << std::endl;
    std::cout << "Сума елементів (порахована реверсивно): " << sum << std::endl;
}

int main() {
    int intArr[] = {12, 7, 24, 15, 30, 3, 8};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    processIntArray(intArr, intSize);

    std::string strArr[] = {"Програмування", "C++", "Вказівник", "Ітерація", "Код"};
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    processStringArray(strArr, strSize);

    double floatArr[] = {10.5, 20.75, 4.2, 8.91, 15.0};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    processFloatArray(floatArr, floatSize);

    std::cout << std::endl;
    return 0;
}
