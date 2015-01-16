#include <iostream>

#include "Bergnum.h";
void myprint(mylist* curr);
Bergnum::Bergnum() : start(new mylist(0,0,4,1))
{
	
	mylist* curr = start;

	curr->less = new mylist(curr, 0, 3, 1);
	curr = curr->less;

	curr->less = new mylist(curr, 0, 2, 0);
	curr = curr->less;

	curr->less = new mylist(curr, 0, 1, 1);
	curr = curr->less;
	
	curr->less = new mylist(curr, 0, 0, 0);
	curr = curr->less;
	
	curr->less = new mylist(curr, 0, -1, 1);
	curr = curr->less;
	test = curr;

	curr->less = new mylist(curr, 0, -2, 0);
	curr = curr->less;
	
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
void Bergnum::decompose(mylist* curr)
{
	// 1 • • 
	if (!curr->less) {
		curr->less = new mylist(curr,0);
		curr->less->less = new mylist(curr->less, 0);
	} // 1 0 • 
	else if (!curr->less->isTrue && !curr->less->less) {
		curr->less->isTrue = true;
		curr->less->less = new mylist(curr->less, 0);
	} // 1 0 0
	else if (!curr->less->isTrue && !curr->less->less->isTrue) {
		// Well, well, well...
	}
	else if (curr->less->less->isTrue) {
		decompose(curr->less->less);
	}
	curr->isTrue = false;
	curr->less->isTrue = true;
	curr->less->less->isTrue = true;

}

void Bergnum::normalise()
{
	mylist* curr = start;
	for (;;) {
		if (!curr->less) return;
		if (curr->isTrue && curr->less->isTrue) {
			if (!curr->more) {
				curr->more = new mylist(0, curr);
				start = curr->more;
			}
			curr->more->isTrue = true;
			curr->isTrue = false;
			curr->less->isTrue = false;
			normalise();
		}
		curr = curr->less;
	}
}

ostream& operator<<(ostream &os, const Bergnum &u)
{
	mylist* curr = u.start;
	for (;;) {
		os << curr->isTrue; /*
		os << " bool: " << curr->isTrue << endl
			<< "power: " << curr->power << endl
			//<< " more: " << curr->more << endl
			<< "  ptr: " << curr << endl
			<< " less: " << curr->less << endl
			<< "=============================\n";*/
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

// very useful func
void Bergnum::myprint(mylist* curr)
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