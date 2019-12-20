#ifndef TERMPROJECT_HASHTABLE_H
#define TERMPROJECT_HASHTABLE_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class hashTable {
private:
    struct Node {
        string stockCode, description;
        int quantity;

        Node(string stockCode, string description, int quantity)
                : stockCode(std::move(stockCode)), description(std::move(description)), quantity(quantity)
        //std:move is ide suggestion.
        {}
    };

    static const int TABLE_SIZE = 1000000;
    Node **table;
public:
    hashTable();

    static size_t hash(const string &stockCode);

    void insert(string stockCode, string description, const string &quantity);

    void printTopTen();
};


#endif //TERMPROJECT_HASHTABLE_H
