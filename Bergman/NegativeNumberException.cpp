#include "NegativeNumberException.h"
#include <iostream>

void NegativeNumberException::printError()
{
	cout << error << endl;
}

NegativeNumberException::NegativeNumberException(char* e) :error(e) {

}