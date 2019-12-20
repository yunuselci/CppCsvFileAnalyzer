#ifndef TERMPROJECT_CPPVECTOR_H
#define TERMPROJECT_CPPVECTOR_H

//unnecessary methods not defined
template<class T>
class cppVector {
    T *data;
    int capacity;
    int index;

    void growth();

public:
    cppVector();

    ~cppVector();

    int size() const;

    int cap() const;

    void push_back(const T &value);

    void reset_vector(int index = 0, int capacity = 1);

    void clear();

    T &at(int indeX);

    T &operator[](int indeX);
};


#endif //TERMPROJECT_CPPVECTOR_H
