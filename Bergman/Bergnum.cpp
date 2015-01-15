#include <iostream>

#include "Bergnum.h";
void myprint(mylist* curr);
Bergnum::Bergnum() : start(new mylist())
{
	/*
	mylist* curr = start;

	curr->less = new mylist(curr, 0, 3, 1);
	curr = curr->less;

	curr->less = new mylist(curr, 0, 2, 0);
	curr = curr->less;

	curr->less = new mylist(curr, 0, 1, 1);
	curr = curr->less;
	
	curr->less = new mylist(curr, 0, 0, 0);
	curr = curr->less;
	
	curr->less = new mylist(curr, 0, -1, 0);
	curr = curr->less;

	curr->less = new mylist(curr, 0, -2, 1);
	curr = curr->less;
	*/
}

Bergnum::Bergnum(const int val)
{

}

Bergnum::Bergnum(Bergnum& orig)
{

}

void Bergnum::sayhello(){ cout << "hello\n"; };

// writes 1 in ptr position
void Bergnum::write1(mylist* ptr) 
{
	if (!ptr->isTrue) {
		ptr->isTrue = true;
		return;
	}
	else {
		decompose(ptr);
		write1(ptr);
	}
}

// 100 -> 011
void Bergnum::decompose(mylist* ptr)
{
	if (ptr->less->less->isTrue) {
		decompose(ptr->less->less);
	}
	ptr->isTrue = false;
	ptr->less->isTrue = true;
	ptr->less->less->isTrue = true;

}

ostream& operator<<(ostream &os, const Bergnum &u)
{
	mylist* curr = u.start;
	for (;;) {
		//os << curr->isTrue;
		os << " bool: " << curr->isTrue << endl
			<< "power: " << curr->power << endl
			//<< " more: " << curr->more << endl
			<< "  ptr: " << curr << endl
			<< " less: " << curr->less << endl
			<< "=============================\n";
		if (curr->power == 0) {
			os << '.';
			if (!curr->less) {
				os << '0';
			}
		}
		curr = curr->less;
		if (!curr) {
			os << endl << "Bergnum printed" << endl;
			break;
		}
	}
	return os;
}

/** very useful func
 *
void myprint(mylist* curr)
{
	for (;;) {
		//os << curr->isTrue;
		cout << " bool: " << curr->isTrue << endl
			<< "power: " << curr->power << endl
			//<< " more: " << curr->more << endl
			<< "  ptr: " << curr << endl
			<< " less: " << curr->less << endl
			<< "=============================\n";
		if (curr->power == 0) {
			cout << '.';
			if (!curr->less) {
				cout << '0';
			}
		}
		curr = curr->less;
		if (!curr) {
			cout << endl << "Bergnum printed" << endl;
			break;
		}
	}
}
*/