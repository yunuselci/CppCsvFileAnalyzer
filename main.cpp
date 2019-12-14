#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cppVector.cpp"
#include <algorithm>
#include <map>

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
    CSVRow row;
    cppVector<string> most;

    while (file >> row) {
        if (row[7] == "United Kingdom") {
            most.push_back(row[1]);
            /*cout << "Stock Code: " << row[1]
                 << "\tDescription: " << row[2]
                 << "\tQuantitiy: " << row[3]
                 << "\tDate: " << row[4]
                 << endl;*/
        }
    }

    map<string, int> src;
    for (auto x:most)
        ++src[x];
    multimap<int, string, greater<int> > dst;
    transform(src.begin(), src.end(), inserter(dst, dst.begin()),
              [](const pair<string, int> &p) {
                  return pair<int, string>(p.second, p.first);
              }
    );

    std::multimap<int, std::string>::iterator it = dst.begin();
    cout << "Product (StockCode)\t" << "Description\t" << "#TotalQuantity\t" << endl;
    for (int count = 0; count < 10 && it != dst.end(); ++it, ++count) {
        std::cout << it->second << ":" << it->first << std::endl;
    }



}
