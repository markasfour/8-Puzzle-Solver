#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unistd.h>
#include "node.h"
#include "operators.h"
#include "heuristics.h"
using namespace std;

// visited nodes
vector <node> VISITED;

// search queue
priority_queue <node, vector<node>, compare> SEARCH;

/* Function returns true if current puzzle already exists in VISITED
 * Returns false otherwise
 */
bool already_visited (VECTOR x) {
	for (int i = 0; i < VISITED.size(); i++) {
		if (VISITED.at(i).x == x) {
			return true;
		}
	}
	return false;
}

/* Called when a solution is found
 * Traverses from solution back up to the root node, storing each node in 
 * a stack along the way. Prints out the contents of the stack as the path
 * to the solution
 */
void print_success(node x, string h, int size, int depth, int expanded) {
	node curr = x;
	stack <node> s;
	s.push(curr);							//add successful node
	while (curr.parent != NULL) {			//go up all parents until at root
		curr = *curr.parent;
		s.push(curr);						//add each parent to stack
	}
	cout << "ROOT NODE" << endl;
	cout << "Expanding state" << endl;
	s.top().print();
	cout << endl;
	s.pop();
	while (!s.empty()) {					//print the contents of the stack
		cout << "The best state to expand with a g(n) = ";
		cout << s.top().heuristic_cost;
		cout << " and h(n) = " << s.top().uniform_cost << " is..." << endl;
		s.top().print();
		cout << "Expanding this node ..." << endl;
		cout << endl;
		s.pop();
	}
	cout << "Goal!!" << endl;
	cout << endl;
	cout << "To solve this problem the search algorithm expanded a total of " << expanded << " nodes."<< endl;
	cout << "The maximum number of nodes in the queue at any one time was " << size << "." << endl;
	cout << "The depth of the goal node was " << depth << endl;
}

/* Create the search tree and find the solution if possible.
 * Uses passed in heuristic to assist in search.
 */
void search(VECTOR problem, string h) {
	node x(problem);
	if (h != "") {
		cout << "Using " << h << " heuristic." << endl;
	}
	VISITED.push_back(x);					//add start node to visited
	SEARCH.push(x);							//add to search tree
	
	int depth = 0;
	int size = 0;
	int expanded = 0;
	while (!SEARCH.empty()) {				//loop while still can search
		node* curr = new node(SEARCH.top()); 
		if (SEARCH.top().x == GOAL) {
			print_success(SEARCH.top(), h, size, depth, expanded);
			break;
		}
		/* diameter of problem = 31
		 * if no solution found at a depth of 31, no solution
		 */
		else if (SEARCH.top().uniform_cost > 31) {
			cout << "NO SOLUTION" << endl;
			break;
		}
		else {
			VISITED.push_back(SEARCH.top());
			int depth_temp = SEARCH.top().uniform_cost;
			if (depth_temp > depth) {		//record max depth
				cout << "DEPTH = " << depth_temp << endl;
				depth = depth_temp;
			}
			int size_temp = SEARCH.size();
			if (size_temp > size) {			//record max size of queue
				size = size_temp;
			}
			SEARCH.pop();
						
			node* n1 = new node (operator_down(curr->x), curr->uniform_cost + 1);
			node* n2 = new node (operator_up(curr->x), curr->uniform_cost + 1);
			node* n3 = new node (operator_left(curr->x), curr->uniform_cost + 1);
			node* n4 = new node (operator_right(curr->x), curr->uniform_cost + 1);
			
			if (h != "") {
				if (h == "misplaced") {		//use misplaced tile heuristic
					n1->heuristic_cost = misplaced_h(n1->x);
					n2->heuristic_cost = misplaced_h(n2->x);
					n3->heuristic_cost = misplaced_h(n3->x);
					n4->heuristic_cost = misplaced_h(n4->x);
				}
				if (h == "manhattan") {		//use manhattan heuristic
					n1->heuristic_cost = manhattan_h(n1->x);
					n2->heuristic_cost = manhattan_h(n2->x);
					n3->heuristic_cost = manhattan_h(n3->x);
					n4->heuristic_cost = manhattan_h(n4->x);
				}
			}
			//calculate total cost
			n1->total = n1->uniform_cost + n1->heuristic_cost;
			n2->total = n2->uniform_cost + n2->heuristic_cost;
			n3->total = n3->uniform_cost + n3->heuristic_cost;
			n4->total = n4->uniform_cost + n4->heuristic_cost;

			if (!already_visited(n1->x)) {	//if not visited, add to search
				curr->child1 = n1;
				n1->parent = curr;
				SEARCH.push(*n1);
				expanded++;					
			}
			if (!already_visited(n2->x)) {	//if not visited, add to search
				curr->child2 = n2;
				n2->parent = curr;
				SEARCH.push(*n2);
				expanded++;
			}
			if (!already_visited(n3->x)) {	//if not visited, add to search
				curr->child3 = n3;
				n3->parent = curr;
				SEARCH.push(*n3);
				expanded++;
			}
			if (!already_visited(n4->x)) {	//if not visited, add to search
				curr->child4 = n4;
				n4->parent = curr;
				SEARCH.push(*n4);
				expanded++;
			}
		}
	}
}

//main function containing UI
int main() {
	cout << "Welcome to Mark Asfour's 8-puzzle solver." << endl;
	cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl;
	int entry = 0;
	while (entry != 1 && entry != 2) {
		cin >> entry;
	}
	int a, b, c, d, e, f, g, h, i;
	if (entry == 1) {
		a = 1; b = 2; c = 3; d = 4;
		e = 5; f = 6; g = 7; h = 0;
		i = 8;
	}
	else {
		cout << "Enter your puzzle, use 0 to represent the blank" << endl;
		cout << "Enter the first row, use space or tabs between numbers" << endl;
		cin >> a >> b >> c;
		cout << "Enter the second row, use space or tabs between numbers" << endl;
		cin >> d >> e >> f;
		cout << "Enter the third row, use space or tabs between numbers" << endl;
		cin >> g >> h >> i;
	}
	vector <int> input;
	input.push_back(a); input.push_back(b); input.push_back(c);
	input.push_back(d); input.push_back(e); input.push_back(f);
	input.push_back(g); input.push_back(h); input.push_back(i);
	
	VECTOR problem(3, vector<int> (3));
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			problem.at(i).at(j) = input.at(k);
			cout << problem.at(i).at(j);
			k++;
		}
		cout << endl;
	}
	
	cout << "Enter your choice of algorithm" << endl;
	cout << "1. Uniform Cost Search" << endl;
	cout << "2. A* with the Misplaced Tile heuristic." << endl;
	cout << "3. A* with the Manhattan distance heuristic." << endl;
	entry = 0;
	while (entry != 1 && entry != 2 && entry != 3) {
		cin >> entry;
	}
	cout << endl;

	string H;
	if (entry == 1) {H = "";}
	if (entry == 2) {H = "misplaced";}
	if (entry == 3) {H = "manhattan";}

	search(problem, H);

	return 0;
}
