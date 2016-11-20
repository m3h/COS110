#include "TranspositionCipher.h"
#include <cmath>

char **TranspositionCipher::createMatrix(int n)
{
    char **mat = new char* [n];

    for(int i = 0; i < n; ++i)
        mat[i] = new char[n];

    return mat;
}


void TranspositionCipher::deleteMatrix(char **mat, int n)
{
    for(int i = 0; i < n; ++i)
        delete [] mat[i];
    delete [] mat;
}

void TranspositionCipher::fillMatrix(char **mat, int n, std::string plaint)
{
    int strPos = 0;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j, ++strPos)

            if( strPos < plaint.length() )
                mat[i][j] = plaint[strPos];
            else
                mat[i][j] = ' '; // else fill with empty space

}


int TranspositionCipher::calculateSide(int n)
{
    return static_cast<int>( ceil( sqrt(n) ) );   
}
