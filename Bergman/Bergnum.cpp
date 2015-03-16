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
		cout << "Negative numbers are not supported\n"
			 <<	"You will get 0\n";
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
	start = new mylist(0, 0, orig->power, orig->multiplier);
	mylist* curr = start;

	for (;;) {
		if (!orig->less) {
			break;
		}
		curr->less = new mylist(curr, 0, orig->less->power, orig->less->multiplier);
		curr = curr->less;
		orig = orig->less;
		if (curr->power == 0) {
			zero = curr;
		}
	}
}


// 1 0 0 -> 0 1 1
void Bergnum::decompose(mylist* curr) const
{
	  // 1 • • -> 1 0 0
	if (!curr->less) {
		curr->less = new mylist(curr,0);
		curr->less->less = new mylist(curr->less, 0);
	} // 1 0 • -> 1 0 0
	else if (curr->less->multiplier == 0 && !curr->less->less) {
		curr->less->less = new mylist(curr->less, 0);
	} // 1 0 0
	else if (curr->less->multiplier == 0 && curr->less->less->multiplier == 0) {
		// Well, well, well...
	} // 1 0 1 -> 1 0 0
	else if (curr->less->less->multiplier != 0) {
		decompose(curr->less->less);
	}
	--(curr->multiplier);
	++(curr->less->multiplier);
	++(curr->less->less->multiplier);
}

void Bergnum::normalise()
{
	mylist* curr = start;
	while (curr) {	
		
		// 0 2 0 0 -> 1 0 0 1
		if (curr->multiplier > 1) {
			//cout << " 0 2 0 0 -> 1 0 0 1" << endl;
			if (!curr->more) { // • 2
				curr->more = new mylist(0, curr);
				start = curr->more;
			}
			if (!curr->less) { // 2 •
				curr->less = new mylist(curr, 0);
			}
			if (!curr->less->less) { // 2 0 •
				curr->less->less = new mylist(curr->less, 0);
			}
			curr->more->multiplier += 1;
			curr->multiplier -= 2;
			curr->less->less->multiplier += 1;
			curr = start;
		}

		// 0 -1 0 -> -1 0 1
		if (curr->multiplier < 0) {
			//cout << " 0 -1 0 -> -1 0 1" << endl;
			if (!curr->more) { // • -1 
				cout << "Invalid number error\n";
				exit(0);
			}
			if (!curr->less) { // -1 •
				curr->less = new mylist(curr, 0);
			}
			--(curr->more->multiplier);
			++(curr->multiplier);
			++(curr->less->multiplier);
			curr = start;

		}
		// 0 1 1 -> 1 0 0
		if (curr->multiplier > 0 && curr->less) {
			if (curr->less->multiplier > 0) {
				//cout << " 0 1 1 -> 1 0 0" << endl;
				if (!curr->more) { // • 1 1
					curr->more = new mylist(0, curr);
					start = curr->more;
				}
				++(curr->more->multiplier);
				--(curr->multiplier);
				--(curr->less->multiplier);
				curr = start;

			}
		}
		curr = curr->less;
	}
}

// increment by 1
void Bergnum::inc()
{
	++(zero->multiplier);
	normalise();
}

int Bergnum::fibonacci(const int n) const {
	if (n == 0) {
		return 0;
	}
	else if (n == 1 || n == -1){
		return 1;
	}
	else if (n > 1) {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	else if (n < -1) {
		return fibonacci(n + 2) - fibonacci(n + 1);
	}

	return 0;
}
int Bergnum::toInt() const
{
	// can't touch *this 
	Bergnum b(*this);
	b.normalise();
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
		if (localzero->multiplier > 0) {
			--(localzero->multiplier);
			res++;
			b.normalise();
			continue;
		} 
		for (;;) {
			// !!! this condition must be first
			if (!curr->more) {
				return res;
			}
			else if (curr->more->multiplier > 0){
				decompose(curr->more);
				break;
			}
			else if (curr->more->multiplier == 0) {
				curr = curr->more;
			}
		}
	}
	return res;
}

int Bergnum::isValid() const
{


	int positiveFib(0);
	int negativeFib(0);

	for (mylist* current = zero->more; current; current = current->more) {
		for (int i = 0; i < current->multiplier; ++i) {
			positiveFib += fibonacci(current->power);
		}
	}

	for (mylist* current = zero->less; current; current = current->less) {
		for (int i = 0; i < current->multiplier; ++i) {
			negativeFib += fibonacci(current->power);
		}
	}

	return positiveFib + negativeFib;
}

// very useful func
// but deprived...
void Bergnum::myprint(mylist* curr) const
{
	for (;;) {
		//os << curr->multiplier;
		cout << " bool: " << curr->multiplier << endl
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

ostream& operator<<(ostream &os, const Bergnum &u)
{
	mylist* curr = u.start;
	for (;;) {
		os << curr->multiplier; 
		/*
		os << " bool: " << curr->multiplier << endl
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

const Bergnum operator+(const Bergnum& a, const Bergnum& b)
{
	Bergnum result;
	mylist* currResult;
	mylist* currOperated;


	// setting pointers to start of borh numbers
	if (a.start->power >= b.start->power) {
		result = Bergnum(a);
		currOperated = b.start;
	}
	else {
		result = Bergnum(b);
		currOperated = a.start;
	}
	currResult = result.start;

	// moving pointer to the same power
	while (currResult->power != currOperated->power) {
		cout << endl;
		currResult = currResult->less;
		if (!currOperated) {
			cout << "Mistake in plus operation\n";
			exit(0);
		}
	}

	// arithmetical addition/*
	while (currOperated) {
		currResult->multiplier += currOperated->multiplier;
		currOperated = currOperated->less;
		currResult = currResult->less;
	}
	cout << result;
	result.normalise();
	return result;
}

const Bergnum operator-(const Bergnum& a, const Bergnum& b)
{

	if (b.toInt() > a.toInt()) {
		cout << "Negative numbers are not supported" << endl
			 << "You'll get ZERO!" << endl;
		return Bergnum(0);
	}	
	
	Bergnum result;
	mylist* currResult;
	mylist* currOperated;


	// setting pointers to start of borh numbers
	result = Bergnum(a);
	currOperated = b.start;
	currResult = result.start;


	// moving pointer to the same power
	while (currResult->power != currOperated->power) {
		cout << endl;
		currResult = currResult->less;
		if (!currOperated) {
			cout << "Mistake in minus operation\n";
			exit(0);
		}
	}

	// arithmetical addition/*
	while (currOperated) {
		currResult->multiplier -= currOperated->multiplier;
		currOperated = currOperated->less;
		currResult = currResult->less;
	}
	cout << result;
	result.normalise();
	return result;
	
}

Bergnum operator*(const Bergnum& a, const Bergnum& b)
{
	return Bergnum(a.toInt() * b.toInt());
}

Bergnum operator/(const Bergnum& a, const Bergnum& b)
{
	return Bergnum(a.toInt() / b.toInt());
}