#include <iostream>
#include "Bergnum.h"
#include <string>

using namespace std;

void menu();
Bergnum inputBergnumInt();
const Bergnum operate(const Bergnum& a, const Bergnum& b, const char op);
char inputOperator();

int main(int argc, char** argv) 
{

	menu();

	cout << endl;
	system("pause");
	return 0;
}

void menu() {

	int choose;
	Bergnum useless(0);
	Bergnum a;
	Bergnum b;
	char op;
	while (true) {
		cout << endl
			<< "=================================" << endl
			<< "Welcome to Bergman calculator!" << endl
			<< "choose your action:" << endl << endl
			<< "1. Plus / Minus / Multiply / Division" << endl
			<< "2. Validate the number" << endl
			<< "3. Exit" << endl
			<< "> ";
		cin >> choose;
		switch (choose) {
		case 1:
			a = inputBergnumInt();
			b = inputBergnumInt();

			cout << a << endl << b << endl;
			op = inputOperator();
			cout << "Result: " << operate(a, b, op) << endl;
			break;
		case 2:
			a = Bergnum::inputBergnum();
			cout << a;
			if (!a.isNotValid()) {
				cout << "Congratulations!! Your number is valid" << endl;
			}
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "Choose correct action" << endl;
			break;
		}
	}
}

Bergnum inputBergnumInt() {
	cout << "Input Integer to convert it to Bergnum" << endl
		<< "> ";
	int myInt;
	cin >> myInt;
	return Bergnum(myInt);
}

Bergnum Bergnum::inputBergnum() {
	cout << "Input Bergnum:" << endl
		<< "> ";
	string mystring;
	cin >> mystring;

	int indexOfDot(mystring.length());
	bool isDotExist = false;

	// check input
	for (size_t i = 0; i < mystring.length(); ++i) {
		// check the only dot
		if (mystring[i] == '.') {
			if (!isDotExist) {
				isDotExist = true;
				indexOfDot = i;
			}
			else {
				cout << "Input only ONE dot" << endl;
				return Bergnum(0);
			}
		}
		// check correct symbols
		if ( (mystring[i] != '.') && (mystring[i] != '0') && (mystring[i] != '1')) {
			cout << "Input number must contain only '0', '1' and '.'" << endl;
			return Bergnum(0);
		}
	}

	mylist* result;
	if (indexOfDot == 0) {
		result = new mylist();
	}
	else {
		result = new mylist(0, 0, indexOfDot - 1, 0);
	}
	mylist* resultStart = result;

	if (mystring[0] == '1') {
		result->multiplier = 1;
	}


	for (size_t i = 1; i < mystring.length(); ++i) {
		if (i == indexOfDot) {
			continue;
		}
		result->less = new mylist(result, 0);
		if (mystring[i] == '1') {
			result->less->multiplier = 1;
		}
		result = result->less;
	}

	return Bergnum(resultStart);
}

char inputOperator()
{
	char op;
	cout << "Enter operator '+' or '-' or '*' or '/'" << endl
		<< "> ";
	cin >> op;
	
	return op;
}

const Bergnum operate(const Bergnum& a, const Bergnum& b, const char op) 
{
	switch (op) {
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	default:
		cout << "Wrong operator" << endl;
		return Bergnum(0);
		break;

	}
}
