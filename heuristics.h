#ifndef HEURISTICS_H
#define HEURISTICS_H

#include <iostream>
#include <vector>
using namespace std;

//goal state for 8 puzzle
const VECTOR GOAL = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };

/*Misplaced heuristic checks each space in the puzzle and increments whenever
* the space in the puzzle's current state does not match the space in the
* goal state. Returns number of spaces misplaced
*/
int misplaced_h(VECTOR x) {
	int num = 0;
	for(int i = 0; i < 3; i++) {					//iterate through rows
		for(int j = 0; j < 3; j++) {				//iterate through columns
			if(x.at(i).at(j) == 0) {
				continue;							//skip the blank
			}
			if(x.at(i).at(j) != GOAL.at(i).at(j)) { //check match
				num++;
			}
		}
	}
	return num;
}

/*Helper function for Manhattan heuristic
* Returns the space in the goal state that has the number passed in
*/
void find(int a, int &p, int &q) {
	for(int i = 0; i < 3; i++) {					//iterate through rows
		for(int j = 0; j < 3; j++) {				//iterate through columns
			if(GOAL.at(i).at(j) == a) {
				p = i;
				q = j;
				return;								//values altered by ref
			}
		}
	}
}

/*Manhattan heuristic measures the distance from each out of place space,
* adds up the total distance, and returns the total distance.
* Uses the find helper function to find the correct location of a number
*/
int manhattan_h(VECTOR x) {
	int num = 0;
	for(int i = 0; i < 3; i++) {					//iterate through rows
		for(int j = 0; j < 3; j++) {				//iterate through columns
			if(x.at(i).at(j) == 0) {
				continue;							//skip space
			}
			if(x.at(i).at(j) != GOAL.at(i).at(j)) { //if not matched with goal
				int a = 0;
				int b = 0;
				find(x.at(i).at(j), a, b);			//right right location
				a = a - i;
				b = b - j;
				while(a != 0 || b != 0) {			//calculate distance
					if(a > 0) {
						a--;
						num++;
					}
					if(a < 0) {
						a++;
						num++;
					}
					if(b > 0) {
						b--;
						num++;
					}
					if(b < 0) {
						b++;
						num++;
					}
				}
			}
		}
	}
	return num;
}

#endif
