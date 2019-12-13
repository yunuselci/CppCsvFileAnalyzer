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

    size_t size() const {
        return m_data.size();
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

int main() {
    ifstream file("OnlineRetail.csv");
    int counter = 0;
    CSVRow row;


    while (file >> row) {
        if (row[7] == "United Kingdom" /*&& row[4] != "3.12.2010 11:27"*/) {
            //cout << "4th Element(" << row[7] << ")\n";
            cout << "Stock Code: " << row[1]
                 << "\tDescription: " << row[2]
                 << "\tQuantitiy: " << row[3]
                 << "\tDate: " << row[4]
                 << endl;
            counter++;
        }
    }
    cout << counter << endl;
}
