#include <iostream>
#include "Bergnum.h"
#include <string>

using namespace std;

void menu();
Bergnum& inputBergnumInt();
//const Bergnum operate(const Bergnum& a, const Bergnum& b, const char op);
//char inputOperator();

int main(int argc, char** argv) 
{

	menu();

	cout << endl;
	system("pause");
	return 0;
}

void menu() {
	
	
	bool i(0);
	i = -1;
	cout << i;
	int choose;
	Bergnum useless(0);
	Bergnum a;
	Bergnum b;
	while (true) {
		cout << endl
			<< "=================================" << endl
			<< "Welcome to Bergman calculator!" << endl
			<< "choose your action:" << endl << endl
			<< "1. Plus / Minus / Multiply / Division" << endl
			<< "2. Validate the number" << endl
			<< "3. Exit" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			a = inputBergnumInt();
			b = inputBergnumInt();

			cout << a << endl << b << endl;
			//char op = inputOperator();
			//cout << operate(a, b, op);
			break;
		case 2:
			a = useless.inputBergnum();
			cout << "validation" << a.isNotValid();
			break;
		case 3:
			cout<< Bergnum(5).isNotValid() << endl;
			cout << Bergnum(Bergnum(5).start) << endl;
			break;
		default:
			cout << "Choose correct action" << endl;
			break;
		}
	}
}

Bergnum& inputBergnumInt() {
	cout << "Input Integer to convert it to Bergnum" << endl;
	int myInt;
	cin >> myInt;
	Bergnum myBerg(myInt);
	return myBerg;
}

Bergnum& Bergnum::inputBergnum() {
	cout << "Input Bergnum" << endl;
	string mystring;
	cin >> mystring;

	int indexOfZeroPower(0);
	for (int i = 0; i < mystring.length(); ++i) {
		if (mystring[i] == '.') {
			indexOfZeroPower = i-1;
			break;
		}
	}
	cout << "Index of zero: " << indexOfZeroPower << endl;

	//Bergnum result(0);
	//cout << "Bergman: " << result << endl;
	//result.start->multiplier = mystring[indexOfZeroPower];
	//cout << "mystring[i]: " << mystring[indexOfZeroPower] << endl;
	//cout << "Bergman: " << result << endl;
	//for (int i = indexOfZeroPower; i >= 0; --i) {/*
	//	result.start->more = new mylist(0, result.start);
	//	result.start->more->multiplier = mystring[i];
	//	result.start = result.start->more;*/
	//	cout << "mystring[i]: " << mystring[i]<<endl;
	//	cout << "1Bergman: " << result << endl;

	//}

	//mylist* current = result.zero;
	//for (int i = indexOfZeroPower+2; i < mystring.length(); ++i) {/*
	//	current->less = new mylist(current, 0);
	//	current->less->multiplier = mystring[i];
	//	current = current->less;*/
	//	cout << "mystring[i]: " << mystring[i] << endl;
	//	cout << "2Bergman: " << result << endl;
	//}
	//cout << "3Bergman: " << result << endl;
	return result;
}
