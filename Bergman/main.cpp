#include <iostream>
#include <fstream>
#include "Bergnum.h"
#include <string>

using namespace std;

void menu();
Bergnum& inputBergnumInt();
//Bergnum& inputBergnum();
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
	
	
	int choose;
	Bergnum a;
	Bergnum b;
	while (true) {
		cout << "\n================================="
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
			//a = inputBergnum();
			cout << "validation" << a.isValid();
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

Bergnum& inputBergnumInt() {
	cout << "Input Integer to convert it to Bergnum" << endl;
	int myInt;
	cin >> myInt;
	Bergnum myBerg(myInt);
	return myBerg;
}
/*
Bergnum& inputBergnum() {
	cout << "Input Bergnum" << endl;
	string charNumber;
	cin >> charNumber;
	cout << charNumber;
	return Bergnum(1);
}*/