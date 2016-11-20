#ifndef CIPHERPIPELINE_H
#define CIPHERPIPELINE_H

#include <vector>

#include "Cipher.h"

using namespace std;


class CipherPipeline: public Cipher {

  private:
    vector<Cipher *> pipeline;

  public:
    string encode(string);
    string decode(string);

    CipherPipeline& operator +=(Cipher *);
    CipherPipeline& operator +=(vector<Cipher *>);
    CipherPipeline& operator =(vector<Cipher *>);


};

#endif
