#include <iostream>
#include "Bergnum.h"

using namespace std;

int main(int argc, char** argv) 
{

	Bergnum a(20);
	cout << a;

	Bergnum b(5);
	cout << a/b;

	cout << endl;
	system("pause");
	return 0;
}