#include <iostream>
#include "Bergnum.h";
void myprint(mylist* curr);
Bergnum::Bergnum() : start(new mylist())
{
	zero = start;
}

Bergnum::Bergnum(const int val)
{
	if (val < 0) {
		;
	}
	start = new mylist();
	zero = start;
	for (int i = 0; i < val; ++i) {
		inc();
	}
}

Bergnum::Bergnum(const Bergnum& u)
{
	mylist* orig = u.start;
	start = new mylist(0, 0, orig->power, orig->isTrue);
	mylist* curr = start;

	for (;;) {
		if (!orig->less) {
			break;
		}
		curr->less = new mylist(curr, 0, orig->less->power, orig->less->isTrue);
		curr = curr->less;
		orig = orig->less;
		if (curr->power == 0) {
			zero = curr;
		}
	}
}


// 100 -> 011
void Bergnum::decompose(mylist* curr) const
{
	  // 1 • • -> 1 0 0
	if (!curr->less) {
		curr->less = new mylist(curr,0);
		curr->less->less = new mylist(curr->less, 0);
	} // 1 0 • -> 1 0 0
	else if (!curr->less->isTrue && !curr->less->less) {
		curr->less->isTrue = true;
		curr->less->less = new mylist(curr->less, 0);
	} // 1 0 0
	else if (!curr->less->isTrue && !curr->less->less->isTrue) {
		// Well, well, well...
	} // 1 0 1 -> 1 0 0
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
			if (!curr->more) { // • 1 1
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

// increment by 1
void Bergnum::inc()
{
	if (zero->isTrue) {
		decompose(zero);
	}
	zero->isTrue = true;
	normalise();
}

int Bergnum::toInt() const
{
	// can't touch *this 
	Bergnum b(*this);
	mylist* curr;
	// Access to zero by local var, not by object
	mylist* localzero = b.zero;
	int res(0);

	/* Algorythm:
	* 1) go to Zero power
	* 2) if (zero_power == true) {
	*		make it false; 
	*		res = res + 1; 
	*		b.normalise(); 
	*		goto 1;
	*	 }
	* 3) search for the closest 1 on the the left
	*	3.1) if found, decompose it, goto 1)
	*	3.2) if found NULL ptr, return res
	*/
	for (;;) {
		curr = localzero;
		if (localzero->isTrue) {
			localzero->isTrue = false;
			res++;
			b.normalise();
			continue;
		} 
		for (;;) {
			// !!! this condition must be first
			if (!curr->more) {
				return res;
			}
			else if (curr->more->isTrue){
				decompose(curr->more);
				break;
			}
			else if (!curr->more->isTrue) {
				curr = curr->more;
			}
		}
	}
	return res;
}

ostream& operator<<(ostream &os, const Bergnum &u)
{
	mylist* curr = u.start;
	for (;;) {
		os << curr->isTrue; 
		/*
		os << " bool: " << curr->isTrue << endl
			<< "power: " << curr->power << endl
			//<< " more: " << curr->more << endl
			<< "  ptr: " << curr << endl
			<< " less: " << curr->less << endl
			<< "=============================\n";
			*/
		if (curr->power == 0) {
			os << '.';
			if (!curr->less) {
				os << '0';
			}
		}
		curr = curr->less;
		if (!curr) {
			os << endl;
			break;
		}
	}
	return os;
}

// very useful func
// but deprived...
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

Bergnum operator+(const Bergnum& a, const Bergnum& b)
{
	return Bergnum(a.toInt() + b.toInt());
}

Bergnum operator-(const Bergnum& a, const Bergnum& b)
{

	if (b.toInt() > a.toInt()) {
		cout << "Negative numbers are not supported" << endl
			 << "You'll get ZERO!" << endl;
		return Bergnum(0);
	}
	return Bergnum(a.toInt() - b.toInt());
	
}

Bergnum operator*(const Bergnum& a, const Bergnum& b)
{
	return Bergnum(a.toInt() * b.toInt());
}

Bergnum operator/(const Bergnum& a, const Bergnum& b)
{
	return Bergnum(a.toInt() / b.toInt());
}