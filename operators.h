#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>
#include <vector>
using namespace std;

// type used to hold puzzle
typedef vector < vector<int> > VECTOR;

/* Swap function used by all operators that swaps the values in the
 * two given positions
 */
VECTOR swap(VECTOR x, int a, int b, int c, int d) {
	int z = x.at(c).at(d);
	x.at(a).at(b) = z;
	x.at(c).at(d) = 0;
	return x;
}

/* Go up. Empty space cannot be in bottom row
 * Returns altered vector. Returns same vector if 0 is in bottom row
 */
VECTOR operator_up(VECTOR x) {
	//check for bad condition
	for (int i = 0; i < 3; i++) {
		if (x.at(2).at(i) == 0) {
			return x;
		}
	}
	//find 0
	int a, b;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (x.at(i).at(j) == 0) {
				a = i;
				b = j;
			}
		}
	}
	return swap(x, a, b, a + 1, b);
}

/* Go down. Empty space cannot be in top row
 * Returns altered vector. Returns same vector if 0 is in top row
 */
VECTOR operator_down(VECTOR x) {
	//check for bad condition
	for (int i = 0; i < 3; i++) {
		if (x.at(0).at(i) == 0) {
			return x;
		}
	}
	//find 0
	int a, b;
	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(x.at(i).at(j) == 0) {
				a = i;
				b = j;
			}
		}
	}
	return swap(x, a, b, a - 1, b);
}

/* Go left. Empty space cannot be in right column
 * Returns altered vector. Returns same vector if 0 is in right column 
 */
VECTOR operator_left(VECTOR x) {
	//check for bad condition
	for (int i = 0; i < 3; i++) {
		if (x.at(i).at(2) == 0) {
			return x;
		}
	}
	//find 0
	int a, b;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (x.at(i).at(j) == 0) {
				a = i;
				b = j;
			}
		}
	}
	return swap(x, a, b, a, b + 1);
}

/* Go right. Empty space cannot be in left column
 * Returns altered vector. Returns same vector if 0 is in left column 
 */
VECTOR operator_right(VECTOR x) {
	//check for bad condition
	for (int i = 0; i < 3; i++) {
		if (x.at(i).at(0) == 0) {
			return x;
		}
	}
	//find 0
	int a, b;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			if (x.at(i).at(j) == 0) {
				a = i;
				b = j;
			}
		}
	}
	return swap(x, a, b, a, b - 1);
}
#endif
