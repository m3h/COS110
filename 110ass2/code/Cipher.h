#ifndef CIPHER_H
#define CIPHER_H

#include <vector>
#include <string>

using namespace std;

class Cipher {

	public:
		virtual std::string encode(std::string) = 0;
		virtual std::string decode(std::string) = 0;

		vector<Cipher *> operator +(Cipher &c)
		{
			vector<Cipher *> ret;

			ret.push_back( this );
			ret.push_back( &c );

			return ret;
		}
};

#endif
