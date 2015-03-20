#ifndef BERGNUM_H
#define	BERGNUM_H

#include "mylist.h"
using namespace std;

class Bergnum 
{
private:
	void inc();
	void normalise();
	void decompose(mylist*) const;
public:
	int fibonacci(const int) const;
	// ptr to number with the highest power
	mylist* start;

	// ptr to number with the power == 0
	mylist* zero;

	// Constructors
	Bergnum();
	Bergnum(const int);
	Bergnum(const Bergnum&);
	Bergnum(mylist*);

	// Destructor
	~Bergnum() {};

	// print function
	static void myprint(mylist* curr);

	// returns int value
	int toInt() const;

	// f-function check
	// return 0 if valid
	int isNotValid() const;

	// a + b
	const Bergnum friend operator+(const Bergnum&, const Bergnum&);

	// a - b
	const Bergnum friend operator-(const Bergnum&, const Bergnum&);

	static Bergnum inputBergnum();

	const Bergnum multiply(const Bergnum&, const Bergnum&) const;
};

ostream& operator<<(ostream &, const Bergnum &);
Bergnum operator*(const Bergnum&, const Bergnum&);
Bergnum operator/(const Bergnum&, const Bergnum&);

#endif