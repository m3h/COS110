#include <cmath>
#include <iostream>

#include "RowsColumns.h"

std::string RowsColumns::encode(std::string plaint)
{
    int matSize = calculateSide( plaint.length() );

    char **mat = createMatrix( matSize );

    fillMatrix( mat, matSize, plaint );

    std::string ciphert = "";

    for(int j = 0; j < matSize; ++j)
        for(int i = 0; i < matSize; ++i)

            ciphert += mat[i][j];

    deleteMatrix( mat, matSize );

    return ciphert;
}

std::string RowsColumns::decode(std::string ciphert)
{

    int matSize = calculateSide( ciphert.length() );
    //std::cout << matSize << " ";

    double temp = sqrt( static_cast<double>(ciphert.length()) );
    //std::cout << temp << " ";
    if( (int)temp - temp != 0 )
        throw "Incompatible text length";

    //return encode( ciphert );
    char **mat = NULL;

    mat = createMatrix( matSize );
    //cout << matSize << endl;


    int strPos = 0;

    for(int i = 0; i < matSize; ++i)
        for(int j = 0; j < matSize; ++j, ++strPos)

             if( strPos < ciphert.length() )
                mat[j][i] = ciphert[strPos];
            else
                mat[j][i] = ' '; // else fill with empty space

    std::string plaint;

    //throw "Made it here";
    /*
    for(int i = 0; i < matSize; ++i) {
      for(int j = 0; j < matSize; ++j) {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }*/

    
    for(int i = 0; i < matSize; ++i)
        for(int j = 0; j < matSize; ++j)

            plaint += mat[i][j];

    deleteMatrix( mat, matSize );

    return plaint;
}
