#ifndef ZIGZAG_H
#define ZIGZAG_H

#include <string>

#include "TranspositionCipher.h"

using namespace std;


class ZigZag: public TranspositionCipher {

    public:
        std::string encode(std::string);
        std::string decode(std::string);

};

#endif
