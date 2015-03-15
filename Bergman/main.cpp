#include <iostream>
#include <fstream>
#include "Bergnum.h"

using namespace std;

int main(int argc, char** argv) 
{
	Bergnum _1(100);
	Bergnum _2(15);
	//Bergnum _2(2);
	/*
	cout << _1 << endl;
	cout << _2 << endl;
	*/
	cout << _1;
	cout << _2;
	cout << _1 - _2;

	cout << endl;
	system("pause");
	return 0;
}
