#include "cppVector.h"
#include <iostream>

using namespace std;

template<class T>
cppVector<T>::cppVector():data(NULL), capacity(1), index(0) {
    data = new T[capacity];
}

template<class T>
cppVector<T>::~cppVector() {
    reset_vector();
}

template<class T>
void cppVector<T>::growth() {
    if (size() >= cap()) {
        capacity *= 2;
        T *tmp = new T[capacity];
        for (int i = 0; i < size(); ++i)
            tmp[i] = data[i];
        delete[] data;
        data = tmp;

    }
}

template<class T>
int cppVector<T>::size() const {
    return index;
}

template<class T>
int cppVector<T>::cap() const {
    return capacity;
}

template<class T>
void cppVector<T>::push_back(const T &value) {
    growth();
    data[index++] = value;
}

template<class T>
void cppVector<T>::clear() {
    reset_vector();
    data = new T[capacity];
}

template<class T>
void cppVector<T>::reset_vector(int index, int capacity) {
    delete[] data;
    data = NULL;
    this->index = index;
    this->capacity = capacity;
}

template<class T>
T &cppVector<T>::at(int indeX) {
    if (indeX >= 0 && indeX < size())
        return data[indeX];
    throw "Error: Vector index'i tasti!.";
}

template<class T>
T &cppVector<T>::operator[](int indeX) {
    return at(indeX);
}
