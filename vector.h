#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
template <typename T>
class Vector {
public:
    int capacity;
    int size;
    T* data;

    Vector() : capacity(0), size(0), data(nullptr) {}
    void push_back(const T& value) {
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    int Size() const {
        return size;
    }


private:
    void reserve(int newCapacity)

    {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};

#endif // VECTOR_H
