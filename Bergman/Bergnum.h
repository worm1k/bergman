#ifndef BERGNUM_H
#define	BERGNUM_H

#include "mylist.h"
using namespace std;

class Bergnum 
{
private:

	void inc();
	void normalise();

public:
	void decompose(mylist*);
	mylist* start;
	mylist* test;

	Bergnum();
	Bergnum(const int);
	Bergnum(Bergnum&);

	~Bergnum() {};

	void sayhello();
	void myprint(mylist* curr);
	int toInt();
	
	
};

ostream& operator<<(ostream &, const Bergnum &);
Bergnum operator+(const Bergnum&, const Bergnum&);
Bergnum operator-(const Bergnum&, const Bergnum&);

#endif