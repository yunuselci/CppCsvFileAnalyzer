#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cppVector.cpp"
using namespace std;

class CSVRow {
public:
    string const &operator[](size_t index) {
        return m_data[index];
    }

    void readNextRow(istream &str) {
        string line;
        getline(str, line);

        stringstream lineStream(line);
        string cell;

        m_data.clear();
        while (getline(lineStream, cell, ';')) {
            m_data.push_back(cell);
        }
        // This checks for a trailing comma with no data after it.
        if (!lineStream && cell.empty()) {
            // If there was a trailing comma then add an empty element.
            m_data.push_back("");
        }
    }

private:
    cppVector<string> m_data;
};
istream &operator>>(istream &str, CSVRow &data) {
    data.readNextRow(str);
    return str;
}

class HashEntry
{
public:
    string key; // the word is actually a key, no need to store hash value
    size_t value; // the word count is the value.
    HashEntry(string key)
            : key(std::move(key)), value(1) // move the string to avoid unnecessary copying
    { }
};


class HashMap
{
private:
    HashEntry * *table;
public:
    HashMap()
    {
        table = new HashEntry *[1000000];
        for (int i = 0; i < 1000000; i++)
        {
            table[i] = NULL;
        }
    }

    size_t Hash(const string &key)
    {
        size_t hash = 5381;
        for (auto &&c : key)
            hash = ((hash << 5) + hash) + c;
        return hash;
    }
    void Insert(string key,string quantity)
    {
        size_t index = Hash(key) % 1000000;
        while (table[index] != nullptr) {
            if (table[index]->key == key) {
                table[index]->value = table[index]->value + stoi(quantity);
                return;
            }
            ++index;
            if (index == 1000000) // "wrap around" if we've reached the end of the hash table
                index = 0;
        }

        table[index] = new HashEntry(std::move(key));
    }

    HashEntry *Find(const string &key)
    {
        size_t index = Hash(key) % 1000000;
        while (table[index] != nullptr) {
            if (table[index]->key == key) {
                cout << table[index]->value;
            }
            ++index;
            if (index == 1000000)
                index = 0;
        }

        return nullptr;
    }

};

int main() {
    try {
        ifstream file("deneme.csv");
        CSVRow row;
        cppVector<string> most;
        cppVector<string> value;
        HashMap stockCodes;
        while (file >> row) {
            stockCodes.Insert(row[1],row[3]);
            if (row[7] == "United Kingdom") {
                /*
                cout << "Stock Code: " << row[1]
                     << "\tDescription: " << row[2]
                     << "\tQuantity: " << row[3]
                     << "\tDate: " << row[4]
                     << endl;*/

            }
        }
        stockCodes.Find("85123A");
    }
    catch (const char *ex) { //->Exception from cppVector class.
        cout << ex << endl;
    }
}
