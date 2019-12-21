#include <fstream>
#include "rowReader.h"
#include "hashTable.h"
#include <chrono> // total elapsed time
//string,sstream are included in hashTable.h
using namespace std;

istream &operator>>(istream &str, rowReader &data) { // in driver program, for (while >> row)
    data.readNextRow(str);
    return str;
}

int main() {
    //this part use <chrono> to measure total elapsed time
    using clock = std::chrono::system_clock;
    using sec = std::chrono::duration<double>;
    const auto before = clock::now();
    //We have try,catch because cppVector.cpp can throw Error
    try {
        //ifstream file("OnlineRetail.csv");
        ifstream file(R"(C:\Users\YUNUS\CLionProjects\TermProject\cmake-build-debug\OnlineRetail.csv)");
        //creating our classes
        rowReader row;
        hashTable table;
        while (file >> row) { // read all rows in file
            table.insert(row[1], row[2], row[3]);
        }
        table.printTopTen();
    }
    catch (const char *exception) { //->Exception from cppVector class.
        cout << exception << endl;
    }
    const sec duration = clock::now() - before;
    cout << endl;
    cout << "Total Elapsed Time: " << duration.count() << " seconds" << endl;
    return 0;
}
