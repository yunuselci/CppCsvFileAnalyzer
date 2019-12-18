#ifndef TERMPROJECT_ROWREADER_H
#define TERMPROJECT_ROWREADER_H

#include "cppVector.cpp"

class rowReader {
private:
    cppVector<string> data;
public:
    void readNextRow(istream &str);

    string const &operator[](size_t index) {
        return data[index];
    }

};


#endif //TERMPROJECT_ROWREADER_H
