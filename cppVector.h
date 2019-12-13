#ifndef TERMPROJECT_CPPVECTOR_H
#define TERMPROJECT_CPPVECTOR_H
//No needed insert method, so I didn't declare it.
//Also front,back,pop_back is not needed.
template <class T>
class cppVector{
    T* data;
    int capacity;
    int index;
    void growth();
    void shrink();
public:
    cppVector();
    int size ()const;
    int cap ()const;
    void push_back(const T &value);
    void pop_back();
    void reset_vector(int index=0,int capacity=1);
    void clear();
    bool isEmpty()const;
    T front() const;
    T back() const;
    T* begin()const;
    T* end()const;
    T& at(int indeX);
    T&operator[](int indeX);
};


#endif //TERMPROJECT_CPPVECTOR_H
