#include "hashTable.h"

hashTable::hashTable() {
    //constructor
    table = new Node *[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) { //All table elements are NULL at first
        table[i] = nullptr;
    }
}

size_t hashTable::hash(const string &stockCode) {
    //MD-5 Style hashing
    size_t hash = 5381;
    for (auto &&c : stockCode)
        hash = ((hash << 5) + hash) + c;
    return hash;
}

void hashTable::insert(string stockCode, string description, const string &quantity) {
    int intValueOfQuantity = 0;
    istringstream(quantity) >> intValueOfQuantity;    //convert string to int
    size_t index = hash(stockCode) % TABLE_SIZE;    //hashing here
    //If that product is already inserted into the structure, its counter increased by the quantity of the order
    while (table[index] != nullptr) {
        if (table[index]->stockCode == stockCode) {
            table[index]->quantity = table[index]->quantity + intValueOfQuantity;
            return;
        }
        ++index;
        if (index == TABLE_SIZE) // If we reach end of the table then go head
            index = 0;
    }
    //std::move is ide suggestion.
    table[index] = new Node(std::move(stockCode), std::move(description), intValueOfQuantity);
}

void hashTable::printTopTen() {
    int maxValue = 0;
    int indexHolder = 0;
    cout << "#" << " " << "Stock Code" << "\t" << "Description" << "\t\t\t" << "Quantity" << endl;
    for (int i = 0; i < 10; ++i) {  //-> This loop for top 10
        for (int index = 0; index < TABLE_SIZE; ++index) { //-> base loop to find max quantity in hash table
            if (table[index] != nullptr) {  // to check if index is NULL or not
                if (table[index]->quantity > maxValue) {
                    maxValue = table[index]->quantity; //update the maxValue with biggest quantity
                    indexHolder = index; // -> to store index number of max quantity in hash table
                }
            }
        }
        for (int indeX = 0; indeX < TABLE_SIZE; ++indeX) { //find the max quantity's stockCode,description
            if (table[indeX] != nullptr) { // to check if index is NULL or not
                if (table[indeX]->quantity == maxValue) { //if we have reached the maxValue then it's quantity is top 1
                    cout << i + 1 << "." << " " << table[indeX]->stockCode << "\t" << table[indeX]->description
                         << "\t" << table[indeX]->quantity << endl;
                    table[indexHolder]->quantity = 0; //after cout the max one, delete the index so it can't be top 1 again
                }
            }
        }
        maxValue = 0; // update max value 0 again for second base loop
    }
}


