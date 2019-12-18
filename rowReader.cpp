#include "rowReader.h"
#include <sstream> //lineStream -> row 7

void rowReader::readNextRow(istream &str) { // read the file row by row
    string line, cell;
    getline(str, line);
    stringstream lineStream(line); //standart sstream process for more info google.com.tr
    data.clear(); //it's means that we just read the rows, we do not memorize it
    while (getline(lineStream, cell, ';')) // No {} here, attention for debug.
        data.push_back(cell);
    if (!lineStream && cell.empty()) // No {} here, attention for debug.
        data.push_back("");    // Trailing Comma check, If there was t.c, then add empty element.
}




