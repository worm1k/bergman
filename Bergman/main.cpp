#include <iostream>
#include "Bergnum.h"

using namespace std;

int main(int argc, char** argv) 
{
	Bergnum b = Bergnum();
	for (int i = 0; i < 10; ++i) {
		cout << b;
		b.inc();
	}
	
	system("pause");
	return 0;
}