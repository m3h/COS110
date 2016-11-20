#ifndef ROWSCOLUMNS_H
#define ROWSCOLUMNS_H

#include <string>

#include "TranspositionCipher.h"

using namespace std;


class RowsColumns: public TranspositionCipher {

    public:
        std::string encode(std::string);
        std::string decode(std::string);

};

#endif
