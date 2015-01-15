#ifndef BERGNUM_H
#define	BERGNUM_H

#include "mylist.h"
using namespace std;

class Bergnum 
{
private:

	void inc();
	void normalise();
	void write1(mylist*);
	void decompose(mylist*);

public:
	mylist* start;

	Bergnum();
	Bergnum(const int);
	Bergnum(Bergnum&);

	~Bergnum() {};

	void sayhello();

	int toInt();

	
};

ostream& operator<<(ostream &, const Bergnum &);
Bergnum operator+(const Bergnum&, const Bergnum&);
Bergnum operator-(const Bergnum&, const Bergnum&);

#endif