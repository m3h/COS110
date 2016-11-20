#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "arrayUtilities.h"

// Implement functions defined in arrayUtilities.h in this file.
// Note: arrayUtilities.h will be overwritten by Fitchfork.

#define YEARINCREMENT 2

int numDaysInMonth(int year, int month)
{
	int daysInMonthArray[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// it's a leap year
	if( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
		daysInMonthArray[1] = 29;		// February now has 29 days

	return daysInMonthArray[month];
}

size_t* yearsMonthSize(int year)
{
	const short monthsInYear = 12;
	size_t *yearsMonthSizeArray = new size_t[monthsInYear];

	for(int curMonth = 0; curMonth < monthsInYear; curMonth++) {
		yearsMonthSizeArray[curMonth] = numDaysInMonth( year, curMonth);
	}

	return yearsMonthSizeArray;
}

int numStringToInt( string number )
{
	for( char digit: number ) { // check for non-digits
		if( isdigit(digit) == 0 ) {
			return -1;
		}
	}

	int output = atoi( number.c_str() );

	if( output <= 0 ) // impossible value
		return -1;
	else
		return output;
}

void parseDateStamp(string stampString, int *stampArray[3])
{
	short const YEAR = 0;
	short const MONTH = 1;
	short const DAY = 2;

	(*stampArray)[YEAR] = numStringToInt( stampString.substr(0, 4) );

	(*stampArray)[MONTH] = numStringToInt( stampString.substr(5, 2) );
	if( (*stampArray)[MONTH] > 12 ) {
		(*stampArray)[MONTH] = -1;
	}

	(*stampArray)[DAY] = numStringToInt( stampString.substr(8, 2) );
	if( (*stampArray)[DAY] > numDaysInMonth( (*stampArray)[YEAR], (*stampArray)[MONTH]-1 ) ) {
		(*stampArray)[DAY] = -1;
	}

	return;
}

int incrementDateArray( int *stampArray[3] )
{
	if( (*stampArray)[2]+1 > numDaysInMonth( (*stampArray)[0], (*stampArray)[1]-1) )
	{
		if( (*stampArray)[1] >= 12 )
		{
			(*stampArray)[0] = (*stampArray)[0] + 1;
			(*stampArray)[1] = 1;
			(*stampArray)[2] = 1;

			return YEARINCREMENT;
		}
		else
		{
			(*stampArray)[1] = (*stampArray)[1] + 1;
			(*stampArray)[2] = 1;
		}
	}
	else
	{
		(*stampArray)[2] = (*stampArray)[2] + 1;
	}
	//cout << (*stampArray)[0] << "_" << (*stampArray)[1] << "_" << (*stampArray)[2] << endl;
	return 0;
}

size_t parseDataFile(string const & filename, short ***&dataPtr, int &firstYear)
{
	//cout << "ccc11";
	ifstream inFile;
	inFile.open( filename );

	if( !inFile ) {
		return -1;
	}

	string stamp;
	int *stampArray = new int[3];
	int *countStamp = new int[3];
	short value;
	size_t *monthSizes;
	size_t arraySize = 2;



	int firstMonth = 0;
	firstYear = 0;
	int curMonth;
	int curDay;
	//cout << "ccc12";
	for( int curYear; !inFile.eof(); curYear++ ) {
                cout << "-----------------------------------------------------------------------------------------------------";
				inFile >> stamp;
				parseDateStamp( stamp, &stampArray );
				inFile >> value;



				if( firstYear == 0 ) {
					//cout << "ccc14";
					reallocShort3d( dataPtr, 0, 2);
				//	cout << stampArray[0] << "_" << stampArray[1] << "_" << stampArray[2] << " ";
					//cout << countStamp[0] << "_" << countStamp[1] << "_" << countStamp[2] << " " << value << endl;
					monthSizes = yearsMonthSize( stampArray[0] );
					dataPtr[arraySize] = newShort2d( 12, monthSizes );

					firstYear = stampArray[0];
					curYear = firstYear;

					curMonth = stampArray[1];
					firstMonth = curMonth;

					curDay = stampArray[2];

					countStamp[0] = firstYear;
					countStamp[1] = firstMonth;
					countStamp[2] = curDay;

				} else {
					if( incrementDateArray( &countStamp ) == YEARINCREMENT ) {
					//	cout << "ccc16";
						reallocShort3d( dataPtr, arraySize, arraySize+1);
						arraySize = arraySize + 1;
					//	cout << stampArray[0] << "_" << stampArray[1] << "_" << stampArray[2] << " ";
					//	cout << countStamp[0] << "_" << countStamp[1] << "_" << countStamp[2] << " " << value << endl;
						monthSizes = yearsMonthSize( stampArray[0] );
						dataPtr[arraySize] = newShort2d( 12, monthSizes );


					}
				}

				while( countStamp[2] != stampArray[2] ) {
				//	cout << "-----" << stampArray[0] << "_" << stampArray[1] << "_" << stampArray[2];
					//cout << "+++++" << countStamp[0] << "_" << countStamp[1] << "_" << countStamp[2] << endl;
					dataPtr[countStamp[0]-firstYear][countStamp[1]-1][countStamp[2]-1] = -1;

					if( incrementDateArray( &countStamp ) == YEARINCREMENT ) {

						reallocShort3d( dataPtr, arraySize, arraySize+1);
						arraySize = arraySize+1;
						//cout << stampArray[0] << "_" << stampArray[1] << "_" << stampArray[2] << " ";
						//cout << countStamp[0] << "_" << countStamp[1] << "_" << countStamp[2] << " " << value << endl;
						monthSizes = yearsMonthSize( stampArray[0] );
						dataPtr[arraySize] = newShort2d( 12, monthSizes );
					}

				}

				dataPtr[countStamp[0]-firstYear][countStamp[1]-1][countStamp[2]-1] = value;
			//	cout << stampArray[0] << "_" << stampArray[1] << "_" << stampArray[2] << " ";
				//cout << countStamp[0] << "_" << countStamp[1] << "_" << countStamp[2] << " " << value << endl;
			}
			cout << inFile.eof() << "HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << endl;
	return countStamp[0] - firstYear + 1;
}

void reallocShort3d(short ***&ptr, size_t oldSize, size_t newSize)
{
	cout << "REALLOC" << endl;
	cout << oldSize << " " << newSize << " " << endl;
        short ***temp = new short **[newSize];

        for( size_t i = 0; i < oldSize; i++ ) {
                temp[i] = ptr[i];
        }

				delete [] ptr;
        ptr = temp;

        return;
}

short ** newShort2d(size_t numRow, size_t const *colSize)
{
    short **temp = new short *[numRow];

		for( size_t row = 0; row < numRow; row++ ) {
			temp[row] = new short[ colSize[row] ];
		}

    return temp;
}


/**
* @brief This function will delete all the elements af a given 2D array.
*
* @param ptr is the pointer, pointing to the data that is to be deleted.
*       this pointer must be set to zero after the deletion process
* @param rowSize is the total rows in the array, i.g. ptr[row][col].
*       The function must loop through every row to delete its columns.
*/
void deleteShort2d(short **&ptr, size_t rowSize)
{
    for( size_t row = 0; row < rowSize; row++ ) {
			delete [] ptr[row];
		}

		delete [] ptr;
		ptr = nullptr;
}
