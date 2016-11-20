#include <cmath>
#include <iostream>

#include "ZigZag.h"

std::string ZigZag::encode(std::string plaint)
{
    int matSize = calculateSide( plaint.length() );

    char **mat = createMatrix( matSize );

    fillMatrix( mat, matSize, plaint );

    std::string ciphert = "";

    for(int j = 0; j < matSize; ++j)
        if( j%2 == 0) // EVEN!
          for(int i = 0; i < matSize; ++i)
            ciphert += mat[i][j];

        else        // ODD!
          for(int i = matSize - 1; i >= 0; --i)
            ciphert += mat[i][j];

    deleteMatrix( mat, matSize );

    return ciphert;
}

std::string ZigZag::decode(std::string ciphert)
{

    int matSize = calculateSide( ciphert.length() );
    //std::cout << matSize << " ";

    double temp = sqrt( static_cast<double>(ciphert.length()) );
    //std::cout << temp << " ";
    if( (int)temp - temp != 0 )
        throw "Incompatible text length";

    char **mat = NULL;

    mat = createMatrix( matSize );



    int strPos = 0;

    for(int j = 0; j < matSize; ++j)
      if( j % 2 == 0 ) // EVEN! -> top down
        for(int i = 0; i < matSize; ++i, ++strPos)
          mat[i][j] = ciphert[strPos];

      else
        for(int i = matSize - 1; i >= 0; --i, ++strPos)
          mat[i][j] = ciphert[strPos];

    std::string plaint;

    //throw "Made it here";

    for(int i = 0; i < matSize; ++i)
        for(int j = 0; j < matSize; ++j)

            plaint += mat[i][j];

    deleteMatrix( mat, matSize );

    return plaint;
}
