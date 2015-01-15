#ifndef MYLIST_H
#define MYLIST_H

struct mylist 
{
	bool isTrue;
	int power;
	mylist* more;
	mylist* less;

	mylist() {
		more = 0;
		less = 0;
		power = 0;
		isTrue = false;
	}

	mylist(mylist* a, mylist* b, int pow, bool c) {
		less = b;
		more = a;
		power = pow;
		isTrue = c;
	}
};

#endif