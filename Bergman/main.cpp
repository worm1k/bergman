#include <iostream>
#include "Bergnum.h"

using namespace std;

int main(int argc, char** argv) 
{
	Bergnum b = Bergnum();

	cout << b;
	b.decompose(b.test);
	cout << b;
	
	system("pause");
	return 0;
}