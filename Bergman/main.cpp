#include <iostream>
#include "Bergnum.h"

using namespace std;

int main(int argc, char** argv) 
{
	Bergnum b(5);
	cout << b;

	cout << b.toInt();

	
	system("pause");
	return 0;
}