#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* buffer;       
    int current_size;  
    int buffer_size;   

    void resize_buffer() {
        buffer_size = (buffer_size == 0) ? 1 : buffer_size * 2;
        int* new_buffer = new int[buffer_size];
        for (int i = 0; i < current_size; ++i) {
            new_buffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = new_buffer;
    }

public:
    Vector() {
        buffer_size = 4; 
        current_size = 0;
        buffer = new int[buffer_size];
    }

    ~Vector() {
        delete[] buffer;
    }

    void push_back(int value) {
        if (current_size >= buffer_size) {
            resize_buffer();
        }
        buffer[current_size] = value;
        current_size++;
    }

    void insert(int index, int value) {
        if (index < 0 || index > current_size) {
            throw std::out_of_range("Помилка: Індекс виходить за межі вектора!");
        }
        if (current_size >= buffer_size) {
            resize_buffer();
        }
        for (int i = current_size; i > index; --i) {
            buffer[i] = buffer[i - 1];
        }
        buffer[index] = value;
        current_size++;
    }

    void erase(int index) {
        if (index < 0 || index >= current_size) {
            throw std::out_of_range("Помилка: Індекс виходить за межі вектора для видалення!");
        }
        for (int i = index; i < current_size - 1; ++i) {
            buffer[i] = buffer[i + 1];
        }
        current_size--;
    }

    int get(int index) const {
        if (index < 0 || index >= current_size) {
            throw std::out_of_range("Помилка: Спроба отримати елемент за неіснуючим індексом!");
        }
        return buffer[index];
    }

    int size() const {
        return current_size;
    }

    int capacity() const {
        return buffer_size;
    }

    void print() const {
        if (current_size == 0) {
            std::cout << "[ Порожній вектор ]" << std::endl;
            return;
        }
        std::cout << "[ ";
        for (int i = 0; i < current_size; ++i) {
            std::cout << buffer[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    std::setlocale(LC_ALL, "Ukrainian"); 
    Vector vec;
    int choice;

    std::cout << "=== Демонстрація роботи структури даних Vector ===" << std::endl;

    while (true) {
        std::cout << "\nПоточний стан вектора: ";
        vec.print();
        std::cout << "Елементів: " << vec.size() << " | Розмір буфера: " << vec.capacity() << std::endl;
        
        std::cout << "\nОберіть дію:\n";
        std::cout << "1. Додати елемент в кінець\n";
        std::cout << "2. Додати елемент за індексом\n";
        std::cout << "3. Видалити елемент за індексом\n";
        std::cout << "4. Отримати елемент за індексом\n";
        std::cout << "5. Вийти з програми\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Програму завершено. Бувай!" << std::endl;
            break;
        }

        try {
            int val, idx;
            switch (choice) {
                case 1:
                    std::cout << "Введіть значення: ";
                    std::cin >> val;
                    vec.push_back(val);
                    break;
                case 2:
                    std::cout << "Введіть індекс: ";
                    std::cin >> idx;
                    std::cout << "Введіть значення: ";
                    std::cin >> val;
                    vec.insert(idx, val);
                    break;
                case 3:
                    std::cout << "Введіть індекс для видалення: ";
                    std::cin >> idx;
                    vec.erase(idx);
                    break;
                case 4:
                    std::cout << "Введіть індекс: ";
                    std::cin >> idx;
                    std::cout << "Елемент за індексом " << idx << " дорівнює: " << vec.get(idx) << std::endl;
                    break;
                default:
                    std::cout << "Некоректний вибір, спробуйте ще раз." << std::endl;
            }
        } 
        catch (const std::out_of_range& e) {
            std::cout << "\n>>> " << e.what() << " <<<\n" << std::endl;
        }
    }

    return 0;
}
