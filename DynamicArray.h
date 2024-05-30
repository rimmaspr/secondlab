#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class DynamicArray {
private:
    T *arr;
    int size_array;
    int size_now; 

public:
    DynamicArray(int size) : size_array(size), size_now(0) {
        arr = new T[size_array];
    }

    ~DynamicArray() {
        delete[] arr;
    }


    void append(const T& element) {
        if (size_now >= size_array) {
            resize(size_array * 2);
            }
        arr[size_now++] = element;
    }

    void resize(int newSize) {
        if (newSize < 0) {
            throw std::invalid_argument("New size must be non-negative");
        }

        T* temp = new T[newSize];
        for (int i = 0; i < size_now; ++i) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size_array = newSize;
    }

    int getSize() const {
        return size_now;
    }

    void printArray() {
        for (int i = 0; i < size_now; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T get_element(int index) {
        if (index < 0 || index >= size_now) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    void set_element(int index, T value) {
        if (index < 0 || index >= size_now) {
            throw std::out_of_range("Index out of bounds");
        }
        arr[index] = value;
    }
};
