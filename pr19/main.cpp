#include <iostream>

class ArrayList {
private:
    int* data;
    int cap;
    int sz;

    void expand() {
        cap = (cap == 0) ? 2 : cap * 2;
        int* new_data = new int[cap];

        for (int i = 0; i < sz; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
    }

public:
    ArrayList() {
        data = nullptr;
        cap = 0;
        sz = 0;
    }

    ~ArrayList() {
        delete[] data;
    }

    void push_back(int value) {
        if (sz >= cap) {
            expand();
        }
        data[sz] = value;
        sz++;
    }

    void insert(int index, int value) {
        if (index < 0 || index > sz) {
            std::cout << "Error: Insert index out of bounds!" << std::endl;
            return;
        }

        if (sz >= cap) {
            expand();
        }

        for (int i = sz; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        sz++;
    }

    void remove(int index) {
        if (index < 0 || index >= sz) {
            std::cout << "Error: Delete index out of bounds!" << std::endl;
            return;
        }

        for (int i = index; i < sz - 1; i++) {
            data[i] = data[i + 1];
        }

        sz--;
    }

    int get(int index) {
        if (index < 0 || index >= sz) {
            std::cout << "Error: Get index out of bounds!" << std::endl;
            return -1; 
        }
        return data[index];
    }

    int size() {
        return sz;
    }

    int get_capacity() {
        return cap;
    }

    void print() {
        if (sz == 0) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        for (int i = 0; i < sz; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ArrayList list;

    std::cout << "--- Testing push_back ---" << std::endl;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.print();
    std::cout << "Size: " << list.size() << ", Buffer: " << list.get_capacity() << "\n\n";

    std::cout << "--- Testing insert ---" << std::endl;
    list.insert(1, 15);
    list.print();
    list.insert(0, 5);
    list.print();
    std::cout << "Size: " << list.size() << ", Buffer: " << list.get_capacity() << "\n\n";

    std::cout << "--- Testing get ---" << std::endl;
    std::cout << "Element at index 2: " << list.get(2) << "\n\n";

    std::cout << "--- Testing remove ---" << std::endl;
    list.remove(2);
    list.print();
    std::cout << "Size: " << list.size() << ", Buffer: " << list.get_capacity() << "\n\n";

    std::cout << "--- Testing errors ---" << std::endl;
    list.get(10);
    list.remove(-5);
    list.insert(20, 99);

    return 0;
}
