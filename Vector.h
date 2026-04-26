#pragma once
#include <iostream>
using namespace std;

template<typename Type>
class MyVector { //vector
    Type* arr;
    int size;

public:
    MyVector() {//size = 0; []
        arr = nullptr;
        size = 0;
    }
    MyVector(int size, Type value) {//size = 3, value = 0,  [0, 0, 0]
        this->size = size;
        arr = new Type[size];
        for (int i = 0; i < size; i++) {
            arr[i] = value;
        }
    }
    ~MyVector() {
        if (arr != nullptr) {
            delete[] arr;
        }
        arr = nullptr;
        size = 0;
    }

    int getSize() const	// повертає розмірність масиву
    {
        return size;
    }
    void  print()const	// виведення всіх елементів масиву
    {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
            // printf("%d ", arr[i]);
        }
        cout << endl;
    }

    void push_back(Type item)	// додавання елемента item у кінець масиву
    {
        Type* tmp = new Type[size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        size++;
        tmp[size - 1] = item;
        arr = tmp;
    }

    Type& operator[](int number) {
        return arr[number];
    }


    Type find_max()const // пошук елемента з максимальним значенням
    {
        Type m = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > m) m = arr[i];
        }
        return m;
    }
    Type find_min()const // пошук елемента з мінімальним значенням
    {
        Type m = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < m) m = arr[i];
        }
        return m;
    }

};