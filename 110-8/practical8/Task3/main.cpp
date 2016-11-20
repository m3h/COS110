#include <iostream>
#include <vector>

#include "lcm.cpp"

using namespace std;

int main()
{

	int in = 1;
	cout << "Enter numbers:";
	
	vector<int> vv;
	while( cin >> in) {
		vv.push_back(in);
	}
	
	cout << endl;
	for(int i = 0; i < vv.size(); ++i)
		cout << vv[i] << " ";
	cout << endl;
	
	int numbers[vv.size()];
	for(int i = 0; i < vv.size(); ++i)
		numbers[i] = vv[i];
	
	cout << "Their LCD is: " << lcm(numbers, vv.size()) << endl;
	return 0;
}