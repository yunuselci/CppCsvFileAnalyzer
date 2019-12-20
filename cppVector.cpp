#include "cppVector.h"
#include <iostream>

using namespace std;

template<class T>
cppVector<T>::cppVector():data(NULL), capacity(1), index(0) {
    data = new T[capacity]; //constructor

}

template<class T>
cppVector<T>::~cppVector() {
    reset_vector(); //destructor
}

template<class T>
void cppVector<T>::growth() {
    if (size() >= cap()) { // if we have reached the capacity, then double it
        capacity *= 2;
        T *temp = new T[capacity]; // temp have double capacity here.
        for (int i = 0; i < size(); ++i)
            temp[i] = data[i]; // copy the elements into temp
        delete[] data;
        data = temp;
    }
}

template<class T>
int cppVector<T>::size() const { //get size here
    return index;
}

template<class T>
int cppVector<T>::cap() const { //get capacity here
    return capacity;
}

template<class T>
void cppVector<T>::push_back(const T &value) { //push_back here
    growth(); //always growth so we have enough size always
    data[index++] = value; // update next index with new value
}

template<class T>
void cppVector<T>::clear() { //clear here
    reset_vector();
    data = new T[capacity];
}

template<class T>
void cppVector<T>::reset_vector(int index, int capacity) { //base for clear
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
T &cppVector<T>::operator[](int indeX) { // to use vector[3]
    return at(indeX);
}
