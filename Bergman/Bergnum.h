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
	mylist* start;
	mylist* zero;
	mylist* test;

	Bergnum();
	Bergnum(const int);
	Bergnum(const Bergnum&);

	~Bergnum() {};

	void sayhello();
	void myprint(mylist* curr);
	int toInt() const;
};

ostream& operator<<(ostream &, const Bergnum &);
Bergnum operator+(const Bergnum&, const Bergnum&);
Bergnum operator-(const Bergnum&, const Bergnum&);
Bergnum operator*(const Bergnum&, const Bergnum&);
Bergnum operator/(const Bergnum&, const Bergnum&);

#endif