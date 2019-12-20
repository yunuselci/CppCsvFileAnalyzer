#include "hashTable.h"

hashTable::hashTable() {
    table = new Node *[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

size_t hashTable::hash(const string &stockCode) {
    size_t hash = 5381;
    for (auto &&c : stockCode)
        hash = ((hash << 5) + hash) + c;
    return hash;
}

void hashTable::insert(string stockCode, string description, const string &quantity) {
    int intValueOfQuantity = 0;
    istringstream(quantity) >> intValueOfQuantity;
    size_t index = hash(stockCode) % TABLE_SIZE;
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
    table[index] = new Node(std::move(stockCode), std::move(description), intValueOfQuantity);
    //std::move is ide suggestion.
}
/* -> Tou use here, you should activate in hashTable.h,hashtable.cpp,main.cpp
void hashTable::selectionSort() {
    int firstCounter, secondCounter;
    Node *emptyOne = new Node("empty", "thisEmpty", 0);
    Node *temp;
    for (firstCounter = 1; firstCounter < TABLE_SIZE; firstCounter++) {
        if (table[firstCounter] == nullptr) {
            table[firstCounter] = emptyOne;
        }
        temp = table[firstCounter];
        secondCounter = firstCounter - 1;
        if (table[secondCounter] == nullptr) {
            table[secondCounter] = emptyOne;
        }
        while (secondCounter >= 0 && table[secondCounter]->quantity > temp->quantity) {
            table[secondCounter + 1] = table[secondCounter];
            secondCounter = secondCounter - 1;
            if (table[secondCounter] == nullptr) {
                table[secondCounter] = emptyOne;
            }
        }
        table[secondCounter + 1] = temp;
    }
}

void hashTable::print() {
    cout << "#" << '\t' << "Stock Code" << '\t' << "Description" << '\t' << "Quantity" << endl;
    for (int index = TABLE_SIZE - 1; index > TABLE_SIZE - 11; --index) { //Sorting trick :), prints the table in reverse
        if (table[index] != nullptr) {
            cout << (TABLE_SIZE - index) << "." << "\t" << table[index]->stockCode << "\t" << table[index]->description
                 << "\t" << table[index]->quantity << endl;
        }
    }
}
*/
void hashTable::printTopTen() {
    int maxValue = 0;
    int indexHolder = 0;
    cout << "#" << " " << "Stock Code" << "\t" << "Description" << "\t\t\t" << "Quantity" << endl;
    for (int i = 0; i < 10; ++i) {
        for (int index = 0; index < TABLE_SIZE; ++index) {
            if(table[index] != nullptr) {
                if (table[index]->quantity > maxValue) {
                    maxValue = table[index]->quantity;
                    indexHolder = index;
                }
            }
        }
        for (int j = 0; j < TABLE_SIZE; ++j) {
            if(table[j]!= nullptr){
                if(table[j]->quantity == maxValue) {
                    cout << i+1 << "." << " " << table[j]->stockCode << "\t" << table[j]->description
                         << "\t\t" << table[j]->quantity << endl;
                    table[indexHolder]->quantity = 0;
                }
            }
        }
        maxValue=0;
    }
}
