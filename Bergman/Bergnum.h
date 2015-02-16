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
	// ptr to number with the highest power
	mylist* start;

	// ptr to number with the power == 0
	mylist* zero;
	void myFunc() {
		cout << start->more << endl;
//			<< (start->more->isTrue == true)
//		<< (start->more->isTrue == false);
	};
	// Constructors
	Bergnum();
	Bergnum(const int);
	Bergnum(const Bergnum&);

	// Destructor
	~Bergnum() {};

	// print function
	void myprint(mylist* curr);

	// returns int value
	int toInt() const;
};

ostream& operator<<(ostream &, const Bergnum &);
Bergnum operator+(const Bergnum&, const Bergnum&);
Bergnum operator-(const Bergnum&, const Bergnum&);
Bergnum operator*(const Bergnum&, const Bergnum&);
Bergnum operator/(const Bergnum&, const Bergnum&);

#endif