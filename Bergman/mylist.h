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

	// deprived
	mylist(mylist* a, mylist* b, int pow, bool c) {
		more = a;
		less = b;
		power = pow;
		isTrue = c;
	}

	mylist(int newLeft, mylist* right) {
		less = right;
		power = right->power + 1;
		isTrue = false;
		more = 0;
	}

	mylist(mylist* left, int newRight) {
		more = left;
		power = left->power - 1;
		isTrue = false;
		less = 0;
	}
};

#endif