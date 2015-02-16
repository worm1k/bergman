#include <iostream>
#include <fstream>
#include "Bergnum.h"

using namespace std;

int main(int argc, char** argv) 
{
	Bergnum _1(100);
	Bergnum _2(200);

	cout << _1 - _2;

	cout << endl;
	system("pause");
	return 0;
}