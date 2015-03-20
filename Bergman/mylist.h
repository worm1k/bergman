#ifndef MYLIST_H
#define MYLIST_H

// Linked list
struct mylist 
{
	int multiplier;
	int power;
	mylist* more;
	mylist* less;

	mylist() {
		more = 0;
		less = 0;
		power = 0;
		multiplier = 0;
	}

	// deprived 
	// only for debugging
	mylist(mylist* a, mylist* b, int pow, int multipl) {
		more = a;
		less = b;
		power = pow;
		multiplier = multipl;
	}

	// int value is useless
	// only for marking, that you make a new number on the left (more)
	mylist(int newLeft, mylist* right) {
		less = right;
		power = right->power + 1;
		multiplier = 0;
		more = 0;
	}

	// int value is useless
	// only for marking, that you make a new number on the right (less)
	mylist(mylist* left, int newRight) {
		more = left;
		power = left->power - 1;
		multiplier = 0;
		less = 0;
	}
};

#endif